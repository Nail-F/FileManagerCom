// FileManager.cpp : Implementation of CFileManager

#include "stdafx.h"
#include <atlsafe.h>

#include "FileManager.h"
#include "FileEntry.h"

#include "boost/filesystem/operations.hpp"
#include "boost/filesystem/path.hpp"
#include <boost/range/iterator_range.hpp>
#include <wchar.h>

#include <sys/stat.h>
#include <sys/types.h>
#include <winerror.h>

namespace fs = boost::filesystem;

CFileManager::CFileManager()
  : last_error_(NOERROR)
{
}

HRESULT STDMETHODCALLTYPE CFileManager::hello_world(BSTR *str_in)
{
  if (!str_in)
  {
    return set_last_error(E_INVALIDARG);
  }
  CComBSTR str("Hello World!");
  *str_in = str.Detach();

  return set_last_error(NOERROR);
}

HRESULT STDMETHODCALLTYPE CFileManager::file_list(BSTR file_path, 
                                                  int /*file_list_options*/, 
                                                  SAFEARRAY** file_entry_list)
{
  if (!file_entry_list)
  {
    return set_last_error(E_INVALIDARG);
  }

  CComSafeArray<VARIANT> list;
  list.Create();

  if (!file_path)
  {
    UINT driveType = DRIVE_UNKNOWN;
    PWSTR driveTypeString = NULL;

    DWORD cchBuffer = GetLogicalDriveStrings(0, NULL);
    WCHAR* const drives_str = (WCHAR*)malloc((cchBuffer + 1) * sizeof(TCHAR));
    WCHAR* p_drives_str = drives_str;

    GetLogicalDriveStrings(cchBuffer, p_drives_str);

    while (*p_drives_str)
    {
      driveType = GetDriveType(p_drives_str);
      enum_file_type type = FT_UNKNOWN;
      switch (driveType)
      {
      case DRIVE_FIXED:
        type = FT_DRIVE_FIXED;
        break;
      case DRIVE_CDROM:
        type = FT_DRIVE_CDROM;
        break;
      case DRIVE_REMOVABLE:
        type = FT_DRIVE_REMOVABLE;
        break;
      case DRIVE_REMOTE:
        type = FT_DRIVE_REMOTE;
        break;
      case DRIVE_RAMDISK:
        type = FT_DRIVE_RAMDISK;
        break;
      default:
        type = FT_UNKNOWN;
        break;
      }

      CComObject<CFileEntry>* file_entry = new CComObject<CFileEntry>();
      file_entry->init(p_drives_str, (int)type);

      VARIANT var_entry;
      var_entry.vt = VT_UNKNOWN;
      var_entry.punkVal = file_entry;
      list.Add(var_entry);

      p_drives_str += lstrlen(p_drives_str) + 1;
    }

    free(drives_str);

    *file_entry_list = list.Detach();
    return set_last_error(NOERROR);
  }

  fs::path dir(file_path);
  //else get list of dirs & files in file_entry
  if (!fs::exists(dir))
  {
    return set_last_error(ERROR_PATH_NOT_FOUND);
  }

  if (!fs::is_directory(dir))
  {
    return set_last_error(ERROR_DIRECTORY);
  }

  for (auto& it : boost::make_iterator_range(fs::directory_iterator(dir), fs::directory_iterator()))
  {
    CComObject<CFileEntry>* file_entry = NULL;
    HRESULT hr = get_entry((BSTR)it.path().c_str(), (IFileEntry**)&file_entry);
    if (!hr)
    {
      VARIANT var_entry;
      var_entry.vt = VT_UNKNOWN;
      var_entry.punkVal = file_entry;
      list.Add(var_entry);
    }
  }

  *file_entry_list = list.Detach();

  return set_last_error(NOERROR);
}

STDMETHODIMP CFileManager::create_file(BSTR path_src)
{
  if (!path_src)
  {
    return set_last_error(E_INVALIDARG);
  }

  fs::path file(path_src);
  boost::system::error_code ec;
  if (!fs::exists(file, ec))
  {
    std::ofstream outfile(file.c_str());
    if (fs::exists(file, ec))
    {
      outfile << "Created file from FileManagerCOM!" << std::endl;
      return set_last_error(NOERROR);
    }
  }
  return set_last_error(ec.value());
}

