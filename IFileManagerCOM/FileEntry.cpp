// FileEntry.cpp : Implementation of CFileEntry

#include "stdafx.h"
#include "FileEntry.h"
#include <iostream>


// CFileEntry
CFileEntry::CFileEntry()
  : file_path_()
  , file_type_(FT_UNKNOWN)
  , permissions_(no_perms)
{

}

CFileEntry::CFileEntry(const std::wstring& file_path, int file_type, int permissions, std::size_t size_bytes, std::time_t created_date, std::time_t modified_date)
  : file_path_(file_path)
  , file_type_(file_type)
  , permissions_(static_cast<enum_permissions>(permissions))
  , size_bytes_(size_bytes)
  , created_date_(created_date)
  , modified_date_(modified_date)
{
}

STDMETHODIMP CFileEntry::init(const std::wstring& file_path, int file_type, int permissions, std::size_t size_bytes, std::time_t created_date, std::time_t modified_date)
{
  file_path_ = file_path;
  file_type_ = file_type;
  permissions_ = static_cast<enum_permissions>(permissions);
  size_bytes_ = size_bytes;
  created_date_ = created_date;
  modified_date_ = modified_date;

  return S_OK;
}

STDMETHODIMP CFileEntry::name(BSTR *file_name)
{
  auto pos = file_path_.find_last_of(L'\\');
  if (pos != std::wstring::npos)
  {
    *file_name = (BSTR)file_path_.c_str() + pos + 1;
    return S_OK;
  }
  *file_name = (BSTR)file_path_.c_str();
  return S_OK;
}

STDMETHODIMP CFileEntry::extension(BSTR *ext_name)
{
  if (!ext_name)
  {
    return MAKE_HRESULT(SEVERITY_ERROR, FACILITY_NULL, E_INVALIDARG);
  }
  const WCHAR *p = wcsrchr(file_path_.c_str(), L'.');
  if (p)
  {
    *ext_name = const_cast<BSTR>(p);
    return S_OK;
  }

  return MAKE_HRESULT(SEVERITY_ERROR, FACILITY_NULL, S_FALSE);
}

STDMETHODIMP CFileEntry::permissions(int *perms)
{
  if (!perms)
  {
    return MAKE_HRESULT(SEVERITY_ERROR, FACILITY_NULL, E_INVALIDARG);
  }

  *perms = permissions_;
  return S_OK;
}

STDMETHODIMP CFileEntry::type(int *file_type)
{
  if (!file_type)
  {
    return MAKE_HRESULT(SEVERITY_ERROR, FACILITY_NULL, E_INVALIDARG);
  }

  *file_type = file_type_;
  return S_OK;
}

STDMETHODIMP CFileEntry::size(__int64 *size_bytes)
{
  if (!size_bytes)
  {
    return MAKE_HRESULT(SEVERITY_ERROR, FACILITY_NULL, E_INVALIDARG);
  }

  *size_bytes = size_bytes_;
  return S_OK;
}

STDMETHODIMP CFileEntry::created(__int64* date)
{
  if (!date)
  {
    return MAKE_HRESULT(SEVERITY_ERROR, FACILITY_NULL, E_INVALIDARG);
  }

  *date = created_date_;
  return S_OK;
}

STDMETHODIMP CFileEntry::modified(__int64* date)
{
  if (!date)
  {
    return MAKE_HRESULT(SEVERITY_ERROR, FACILITY_NULL, E_INVALIDARG);
  }

  *date = modified_date_;
  return S_OK;
}

STDMETHODIMP CFileEntry::exists()
{
  return S_OK;
}
