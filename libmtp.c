libmtp.c(3)                                                                                       libmtp                                                                                       libmtp.c(3)

NAME
       libmtp.c

SYNOPSIS
       #include 'config.h'
       #include 'libmtp.h'
       #include 'unicode.h'
       #include 'ptp.h'
       #include 'libusb-glue.h'
       #include 'device-flags.h'
       #include 'playlist-spl.h'
       #include 'util.h'
       #include 'mtpz.h'
       #include <stdarg.h>
       #include <stdlib.h>
       #include <limits.h>
       #include <unistd.h>
       #include <string.h>
       #include <sys/types.h>
       #include <sys/stat.h>
       #include <fcntl.h>
       #include <time.h>
       #include <errno.h>

   Data Structures
       struct filemap_struct
       struct propertymap_struct
       struct event_cb_data_struct
       struct _MTPDataHandler

   Typedefs
       typedef struct filemap_struct filemap_t
       typedef struct propertymap_struct propertymap_t
       typedef struct event_cb_data_struct event_cb_data_t
       typedef struct _MTPDataHandler MTPDataHandler

   Functions
       void LIBMTP_Set_Debug (int level)
       void LIBMTP_Init (void)
       char const * LIBMTP_Get_Filetype_Description (LIBMTP_filetype_t intype)
       char const * LIBMTP_Get_Property_Description (LIBMTP_property_t inproperty)
       int LIBMTP_Get_Allowed_Property_Values (LIBMTP_mtpdevice_t *device, LIBMTP_property_t const property, LIBMTP_filetype_t const filetype, LIBMTP_allowed_values_t *allowed_vals)
       void LIBMTP_destroy_allowed_values_t (LIBMTP_allowed_values_t *allowed_vals)
       int LIBMTP_Is_Property_Supported (LIBMTP_mtpdevice_t *device, LIBMTP_property_t const property, LIBMTP_filetype_t const filetype)
       char * LIBMTP_Get_String_From_Object (LIBMTP_mtpdevice_t *device, uint32_t const object_id, LIBMTP_property_t const attribute_id)
       uint64_t LIBMTP_Get_u64_From_Object (LIBMTP_mtpdevice_t *device, uint32_t const object_id, LIBMTP_property_t const attribute_id, uint64_t const value_default)
       uint32_t LIBMTP_Get_u32_From_Object (LIBMTP_mtpdevice_t *device, uint32_t const object_id, LIBMTP_property_t const attribute_id, uint32_t const value_default)
       uint16_t LIBMTP_Get_u16_From_Object (LIBMTP_mtpdevice_t *device, uint32_t const object_id, LIBMTP_property_t const attribute_id, uint16_t const value_default)
       uint8_t LIBMTP_Get_u8_From_Object (LIBMTP_mtpdevice_t *device, uint32_t const object_id, LIBMTP_property_t const attribute_id, uint8_t const value_default)
       int LIBMTP_Set_Object_String (LIBMTP_mtpdevice_t *device, uint32_t const object_id, LIBMTP_property_t const attribute_id, char const *const string)
       int LIBMTP_Set_Object_u32 (LIBMTP_mtpdevice_t *device, uint32_t const object_id, LIBMTP_property_t const attribute_id, uint32_t const value)
       int LIBMTP_Set_Object_u16 (LIBMTP_mtpdevice_t *device, uint32_t const object_id, LIBMTP_property_t const attribute_id, uint16_t const value)
       int LIBMTP_Set_Object_u8 (LIBMTP_mtpdevice_t *device, uint32_t const object_id, LIBMTP_property_t const attribute_id, uint8_t const value)
       LIBMTP_mtpdevice_t * LIBMTP_Get_Device (int device_nr)
       LIBMTP_mtpdevice_t * LIBMTP_Get_First_Device (void)
       LIBMTP_mtpdevice_t * LIBMTP_Open_Raw_Device_Uncached (LIBMTP_raw_device_t *rawdevice)
       LIBMTP_mtpdevice_t * LIBMTP_Open_Raw_Device (LIBMTP_raw_device_t *rawdevice)
       int LIBMTP_Read_Event (LIBMTP_mtpdevice_t *device, LIBMTP_event_t *event, uint32_t *out1)
       int LIBMTP_Read_Event_Async (LIBMTP_mtpdevice_t *device, LIBMTP_event_cb_fn cb, void *user_data)
       uint32_t LIBMTP_Number_Devices_In_List (LIBMTP_mtpdevice_t *device_list)
       LIBMTP_error_number_t LIBMTP_Get_Connected_Devices (LIBMTP_mtpdevice_t **device_list)
       void LIBMTP_Release_Device_List (LIBMTP_mtpdevice_t *device)
       void LIBMTP_Release_Device (LIBMTP_mtpdevice_t *device)
       LIBMTP_error_t * LIBMTP_Get_Errorstack (LIBMTP_mtpdevice_t *device)
       void LIBMTP_Clear_Errorstack (LIBMTP_mtpdevice_t *device)
       void LIBMTP_Dump_Errorstack (LIBMTP_mtpdevice_t *device)
       void LIBMTP_Dump_Device_Info (LIBMTP_mtpdevice_t *device)
       int LIBMTP_Reset_Device (LIBMTP_mtpdevice_t *device)
       char * LIBMTP_Get_Manufacturername (LIBMTP_mtpdevice_t *device)
       char * LIBMTP_Get_Modelname (LIBMTP_mtpdevice_t *device)
       char * LIBMTP_Get_Serialnumber (LIBMTP_mtpdevice_t *device)
       char * LIBMTP_Get_Deviceversion (LIBMTP_mtpdevice_t *device)
       char * LIBMTP_Get_Friendlyname (LIBMTP_mtpdevice_t *device)
       int LIBMTP_Set_Friendlyname (LIBMTP_mtpdevice_t *device, char const *const friendlyname)
       char * LIBMTP_Get_Syncpartner (LIBMTP_mtpdevice_t *device)
       int LIBMTP_Set_Syncpartner (LIBMTP_mtpdevice_t *device, char const *const syncpartner)
       int LIBMTP_Get_Batterylevel (LIBMTP_mtpdevice_t *device, uint8_t *const maximum_level, uint8_t *const current_level)
       int LIBMTP_Format_Storage (LIBMTP_mtpdevice_t *device, LIBMTP_devicestorage_t *storage)
       int LIBMTP_Get_Secure_Time (LIBMTP_mtpdevice_t *device, char **const sectime)
       int LIBMTP_Get_Device_Certificate (LIBMTP_mtpdevice_t *device, char **const devcert)
       int LIBMTP_Get_Supported_Filetypes (LIBMTP_mtpdevice_t *device, uint16_t **const filetypes, uint16_t *const length)
       int LIBMTP_Check_Capability (LIBMTP_mtpdevice_t *device, LIBMTP_devicecap_t cap)
       int LIBMTP_Get_Storage (LIBMTP_mtpdevice_t *device, int const sortby)
       LIBMTP_file_t * LIBMTP_new_file_t (void)
       void LIBMTP_destroy_file_t (LIBMTP_file_t *file)
       LIBMTP_file_t * LIBMTP_Get_Filemetadata (LIBMTP_mtpdevice_t *device, uint32_t const fileid)
       LIBMTP_file_t * LIBMTP_Get_Filelisting (LIBMTP_mtpdevice_t *device)
       LIBMTP_file_t * LIBMTP_Get_Filelisting_With_Callback (LIBMTP_mtpdevice_t *device, LIBMTP_progressfunc_t const callback, void const *const data)
       LIBMTP_file_t * LIBMTP_Get_Files_And_Folders (LIBMTP_mtpdevice_t *device, uint32_t const storage, uint32_t const parent)
       LIBMTP_track_t * LIBMTP_new_track_t (void)
       void LIBMTP_destroy_track_t (LIBMTP_track_t *track)
       LIBMTP_track_t * LIBMTP_Get_Tracklisting (LIBMTP_mtpdevice_t *device)
       LIBMTP_track_t * LIBMTP_Get_Tracklisting_With_Callback (LIBMTP_mtpdevice_t *device, LIBMTP_progressfunc_t const callback, void const *const data)
       LIBMTP_track_t * LIBMTP_Get_Tracklisting_With_Callback_For_Storage (LIBMTP_mtpdevice_t *device, uint32_t const storage_id, LIBMTP_progressfunc_t const callback, void const *const data)
       LIBMTP_track_t * LIBMTP_Get_Trackmetadata (LIBMTP_mtpdevice_t *device, uint32_t const trackid)
       int LIBMTP_Get_File_To_File (LIBMTP_mtpdevice_t *device, uint32_t const id, char const *const path, LIBMTP_progressfunc_t const callback, void const *const data)
       int LIBMTP_Get_File_To_File_Descriptor (LIBMTP_mtpdevice_t *device, uint32_t const id, int const fd, LIBMTP_progressfunc_t const callback, void const *const data)
       int LIBMTP_Get_File_To_Handler (LIBMTP_mtpdevice_t *device, uint32_t const id, MTPDataPutFunc put_func, void *priv, LIBMTP_progressfunc_t const callback, void const *const data)
       int LIBMTP_Get_Track_To_File (LIBMTP_mtpdevice_t *device, uint32_t const id, char const *const path, LIBMTP_progressfunc_t const callback, void const *const data)
       int LIBMTP_Get_Track_To_File_Descriptor (LIBMTP_mtpdevice_t *device, uint32_t const id, int const fd, LIBMTP_progressfunc_t const callback, void const *const data)
       int LIBMTP_Get_Track_To_Handler (LIBMTP_mtpdevice_t *device, uint32_t const id, MTPDataPutFunc put_func, void *priv, LIBMTP_progressfunc_t const callback, void const *const data)
       int LIBMTP_Send_Track_From_File (LIBMTP_mtpdevice_t *device, char const *const path, LIBMTP_track_t *const metadata, LIBMTP_progressfunc_t const callback, void const *const data)
       int LIBMTP_Send_Track_From_File_Descriptor (LIBMTP_mtpdevice_t *device, int const fd, LIBMTP_track_t *const metadata, LIBMTP_progressfunc_t const callback, void const *const data)
       int LIBMTP_Send_Track_From_Handler (LIBMTP_mtpdevice_t *device, MTPDataGetFunc get_func, void *priv, LIBMTP_track_t *const metadata, LIBMTP_progressfunc_t const callback, void const *const data)
       int LIBMTP_Send_File_From_File (LIBMTP_mtpdevice_t *device, char const *const path, LIBMTP_file_t *const filedata, LIBMTP_progressfunc_t const callback, void const *const data)
       int LIBMTP_Send_File_From_File_Descriptor (LIBMTP_mtpdevice_t *device, int const fd, LIBMTP_file_t *const filedata, LIBMTP_progressfunc_t const callback, void const *const data)
       int LIBMTP_Send_File_From_Handler (LIBMTP_mtpdevice_t *device, MTPDataGetFunc get_func, void *priv, LIBMTP_file_t *const filedata, LIBMTP_progressfunc_t const callback, void const *const data)
       int LIBMTP_Update_Track_Metadata (LIBMTP_mtpdevice_t *device, LIBMTP_track_t const *const metadata)
       int LIBMTP_Delete_Object (LIBMTP_mtpdevice_t *device, uint32_t object_id)
       int LIBMTP_Move_Object (LIBMTP_mtpdevice_t *device, uint32_t object_id, uint32_t storage_id, uint32_t parent_id)
       int LIBMTP_Copy_Object (LIBMTP_mtpdevice_t *device, uint32_t object_id, uint32_t storage_id, uint32_t parent_id)
       int LIBMTP_Set_File_Name (LIBMTP_mtpdevice_t *device, LIBMTP_file_t *file, const char *newname)
       int LIBMTP_Set_Folder_Name (LIBMTP_mtpdevice_t *device, LIBMTP_folder_t *folder, const char *newname)
       int LIBMTP_Set_Track_Name (LIBMTP_mtpdevice_t *device, LIBMTP_track_t *track, const char *newname)
       int LIBMTP_Set_Playlist_Name (LIBMTP_mtpdevice_t *device, LIBMTP_playlist_t *playlist, const char *newname)
       int LIBMTP_Set_Album_Name (LIBMTP_mtpdevice_t *device, LIBMTP_album_t *album, const char *newname)
       int LIBMTP_Set_Object_Filename (LIBMTP_mtpdevice_t *device, uint32_t object_id, char *newname)
       int LIBMTP_Track_Exists (LIBMTP_mtpdevice_t *device, uint32_t const id)
       LIBMTP_folder_t * LIBMTP_new_folder_t (void)
       void LIBMTP_destroy_folder_t (LIBMTP_folder_t *folder)
       LIBMTP_folder_t * LIBMTP_Find_Folder (LIBMTP_folder_t *folderlist, uint32_t id)
       LIBMTP_folder_t * LIBMTP_Get_Folder_List_For_Storage (LIBMTP_mtpdevice_t *device, uint32_t const storage)
       LIBMTP_folder_t * LIBMTP_Get_Folder_List (LIBMTP_mtpdevice_t *device)
       uint32_t LIBMTP_Create_Folder (LIBMTP_mtpdevice_t *device, char *name, uint32_t parent_id, uint32_t storage_id)
       LIBMTP_playlist_t * LIBMTP_new_playlist_t (void)
       void LIBMTP_destroy_playlist_t (LIBMTP_playlist_t *playlist)
       LIBMTP_playlist_t * LIBMTP_Get_Playlist_List (LIBMTP_mtpdevice_t *device)
       LIBMTP_playlist_t * LIBMTP_Get_Playlist (LIBMTP_mtpdevice_t *device, uint32_t const plid)
       int LIBMTP_Create_New_Playlist (LIBMTP_mtpdevice_t *device, LIBMTP_playlist_t *const metadata)
       int LIBMTP_Update_Playlist (LIBMTP_mtpdevice_t *device, LIBMTP_playlist_t *const metadata)
       LIBMTP_album_t * LIBMTP_new_album_t (void)
       void LIBMTP_destroy_album_t (LIBMTP_album_t *album)
       LIBMTP_album_t * LIBMTP_Get_Album_List (LIBMTP_mtpdevice_t *device)
       LIBMTP_album_t * LIBMTP_Get_Album_List_For_Storage (LIBMTP_mtpdevice_t *device, uint32_t const storage_id)
       LIBMTP_album_t * LIBMTP_Get_Album (LIBMTP_mtpdevice_t *device, uint32_t const albid)
       int LIBMTP_Create_New_Album (LIBMTP_mtpdevice_t *device, LIBMTP_album_t *const metadata)
       LIBMTP_filesampledata_t * LIBMTP_new_filesampledata_t (void)
       void LIBMTP_destroy_filesampledata_t (LIBMTP_filesampledata_t *sample)
       int LIBMTP_Get_Representative_Sample_Format (LIBMTP_mtpdevice_t *device, LIBMTP_filetype_t const filetype, LIBMTP_filesampledata_t **sample)
       int LIBMTP_Send_Representative_Sample (LIBMTP_mtpdevice_t *device, uint32_t const id, LIBMTP_filesampledata_t *sampledata)
       int LIBMTP_Get_Representative_Sample (LIBMTP_mtpdevice_t *device, uint32_t const id, LIBMTP_filesampledata_t *sampledata)
       int LIBMTP_Get_Thumbnail (LIBMTP_mtpdevice_t *device, uint32_t const id, unsigned char **data, unsigned int *size)
       int LIBMTP_GetPartialObject (LIBMTP_mtpdevice_t *device, uint32_t const id, uint64_t offset, uint32_t maxbytes, unsigned char **data, unsigned int *size)
       int LIBMTP_SendPartialObject (LIBMTP_mtpdevice_t *device, uint32_t const id, uint64_t offset, unsigned char *data, unsigned int size)
       int LIBMTP_BeginEditObject (LIBMTP_mtpdevice_t *device, uint32_t const id)
       int LIBMTP_EndEditObject (LIBMTP_mtpdevice_t *device, uint32_t const id)
       int LIBMTP_TruncateObject (LIBMTP_mtpdevice_t *device, uint32_t const id, uint64_t offset)
       int LIBMTP_Update_Album (LIBMTP_mtpdevice_t *device, LIBMTP_album_t const *const metadata)
       void ptp_nikon_getptpipguid (unsigned char *guid)
       int LIBMTP_Custom_Operation (LIBMTP_mtpdevice_t *device, uint16_t code, int n_param,...)

   Variables
       int use_mtpz
       int LIBMTP_debug = LIBMTP_DEBUG_NONE

