libmtp.h(3)                                                                                       libmtp                                                                                       libmtp.h(3)

NAME
       libmtp.h

SYNOPSIS
       #include <sys/time.h>
       #include <stdio.h>
       #include <stdint.h>
       #include <time.h>

   Data Structures
       struct LIBMTP_device_entry_struct
       struct LIBMTP_raw_device_struct
       struct LIBMTP_error_struct
       struct LIBMTP_allowed_values_struct
       struct LIBMTP_device_extension_struct
       struct LIBMTP_mtpdevice_struct
       struct LIBMTP_file_struct
       struct LIBMTP_track_struct
       struct LIBMTP_playlist_struct
       struct LIBMTP_album_struct
       struct LIBMTP_folder_struct
       struct LIBMTP_filesampledata_struct
       struct LIBMTP_devicestorage_struct

   Macros
       #define LIBMTP_VERSION   1.1.20
       #define LIBMTP_VERSION_STRING   '1.1.20'
       #define LIBMTP_DEBUG_NONE   0x00
       #define LIBMTP_DEBUG_PTP   0x01
       #define LIBMTP_DEBUG_PLST   0x02
       #define LIBMTP_DEBUG_USB   0x04
       #define LIBMTP_DEBUG_DATA   0x08
       #define LIBMTP_DEBUG_ALL   0xFF
       #define LIBMTP_FILETYPE_IS_AUDIO(a)
       #define LIBMTP_FILETYPE_IS_VIDEO(a)
       #define LIBMTP_FILETYPE_IS_AUDIOVIDEO(a)
       #define LIBMTP_FILETYPE_IS_TRACK(a)
       #define LIBMTP_FILETYPE_IS_IMAGE(a)
       #define LIBMTP_FILETYPE_IS_ADDRESSBOOK(a)
       #define LIBMTP_FILETYPE_IS_CALENDAR(a)
       #define LIBMTP_HANDLER_RETURN_OK   0
       #define LIBMTP_HANDLER_RETURN_ERROR   1
       #define LIBMTP_HANDLER_RETURN_CANCEL   2
       #define LIBMTP_STORAGE_SORTBY_NOTSORTED   0
       #define LIBMTP_STORAGE_SORTBY_FREESPACE   1
       #define LIBMTP_STORAGE_SORTBY_MAXSPACE   2
       #define LIBMTP_FILES_AND_FOLDERS_ROOT   0xffffffff

   Typedefs
       typedef struct LIBMTP_device_entry_struct LIBMTP_device_entry_t
       typedef struct LIBMTP_raw_device_struct LIBMTP_raw_device_t
       typedef struct LIBMTP_error_struct LIBMTP_error_t
       typedef struct LIBMTP_allowed_values_struct LIBMTP_allowed_values_t
       typedef struct LIBMTP_device_extension_struct LIBMTP_device_extension_t
       typedef struct LIBMTP_mtpdevice_struct LIBMTP_mtpdevice_t
       typedef struct LIBMTP_file_struct LIBMTP_file_t
       typedef struct LIBMTP_track_struct LIBMTP_track_t
       typedef struct LIBMTP_playlist_struct LIBMTP_playlist_t
       typedef struct LIBMTP_album_struct LIBMTP_album_t
       typedef struct LIBMTP_folder_struct LIBMTP_folder_t
       typedef struct LIBMTP_filesampledata_struct LIBMTP_filesampledata_t
       typedef struct LIBMTP_devicestorage_struct LIBMTP_devicestorage_t
       typedef int(* LIBMTP_progressfunc_t) (uint64_t const sent, uint64_t const total, void const *const data)
       typedef uint16_t(* MTPDataGetFunc) (void *params, void *priv, uint32_t wantlen, unsigned char *data, uint32_t *gotlen)
       typedef uint16_t(* MTPDataPutFunc) (void *params, void *priv, uint32_t sendlen, unsigned char *data, uint32_t *putlen)
       typedef enum LIBMTP_event_enum LIBMTP_event_t
       typedef void(* LIBMTP_event_cb_fn) (int, LIBMTP_event_t, uint32_t, void *)

   Enumerations
       enum LIBMTP_filetype_t { LIBMTP_FILETYPE_FOLDER, LIBMTP_FILETYPE_WAV, LIBMTP_FILETYPE_MP3, LIBMTP_FILETYPE_WMA, LIBMTP_FILETYPE_OGG, LIBMTP_FILETYPE_AUDIBLE, LIBMTP_FILETYPE_MP4,
           LIBMTP_FILETYPE_UNDEF_AUDIO, LIBMTP_FILETYPE_WMV, LIBMTP_FILETYPE_AVI, LIBMTP_FILETYPE_MPEG, LIBMTP_FILETYPE_ASF, LIBMTP_FILETYPE_QT, LIBMTP_FILETYPE_UNDEF_VIDEO, LIBMTP_FILETYPE_JPEG,
           LIBMTP_FILETYPE_JFIF, LIBMTP_FILETYPE_TIFF, LIBMTP_FILETYPE_BMP, LIBMTP_FILETYPE_GIF, LIBMTP_FILETYPE_PICT, LIBMTP_FILETYPE_PNG, LIBMTP_FILETYPE_VCALENDAR1, LIBMTP_FILETYPE_VCALENDAR2,
           LIBMTP_FILETYPE_VCARD2, LIBMTP_FILETYPE_VCARD3, LIBMTP_FILETYPE_WINDOWSIMAGEFORMAT, LIBMTP_FILETYPE_WINEXEC, LIBMTP_FILETYPE_TEXT, LIBMTP_FILETYPE_HTML, LIBMTP_FILETYPE_FIRMWARE,
           LIBMTP_FILETYPE_AAC, LIBMTP_FILETYPE_MEDIACARD, LIBMTP_FILETYPE_FLAC, LIBMTP_FILETYPE_MP2, LIBMTP_FILETYPE_M4A, LIBMTP_FILETYPE_DOC, LIBMTP_FILETYPE_XML, LIBMTP_FILETYPE_XLS,
           LIBMTP_FILETYPE_PPT, LIBMTP_FILETYPE_MHT, LIBMTP_FILETYPE_JP2, LIBMTP_FILETYPE_JPX, LIBMTP_FILETYPE_ALBUM, LIBMTP_FILETYPE_PLAYLIST, LIBMTP_FILETYPE_UNKNOWN }
       enum LIBMTP_property_t { LIBMTP_PROPERTY_StorageID, LIBMTP_PROPERTY_ObjectFormat, LIBMTP_PROPERTY_ProtectionStatus, LIBMTP_PROPERTY_ObjectSize, LIBMTP_PROPERTY_AssociationType,
           LIBMTP_PROPERTY_AssociationDesc, LIBMTP_PROPERTY_ObjectFileName, LIBMTP_PROPERTY_DateCreated, LIBMTP_PROPERTY_DateModified, LIBMTP_PROPERTY_Keywords, LIBMTP_PROPERTY_ParentObject,
           LIBMTP_PROPERTY_AllowedFolderContents, LIBMTP_PROPERTY_Hidden, LIBMTP_PROPERTY_SystemObject, LIBMTP_PROPERTY_PersistantUniqueObjectIdentifier, LIBMTP_PROPERTY_SyncID,
           LIBMTP_PROPERTY_PropertyBag, LIBMTP_PROPERTY_Name, LIBMTP_PROPERTY_CreatedBy, LIBMTP_PROPERTY_Artist, LIBMTP_PROPERTY_DateAuthored, LIBMTP_PROPERTY_Description, LIBMTP_PROPERTY_URLReference,
           LIBMTP_PROPERTY_LanguageLocale, LIBMTP_PROPERTY_CopyrightInformation, LIBMTP_PROPERTY_Source, LIBMTP_PROPERTY_OriginLocation, LIBMTP_PROPERTY_DateAdded, LIBMTP_PROPERTY_NonConsumable,
           LIBMTP_PROPERTY_CorruptOrUnplayable, LIBMTP_PROPERTY_ProducerSerialNumber, LIBMTP_PROPERTY_RepresentativeSampleFormat, LIBMTP_PROPERTY_RepresentativeSampleSize,
           LIBMTP_PROPERTY_RepresentativeSampleHeight, LIBMTP_PROPERTY_RepresentativeSampleWidth, LIBMTP_PROPERTY_RepresentativeSampleDuration, LIBMTP_PROPERTY_RepresentativeSampleData,
           LIBMTP_PROPERTY_Width, LIBMTP_PROPERTY_Height, LIBMTP_PROPERTY_Duration, LIBMTP_PROPERTY_Rating, LIBMTP_PROPERTY_Track, LIBMTP_PROPERTY_Genre, LIBMTP_PROPERTY_Credits, LIBMTP_PROPERTY_Lyrics,
           LIBMTP_PROPERTY_SubscriptionContentID, LIBMTP_PROPERTY_ProducedBy, LIBMTP_PROPERTY_UseCount, LIBMTP_PROPERTY_SkipCount, LIBMTP_PROPERTY_LastAccessed, LIBMTP_PROPERTY_ParentalRating,
           LIBMTP_PROPERTY_MetaGenre, LIBMTP_PROPERTY_Composer, LIBMTP_PROPERTY_EffectiveRating, LIBMTP_PROPERTY_Subtitle, LIBMTP_PROPERTY_OriginalReleaseDate, LIBMTP_PROPERTY_AlbumName,
           LIBMTP_PROPERTY_AlbumArtist, LIBMTP_PROPERTY_Mood, LIBMTP_PROPERTY_DRMStatus, LIBMTP_PROPERTY_SubDescription, LIBMTP_PROPERTY_IsCropped, LIBMTP_PROPERTY_IsColorCorrected,
           LIBMTP_PROPERTY_ImageBitDepth, LIBMTP_PROPERTY_Fnumber, LIBMTP_PROPERTY_ExposureTime, LIBMTP_PROPERTY_ExposureIndex, LIBMTP_PROPERTY_DisplayName, LIBMTP_PROPERTY_BodyText,
           LIBMTP_PROPERTY_Subject, LIBMTP_PROPERTY_Priority, LIBMTP_PROPERTY_GivenName, LIBMTP_PROPERTY_MiddleNames, LIBMTP_PROPERTY_FamilyName, LIBMTP_PROPERTY_Prefix, LIBMTP_PROPERTY_Suffix,
           LIBMTP_PROPERTY_PhoneticGivenName, LIBMTP_PROPERTY_PhoneticFamilyName, LIBMTP_PROPERTY_EmailPrimary, LIBMTP_PROPERTY_EmailPersonal1, LIBMTP_PROPERTY_EmailPersonal2,
           LIBMTP_PROPERTY_EmailBusiness1, LIBMTP_PROPERTY_EmailBusiness2, LIBMTP_PROPERTY_EmailOthers, LIBMTP_PROPERTY_PhoneNumberPrimary, LIBMTP_PROPERTY_PhoneNumberPersonal,
           LIBMTP_PROPERTY_PhoneNumberPersonal2, LIBMTP_PROPERTY_PhoneNumberBusiness, LIBMTP_PROPERTY_PhoneNumberBusiness2, LIBMTP_PROPERTY_PhoneNumberMobile, LIBMTP_PROPERTY_PhoneNumberMobile2,
           LIBMTP_PROPERTY_FaxNumberPrimary, LIBMTP_PROPERTY_FaxNumberPersonal, LIBMTP_PROPERTY_FaxNumberBusiness, LIBMTP_PROPERTY_PagerNumber, LIBMTP_PROPERTY_PhoneNumberOthers,
           LIBMTP_PROPERTY_PrimaryWebAddress, LIBMTP_PROPERTY_PersonalWebAddress, LIBMTP_PROPERTY_BusinessWebAddress, LIBMTP_PROPERTY_InstantMessengerAddress, LIBMTP_PROPERTY_InstantMessengerAddress2,
           LIBMTP_PROPERTY_InstantMessengerAddress3, LIBMTP_PROPERTY_PostalAddressPersonalFull, LIBMTP_PROPERTY_PostalAddressPersonalFullLine1, LIBMTP_PROPERTY_PostalAddressPersonalFullLine2,
           LIBMTP_PROPERTY_PostalAddressPersonalFullCity, LIBMTP_PROPERTY_PostalAddressPersonalFullRegion, LIBMTP_PROPERTY_PostalAddressPersonalFullPostalCode,
           LIBMTP_PROPERTY_PostalAddressPersonalFullCountry, LIBMTP_PROPERTY_PostalAddressBusinessFull, LIBMTP_PROPERTY_PostalAddressBusinessLine1, LIBMTP_PROPERTY_PostalAddressBusinessLine2,
           LIBMTP_PROPERTY_PostalAddressBusinessCity, LIBMTP_PROPERTY_PostalAddressBusinessRegion, LIBMTP_PROPERTY_PostalAddressBusinessPostalCode, LIBMTP_PROPERTY_PostalAddressBusinessCountry,
           LIBMTP_PROPERTY_PostalAddressOtherFull, LIBMTP_PROPERTY_PostalAddressOtherLine1, LIBMTP_PROPERTY_PostalAddressOtherLine2, LIBMTP_PROPERTY_PostalAddressOtherCity,
           LIBMTP_PROPERTY_PostalAddressOtherRegion, LIBMTP_PROPERTY_PostalAddressOtherPostalCode, LIBMTP_PROPERTY_PostalAddressOtherCountry, LIBMTP_PROPERTY_OrganizationName,
           LIBMTP_PROPERTY_PhoneticOrganizationName, LIBMTP_PROPERTY_Role, LIBMTP_PROPERTY_Birthdate, LIBMTP_PROPERTY_MessageTo, LIBMTP_PROPERTY_MessageCC, LIBMTP_PROPERTY_MessageBCC,
           LIBMTP_PROPERTY_MessageRead, LIBMTP_PROPERTY_MessageReceivedTime, LIBMTP_PROPERTY_MessageSender, LIBMTP_PROPERTY_ActivityBeginTime, LIBMTP_PROPERTY_ActivityEndTime,
           LIBMTP_PROPERTY_ActivityLocation, LIBMTP_PROPERTY_ActivityRequiredAttendees, LIBMTP_PROPERTY_ActivityOptionalAttendees, LIBMTP_PROPERTY_ActivityResources, LIBMTP_PROPERTY_ActivityAccepted,
           LIBMTP_PROPERTY_Owner, LIBMTP_PROPERTY_Editor, LIBMTP_PROPERTY_Webmaster, LIBMTP_PROPERTY_URLSource, LIBMTP_PROPERTY_URLDestination, LIBMTP_PROPERTY_TimeBookmark,
           LIBMTP_PROPERTY_ObjectBookmark, LIBMTP_PROPERTY_ByteBookmark, LIBMTP_PROPERTY_LastBuildDate, LIBMTP_PROPERTY_TimetoLive, LIBMTP_PROPERTY_MediaGUID, LIBMTP_PROPERTY_TotalBitRate,
           LIBMTP_PROPERTY_BitRateType, LIBMTP_PROPERTY_SampleRate, LIBMTP_PROPERTY_NumberOfChannels, LIBMTP_PROPERTY_AudioBitDepth, LIBMTP_PROPERTY_ScanDepth, LIBMTP_PROPERTY_AudioWAVECodec,
           LIBMTP_PROPERTY_AudioBitRate, LIBMTP_PROPERTY_VideoFourCCCodec, LIBMTP_PROPERTY_VideoBitRate, LIBMTP_PROPERTY_FramesPerThousandSeconds, LIBMTP_PROPERTY_KeyFrameDistance,
           LIBMTP_PROPERTY_BufferSize, LIBMTP_PROPERTY_EncodingQuality, LIBMTP_PROPERTY_EncodingProfile, LIBMTP_PROPERTY_BuyFlag, LIBMTP_PROPERTY_UNKNOWN }
       enum LIBMTP_datatype_t { LIBMTP_DATATYPE_INT8, LIBMTP_DATATYPE_UINT8, LIBMTP_DATATYPE_INT16, LIBMTP_DATATYPE_UINT16, LIBMTP_DATATYPE_INT32, LIBMTP_DATATYPE_UINT32, LIBMTP_DATATYPE_INT64,
           LIBMTP_DATATYPE_UINT64 }
       enum LIBMTP_devicecap_t { LIBMTP_DEVICECAP_GetPartialObject, LIBMTP_DEVICECAP_SendPartialObject, LIBMTP_DEVICECAP_EditObjects, LIBMTP_DEVICECAP_MoveObject, LIBMTP_DEVICECAP_CopyObject }
       enum LIBMTP_error_number_t { LIBMTP_ERROR_NONE, LIBMTP_ERROR_GENERAL, LIBMTP_ERROR_PTP_LAYER, LIBMTP_ERROR_USB_LAYER, LIBMTP_ERROR_MEMORY_ALLOCATION, LIBMTP_ERROR_NO_DEVICE_ATTACHED,
           LIBMTP_ERROR_STORAGE_FULL, LIBMTP_ERROR_CONNECTING, LIBMTP_ERROR_CANCELLED }
       enum LIBMTP_event_enum { LIBMTP_EVENT_NONE, LIBMTP_EVENT_STORE_ADDED, LIBMTP_EVENT_STORE_REMOVED, LIBMTP_EVENT_OBJECT_ADDED, LIBMTP_EVENT_OBJECT_REMOVED, LIBMTP_EVENT_DEVICE_PROPERTY_CHANGED }

   Functions
       void LIBMTP_Set_Debug (int)
       void LIBMTP_Init (void)
       int LIBMTP_Get_Supported_Devices_List (LIBMTP_device_entry_t **const, int *const)
       LIBMTP_error_number_t LIBMTP_Detect_Raw_Devices (LIBMTP_raw_device_t **, int *)
       int LIBMTP_Check_Specific_Device (int busno, int devno)
       LIBMTP_mtpdevice_t * LIBMTP_Open_Raw_Device (LIBMTP_raw_device_t *)
       LIBMTP_mtpdevice_t * LIBMTP_Open_Raw_Device_Uncached (LIBMTP_raw_device_t *)
       LIBMTP_mtpdevice_t * LIBMTP_Get_Device (int)
       LIBMTP_mtpdevice_t * LIBMTP_Get_First_Device (void)
       LIBMTP_error_number_t LIBMTP_Get_Connected_Devices (LIBMTP_mtpdevice_t **)
       uint32_t LIBMTP_Number_Devices_In_List (LIBMTP_mtpdevice_t *)
       void LIBMTP_Release_Device_List (LIBMTP_mtpdevice_t *)
       void LIBMTP_Release_Device (LIBMTP_mtpdevice_t *)
       void LIBMTP_Dump_Device_Info (LIBMTP_mtpdevice_t *)
       int LIBMTP_Reset_Device (LIBMTP_mtpdevice_t *)
       char * LIBMTP_Get_Manufacturername (LIBMTP_mtpdevice_t *)
       char * LIBMTP_Get_Modelname (LIBMTP_mtpdevice_t *)
       char * LIBMTP_Get_Serialnumber (LIBMTP_mtpdevice_t *)
       char * LIBMTP_Get_Deviceversion (LIBMTP_mtpdevice_t *)
       char * LIBMTP_Get_Friendlyname (LIBMTP_mtpdevice_t *)
       int LIBMTP_Set_Friendlyname (LIBMTP_mtpdevice_t *, char const *const)
       char * LIBMTP_Get_Syncpartner (LIBMTP_mtpdevice_t *)
       int LIBMTP_Set_Syncpartner (LIBMTP_mtpdevice_t *, char const *const)
       int LIBMTP_Get_Batterylevel (LIBMTP_mtpdevice_t *, uint8_t *const, uint8_t *const)
       int LIBMTP_Get_Secure_Time (LIBMTP_mtpdevice_t *, char **const)
       int LIBMTP_Get_Device_Certificate (LIBMTP_mtpdevice_t *, char **const)
       int LIBMTP_Get_Supported_Filetypes (LIBMTP_mtpdevice_t *, uint16_t **const, uint16_t *const)
       int LIBMTP_Check_Capability (LIBMTP_mtpdevice_t *, LIBMTP_devicecap_t)
       LIBMTP_error_t * LIBMTP_Get_Errorstack (LIBMTP_mtpdevice_t *)
       void LIBMTP_Clear_Errorstack (LIBMTP_mtpdevice_t *)
       void LIBMTP_Dump_Errorstack (LIBMTP_mtpdevice_t *)
       int LIBMTP_Get_Storage (LIBMTP_mtpdevice_t *, int const)
       int LIBMTP_Format_Storage (LIBMTP_mtpdevice_t *, LIBMTP_devicestorage_t *)
       char * LIBMTP_Get_String_From_Object (LIBMTP_mtpdevice_t *, uint32_t const, LIBMTP_property_t const)
       uint64_t LIBMTP_Get_u64_From_Object (LIBMTP_mtpdevice_t *, uint32_t const, LIBMTP_property_t const, uint64_t const)
       uint32_t LIBMTP_Get_u32_From_Object (LIBMTP_mtpdevice_t *, uint32_t const, LIBMTP_property_t const, uint32_t const)
       uint16_t LIBMTP_Get_u16_From_Object (LIBMTP_mtpdevice_t *, uint32_t const, LIBMTP_property_t const, uint16_t const)
       uint8_t LIBMTP_Get_u8_From_Object (LIBMTP_mtpdevice_t *, uint32_t const, LIBMTP_property_t const, uint8_t const)
       int LIBMTP_Set_Object_String (LIBMTP_mtpdevice_t *, uint32_t const, LIBMTP_property_t const, char const *const)
       int LIBMTP_Set_Object_u32 (LIBMTP_mtpdevice_t *, uint32_t const, LIBMTP_property_t const, uint32_t const)
       int LIBMTP_Set_Object_u16 (LIBMTP_mtpdevice_t *, uint32_t const, LIBMTP_property_t const, uint16_t const)
       int LIBMTP_Set_Object_u8 (LIBMTP_mtpdevice_t *, uint32_t const, LIBMTP_property_t const, uint8_t const)
       char const * LIBMTP_Get_Property_Description (LIBMTP_property_t inproperty)
       int LIBMTP_Is_Property_Supported (LIBMTP_mtpdevice_t *, LIBMTP_property_t const, LIBMTP_filetype_t const)
       int LIBMTP_Get_Allowed_Property_Values (LIBMTP_mtpdevice_t *, LIBMTP_property_t const, LIBMTP_filetype_t const, LIBMTP_allowed_values_t *)
       void LIBMTP_destroy_allowed_values_t (LIBMTP_allowed_values_t *)
       LIBMTP_file_t * LIBMTP_new_file_t (void)
       void LIBMTP_destroy_file_t (LIBMTP_file_t *)
       char const * LIBMTP_Get_Filetype_Description (LIBMTP_filetype_t)
       LIBMTP_file_t * LIBMTP_Get_Filelisting (LIBMTP_mtpdevice_t *)
       LIBMTP_file_t * LIBMTP_Get_Filelisting_With_Callback (LIBMTP_mtpdevice_t *, LIBMTP_progressfunc_t const, void const *const)
       LIBMTP_file_t * LIBMTP_Get_Files_And_Folders (LIBMTP_mtpdevice_t *, uint32_t const, uint32_t const)
       LIBMTP_file_t * LIBMTP_Get_Filemetadata (LIBMTP_mtpdevice_t *, uint32_t const)
       int LIBMTP_Get_File_To_File (LIBMTP_mtpdevice_t *, uint32_t, char const *const, LIBMTP_progressfunc_t const, void const *const)
       int LIBMTP_Get_File_To_File_Descriptor (LIBMTP_mtpdevice_t *, uint32_t const, int const, LIBMTP_progressfunc_t const, void const *const)
       int LIBMTP_Get_File_To_Handler (LIBMTP_mtpdevice_t *, uint32_t const, MTPDataPutFunc, void *, LIBMTP_progressfunc_t const, void const *const)
       int LIBMTP_Send_File_From_File (LIBMTP_mtpdevice_t *, char const *const, LIBMTP_file_t *const, LIBMTP_progressfunc_t const, void const *const)
       int LIBMTP_Send_File_From_File_Descriptor (LIBMTP_mtpdevice_t *, int const, LIBMTP_file_t *const, LIBMTP_progressfunc_t const, void const *const)
       int LIBMTP_Send_File_From_Handler (LIBMTP_mtpdevice_t *, MTPDataGetFunc, void *, LIBMTP_file_t *const, LIBMTP_progressfunc_t const, void const *const)
       int LIBMTP_Set_File_Name (LIBMTP_mtpdevice_t *, LIBMTP_file_t *, const char *)
       LIBMTP_filesampledata_t * LIBMTP_new_filesampledata_t (void)
       void LIBMTP_destroy_filesampledata_t (LIBMTP_filesampledata_t *)
       int LIBMTP_Get_Representative_Sample_Format (LIBMTP_mtpdevice_t *, LIBMTP_filetype_t const, LIBMTP_filesampledata_t **)
       int LIBMTP_Send_Representative_Sample (LIBMTP_mtpdevice_t *, uint32_t const, LIBMTP_filesampledata_t *)
       int LIBMTP_Get_Representative_Sample (LIBMTP_mtpdevice_t *, uint32_t const, LIBMTP_filesampledata_t *)
       int LIBMTP_Get_Thumbnail (LIBMTP_mtpdevice_t *, uint32_t const, unsigned char **data, unsigned int *size)
       LIBMTP_track_t * LIBMTP_new_track_t (void)
       void LIBMTP_destroy_track_t (LIBMTP_track_t *)
       LIBMTP_track_t * LIBMTP_Get_Tracklisting (LIBMTP_mtpdevice_t *)
       LIBMTP_track_t * LIBMTP_Get_Tracklisting_With_Callback (LIBMTP_mtpdevice_t *, LIBMTP_progressfunc_t const, void const *const)
       LIBMTP_track_t * LIBMTP_Get_Tracklisting_With_Callback_For_Storage (LIBMTP_mtpdevice_t *, uint32_t const, LIBMTP_progressfunc_t const, void const *const)
       LIBMTP_track_t * LIBMTP_Get_Trackmetadata (LIBMTP_mtpdevice_t *, uint32_t const)
       int LIBMTP_Get_Track_To_File (LIBMTP_mtpdevice_t *, uint32_t, char const *const, LIBMTP_progressfunc_t const, void const *const)
       int LIBMTP_Get_Track_To_File_Descriptor (LIBMTP_mtpdevice_t *, uint32_t const, int const, LIBMTP_progressfunc_t const, void const *const)
       int LIBMTP_Get_Track_To_Handler (LIBMTP_mtpdevice_t *, uint32_t const, MTPDataPutFunc, void *, LIBMTP_progressfunc_t const, void const *const)
       int LIBMTP_Send_Track_From_File (LIBMTP_mtpdevice_t *, char const *const, LIBMTP_track_t *const, LIBMTP_progressfunc_t const, void const *const)
       int LIBMTP_Send_Track_From_File_Descriptor (LIBMTP_mtpdevice_t *, int const, LIBMTP_track_t *const, LIBMTP_progressfunc_t const, void const *const)
       int LIBMTP_Send_Track_From_Handler (LIBMTP_mtpdevice_t *, MTPDataGetFunc, void *, LIBMTP_track_t *const, LIBMTP_progressfunc_t const, void const *const)
       int LIBMTP_Update_Track_Metadata (LIBMTP_mtpdevice_t *, LIBMTP_track_t const *const)
       int LIBMTP_Track_Exists (LIBMTP_mtpdevice_t *, uint32_t const)
       int LIBMTP_Set_Track_Name (LIBMTP_mtpdevice_t *, LIBMTP_track_t *, const char *)
       LIBMTP_folder_t * LIBMTP_new_folder_t (void)
       void LIBMTP_destroy_folder_t (LIBMTP_folder_t *)
       LIBMTP_folder_t * LIBMTP_Get_Folder_List (LIBMTP_mtpdevice_t *)
       LIBMTP_folder_t * LIBMTP_Get_Folder_List_For_Storage (LIBMTP_mtpdevice_t *, uint32_t const)
       LIBMTP_folder_t * LIBMTP_Find_Folder (LIBMTP_folder_t *, uint32_t const)
       uint32_t LIBMTP_Create_Folder (LIBMTP_mtpdevice_t *, char *, uint32_t, uint32_t)
       int LIBMTP_Set_Folder_Name (LIBMTP_mtpdevice_t *, LIBMTP_folder_t *, const char *)
       LIBMTP_playlist_t * LIBMTP_new_playlist_t (void)
       void LIBMTP_destroy_playlist_t (LIBMTP_playlist_t *)
       LIBMTP_playlist_t * LIBMTP_Get_Playlist_List (LIBMTP_mtpdevice_t *)
       LIBMTP_playlist_t * LIBMTP_Get_Playlist (LIBMTP_mtpdevice_t *, uint32_t const)
       int LIBMTP_Create_New_Playlist (LIBMTP_mtpdevice_t *, LIBMTP_playlist_t *const)
       int LIBMTP_Update_Playlist (LIBMTP_mtpdevice_t *, LIBMTP_playlist_t *const)
       int LIBMTP_Set_Playlist_Name (LIBMTP_mtpdevice_t *, LIBMTP_playlist_t *, const char *)
       LIBMTP_album_t * LIBMTP_new_album_t (void)
       void LIBMTP_destroy_album_t (LIBMTP_album_t *)
       LIBMTP_album_t * LIBMTP_Get_Album_List (LIBMTP_mtpdevice_t *)
       LIBMTP_album_t * LIBMTP_Get_Album_List_For_Storage (LIBMTP_mtpdevice_t *, uint32_t const)
       LIBMTP_album_t * LIBMTP_Get_Album (LIBMTP_mtpdevice_t *, uint32_t const)
       int LIBMTP_Create_New_Album (LIBMTP_mtpdevice_t *, LIBMTP_album_t *const)
       int LIBMTP_Update_Album (LIBMTP_mtpdevice_t *, LIBMTP_album_t const *const)
       int LIBMTP_Set_Album_Name (LIBMTP_mtpdevice_t *, LIBMTP_album_t *, const char *)
       int LIBMTP_Delete_Object (LIBMTP_mtpdevice_t *, uint32_t)
       int LIBMTP_Move_Object (LIBMTP_mtpdevice_t *, uint32_t, uint32_t, uint32_t)
       int LIBMTP_Copy_Object (LIBMTP_mtpdevice_t *, uint32_t, uint32_t, uint32_t)
       int LIBMTP_Set_Object_Filename (LIBMTP_mtpdevice_t *, uint32_t, char *)
       int LIBMTP_GetPartialObject (LIBMTP_mtpdevice_t *, uint32_t const, uint64_t, uint32_t, unsigned char **, unsigned int *)
       int LIBMTP_SendPartialObject (LIBMTP_mtpdevice_t *, uint32_t const, uint64_t, unsigned char *, unsigned int)
       int LIBMTP_BeginEditObject (LIBMTP_mtpdevice_t *, uint32_t const)
       int LIBMTP_EndEditObject (LIBMTP_mtpdevice_t *, uint32_t const)
       int LIBMTP_TruncateObject (LIBMTP_mtpdevice_t *, uint32_t const, uint64_t)
       int LIBMTP_Read_Event (LIBMTP_mtpdevice_t *, LIBMTP_event_t *, uint32_t *)
       int LIBMTP_Read_Event_Async (LIBMTP_mtpdevice_t *, LIBMTP_event_cb_fn, void *)
       int LIBMTP_Handle_Events_Timeout_Completed (struct timeval *, int *)
       int LIBMTP_Custom_Operation (LIBMTP_mtpdevice_t *, uint16_t, int,...)

   Variables
       int LIBMTP_debug

Detailed Description
       Interface to the Media Transfer Protocol library.

       Copyright (C) 2005-2013 Linus Walleij triad@df.lth.se Copyright (C) 2005-2008 Richard A. Low richard@wentnet.com Copyright (C) 2007 Ted Bullock tbullock@canada.com Copyright (C) 2008 Florent
       Mertens flomertens@gmail.com

       This library is free software; you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation; either version 2 of
       the License, or (at your option) any later version.

       This library is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
       Lesser General Public License for more details.

       You should have received a copy of the GNU Lesser General Public License along with this library; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA
       02111-1307, USA.

        #include <libmtp.h>

Variable Documentation
   int LIBMTP_debug [extern]
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

Version 1.1.20                                                                                Mon Jul 4 2022                                                                                   libmtp.h(3)
