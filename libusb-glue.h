libusb-glue.h(3)                                                                                  libmtp                                                                                  libusb-glue.h(3)

NAME
       libusb-glue.h

SYNOPSIS
       #include 'ptp.h'
       #include 'libmtp.h'
       #include 'device-flags.h'

   Data Structures
       struct _PTP_USB

   Macros
       #define LIBMTP_USB_DEBUG(format,  args...)
       #define LIBMTP_USB_DATA(buffer,  length,  base)
       #define FLAG_BROKEN_MTPGETOBJPROPLIST_ALL(a)     ((a)->rawdevice.device_entry.device_flags & DEVICE_FLAG_BROKEN_MTPGETOBJPROPLIST_ALL)
       #define FLAG_UNLOAD_DRIVER(a)     ((a)->rawdevice.device_entry.device_flags & DEVICE_FLAG_UNLOAD_DRIVER)
       #define FLAG_BROKEN_MTPGETOBJPROPLIST(a)     ((a)->rawdevice.device_entry.device_flags & DEVICE_FLAG_BROKEN_MTPGETOBJPROPLIST)
       #define FLAG_NO_ZERO_READS(a)     ((a)->rawdevice.device_entry.device_flags & DEVICE_FLAG_NO_ZERO_READS)
       #define FLAG_IRIVER_OGG_ALZHEIMER(a)     ((a)->rawdevice.device_entry.device_flags & DEVICE_FLAG_IRIVER_OGG_ALZHEIMER)
       #define FLAG_ONLY_7BIT_FILENAMES(a)     ((a)->rawdevice.device_entry.device_flags & DEVICE_FLAG_ONLY_7BIT_FILENAMES)
       #define FLAG_NO_RELEASE_INTERFACE(a)     ((a)->rawdevice.device_entry.device_flags & DEVICE_FLAG_NO_RELEASE_INTERFACE)
       #define FLAG_IGNORE_HEADER_ERRORS(a)     ((a)->rawdevice.device_entry.device_flags & DEVICE_FLAG_IGNORE_HEADER_ERRORS)
       #define FLAG_BROKEN_SET_OBJECT_PROPLIST(a)     ((a)->rawdevice.device_entry.device_flags & DEVICE_FLAG_BROKEN_SET_OBJECT_PROPLIST)
       #define FLAG_OGG_IS_UNKNOWN(a)     ((a)->rawdevice.device_entry.device_flags & DEVICE_FLAG_OGG_IS_UNKNOWN)
       #define FLAG_BROKEN_SET_SAMPLE_DIMENSIONS(a)     ((a)->rawdevice.device_entry.device_flags & DEVICE_FLAG_BROKEN_SET_SAMPLE_DIMENSIONS)
       #define FLAG_ALWAYS_PROBE_DESCRIPTOR(a)     ((a)->rawdevice.device_entry.device_flags & DEVICE_FLAG_ALWAYS_PROBE_DESCRIPTOR)
       #define FLAG_PLAYLIST_SPL_V1(a)     ((a)->rawdevice.device_entry.device_flags & DEVICE_FLAG_PLAYLIST_SPL_V1)
       #define FLAG_PLAYLIST_SPL_V2(a)     ((a)->rawdevice.device_entry.device_flags & DEVICE_FLAG_PLAYLIST_SPL_V2)
       #define FLAG_PLAYLIST_SPL(a)     ((a)->rawdevice.device_entry.device_flags & (DEVICE_FLAG_PLAYLIST_SPL_V1 | DEVICE_FLAG_PLAYLIST_SPL_V2))
       #define FLAG_CANNOT_HANDLE_DATEMODIFIED(a)     ((a)->rawdevice.device_entry.device_flags & DEVICE_FLAG_CANNOT_HANDLE_DATEMODIFIED)
       #define FLAG_BROKEN_SEND_OBJECT_PROPLIST(a)     ((a)->rawdevice.device_entry.device_flags & DEVICE_FLAG_BROKEN_SEND_OBJECT_PROPLIST)
       #define FLAG_BROKEN_BATTERY_LEVEL(a)     ((a)->rawdevice.device_entry.device_flags & DEVICE_FLAG_BROKEN_BATTERY_LEVEL)
       #define FLAG_FLAC_IS_UNKNOWN(a)     ((a)->rawdevice.device_entry.device_flags & DEVICE_FLAG_FLAC_IS_UNKNOWN)
       #define FLAG_UNIQUE_FILENAMES(a)     ((a)->rawdevice.device_entry.device_flags & DEVICE_FLAG_UNIQUE_FILENAMES)
       #define FLAG_SWITCH_MODE_BLACKBERRY(a)     ((a)->rawdevice.device_entry.device_flags & DEVICE_FLAG_SWITCH_MODE_BLACKBERRY)
       #define FLAG_LONG_TIMEOUT(a)     ((a)->rawdevice.device_entry.device_flags & DEVICE_FLAG_LONG_TIMEOUT)
       #define FLAG_FORCE_RESET_ON_CLOSE(a)     ((a)->rawdevice.device_entry.device_flags & DEVICE_FLAG_FORCE_RESET_ON_CLOSE)
       #define PTP_CD_RC_CONNECTED   0
       #define PTP_CD_RC_NO_DEVICES   1
       #define PTP_CD_RC_ERROR_CONNECTING   2

   Typedefs
       typedef struct _PTP_USB PTP_USB

   Functions
       void dump_usbinfo (PTP_USB *ptp_usb)
       const char * get_playlist_extension (PTP_USB *ptp_usb)
       void close_device (PTP_USB *ptp_usb, PTPParams *params)
       LIBMTP_error_number_t configure_usb_device (LIBMTP_raw_device_t *device, PTPParams *params, void **usbinfo)
       void set_usb_device_timeout (PTP_USB *ptp_usb, int timeout)
       void get_usb_device_timeout (PTP_USB *ptp_usb, int *timeout)
       int guess_usb_speed (PTP_USB *ptp_usb)