Detailed Description
       Copyright (C) 2005-2011 Linus Walleij triad@df.lth.se Copyright (C) 2005-2008 Richard A. Low richard@wentnet.com Copyright (C) 2007 Ted Bullock tbullock@canada.com Copyright (C) 2007 Tero Saarni
       tero.saarni@gmail.com Copyright (C) 2008 Florent Mertens flomertens@gmail.com

       This library is free software; you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation; either version 2 of
       the License, or (at your option) any later version.

       This library is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
       Lesser General Public License for more details.

       You should have received a copy of the GNU Lesser General Public License along with this library; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA
       02111-1307, USA.

       This file provides an interface 'glue' to the underlying PTP implementation from libgphoto2. It uses some local code to convert from/to UTF-8 (stored in unicode.c/.h) and some small utility
       functions, mainly for debugging (stored in util.c/.h).

       The three PTP files (ptp.c, ptp.h and ptp-pack.c) are plain copied from the libhphoto2 codebase.

       The files libusb-glue.c/.h are just what they say: an interface to libusb for the actual, physical USB traffic.

Typedef Documentation
   typedef struct _MTPDataHandler MTPDataHandler
       These are to wrap the get/put handlers to convert from the MTP types to PTP types in a reliable way

Function Documentation
   void ptp_nikon_getptpipguid (unsigned char * guid)
       Dummy function needed to interface to upstream ptp.c/ptp.h files.

