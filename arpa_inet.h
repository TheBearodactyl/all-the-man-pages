arpa_inet.h(0P)                                                                          POSIX Programmer's Manual                                                                         arpa_inet.h(0P)

PROLOG
       This  manual  page is part of the POSIX Programmer's Manual.  The Linux implementation of this interface may differ (consult the corresponding Linux manual page for details of Linux behavior), or
       the interface may not be implemented on Linux.

NAME
       arpa/inet.h — definitions for internet operations

SYNOPSIS
       #include <arpa/inet.h>

DESCRIPTION
       The <arpa/inet.h> header shall define the in_port_t and in_addr_t types as described in <netinet/in.h>.

       The <arpa/inet.h> header shall define the in_addr structure as described in <netinet/in.h>.

       The <arpa/inet.h> header shall define the INET_ADDRSTRLEN and INET6_ADDRSTRLEN macros as described in <netinet/in.h>.

       The following shall be declared as functions, or defined as macros, or both. If functions are declared, function prototypes shall be provided.

           uint32_t htonl(uint32_t);
           uint16_t htons(uint16_t);
           uint32_t ntohl(uint32_t);
           uint16_t ntohs(uint16_t);

       The <arpa/inet.h> header shall define the uint32_t and uint16_t types as described in <inttypes.h>.

       The following shall be declared as functions and may also be defined as macros. Function prototypes shall be provided.

           in_addr_t    inet_addr(const char *);
           char        *inet_ntoa(struct in_addr);
           const char  *inet_ntop(int, const void *restrict, char *restrict,
                            socklen_t);
           int          inet_pton(int, const char *restrict, void *restrict);

       Inclusion of the <arpa/inet.h> header may also make visible all symbols from <netinet/in.h> and <inttypes.h>.

       The following sections are informative.

APPLICATION USAGE
       None.

RATIONALE
       None.

FUTURE DIRECTIONS
       None.

SEE ALSO
       <inttypes.h>, <netinet_in.h>

       The System Interfaces volume of POSIX.1‐2017, htonl(), inet_addr(), inet_ntop()

COPYRIGHT
       Portions of this text are reprinted and reproduced in electronic form from IEEE Std 1003.1-2017, Standard for Information Technology -- Portable Operating System Interface (POSIX), The Open Group
       Base  Specifications Issue 7, 2018 Edition, Copyright (C) 2018 by the Institute of Electrical and Electronics Engineers, Inc and The Open Group.  In the event of any discrepancy between this ver‐
       sion and the original IEEE and The Open Group Standard, the original IEEE and The Open Group Standard is the referee document. The original Standard can be  obtained  online  at  http://www.open‐
       group.org/unix/online.html .

       Any  typographical  or  formatting errors that appear in this page are most likely to have been introduced during the conversion of the source files to man page format. To report such errors, see
       https://www.kernel.org/doc/man-pages/reporting_bugs.html .

IEEE/The Open Group                                                                                2017                                                                                    arpa_inet.h(0P)
