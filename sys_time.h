sys_time.h(0P)             POSIX Programmer's Manual            sys_time.h(0P)

PROLOG
       This  manual  page is part of the POSIX Programmer's Manual.  The Linux
       implementation of this interface may differ (consult the  corresponding
       Linux  manual page for details of Linux behavior), or the interface may
       not be implemented on Linux.

NAME
       sys/time.h — time types

SYNOPSIS
       #include <sys/time.h>

DESCRIPTION
       The <sys/time.h> header shall define the timeval structure, which shall
       include at least the following members:

           time_t         tv_sec      Seconds.
           suseconds_t    tv_usec     Microseconds.

       The  <sys/time.h>  header  shall  define the itimerval structure, which
       shall include at least the following members:

           struct timeval it_interval Timer interval.
           struct timeval it_value    Current value.

       The <sys/time.h> header shall define the time_t and  suseconds_t  types
       as described in <sys/types.h>.

       The  <sys/time.h>  header  shall define the fd_set type as described in
       <sys/select.h>.

       The <sys/time.h> header shall define the following  symbolic  constants
       for the which argument of getitimer() and setitimer():

       ITIMER_REAL   Decrements in real time.

       ITIMER_VIRTUAL
                     Decrements in process virtual time.

       ITIMER_PROF   Decrements both in process virtual time and when the sys‐
                     tem is running on behalf of the process.

       The <sys/time.h> header shall define  the  following  as  described  in
       <sys/select.h>: FD_CLR() FD_ISSET() FD_SET() FD_ZERO() FD_SETSIZE

       The following shall be declared as functions and may also be defined as
       macros. Function prototypes shall be provided.

           int   getitimer(int, struct itimerval *);
           int   gettimeofday(struct timeval *restrict, void *restrict);
           int   setitimer(int, const struct itimerval *restrict,
                     struct itimerval *restrict);
           int   select(int, fd_set *restrict, fd_set *restrict, fd_set *restrict,
                     struct timeval *restrict);
           int   utimes(const char *, const struct timeval [2]);

       Inclusion of the <sys/time.h> header may make visible all symbols  from
       the <sys/select.h> header.

       The following sections are informative.

APPLICATION USAGE
       None.

RATIONALE
       None.

FUTURE DIRECTIONS
       None.

SEE ALSO
       <sys_select.h>, <sys_types.h>

       The  System Interfaces volume of POSIX.1‐2017, futimens(), getitimer(),
       gettimeofday(), pselect()

COPYRIGHT
       Portions of this text are reprinted and reproduced in  electronic  form
       from  IEEE Std 1003.1-2017, Standard for Information Technology -- Por‐
       table Operating System Interface (POSIX), The Open Group Base  Specifi‐
       cations  Issue  7, 2018 Edition, Copyright (C) 2018 by the Institute of
       Electrical and Electronics Engineers, Inc and The Open Group.   In  the
       event of any discrepancy between this version and the original IEEE and
       The Open Group Standard, the original IEEE and The Open Group  Standard
       is  the  referee document. The original Standard can be obtained online
       at http://www.opengroup.org/unix/online.html .

       Any typographical or formatting errors that appear  in  this  page  are
       most likely to have been introduced during the conversion of the source
       files to man page format. To report such errors,  see  https://www.ker‐
       nel.org/doc/man-pages/reporting_bugs.html .

IEEE/The Open Group                  2017                       sys_time.h(0P)