Variable Documentation
   int LIBMTP_debug = LIBMTP_DEBUG_NONE
       Global debug level We use a flag system to enable a part of logs.

       The LIBMTP_DEBUG environment variable sets the debug flags for any binary that uses libmtp and calls LIBMTP_Init. The value can be given in decimal (must not start with '0' or it will be
       interpreted in octal), or in hexadecimal (must start with '0x').

       The value '-1' enables all debug flags.

       Some of the utilities in examples/ also take a command-line flag '-d' that enables LIBMTP_DEBUG_PTP and LIBMTP_DEBUG_DATA (same as setting LIBMTP_DEBUG=9).

       Flags (combine by adding the hex values): 0x00 [0000 0000] : LIBMTP_DEBUG_NONE : no debug (default) 0x01 [0000 0001] : LIBMTP_DEBUG_PTP : PTP debug 0x02 [0000 0010] : LIBMTP_DEBUG_PLST : Playlist
       debug 0x04 [0000 0100] : LIBMTP_DEBUG_USB : USB debug 0x08 [0000 1000] : LIBMTP_DEBUG_DATA : USB data debug

       (Please keep this list in sync with libmtp.h.)

       Referenced by LIBMTP_Set_Debug().

Author
       Generated automatically by Doxygen for libmtp from the source code.

Version 1.1.20                                                                                Mon Jul 4 2022                                                                                   libmtp.c(3)
