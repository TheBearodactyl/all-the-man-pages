util.c(3)                                                                                         libmtp                                                                                         util.c(3)

NAME
       util.c

SYNOPSIS
       #include <sys/time.h>
       #include <unistd.h>
       #include <stdio.h>
       #include <stdlib.h>
       #include <errno.h>
       #include <sys/stat.h>
       #include <fcntl.h>
       #include <string.h>
       #include 'config.h'
       #include 'libmtp.h'
       #include 'util.h'

   Functions
       void device_unknown (const int dev_number, const int id_vendor, const int id_product)
       void data_dump (FILE *f, void *buf, uint32_t n)
       void data_dump_ascii (FILE *f, void *buf, uint32_t n, uint32_t dump_boundry)
       char * strndup (const char *s, size_t n)

Detailed Description
       This file contains generic utility functions such as can be used for debugging for example.

       Copyright (C) 2005-2007 Linus Walleij triad@df.lth.se

       This library is free software; you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation; either version 2 of
       the License, or (at your option) any later version.

       This library is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
       Lesser General Public License for more details.

       You should have received a copy of the GNU Lesser General Public License along with this library; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA
       02111-1307, USA.

Function Documentation
   void data_dump (FILE * f, void * buf, uint32_t n)
       This dumps out a number of bytes to a textual, hexadecimal dump.

       Parameters
           f the file to dump to (e.g. stdout or stderr)
           buf a pointer to the buffer containing the bytes to be dumped out in hex
           n the number of bytes to dump from this buffer

   void data_dump_ascii (FILE * f, void * buf, uint32_t n, uint32_t dump_boundry)
       This dumps out a number of bytes to a textual, hexadecimal dump, and also prints out the string ASCII representation for each line of bytes. It will also print the memory address offset from a
       certain boundry.

       Parameters
           f the file to dump to (e.g. stdout or stderr)
           buf a pointer to the buffer containing the bytes to be dumped out in hex
           n the number of bytes to dump from this buffer
           dump_boundry the address offset to start at (usually 0)

   void device_unknown (const int dev_number, const int id_vendor, const int id_product)
       This prints to stdout info about device being UNKNOWN, its ids, and libmtp's version number.

       Parameters
           dev_number the device number
           id_vendor vendor ID from the usb_device_desc struct
           id_product product ID from the usb_device_desc struct

Author
       Generated automatically by Doxygen for libmtp from the source code.

Version 1.1.20                                                                                Mon Jul 4 2022                                                                                     util.c(3)
