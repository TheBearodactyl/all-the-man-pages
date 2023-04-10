sys_select.h(0P)           POSIX Programmer's Manual          sys_select.h(0P)

PROLOG
       This  manual  page is part of the POSIX Programmer's Manual.  The Linux
       implementation of this interface may differ (consult the  corresponding
       Linux  manual page for details of Linux behavior), or the interface may
       not be implemented on Linux.

NAME
       sys/select.h — select types

SYNOPSIS
       #include <sys/select.h>

DESCRIPTION
       The <sys/select.h> header shall define  the  timeval  structure,  which
       shall include at least the following members:

           time_t         tv_sec      Seconds.
           suseconds_t    tv_usec     Microseconds.

       The <sys/select.h> header shall define the time_t and suseconds_t types
       as described in <sys/types.h>.

       The <sys/select.h> header shall define the sigset_t type  as  described
       in <signal.h>.

       The  <sys/select.h>  header  shall define the timespec structure as de‐
       scribed in <time.h>.

       The <sys/select.h> header shall define the fd_set type as a structure.

       The <sys/select.h> header shall define the following symbolic constant,
       which  shall  have a value suitable for use in #if preprocessing direc‐
       tives:

       FD_SETSIZE  Maximum number of file descriptors in an fd_set structure.

       The following shall be declared as functions,  defined  as  macros,  or
       both. If functions are declared, function prototypes shall be provided.

           void FD_CLR(int, fd_set *);
           int  FD_ISSET(int, fd_set *);
           void FD_SET(int, fd_set *);
           void FD_ZERO(fd_set *);

       If  implemented as macros, these may evaluate their arguments more than
       once, so applications should ensure that the arguments they supply  are
       never expressions with side-effects.

       The following shall be declared as functions and may also be defined as
       macros. Function prototypes shall be provided.

           int  pselect(int, fd_set *restrict, fd_set *restrict, fd_set *restrict,
                    const struct timespec *restrict, const sigset_t *restrict);
           int  select(int, fd_set *restrict, fd_set *restrict, fd_set *restrict,
                    struct timeval *restrict);

       Inclusion of the <sys/select.h> header may  make  visible  all  symbols
       from the headers <signal.h> and <time.h>.

       The following sections are informative.

APPLICATION USAGE
       None.

RATIONALE
       None.

FUTURE DIRECTIONS
       None.

SEE ALSO
       <signal.h>, <sys_time.h>, <sys_types.h>, <time.h>

       The System Interfaces volume of POSIX.1‐2017, pselect()

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

IEEE/The Open Group                  2017                     sys_select.h(0P)
