net_if.h(0P)                                                                             POSIX Programmer's Manual                                                                            net_if.h(0P)

PROLOG
       This  manual  page is part of the POSIX Programmer's Manual.  The Linux implementation of this interface may differ (consult the corresponding Linux manual page for details of Linux behavior), or
       the interface may not be implemented on Linux.

NAME
       net/if.h — sockets local interfaces

SYNOPSIS
       #include <net/if.h>

DESCRIPTION
       The <net/if.h> header shall define the if_nameindex structure, which shall include at least the following members:

           unsigned  if_index  Numeric index of the interface.
           char     *if_name   Null-terminated name of the interface.

       The <net/if.h> header shall define the following symbolic constant for the length of a buffer containing an interface name (including the terminating NULL character):

       IF_NAMESIZE Interface name length.

       The following shall be declared as functions and may also be defined as macros. Function prototypes shall be provided.

           void                  if_freenameindex(struct if_nameindex *);
           char                 *if_indextoname(unsigned, char *);
           struct if_nameindex  *if_nameindex(void);
           unsigned              if_nametoindex(const char *);

       The following sections are informative.

APPLICATION USAGE
       None.

RATIONALE
       None.

FUTURE DIRECTIONS
       None.

SEE ALSO
       The System Interfaces volume of POSIX.1‐2017, if_freenameindex(), if_indextoname(), if_nameindex(), if_nametoindex()

COPYRIGHT
       Portions of this text are reprinted and reproduced in electronic form from IEEE Std 1003.1-2017, Standard for Information Technology -- Portable Operating System Interface (POSIX), The Open Group
       Base  Specifications Issue 7, 2018 Edition, Copyright (C) 2018 by the Institute of Electrical and Electronics Engineers, Inc and The Open Group.  In the event of any discrepancy between this ver‐
       sion and the original IEEE and The Open Group Standard, the original IEEE and The Open Group Standard is the referee document. The original Standard can be  obtained  online  at  http://www.open‐
       group.org/unix/online.html .

       Any  typographical  or  formatting errors that appear in this page are most likely to have been introduced during the conversion of the source files to man page format. To report such errors, see
       https://www.kernel.org/doc/man-pages/reporting_bugs.html .

IEEE/The Open Group                                                                                2017                                                                                       net_if.h(0P)