Detailed Description
       Low-level USB interface glue towards libusb.

       Copyright (C) 2005-2007 Richard A. Low richard@wentnet.com Copyright (C) 2005-2012 Linus Walleij triad@df.lth.se Copyright (C) 2006-2011 Marcus Meissner Copyright (C) 2007 Ted Bullock Copyright
       (C) 2008 Chris Bagwell chris@cnpbagwell.com

       This library is free software; you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation; either version 2 of
       the License, or (at your option) any later version.

       This library is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
       Lesser General Public License for more details.

       You should have received a copy of the GNU Lesser General Public License along with this library; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA
       02111-1307, USA.

       Created by Richard Low on 24/12/2005. Modified by Linus Walleij

Macro Definition Documentation
   #define LIBMTP_USB_DATA(buffer, length, base)
       Value:

         do {     if ((LIBMTP_debug & LIBMTP_DEBUG_DATA) != 0)       data_dump_ascii (stdout, buffer, length, base);   } while (0)

   #define LIBMTP_USB_DEBUG(format, args...)
       Value:

         do {     if ((LIBMTP_debug & LIBMTP_DEBUG_USB) != 0)       fprintf(stdout, "LIBMTP %s[%d]: " format, __FUNCTION__, __LINE__, ##args);   } while (0)
       Debug macro

Typedef Documentation
   typedef struct _PTP_USB PTP_USB
       Internal USB struct.

Function Documentation
   LIBMTP_error_number_t configure_usb_device (LIBMTP_raw_device_t * device, PTPParams * params, void ** usbinfo)
       This function assigns params and usbinfo given a raw device as input.

       Parameters
           device the device to be assigned.
           usbinfo a pointer to the new usbinfo.

       Returns
           an error code.

       References LIBMTP_raw_device_struct::device_entry, LIBMTP_device_entry_struct::product_id, and LIBMTP_device_entry_struct::vendor_id.

   void dump_usbinfo (PTP_USB * ptp_usb)
       This routine just dumps out low-level USB information about the current device.

       Parameters
           ptp_usb the USB device to get information from.

       References LIBMTP_raw_device_struct::bus_location, LIBMTP_raw_device_struct::device_entry, LIBMTP_device_entry_struct::device_flags, LIBMTP_raw_device_struct::devnum,
       LIBMTP_device_entry_struct::product, LIBMTP_device_entry_struct::product_id, _PTP_USB::rawdevice, LIBMTP_device_entry_struct::vendor, and LIBMTP_device_entry_struct::vendor_id.

       Referenced by LIBMTP_Dump_Device_Info().

   const char * get_playlist_extension (PTP_USB * ptp_usb)
       Retrieve the appropriate playlist extension for this device. Rather hacky at the moment. This is probably desired by the managing software, but when creating lists on the device itself you notice
       certain preferences.

       Parameters
           ptp_usb the USB device to get suggestion for.

       Returns
           the suggested playlist extension.

Author
       Generated automatically by Doxygen for libmtp from the source code.

Version 1.1.20                                                                                Mon Jul 4 2022                                                                              libusb-glue.h(3)