STDMETHODIMP CFileManager::create_folder(BSTR folder_path)
{
  if (!folder_path)
  {
    return set_last_error(E_INVALIDARG);
  }

  fs::path folder(folder_path);
  if (!fs::exists(folder))
  {
    boost::system::error_code ec;
    fs::create_directory(folder, ec);
    if (ec)
    {
      return set_last_error(ec.value());
    }
  }
  return set_last_error(NOERROR);
}

STDMETHODIMP CFileManager::copy_file(BSTR file_path_src, BSTR file_path_dst)
{
  if (!file_path_src || !file_path_dst)
  {
    return set_last_error(E_INVALIDARG);
  }

  fs::path src(file_path_src);
  fs::path dst(file_path_dst);
  if (!fs::exists(src) || fs::exists(dst))
  {
    return set_last_error(ERROR_PATH_NOT_FOUND);
  }

  boost::system::error_code ec;
  fs::copy_file(src, dst, ec);
  if (ec)
  {
    return set_last_error(ec.value());
  }
  return set_last_error(NOERROR);
}

STDMETHODIMP CFileManager::rename_file(BSTR file_path_src, BSTR file_path_dst)
{
  if (!file_path_src || !file_path_dst)
  {
    return set_last_error(E_INVALIDARG);
  }

  fs::path src(file_path_src);
  fs::path dst(file_path_dst);
  if (!fs::exists(src) || fs::exists(dst))
  {
    return set_last_error(E_INVALIDARG);
  }

  boost::system::error_code ec;
  fs::rename(src, dst, ec);
  if (ec)
  {
    return set_last_error(ec.value());
  }
  return set_last_error(NOERROR);
}

STDMETHODIMP CFileManager::delete_file(BSTR file_path)
{
  if (!file_path)
  {
    return set_last_error(E_INVALIDARG);
  }

  fs::path src(file_path);
  if (!fs::exists(src))
  {
    return set_last_error(ERROR_PATH_NOT_FOUND);
  }

  boost::system::error_code ec;
  fs::remove_all(src, ec);
  if (ec)
  {
    return set_last_error(ec.value());
  }
  return set_last_error(NOERROR);
}

STDMETHODIMP CFileManager::get_entry(BSTR file_path, IFileEntry **file_entry_out)
{
  if (!file_path || !file_entry_out)
  {
    return set_last_error(E_INVALIDARG);
  }
  *file_entry_out = NULL;

  fs::path src(file_path);
  if (!fs::exists(src))
  {
    return set_last_error(ERROR_PATH_NOT_FOUND);
  }

  boost::system::error_code ec;
  fs::file_status status = fs::status(src, ec);
  if (!ec || ec.value() == ERROR_SHARING_VIOLATION)
  {
    struct _stat64 file_stat;
    std::time_t created_time = 0;
    std::time_t modified_time = 0;
    std::size_t file_size = 0;
    if (!_wstat64(file_path, &file_stat))
    {
      created_time = file_stat.st_ctime;
      modified_time = file_stat.st_mtime;
      file_size = file_stat.st_size;

      if (ec.value() == ERROR_SHARING_VIOLATION)
      {
        fs::perms perms = fs::no_perms;
        if (file_stat.st_mode & S_IREAD)
        {
          perms |= fs::owner_read;
        }
        if (file_stat.st_mode & S_IWRITE)
        {
          perms |= fs::owner_read;
        }
        if (file_stat.st_mode & S_IEXEC)
        {
          perms |= fs::owner_exe;
        }
        status.permissions(perms);
      }
    }

    if (ec.value() == ERROR_SHARING_VIOLATION)
    {
      if (DWORD attrs = GetFileAttributes(file_path) != INVALID_FILE_ATTRIBUTES)
      {
        status.type((attrs & FILE_ATTRIBUTE_DIRECTORY) ? fs::directory_file : fs::regular_file);
      }
    }

    CComObject<CFileEntry> *file_entry = new CComObject<CFileEntry>();
    file_entry->init(src.wstring(),
      (int)status.type(),
      (int)status.permissions(),
      file_size,
      created_time,
      modified_time
     );
    *file_entry_out = file_entry;
    return set_last_error(NOERROR);
  }

  return set_last_error(ec.value());
}

STDMETHODIMP CFileManager::last_error()
{
  return last_error_;
}

STDMETHODIMP CFileManager::set_last_error(HRESULT error_code)
{
  if (error_code != NOERROR)
  {
    last_error_ = MAKE_HRESULT(SEVERITY_ERROR, FACILITY_NULL, error_code);
    return S_FALSE;
  }
  last_error_ = NOERROR;
  return S_OK;
}
