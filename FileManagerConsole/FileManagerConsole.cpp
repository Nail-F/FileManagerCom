// FileManagerConsole.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "..\IFileManagerCOM\IFileManagerCOM.h"
#include "..\IFileManagerCOM\IFileManagerCOM_i.c"
#include "..\IFileManagerCOM\IFileEntry.h"

#include <iostream>
#include <objbase.h>
#include <atlcomcli.h>
#include <atlsafe.h>
#include <assert.h>
#include <regex>
#include <stdint.h>
#include <string>

const BSTR CONST_COMMAND_EXIT = L"exit";
const BSTR CONST_COMMAND_COPY = L"cp ";
const BSTR CONST_COMMAND_MOVE = L"mv ";
const BSTR CONST_COMMAND_DELETE = L"rm ";
const BSTR CONST_COMMAND_LIST = L"ls ";
const BSTR CONST_COMMAND_CREATE_FOLDER = L"mkdir ";
const BSTR CONST_COMMAND_CREATE_FILE = L"mkfile ";
const BSTR CONST_COMMAND_HELP = L"help";
const BSTR CONST_COMMAND_TEST = L"test";

const int CONST_HEADER_NAME_SIZE = 70;
const int CONST_HEADER_TYPE_SIZE = 10;
const int CONST_HEADER_SIZE_SIZE = 13;
const int CONST_HEADER_DATE_SIZE = 20;

struct ComRaii
{
  ComRaii()
  {
    CoInitialize(NULL);
  }

  ~ComRaii() 
  { 
    CoUninitialize(); 
  }
};

void print_help();
std::string GetLastErrorAsString(IFileManager * p_manager = NULL);
void erase_quotes(std::wstring &str);
bool IS_0(const WCHAR *inbound, const WCHAR *command);
bool IS_1(const WCHAR *inbound, const WCHAR *command, WCHAR **out_param);
bool IS_2(const WCHAR *inbound, const WCHAR *command, WCHAR **out_param1, WCHAR **out_param2);

