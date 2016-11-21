

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.00.0595 */
/* at Mon Nov 21 12:42:19 2016
 */
/* Compiler settings for IFileEntry.idl:
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

#ifndef __IFileEntry_h__
#define __IFileEntry_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IFileEntry_FWD_DEFINED__
#define __IFileEntry_FWD_DEFINED__
typedef interface IFileEntry IFileEntry;

#endif 	/* __IFileEntry_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IFileEntry_INTERFACE_DEFINED__
#define __IFileEntry_INTERFACE_DEFINED__

/* interface IFileEntry */
/* [unique][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IFileEntry;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("C1827425-B401-46DF-AE93-B241AB68E355")
    IFileEntry : public IDispatch
    {
    public:
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE name( 
            /* [out] */ BSTR *file_name) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE extension( 
            /* [out] */ BSTR *ext_name) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE permissions( 
            /* [out] */ int *perms) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE type( 
            /* [out] */ int *file_type) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE size( 
            /* [out] */ __int64 *size_bytes) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE created( 
            /* [out] */ __int64 *date) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE modified( 
            /* [out] */ __int64 *date) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE exists( void) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IFileEntryVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IFileEntry * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IFileEntry * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IFileEntry * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IFileEntry * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IFileEntry * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IFileEntry * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IFileEntry * This,
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
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *name )( 
            IFileEntry * This,
            /* [out] */ BSTR *file_name);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *extension )( 
            IFileEntry * This,
            /* [out] */ BSTR *ext_name);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *permissions )( 
            IFileEntry * This,
            /* [out] */ int *perms);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *type )( 
            IFileEntry * This,
            /* [out] */ int *file_type);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *size )( 
            IFileEntry * This,
            /* [out] */ __int64 *size_bytes);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *created )( 
            IFileEntry * This,
            /* [out] */ __int64 *date);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *modified )( 
            IFileEntry * This,
            /* [out] */ __int64 *date);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *exists )( 
            IFileEntry * This);
        
        END_INTERFACE
    } IFileEntryVtbl;

    interface IFileEntry
    {
        CONST_VTBL struct IFileEntryVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFileEntry_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IFileEntry_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IFileEntry_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IFileEntry_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IFileEntry_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IFileEntry_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IFileEntry_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IFileEntry_name(This,file_name)	\
    ( (This)->lpVtbl -> name(This,file_name) ) 

#define IFileEntry_extension(This,ext_name)	\
    ( (This)->lpVtbl -> extension(This,ext_name) ) 

#define IFileEntry_permissions(This,perms)	\
    ( (This)->lpVtbl -> permissions(This,perms) ) 

#define IFileEntry_type(This,file_type)	\
    ( (This)->lpVtbl -> type(This,file_type) ) 

#define IFileEntry_size(This,size_bytes)	\
    ( (This)->lpVtbl -> size(This,size_bytes) ) 

#define IFileEntry_created(This,date)	\
    ( (This)->lpVtbl -> created(This,date) ) 

#define IFileEntry_modified(This,date)	\
    ( (This)->lpVtbl -> modified(This,date) ) 

#define IFileEntry_exists(This)	\
    ( (This)->lpVtbl -> exists(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IFileEntry_INTERFACE_DEFINED__ */


/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long *, BSTR * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


