// FileManager.h : Declaration of the CFileManager

#pragma once
#include "resource.h"       // main symbols


#include "IFileManagerCOM.h"

#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif

using namespace ATL;


// CFileManager

class ATL_NO_VTABLE CFileManager :
  public CComObjectRootEx<CComSingleThreadModel>,
  public CComCoClass<CFileManager, &CLSID_FileManager>,
  public IDispatchImpl<IFileManager, &IID_IFileManager, &LIBID_IFileManagerCOMLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
  CFileManager()
  {
  }

  DECLARE_REGISTRY_RESOURCEID(IDR_FILEMANAGER)


  BEGIN_COM_MAP(CFileManager)
    COM_INTERFACE_ENTRY(IFileManager)
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
  STDMETHODIMP hello_world(BSTR *str_in);
  STDMETHODIMP file_list(BSTR file_path, int file_list_options, SAFEARRAY** file_entries);
  STDMETHODIMP create_file(BSTR path_src);
  STDMETHODIMP create_folder(BSTR folder_path);
  STDMETHODIMP copy_file(BSTR file_path_src, BSTR file_path_dst);
  STDMETHODIMP rename_file(BSTR file_path_src, BSTR file_path_dst);
  STDMETHODIMP delete_file(BSTR file_path);
  STDMETHODIMP get_entry(BSTR file_path, IFileEntry **file_entry);
};

OBJECT_ENTRY_AUTO(__uuidof(FileManager), CFileManager)
