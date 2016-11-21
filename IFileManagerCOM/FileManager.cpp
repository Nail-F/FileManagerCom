// FileManager.cpp : Implementation of CFileManager

#include "stdafx.h"
#include <atlsafe.h>

#include "FileManager.h"
#include "FileEntry.h"

#include "boost/filesystem/operations.hpp"
#include "boost/filesystem/path.hpp"
#include <wchar.h>

#include <sys/stat.h>
#include <sys/types.h>

namespace fs = boost::filesystem;

// CFileManager

HRESULT STDMETHODCALLTYPE CFileManager::hello_world(BSTR *str_in)
{
  if (!str_in)
  {
    return MAKE_HRESULT(SEVERITY_ERROR, FACILITY_NULL, E_INVALIDARG);
  }
  CComBSTR str("Hello World!");
  *str_in = str.Detach();

  return S_OK;
}

HRESULT STDMETHODCALLTYPE CFileManager::file_list(BSTR file_path, 
                                                  int /*file_list_options*/, 
                                                  SAFEARRAY** file_entry_list)
{
  if (!file_entry_list)
  {
    return MAKE_HRESULT(SEVERITY_ERROR, FACILITY_NULL, S_FALSE);
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
    return S_OK;
  }

  fs::path dir(file_path);
  //else get list of dirs & files in file_entry
  if (!fs::exists(dir))
  {
    return MAKE_HRESULT(SEVERITY_ERROR, FACILITY_NULL, E_PATH_NOT_FOUND);
  }

  fs::directory_iterator end_it;
  for (fs::directory_iterator it(dir); it != end_it; ++it)
  {
    CComObject<CFileEntry>* file_entry = NULL;
    HRESULT hr = get_entry((BSTR)it->path().c_str(), (IFileEntry**)&file_entry);
    if (SUCCEEDED(hr))
    {
      VARIANT var_entry;
      var_entry.vt = VT_UNKNOWN;
      var_entry.punkVal = file_entry;
      list.Add(var_entry);
    }
  }

  *file_entry_list = list.Detach();

  return S_OK;
}

STDMETHODIMP CFileManager::create_file(BSTR path_src)
{
  if (!path_src)
  {
    return MAKE_HRESULT(SEVERITY_ERROR, FACILITY_NULL, E_INVALIDARG);
  }

  fs::path file(path_src);
  if (!fs::exists(file))
  {
    std::ofstream outfile(file.c_str());
    if (fs::exists(file))
    {
      outfile << "Created file from FileManagerCOM!" << std::endl;
      return S_OK;
    }
  }
  return MAKE_HRESULT(SEVERITY_ERROR, FACILITY_NULL, S_FALSE);
}

STDMETHODIMP CFileManager::create_folder(BSTR folder_path)
{
  if (!folder_path)
  {
    return MAKE_HRESULT(SEVERITY_ERROR, FACILITY_NULL, E_INVALIDARG);
  }

  fs::path folder(folder_path);
  if (!fs::exists(folder))
  {
    boost::system::error_code ec;
    fs::create_directory(folder, ec);
    if (ec)
    {
      return MAKE_HRESULT(SEVERITY_ERROR, FACILITY_NULL, ec.value());
    }
  }
  return S_OK;
}

STDMETHODIMP CFileManager::copy_file(BSTR file_path_src, BSTR file_path_dst)
{
  if (!file_path_src || !file_path_dst)
  {
    return MAKE_HRESULT(SEVERITY_ERROR, FACILITY_NULL, E_INVALIDARG);
  }

  fs::path src(file_path_src);
  fs::path dst(file_path_dst);
  if (!fs::exists(src) || fs::exists(dst))
  {
    return MAKE_HRESULT(SEVERITY_ERROR, FACILITY_NULL, E_PATH_NOT_FOUND);
  }

  boost::system::error_code ec;
  fs::copy_file(src, dst, ec);
  if (ec)
  {
    return MAKE_HRESULT(SEVERITY_ERROR, FACILITY_NULL, ec.value());
  }
  return S_OK;
}

STDMETHODIMP CFileManager::rename_file(BSTR file_path_src, BSTR file_path_dst)
{
  if (!file_path_src || !file_path_dst)
  {
    return MAKE_HRESULT(SEVERITY_ERROR, FACILITY_NULL, E_INVALIDARG);
  }

  fs::path src(file_path_src);
  fs::path dst(file_path_dst);
  if (!fs::exists(src) || fs::exists(dst))
  {
    return MAKE_HRESULT(SEVERITY_ERROR, FACILITY_NULL, E_INVALIDARG);
  }

  boost::system::error_code ec;
  fs::rename(src, dst, ec);
  if (ec)
  {
    return MAKE_HRESULT(SEVERITY_ERROR, FACILITY_NULL, ec.value());
  }
  return S_OK;
}

STDMETHODIMP CFileManager::delete_file(BSTR file_path)
{
  if (!file_path)
  {
    return MAKE_HRESULT(SEVERITY_ERROR, FACILITY_NULL, E_INVALIDARG);
  }

  fs::path src(file_path);
  if (!fs::exists(src))
  {
    return MAKE_HRESULT(SEVERITY_ERROR, FACILITY_NULL, E_PATH_NOT_FOUND);
  }

  boost::system::error_code ec;
  fs::remove_all(src, ec);
  if (ec)
  {
    return MAKE_HRESULT(SEVERITY_ERROR, FACILITY_NULL, ec.value());
  }
  return S_OK;
}

STDMETHODIMP CFileManager::get_entry(BSTR file_path, IFileEntry **file_entry_out)
{
  if (!file_path || !file_entry_out)
  {
    return MAKE_HRESULT(SEVERITY_ERROR, FACILITY_NULL, E_INVALIDARG);
  }
  *file_entry_out = NULL;

  fs::path src(file_path);
  if (!fs::exists(src))
  {
    return MAKE_HRESULT(SEVERITY_ERROR, FACILITY_NULL, E_PATH_NOT_FOUND);
  }

  boost::system::error_code ec;
  fs::file_status status = fs::status(src, ec);
  if (!ec)
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
    return S_OK;
  }

  return MAKE_HRESULT(SEVERITY_ERROR, FACILITY_NULL, ec.value());
}



