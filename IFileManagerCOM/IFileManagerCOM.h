

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.00.0595 */
/* at Mon Nov 21 12:42:15 2016
 */
/* Compiler settings for IFileManagerCOM.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 8.00.0595 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __IFileManagerCOM_h__
#define __IFileManagerCOM_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IComponentRegistrar_FWD_DEFINED__
#define __IComponentRegistrar_FWD_DEFINED__
typedef interface IComponentRegistrar IComponentRegistrar;

#endif 	/* __IComponentRegistrar_FWD_DEFINED__ */


#ifndef __IFileManager_FWD_DEFINED__
#define __IFileManager_FWD_DEFINED__
typedef interface IFileManager IFileManager;

#endif 	/* __IFileManager_FWD_DEFINED__ */


#ifndef __CompReg_FWD_DEFINED__
#define __CompReg_FWD_DEFINED__

#ifdef __cplusplus
typedef class CompReg CompReg;
#else
typedef struct CompReg CompReg;
#endif /* __cplusplus */

#endif 	/* __CompReg_FWD_DEFINED__ */


#ifndef __FileManager_FWD_DEFINED__
#define __FileManager_FWD_DEFINED__

#ifdef __cplusplus
typedef class FileManager FileManager;
#else
typedef struct FileManager FileManager;
#endif /* __cplusplus */

#endif 	/* __FileManager_FWD_DEFINED__ */


#ifndef __FileEntry_FWD_DEFINED__
#define __FileEntry_FWD_DEFINED__

#ifdef __cplusplus
typedef class FileEntry FileEntry;
#else
typedef struct FileEntry FileEntry;
#endif /* __cplusplus */

#endif 	/* __FileEntry_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "enums.h"
#include "IFileEntry.h"
#include "shobjidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IComponentRegistrar_INTERFACE_DEFINED__
#define __IComponentRegistrar_INTERFACE_DEFINED__

/* interface IComponentRegistrar */
/* [unique][dual][uuid][object] */ 


