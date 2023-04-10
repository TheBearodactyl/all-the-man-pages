sys_utsname.h(0P)          POSIX Programmer's Manual         sys_utsname.h(0P)

PROLOG
       This  manual  page is part of the POSIX Programmer's Manual.  The Linux
       implementation of this interface may differ (consult the  corresponding
       Linux  manual page for details of Linux behavior), or the interface may
       not be implemented on Linux.

NAME
       sys/utsname.h — system name structure

SYNOPSIS
       #include <sys/utsname.h>

DESCRIPTION
       The <sys/utsname.h> header shall define  the  structure  utsname  which
       shall include at least the following members:

           char  sysname[]  Name of this implementation of the operating system.
           char  nodename[] Name of this node within the communications
                            network to which this node is attached, if any.
           char  release[]  Current release level of this implementation.
           char  version[]  Current version level of this release.
           char  machine[]  Name of the hardware type on which the system is running.

       The  character  arrays  are of unspecified size, but the data stored in
       them shall be terminated by a null byte.

       The following shall be declared as a function and may also  be  defined
       as a macro:

           int uname(struct utsname *);

       The following sections are informative.

APPLICATION USAGE
       None.

RATIONALE
       None.

FUTURE DIRECTIONS
       None.

SEE ALSO
       The System Interfaces volume of POSIX.1‐2017, uname()

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

IEEE/The Open Group                  2017                    sys_utsname.h(0P)
