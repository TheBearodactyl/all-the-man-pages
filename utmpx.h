utmpx.h(0P)                                                                              POSIX Programmer's Manual                                                                             utmpx.h(0P)

PROLOG
       This  manual  page is part of the POSIX Programmer's Manual.  The Linux implementation of this interface may differ (consult the corresponding Linux manual page for details of Linux behavior), or
       the interface may not be implemented on Linux.

NAME
       utmpx.h — user accounting database definitions

SYNOPSIS
       #include <utmpx.h>

DESCRIPTION
       The <utmpx.h> header shall define the utmpx structure that shall include at least the following members:

           char            ut_user[]  User login name.
           char            ut_id[]    Unspecified initialization process identifier.
           char            ut_line[]  Device name.
           pid_t           ut_pid     Process ID.
           short           ut_type    Type of entry.
           struct timeval  ut_tv      Time entry was made.

       The <utmpx.h> header shall define the pid_t type through typedef, as described in <sys/types.h>.

       The <utmpx.h> header shall define the timeval structure as described in <sys/time.h>.

       Inclusion of the <utmpx.h> header may also make visible all symbols from <sys/time.h>.

       The <utmpx.h> header shall define the following symbolic constants as possible values for the ut_type member of the utmpx structure:

       EMPTY         No valid user accounting information.

       BOOT_TIME     Identifies time of system boot.

       OLD_TIME      Identifies time when system clock changed.

       NEW_TIME      Identifies time after system clock changed.

       USER_PROCESS  Identifies a process.

       INIT_PROCESS  Identifies a process spawned by the init process.

       LOGIN_PROCESS Identifies the session leader of a logged-in user.

       DEAD_PROCESS  Identifies a session leader who has exited.

       The following shall be declared as functions and may also be defined as macros. Function prototypes shall be provided.

           void          endutxent(void);
           struct utmpx *getutxent(void);
           struct utmpx *getutxid(const struct utmpx *);
           struct utmpx *getutxline(const struct utmpx *);
           struct utmpx *pututxline(const struct utmpx *);
           void          setutxent(void);

       The following sections are informative.

APPLICATION USAGE
       None.

RATIONALE
       None.

FUTURE DIRECTIONS
       None.

SEE ALSO
       <sys_time.h>, <sys_types.h>

       The System Interfaces volume of POSIX.1‐2017, endutxent()

COPYRIGHT
       Portions of this text are reprinted and reproduced in electronic form from IEEE Std 1003.1-2017, Standard for Information Technology -- Portable Operating System Interface (POSIX), The Open Group
       Base  Specifications Issue 7, 2018 Edition, Copyright (C) 2018 by the Institute of Electrical and Electronics Engineers, Inc and The Open Group.  In the event of any discrepancy between this ver‐
       sion and the original IEEE and The Open Group Standard, the original IEEE and The Open Group Standard is the referee document. The original Standard can be  obtained  online  at  http://www.open‐
       group.org/unix/online.html .

       Any  typographical  or  formatting errors that appear in this page are most likely to have been introduced during the conversion of the source files to man page format. To report such errors, see
       https://www.kernel.org/doc/man-pages/reporting_bugs.html .

IEEE/The Open Group                                                                                2017                                                                                        utmpx.h(0P)