int _tmain(int argc, _TCHAR* argv[])
{
  setlocale(LC_ALL, "ru-RU");
  SetConsoleOutputCP(866);

  ComRaii com_init;

  CComPtr<IFileManager> p_manager;
  HRESULT hr = CoCreateInstance(CLSID_FileManager, NULL, CLSCTX_INPROC_SERVER, IID_IFileManager, (LPVOID*)&p_manager);
  if (!hr && p_manager)
  {
    CComBSTR str;
    hr = p_manager->hello_world(&str);
    if (!hr)
    {
      std::wcout << str.m_str << std::endl;
    }
    else
    {
      std::cout << "error occured: " << p_manager->last_error() << std::endl;
    }

    CComBSTR command(3 * MAX_PATH);
    CComBSTR out_param1(MAX_PATH);
    CComBSTR out_param2(MAX_PATH);

#pragma region tests IS_0 IS_1 IS_2
    assert(IS_0(L"help", CONST_COMMAND_HELP));
    assert(!IS_0(L"helpp", CONST_COMMAND_HELP));
    assert(IS_1(L"rm qw er", CONST_COMMAND_DELETE, &out_param1));
    assert(wcsncmp(out_param1, L"qw er", wcslen(out_param1)) == 0);
    assert(IS_1(L"rm \"qw er\"", CONST_COMMAND_DELETE, &out_param1));
    assert(wcsncmp(out_param1, L"qw er", wcslen(out_param1)) == 0);
    assert(!IS_1(L"rmqw er", CONST_COMMAND_DELETE, &out_param1));
    assert(wcsncmp(out_param1, L"", wcslen(out_param1)) == 0);
    assert(IS_2(L"cp d:\\qwerty d:\\asdfgh", CONST_COMMAND_COPY, &out_param1, &out_param2));
    assert(wcsncmp(out_param1, L"d:\\qwerty", wcslen(out_param1)) == 0);
    assert(wcsncmp(out_param2, L"d:\\asdfgh", wcslen(out_param2)) == 0);
    assert(!IS_2(L"cp qwertyasdfgh", CONST_COMMAND_COPY, &out_param1, &out_param2));
    assert(wcsncmp(out_param1, L"", wcslen(out_param1)) == 0);
    assert(wcsncmp(out_param2, L"", wcslen(out_param2)) == 0);
#pragma endregion
    
    print_help();

    while (!IS_0(command, CONST_COMMAND_EXIT))
    {
      std::wcin.getline(command, command.Length());
      if (IS_0(command, CONST_COMMAND_EXIT))
      {
        std::wcout << "Bye!" << std::endl;
        break;
      }
      else if (IS_0(command, CONST_COMMAND_HELP))
      {
        print_help();
      }
      else if (IS_2(command, CONST_COMMAND_COPY, &out_param1, &out_param2))
      {
        hr = p_manager->copy_file(out_param1, out_param2);
      }
      else if (IS_2(command, CONST_COMMAND_MOVE, &out_param1, &out_param2))
      {
        hr = p_manager->rename_file(out_param1, out_param2);
      }
      else if (IS_1(command, CONST_COMMAND_DELETE, &out_param1))
      {
        hr = p_manager->delete_file(out_param1);
      }
      else if (IS_1(command, CONST_COMMAND_LIST, &out_param1))
      {
        LPSAFEARRAY p_list = NULL;
        hr = p_manager->file_list(out_param1, NULL, &p_list);
        if (hr)
        {
          std::cout << "Getting list failed with error: " << p_manager->last_error() << std::endl;
          continue;
        }
        CComSafeArray<VARIANT> list;
        list.Attach(p_list);
        if (!hr)
        {
          std::wstring name(L"name");
          name.resize(CONST_HEADER_NAME_SIZE, L' ');
          std::wstring type_str(L"type");
          type_str.resize(CONST_HEADER_TYPE_SIZE + 2, L' ');
          std::wstring size_str(L"size (bytes) ");
          size_str.resize(CONST_HEADER_SIZE_SIZE, L' ');
          std::wstring date_str(L"create date");
          date_str.resize(CONST_HEADER_DATE_SIZE, L' ');
          std::wstring delimiter;
          delimiter.resize(CONST_HEADER_NAME_SIZE +
                           CONST_HEADER_TYPE_SIZE + 2 +
                           CONST_HEADER_SIZE_SIZE +
                           CONST_HEADER_DATE_SIZE, L'-');


          std::wcout << name << type_str << size_str << date_str << std::endl;
          std::wcout << delimiter << std::endl;

          for (ULONG i = 0; i < list.GetCount(); ++i)
          {
            VARIANT v = list.GetAt(i);
            if (v.vt == VT_UNKNOWN)
            {
              IFileEntry* entry = (IFileEntry*)v.punkVal;
              if (!entry)
              {
                continue;
              }
              BSTR c_name;
              entry->name(&c_name);
              name = c_name;
              if (name.size() < CONST_HEADER_NAME_SIZE)
              {
                name.resize(CONST_HEADER_NAME_SIZE, L' ');
              }
              else
              {
                name += L" ";
              }

              enum_file_type type = FT_UNKNOWN;
              entry->type((int*)&type);
              type_str = type;
              switch (type)
              {
              case FT_DIRECTORY_FILE:
              case FT_DRIVE_NO_ROOT_DIR:
              case FT_DRIVE_REMOVABLE:
              case FT_DRIVE_FIXED:
              case FT_DRIVE_REMOTE:
              case FT_DRIVE_CDROM:
              case FT_DRIVE_RAMDISK:
                type_str = L"FOLDER";
                break;

              case FT_REGULAR_FILE:
              case FT_SYMLINK_FILE:
              case FT_BLOCK_FILE:
              case FT_CHARACTER_FILE:
              case FT_FIFO_FILE:
              case FT_SOCKET_FILE:
              case FT_REPARSE_FILE:
              case FT__DETAIL_DIRECTORY_SYMLINK:
                type_str = L"FILE";
                break;

              case FT_STATUS_ERROR:
              case FT_FILE_NOT_FOUND:
              case FT_TYPE_UNKNOWN:
              case FT_UNKNOWN:
                type_str = L"UNKNOWN";
              default:

                break;
              }
              type_str.resize(CONST_HEADER_TYPE_SIZE, L' ');

              int64_t size = 0;
              entry->size(&size);
              size_str = std::to_wstring(size);
              size_str.resize(CONST_HEADER_SIZE_SIZE, L' ');

              int64_t date_cr = 0;
              entry->created(&date_cr);
              struct tm *lt = localtime(&date_cr);
              char timbuf[CONST_HEADER_DATE_SIZE];
              strftime(timbuf, sizeof(timbuf), "%c", lt);

              std::wcout << name << type << L" " << type_str << size_str << timbuf << "\n";
            }
          }
        }
      }
      else if (IS_1(command, CONST_COMMAND_CREATE_FOLDER, &out_param1))
      {
        hr = p_manager->create_folder(out_param1);
      }
      else if (IS_1(command, CONST_COMMAND_CREATE_FILE, &out_param1))
      {
        hr = p_manager->create_file(out_param1);
      }
      else if (IS_2(command, CONST_COMMAND_TEST, &out_param1, &out_param2))
      {
        int count = -1;
        count = _wtoi(out_param2);
        if (count < 0)
        {
          continue;
        }

        hr = S_OK;
        while (!hr && count--)
        {
          LPSAFEARRAY p_list = NULL;
          hr = p_manager->file_list(out_param1, NULL, &p_list);
          if (!hr)
          {
            CComSafeArray<VARIANT> list;
            list.Attach(p_list);
            std::cout << count <<") Getting list with " << list.GetCount() << " elements" << std::endl;
          }
        }
      }
      else
      {
        std::wcout << "Misunderstood command. Please retry!" << std::endl;
      }

      if (hr)
      {
        std::cout << "Error:\n" << GetLastErrorAsString(p_manager) << std::endl;
      }
    }
  }

  if (hr)
  {
    std::cout << "Error:\n" << GetLastErrorAsString() << std::endl;
  }

  return 0;
}

