iconv.h(0P)                                                                              POSIX Programmer's Manual                                                                             iconv.h(0P)

PROLOG
       This  manual  page is part of the POSIX Programmer's Manual.  The Linux implementation of this interface may differ (consult the corresponding Linux manual page for details of Linux behavior), or
       the interface may not be implemented on Linux.

NAME
       iconv.h — codeset conversion facility

SYNOPSIS
       #include <iconv.h>

DESCRIPTION
       The <iconv.h> header shall define the following types:

       iconv_t     Identifies the conversion from one codeset to another.

       size_t      As described in <sys/types.h>.

       The following shall be declared as functions and may also be defined as macros. Function prototypes shall be provided.

           size_t  iconv(iconv_t, char **restrict, size_t *restrict,
                       char **restrict, size_t *restrict);
           int     iconv_close(iconv_t);
           iconv_t iconv_open(const char *, const char *);

       The following sections are informative.

APPLICATION USAGE
       None.

RATIONALE
       None.

FUTURE DIRECTIONS
       None.

SEE ALSO
       <sys_types.h>

       The System Interfaces volume of POSIX.1‐2017, iconv(), iconv_close(), iconv_open()

COPYRIGHT
       Portions of this text are reprinted and reproduced in electronic form from IEEE Std 1003.1-2017, Standard for Information Technology -- Portable Operating System Interface (POSIX), The Open Group
       Base  Specifications Issue 7, 2018 Edition, Copyright (C) 2018 by the Institute of Electrical and Electronics Engineers, Inc and The Open Group.  In the event of any discrepancy between this ver‐
       sion and the original IEEE and The Open Group Standard, the original IEEE and The Open Group Standard is the referee document. The original Standard can be  obtained  online  at  http://www.open‐
       group.org/unix/online.html .

       Any  typographical  or  formatting errors that appear in this page are most likely to have been introduced during the conversion of the source files to man page format. To report such errors, see
       https://www.kernel.org/doc/man-pages/reporting_bugs.html .

IEEE/The Open Group                                                                                2017                                                                                        iconv.h(0P)
