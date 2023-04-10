sys_wait.h(0P)             POSIX Programmer's Manual            sys_wait.h(0P)

PROLOG
       This  manual  page is part of the POSIX Programmer's Manual.  The Linux
       implementation of this interface may differ (consult the  corresponding
       Linux  manual page for details of Linux behavior), or the interface may
       not be implemented on Linux.

NAME
       sys/wait.h — declarations for waiting

SYNOPSIS
       #include <sys/wait.h>

DESCRIPTION
       The <sys/wait.h> header shall define the following  symbolic  constants
       for use with waitpid():

       WCONTINUED    Report status of continued child process.

       WNOHANG       Do  not  hang  if  no status is available; return immedi‐
                     ately.

       WUNTRACED     Report status of stopped child process.

       The <sys/wait.h> header shall define the following macros for  analysis
       of process status values:

       WEXITSTATUS   Return exit status.

       WIFCONTINUED  True if child has been continued.

       WIFEXITED     True if child exited normally.

       WIFSIGNALED   True if child exited due to uncaught signal.

       WIFSTOPPED    True if child is currently stopped.

       WSTOPSIG      Return signal number that caused process to stop.

       WTERMSIG      Return signal number that caused process to terminate.

       The  <sys/wait.h>  header shall define the following symbolic constants
       as possible values for the options argument to waitid():

       WEXITED       Wait for processes that have exited.

       WNOWAIT       Keep the process whose status is returned in infop  in  a
                     waitable state.

       WSTOPPED      Status  is  returned  for any child that has stopped upon
                     receipt of a signal.

       The WCONTINUED and WNOHANG constants, described  above  for  waitpid(),
       can also be used with waitid().

       The  type idtype_t shall be defined as an enumeration type whose possi‐
       ble values shall include at least the following: P_ALL P_PGID P_PID

       The <sys/wait.h> header shall define the id_t and pid_t  types  as  de‐
       scribed in <sys/types.h>.

       The  <sys/wait.h> header shall define the siginfo_t type and the sigval
       union as described in <signal.h>.

       Inclusion of the <sys/wait.h> header may also make visible all  symbols
       from <signal.h>.

       The following shall be declared as functions and may also be defined as
       macros. Function prototypes shall be provided.

           pid_t  wait(int *);
           int    waitid(idtype_t, id_t, siginfo_t *, int);
           pid_t  waitpid(pid_t, int *, int);

       The following sections are informative.

APPLICATION USAGE
       None.

RATIONALE
       None.

FUTURE DIRECTIONS
       None.

SEE ALSO
       <signal.h>, <sys_resource.h>, <sys_types.h>

       The System Interfaces volume of POSIX.1‐2017, wait(), waitid()

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

IEEE/The Open Group                  2017                       sys_wait.h(0P)