EXTERN_C const IID IID_IComponentRegistrar;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("a817e7a2-43fa-11d0-9e44-00aa00b6770a")
    IComponentRegistrar : public IDispatch
    {
    public:
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Attach( 
            /* [in] */ BSTR bstrPath) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE RegisterAll( void) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE UnregisterAll( void) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetComponents( 
            /* [out] */ SAFEARRAY * *pbstrCLSIDs,
            /* [out] */ SAFEARRAY * *pbstrDescriptions) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE RegisterComponent( 
            /* [in] */ BSTR bstrCLSID) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE UnregisterComponent( 
            /* [in] */ BSTR bstrCLSID) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IComponentRegistrarVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IComponentRegistrar * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IComponentRegistrar * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IComponentRegistrar * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IComponentRegistrar * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IComponentRegistrar * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IComponentRegistrar * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IComponentRegistrar * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *Attach )( 
            IComponentRegistrar * This,
            /* [in] */ BSTR bstrPath);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *RegisterAll )( 
            IComponentRegistrar * This);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *UnregisterAll )( 
            IComponentRegistrar * This);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetComponents )( 
            IComponentRegistrar * This,
            /* [out] */ SAFEARRAY * *pbstrCLSIDs,
            /* [out] */ SAFEARRAY * *pbstrDescriptions);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *RegisterComponent )( 
            IComponentRegistrar * This,
            /* [in] */ BSTR bstrCLSID);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *UnregisterComponent )( 
            IComponentRegistrar * This,
            /* [in] */ BSTR bstrCLSID);
        
        END_INTERFACE
    } IComponentRegistrarVtbl;

    interface IComponentRegistrar
    {
        CONST_VTBL struct IComponentRegistrarVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IComponentRegistrar_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IComponentRegistrar_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IComponentRegistrar_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IComponentRegistrar_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IComponentRegistrar_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IComponentRegistrar_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IComponentRegistrar_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IComponentRegistrar_Attach(This,bstrPath)	\
    ( (This)->lpVtbl -> Attach(This,bstrPath) ) 

#define IComponentRegistrar_RegisterAll(This)	\
    ( (This)->lpVtbl -> RegisterAll(This) ) 

#define IComponentRegistrar_UnregisterAll(This)	\
    ( (This)->lpVtbl -> UnregisterAll(This) ) 

#define IComponentRegistrar_GetComponents(This,pbstrCLSIDs,pbstrDescriptions)	\
    ( (This)->lpVtbl -> GetComponents(This,pbstrCLSIDs,pbstrDescriptions) ) 

#define IComponentRegistrar_RegisterComponent(This,bstrCLSID)	\
    ( (This)->lpVtbl -> RegisterComponent(This,bstrCLSID) ) 

#define IComponentRegistrar_UnregisterComponent(This,bstrCLSID)	\
    ( (This)->lpVtbl -> UnregisterComponent(This,bstrCLSID) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IComponentRegistrar_INTERFACE_DEFINED__ */


#ifndef __IFileManager_INTERFACE_DEFINED__
#define __IFileManager_INTERFACE_DEFINED__

/* interface IFileManager */
/* [unique][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IFileManager;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("ACC8DE46-4E6A-4B1A-B234-3C47579CDB37")
    IFileManager : public IDispatch
    {
    public:
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE hello_world( 
            /* [out] */ BSTR *str) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE file_list( 
            /* [in] */ BSTR file_path,
            /* [in] */ int file_list_options,
            /* [out] */ SAFEARRAY * *file_entry_list) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE create_file( 
            /* [in] */ BSTR path_src) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE create_folder( 
            /* [in] */ BSTR folder_path) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE copy_file( 
            /* [in] */ BSTR file_path_src,
            /* [in] */ BSTR file_path_dst) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE rename_file( 
            /* [in] */ BSTR file_path_src,
            /* [in] */ BSTR file_path_dst) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE delete_file( 
            /* [in] */ BSTR file_path) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE get_entry( 
            /* [in] */ BSTR file_path,
            /* [out] */ IFileEntry **file_entry) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IFileManagerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IFileManager * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IFileManager * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IFileManager * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IFileManager * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IFileManager * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IFileManager * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IFileManager * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *hello_world )( 
            IFileManager * This,
            /* [out] */ BSTR *str);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *file_list )( 
            IFileManager * This,
            /* [in] */ BSTR file_path,
            /* [in] */ int file_list_options,
            /* [out] */ SAFEARRAY * *file_entry_list);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *create_file )( 
            IFileManager * This,
            /* [in] */ BSTR path_src);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *create_folder )( 
            IFileManager * This,
            /* [in] */ BSTR folder_path);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *copy_file )( 
            IFileManager * This,
            /* [in] */ BSTR file_path_src,
            /* [in] */ BSTR file_path_dst);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *rename_file )( 
            IFileManager * This,
            /* [in] */ BSTR file_path_src,
            /* [in] */ BSTR file_path_dst);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *delete_file )( 
            IFileManager * This,
            /* [in] */ BSTR file_path);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *get_entry )( 
            IFileManager * This,
            /* [in] */ BSTR file_path,
            /* [out] */ IFileEntry **file_entry);
        
        END_INTERFACE
    } IFileManagerVtbl;

    interface IFileManager
    {
        CONST_VTBL struct IFileManagerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFileManager_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IFileManager_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IFileManager_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IFileManager_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IFileManager_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IFileManager_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IFileManager_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IFileManager_hello_world(This,str)	\
    ( (This)->lpVtbl -> hello_world(This,str) ) 

#define IFileManager_file_list(This,file_path,file_list_options,file_entry_list)	\
    ( (This)->lpVtbl -> file_list(This,file_path,file_list_options,file_entry_list) ) 

#define IFileManager_create_file(This,path_src)	\
    ( (This)->lpVtbl -> create_file(This,path_src) ) 

#define IFileManager_create_folder(This,folder_path)	\
    ( (This)->lpVtbl -> create_folder(This,folder_path) ) 

#define IFileManager_copy_file(This,file_path_src,file_path_dst)	\
    ( (This)->lpVtbl -> copy_file(This,file_path_src,file_path_dst) ) 

#define IFileManager_rename_file(This,file_path_src,file_path_dst)	\
    ( (This)->lpVtbl -> rename_file(This,file_path_src,file_path_dst) ) 

#define IFileManager_delete_file(This,file_path)	\
    ( (This)->lpVtbl -> delete_file(This,file_path) ) 

#define IFileManager_get_entry(This,file_path,file_entry)	\
    ( (This)->lpVtbl -> get_entry(This,file_path,file_entry) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IFileManager_INTERFACE_DEFINED__ */



#ifndef __IFileManagerCOMLib_LIBRARY_DEFINED__
#define __IFileManagerCOMLib_LIBRARY_DEFINED__

/* library IFileManagerCOMLib */
/* [custom][version][uuid] */ 


EXTERN_C const IID LIBID_IFileManagerCOMLib;

EXTERN_C const CLSID CLSID_CompReg;

#ifdef __cplusplus

class DECLSPEC_UUID("9EB77A10-A350-45C0-B7B0-AFD6937C4174")
CompReg;
#endif

EXTERN_C const CLSID CLSID_FileManager;

#ifdef __cplusplus

class DECLSPEC_UUID("EEC62346-FC1D-4D07-AA39-DB82955CA940")
FileManager;
#endif

EXTERN_C const CLSID CLSID_FileEntry;

#ifdef __cplusplus

class DECLSPEC_UUID("BFF890DD-E557-412F-8085-F52789648732")
FileEntry;
#endif
#endif /* __IFileManagerCOMLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long *, BSTR * ); 

unsigned long             __RPC_USER  LPSAFEARRAY_UserSize(     unsigned long *, unsigned long            , LPSAFEARRAY * ); 
unsigned char * __RPC_USER  LPSAFEARRAY_UserMarshal(  unsigned long *, unsigned char *, LPSAFEARRAY * ); 
unsigned char * __RPC_USER  LPSAFEARRAY_UserUnmarshal(unsigned long *, unsigned char *, LPSAFEARRAY * ); 
void                      __RPC_USER  LPSAFEARRAY_UserFree(     unsigned long *, LPSAFEARRAY * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


