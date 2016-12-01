// FileEntry.h : Declaration of the CFileEntry

#pragma once
#include "resource.h"       // main symbols



#include "IFileManagerCOM.h"
#include <string>
#include "IFileEntry.h"
#include <stdint.h>
#include <ctime>



#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif

using namespace ATL;


// CFileEntry

class ATL_NO_VTABLE CFileEntry :
  public CComObjectRootEx<CComSingleThreadModel>,
  public CComCoClass<CFileEntry, &CLSID_FileEntry>,
  public IDispatchImpl<IFileEntry, &IID_IFileEntry, &LIBID_IFileManagerCOMLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
  CFileEntry();
  CFileEntry(const std::wstring& file_path, int file_type = FT_UNKNOWN, int permissions = no_perms, std::size_t size_bytes = 0, std::time_t created_date = 0, std::time_t modified_date = 0);


  DECLARE_REGISTRY_RESOURCEID(IDR_FILEENTRY)

  BEGIN_COM_MAP(CFileEntry)
    COM_INTERFACE_ENTRY(IFileEntry)
    COM_INTERFACE_ENTRY(IDispatch)
  END_COM_MAP()



  DECLARE_PROTECT_FINAL_CONSTRUCT()

  HRESULT FinalConstruct()
  {
    return S_OK;
  }

  void FinalRelease()
  {
  }

public:
  STDMETHOD(init)(const std::wstring& file_path, 
                  int file_type = FT_UNKNOWN, 
                  int permissions = no_perms, 
                  std::size_t size_bytes = 0, 
                  std::time_t created_date = 0, 
                  std::time_t modified_date = 0);

  STDMETHOD(name)(BSTR *file_name);
  STDMETHOD(extension)(BSTR *ext_name);
  STDMETHOD(permissions)(int *perms);
  STDMETHOD(type)(int *file_type);
  STDMETHOD(size)(__int64 *size_bytes);
  STDMETHOD(created)(__int64* date);
  STDMETHOD(modified)(__int64* date);
  STDMETHOD(exists)();



private:
  std::wstring     file_path_;
  int              file_type_;
  enum_permissions permissions_;
  std::size_t      size_bytes_;
  std::time_t      created_date_;
  std::time_t      modified_date_;
};

OBJECT_ENTRY_AUTO(__uuidof(FileEntry), CFileEntry)
