sys_resource.h(0P)         POSIX Programmer's Manual        sys_resource.h(0P)

PROLOG
       This  manual  page is part of the POSIX Programmer's Manual.  The Linux
       implementation of this interface may differ (consult the  corresponding
       Linux  manual page for details of Linux behavior), or the interface may
       not be implemented on Linux.

NAME
       sys/resource.h — definitions for XSI resource operations

SYNOPSIS
       #include <sys/resource.h>

DESCRIPTION
       The <sys/resource.h> header shall define the  following  symbolic  con‐
       stants  as  possible  values of the which argument of getpriority() and
       setpriority():

       PRIO_PROCESS    Identifies the who argument as a process ID.

       PRIO_PGRP       Identifies the who argument as a process group ID.

       PRIO_USER       Identifies the who argument as a user ID.

       The <sys/resource.h> header shall define  the  following  type  through
       typedef:

       rlim_t          Unsigned integer type used for limit values.

       The  <sys/resource.h>  header  shall define the following symbolic con‐
       stants, which shall have values suitable for use in  #if  preprocessing
       directives:

       RLIM_INFINITY   A value of rlim_t indicating no limit.

       RLIM_SAVED_MAX  A  value  of  type rlim_t indicating an unrepresentable
                       saved hard limit.

       RLIM_SAVED_CUR  A value of type rlim_t  indicating  an  unrepresentable
                       saved soft limit.

       On  implementations  where  all resource limits are representable in an
       object of type rlim_t, RLIM_SAVED_MAX and RLIM_SAVED_CUR  need  not  be
       distinct from RLIM_INFINITY.

       The  <sys/resource.h>  header  shall define the following symbolic con‐
       stants as possible values of the who parameter of getrusage():

       RUSAGE_SELF     Returns information about the current process.

       RUSAGE_CHILDREN Returns  information  about  children  of  the  current
                       process.

       The  <sys/resource.h>  header  shall define the rlimit structure, which
       shall include at least the following members:

           rlim_t rlim_cur  The current (soft) limit.
           rlim_t rlim_max  The hard limit.

       The <sys/resource.h> header shall define the  rusage  structure,  which
       shall include at least the following members:

           struct timeval ru_utime  User time used.
           struct timeval ru_stime  System time used.

       The  <sys/resource.h>  header shall define the timeval structure as de‐
       scribed in <sys/time.h>.

       The <sys/resource.h> header shall define the  following  symbolic  con‐
       stants  as possible values for the resource argument of getrlimit() and
       setrlimit():

       RLIMIT_CORE     Limit on size of core file.

       RLIMIT_CPU      Limit on CPU time per process.

       RLIMIT_DATA     Limit on data segment size.

       RLIMIT_FSIZE    Limit on file size.

       RLIMIT_NOFILE   Limit on number of open files.

       RLIMIT_STACK    Limit on stack size.

       RLIMIT_AS       Limit on address space size.

       The following shall be declared as functions and may also be defined as
       macros. Function prototypes shall be provided.

           int  getpriority(int, id_t);
           int  getrlimit(int, struct rlimit *);
           int  getrusage(int, struct rusage *);
           int  setpriority(int, id_t, int);
           int  setrlimit(int, const struct rlimit *);

       The <sys/resource.h> header shall define the id_t type through typedef,
       as described in <sys/types.h>.

       Inclusion of the <sys/resource.h> header may also make visible all sym‐
       bols from <sys/time.h>.

       The following sections are informative.

APPLICATION USAGE
       None.

RATIONALE
       None.

FUTURE DIRECTIONS
       None.

SEE ALSO
       <sys_time.h>, <sys_types.h>

       The  System  Interfaces  volume  of  POSIX.1‐2017, getpriority(), getr‐
       limit(), getrusage()

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

IEEE/The Open Group                  2017                   sys_resource.h(0P)
