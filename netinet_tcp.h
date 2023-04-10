netinet_tcp.h(0P)                                                                        POSIX Programmer's Manual                                                                       netinet_tcp.h(0P)

PROLOG
       This  manual  page is part of the POSIX Programmer's Manual.  The Linux implementation of this interface may differ (consult the corresponding Linux manual page for details of Linux behavior), or
       the interface may not be implemented on Linux.

NAME
       netinet/tcp.h — definitions for the Internet Transmission Control Protocol (TCP)

SYNOPSIS
       #include <netinet/tcp.h>

DESCRIPTION
       The <netinet/tcp.h> header shall define the following symbolic constant for use as a socket option at the IPPROTO_TCP level:

       TCP_NODELAY Avoid coalescing of small segments.

       The implementation need not allow the value of the option to be set via setsockopt() or retrieved via getsockopt().

       The following sections are informative.

APPLICATION USAGE
       None.

RATIONALE
       None.

FUTURE DIRECTIONS
       None.

SEE ALSO
       <sys_socket.h>

       The System Interfaces volume of POSIX.1‐2017, getsockopt(), setsockopt()

COPYRIGHT
       Portions of this text are reprinted and reproduced in electronic form from IEEE Std 1003.1-2017, Standard for Information Technology -- Portable Operating System Interface (POSIX), The Open Group
       Base  Specifications Issue 7, 2018 Edition, Copyright (C) 2018 by the Institute of Electrical and Electronics Engineers, Inc and The Open Group.  In the event of any discrepancy between this ver‐
       sion and the original IEEE and The Open Group Standard, the original IEEE and The Open Group Standard is the referee document. The original Standard can be  obtained  online  at  http://www.open‐
       group.org/unix/online.html .

       Any  typographical  or  formatting errors that appear in this page are most likely to have been introduced during the conversion of the source files to man page format. To report such errors, see
       https://www.kernel.org/doc/man-pages/reporting_bugs.html .

IEEE/The Open Group                                                                                2017                                                                                  netinet_tcp.h(0P)