void print_help()
{
  std::wcout << L"========" << std::endl;
  std::wcout << L"Use these commands to operate with files & folders" << std::endl;
  std::wcout << L"'" << CONST_COMMAND_HELP << L"' to see this text" << std::endl;
  std::wcout << L"'" << CONST_COMMAND_EXIT << L"' to exit from program" << std::endl;
  std::wcout << L"'" << CONST_COMMAND_COPY << L"%1 %2' to copy from %1 to %2" << std::endl;
  std::wcout << L"'" << CONST_COMMAND_MOVE << L"%1 %2' to rename (move) from %1 to %2" << std::endl;
  std::wcout << L"'" << CONST_COMMAND_DELETE << L"%1' to delete %1" << std::endl;
  std::wcout << L"'" << CONST_COMMAND_LIST << L"%1' to see list of files & folders in %1" << std::endl;
  std::wcout << L"'" << CONST_COMMAND_CREATE_FOLDER << L"%1' to create a folder %1" << std::endl;
  std::wcout << L"'" << CONST_COMMAND_CREATE_FILE << L"%1' to create a file %1" << std::endl;
  std::wcout << L"========" << std::endl;
}

std::string GetLastErrorAsString(IFileManager * p_manager)
{
  //Get the error message, if any.
  DWORD errorMessageID = NOERROR;
  if (p_manager)
  {
    errorMessageID = p_manager->last_error();
  }
  else
  {
    errorMessageID = ::GetLastError();
  }

  if(errorMessageID == 0)
    return std::string(); //No error message has been recorded

  LPSTR messageBuffer = nullptr;
  size_t size = FormatMessageA(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
    NULL, errorMessageID, MAKELANGID(LANG_ENGLISH, SUBLANG_ENGLISH_US), (LPSTR)&messageBuffer, 0, NULL);

  std::string message(messageBuffer, size);

  //Free the buffer.
  LocalFree(messageBuffer);

  return message;
}

void erase_quotes(std::wstring &str)
{
  if (str.empty())
  {
    return;
  }
  str.erase(std::remove( str.begin(), str.end(), '\"' ), str.end());
  str.erase(std::remove( str.begin(), str.end(), '\'' ), str.end());
}

bool IS_0(const WCHAR *inbound, const WCHAR *command)
{
  return wcscmp(inbound, command) == 0 && wcslen(inbound) == wcslen(command);
}

bool IS_1(const WCHAR *inbound, const WCHAR *command, WCHAR **out_param)
{
  if (out_param)
  {
    *out_param[0] = '\0';
    if (wcsncmp(inbound, command, wcslen(command)) == 0 && wcslen(inbound) > wcslen(command))
    {
      *out_param[0] = '\0';
      std::wstring temp = const_cast<WCHAR*>(inbound) + wcslen(command);
      erase_quotes(temp);
      try
      {
        wcscpy(*out_param, temp.c_str());
      }
      catch(std::exception &ex)
      {
        std::cout << ex.what() << "\n";
        return false;
      }
      return true;
    }
  }
  return false;
}

bool IS_2(const WCHAR *inbound, const WCHAR *command, WCHAR **out_param1, WCHAR **out_param2)
{
  if (out_param1 && out_param2)
  {
    if (wcsncmp(inbound, command, wcslen(command)) == 0 && wcslen(inbound) > wcslen(command))
    {
      *out_param1[0] = '\0';
      *out_param2[0] = '\0';
      try
      {
        std::wstring str(inbound+wcslen(command));
        std::wregex rgx(L"\"([^\"]*)\"|([\\w\\\\/:.]+)");
        std::wsregex_iterator current(str.begin(), str.end(), rgx);
        std::wsregex_iterator end;
        if (current != end)
        {
          std::wstring temp1 = (*current).str();
          erase_quotes(temp1);
          if (++current != end)
          {
            std::wstring temp2 = (*current).str();
            erase_quotes(temp2);
            wcscpy(*out_param1, temp1.c_str());
            wcscpy(*out_param2, temp2.c_str());
            return true;
          }
        }
      }
      catch(std::exception &ex)
      {
        std::cout << ex.what() << "\n";
        return false;
      }
    }
  }
  return false;
}