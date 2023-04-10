sys_times.h(0P)            POSIX Programmer's Manual           sys_times.h(0P)

PROLOG
       This  manual  page is part of the POSIX Programmer's Manual.  The Linux
       implementation of this interface may differ (consult the  corresponding
       Linux  manual page for details of Linux behavior), or the interface may
       not be implemented on Linux.

NAME
       sys/times.h — file access and modification times structure

SYNOPSIS
       #include <sys/times.h>

DESCRIPTION
       The <sys/times.h> header shall define the tms structure, which  is  re‐
       turned by times() and shall include at least the following members:

           clock_t  tms_utime  User CPU time.
           clock_t  tms_stime  System CPU time.
           clock_t  tms_cutime User CPU time of terminated child processes.
           clock_t  tms_cstime System CPU time of terminated child processes.

       The  <sys/times.h> header shall define the clock_t type as described in
       <sys/types.h>.

       The following shall be declared as a function and may also  be  defined
       as a macro. A function prototype shall be provided.

           clock_t times(struct tms *);

       The following sections are informative.

APPLICATION USAGE
       None.

RATIONALE
       None.

FUTURE DIRECTIONS
       None.

SEE ALSO
       <sys_types.h>

       The System Interfaces volume of POSIX.1‐2017, times()

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

IEEE/The Open Group                  2017                      sys_times.h(0P)
