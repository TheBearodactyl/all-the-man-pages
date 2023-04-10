sys_statvfs.h(0P)          POSIX Programmer's Manual         sys_statvfs.h(0P)

PROLOG
       This  manual  page is part of the POSIX Programmer's Manual.  The Linux
       implementation of this interface may differ (consult the  corresponding
       Linux  manual page for details of Linux behavior), or the interface may
       not be implemented on Linux.

NAME
       sys/statvfs.h — VFS File System information structure

SYNOPSIS
       #include <sys/statvfs.h>

DESCRIPTION
       The <sys/statvfs.h> header shall define the  statvfs  structure,  which
       shall include at least the following members:

           unsigned long f_bsize    File system block size.
           unsigned long f_frsize   Fundamental file system block size.
           fsblkcnt_t    f_blocks   Total number of blocks on file system in units of f_frsize.
           fsblkcnt_t    f_bfree    Total number of free blocks.
           fsblkcnt_t    f_bavail   Number of free blocks available to
                                    non-privileged process.
           fsfilcnt_t    f_files    Total number of file serial numbers.
           fsfilcnt_t    f_ffree    Total number of free file serial numbers.
           fsfilcnt_t    f_favail   Number of file serial numbers available to
                                    non-privileged process.
           unsigned long f_fsid     File system ID.
           unsigned long f_flag     Bit mask of f_flag values.
           unsigned long f_namemax  Maximum filename length.

       The  <sys/statvfs.h>  header shall define the fsblkcnt_t and fsfilcnt_t
       types as described in <sys/types.h>.

       The <sys/statvfs.h> header shall define  the  following  symbolic  con‐
       stants for the f_flag member:

       ST_RDONLY   Read-only file system.

       ST_NOSUID   Does not support the semantics of the ST_ISUID and ST_ISGID
                   file mode bits.

       The following shall be declared as functions and may also be defined as
       macros. Function prototypes shall be provided.

           int fstatvfs(int, struct statvfs *);
           int statvfs(const char *restrict, struct statvfs *restrict);

       The following sections are informative.

APPLICATION USAGE
       None.

RATIONALE
       None.

FUTURE DIRECTIONS
       None.

SEE ALSO
       <sys_types.h>

       The System Interfaces volume of POSIX.1‐2017, fstatvfs()

COPYRIGHT
       Portions  of  this text are reprinted and reproduced in electronic form
       from IEEE Std 1003.1-2017, Standard for Information Technology --  Por‐
       table  Operating System Interface (POSIX), The Open Group Base Specifi‐
       cations Issue 7, 2018 Edition, Copyright (C) 2018 by the  Institute  of
       Electrical  and  Electronics Engineers, Inc and The Open Group.  In the
       event of any discrepancy between this version and the original IEEE and
       The  Open Group Standard, the original IEEE and The Open Group Standard
       is the referee document. The original Standard can be  obtained  online
       at http://www.opengroup.org/unix/online.html .

       Any  typographical  or  formatting  errors that appear in this page are
       most likely to have been introduced during the conversion of the source
       files  to  man page format. To report such errors, see https://www.ker‐
       nel.org/doc/man-pages/reporting_bugs.html .

IEEE/The Open Group                  2017                    sys_statvfs.h(0P)
