

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.00.0595 */
/* at Mon Nov 21 12:42:18 2016
 */
/* Compiler settings for enums.idl:
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


#ifndef __enums_h__
#define __enums_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_enums_0000_0000 */
/* [local] */ 


enum enum_file_type
    {
        FT_STATUS_ERROR	= 0,
        FT_FILE_NOT_FOUND	= ( FT_STATUS_ERROR + 1 ) ,
        FT_REGULAR_FILE	= ( FT_FILE_NOT_FOUND + 1 ) ,
        FT_DIRECTORY_FILE	= ( FT_REGULAR_FILE + 1 ) ,
        FT_SYMLINK_FILE	= ( FT_DIRECTORY_FILE + 1 ) ,
        FT_BLOCK_FILE	= ( FT_SYMLINK_FILE + 1 ) ,
        FT_CHARACTER_FILE	= ( FT_BLOCK_FILE + 1 ) ,
        FT_FIFO_FILE	= ( FT_CHARACTER_FILE + 1 ) ,
        FT_SOCKET_FILE	= ( FT_FIFO_FILE + 1 ) ,
        FT_REPARSE_FILE	= ( FT_SOCKET_FILE + 1 ) ,
        FT_TYPE_UNKNOWN	= ( FT_REPARSE_FILE + 1 ) ,
        FT__DETAIL_DIRECTORY_SYMLINK	= ( FT_TYPE_UNKNOWN + 1 ) ,
        FT_DRIVE_NO_ROOT_DIR	= ( FT__DETAIL_DIRECTORY_SYMLINK + 1 ) ,
        FT_DRIVE_REMOVABLE	= ( FT_DRIVE_NO_ROOT_DIR + 1 ) ,
        FT_DRIVE_FIXED	= ( FT_DRIVE_REMOVABLE + 1 ) ,
        FT_DRIVE_REMOTE	= ( FT_DRIVE_FIXED + 1 ) ,
        FT_DRIVE_CDROM	= ( FT_DRIVE_REMOTE + 1 ) ,
        FT_DRIVE_RAMDISK	= ( FT_DRIVE_CDROM + 1 ) ,
        FT_UNKNOWN	= ( FT_DRIVE_RAMDISK + 1 ) 
    } ;

enum enum_permissions
    {
        P_NONE	= 0,
        P_READ	= 0x1,
        P_WRITE	= 0x2,
        P_EXEC	= 0x4,
        P_ALL	= 0x7
    } ;

enum enum_error
    {
        E_SUCCESS	= 0,
        E_FILE_NOT_FOUND	= ( E_SUCCESS + 1 ) ,
        E_PATH_NOT_FOUND	= ( E_FILE_NOT_FOUND + 1 ) ,
        E_ACCESS_DENIED	= ( E_PATH_NOT_FOUND + 1 ) 
    } ;


extern RPC_IF_HANDLE __MIDL_itf_enums_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_enums_0000_0000_v0_0_s_ifspec;

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


