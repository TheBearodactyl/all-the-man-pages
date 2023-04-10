utime.h(0P)                                                                              POSIX Programmer's Manual                                                                             utime.h(0P)

PROLOG
       This  manual  page is part of the POSIX Programmer's Manual.  The Linux implementation of this interface may differ (consult the corresponding Linux manual page for details of Linux behavior), or
       the interface may not be implemented on Linux.

NAME
       utime.h — access and modification times structure

SYNOPSIS
       #include <utime.h>

DESCRIPTION
       The <utime.h> header shall declare the utimbuf structure, which shall include the following members:

           time_t    actime    Access time.
           time_t    modtime   Modification time.

       The times shall be measured in seconds since the Epoch.

       The <utime.h> header shall define the time_t type as described in <sys/types.h>.

       The following shall be declared as a function and may also be defined as a macro. A function prototype shall be provided.

           int utime(const char *, const struct utimbuf *);

       The following sections are informative.

APPLICATION USAGE
       The utime() function only allows setting file timestamps to the nearest second.  Applications should use the utimensat() function instead. See <sys/stat.h>.

RATIONALE
       None.

FUTURE DIRECTIONS
       The <utime.h> header may be removed in a future version.

SEE ALSO
       <sys_stat.h>, <sys_types.h>

       The System Interfaces volume of POSIX.1‐2017, futimens(), utime()

COPYRIGHT
       Portions of this text are reprinted and reproduced in electronic form from IEEE Std 1003.1-2017, Standard for Information Technology -- Portable Operating System Interface (POSIX), The Open Group
       Base  Specifications Issue 7, 2018 Edition, Copyright (C) 2018 by the Institute of Electrical and Electronics Engineers, Inc and The Open Group.  In the event of any discrepancy between this ver‐
       sion and the original IEEE and The Open Group Standard, the original IEEE and The Open Group Standard is the referee document. The original Standard can be  obtained  online  at  http://www.open‐
       group.org/unix/online.html .

       Any  typographical  or  formatting errors that appear in this page are most likely to have been introduced during the conversion of the source files to man page format. To report such errors, see
       https://www.kernel.org/doc/man-pages/reporting_bugs.html .

IEEE/The Open Group                                                                                2017                                                                                        utime.h(0P)
