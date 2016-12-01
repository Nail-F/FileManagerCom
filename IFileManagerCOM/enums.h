

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.00.0595 */
/* at Thu Dec 01 10:21:45 2016
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
        no_perms	= 0,
        owner_read	= 0400,
        owner_write	= 0200,
        owner_exe	= 0100,
        owner_all	= 0700,
        group_read	= 040,
        group_write	= 020,
        group_exe	= 010,
        group_all	= 070,
        others_read	= 04,
        others_write	= 02,
        others_exe	= 01,
        others_all	= 07,
        all_all	= 0777,
        set_uid_on_exe	= 04000,
        set_gid_on_exe	= 02000,
        sticky_bit	= 01000,
        perms_mask	= 07777,
        perms_not_known	= 0xffff,
        add_perms	= 0x1000,
        remove_perms	= 0x2000,
        symlink_perms	= 0x4000
    } ;


extern RPC_IF_HANDLE __MIDL_itf_enums_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_enums_0000_0000_v0_0_s_ifspec;

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


