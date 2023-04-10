sched.h(0P)                POSIX Programmer's Manual               sched.h(0P)

PROLOG
       This  manual  page is part of the POSIX Programmer's Manual.  The Linux
       implementation of this interface may differ (consult the  corresponding
       Linux  manual page for details of Linux behavior), or the interface may
       not be implemented on Linux.

NAME
       sched.h — execution scheduling

SYNOPSIS
       #include <sched.h>

DESCRIPTION
       The <sched.h> header shall  define  the  pid_t  type  as  described  in
       <sys/types.h>.

       The  <sched.h>  header  shall  define  the  time_t type as described in
       <sys/types.h>.

       The <sched.h> header shall define the timespec structure  as  described
       in <time.h>.

       The  <sched.h>  header  shall  define  the sched_param structure, which
       shall include the scheduling parameters required for implementation  of
       each supported scheduling policy. This structure shall include at least
       the following member:

           int       sched_priority        Process or thread execution scheduling priority.

       The sched_param structure defined in <sched.h> shall include  the  fol‐
       lowing members in addition to those specified above:

           int             sched_ss_low_priority Low scheduling priority for
                                                 sporadic server.
           struct timespec sched_ss_repl_period  Replenishment period for
                                                 sporadic server.
           struct timespec sched_ss_init_budget  Initial budget for sporadic server.
           int             sched_ss_max_repl     Maximum pending replenishments for
                                                 sporadic server.

       Each process or thread is controlled by an associated scheduling policy
       and priority. Associated with each policy is  a  priority  range.  Each
       policy definition specifies the minimum priority range for that policy.
       The priority ranges for each policy may overlap the priority ranges  of
       other policies.

       Four  scheduling policies are defined; others may be defined by the im‐
       plementation. The four standard policies are indicated by the values of
       the following symbolic constants:

       SCHED_FIFO    First in-first out (FIFO) scheduling policy.

       SCHED_RR      Round robin scheduling policy.

       SCHED_SPORADIC
                     Sporadic server scheduling policy.

       SCHED_OTHER   Another scheduling policy.

       The values of these constants are distinct.

       The following shall be declared as functions and may also be defined as
       macros. Function prototypes shall be provided.

           int    sched_get_priority_max(int);
           int    sched_get_priority_min(int);
           int    sched_getparam(pid_t, struct sched_param *);
           int    sched_getscheduler(pid_t);
           int    sched_rr_get_interval(pid_t, struct timespec *);
           int    sched_setparam(pid_t, const struct sched_param *);
           int    sched_setscheduler(pid_t, int, const struct sched_param *);
           int    sched_yield(void);

       Inclusion of the <sched.h> header may make visible all symbols from the
       <time.h> header.

       The following sections are informative.

APPLICATION USAGE
       None.

RATIONALE
       None.

FUTURE DIRECTIONS
       None.

SEE ALSO
       <sys_types.h>, <time.h>

       The System Interfaces volume of POSIX.1‐2017, sched_get_priority_max(),
       sched_getparam(),    sched_getscheduler(),     sched_rr_get_interval(),
       sched_setparam(), sched_setscheduler(), sched_yield()

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

IEEE/The Open Group                  2017                          sched.h(0P)
