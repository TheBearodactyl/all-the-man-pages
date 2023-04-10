spawn.h(0P)                POSIX Programmer's Manual               spawn.h(0P)

PROLOG
       This  manual  page is part of the POSIX Programmer's Manual.  The Linux
       implementation of this interface may differ (consult the  corresponding
       Linux  manual page for details of Linux behavior), or the interface may
       not be implemented on Linux.

NAME
       spawn.h — spawn (ADVANCED REALTIME)

SYNOPSIS
       #include <spawn.h>

DESCRIPTION
       The  <spawn.h>  header   shall   define   the   posix_spawnattr_t   and
       posix_spawn_file_actions_t types used in performing spawn operations.

       The  <spawn.h>  header  shall  define the mode_t and pid_t types as de‐
       scribed in <sys/types.h>.

       The <spawn.h> header shall define the sigset_t  type  as  described  in
       <signal.h>.

       The tag sched_param shall be declared as naming an incomplete structure
       type, the contents of which are described in the <sched.h> header.

       The <spawn.h> header shall define the following symbolic constants  for
       use  as  the  flags that may be set in a posix_spawnattr_t object using
       the posix_spawnattr_setflags() function:

       POSIX_SPAWN_RESETIDS
       POSIX_SPAWN_SETPGROUP
       POSIX_SPAWN_SETSCHEDPARAM
       POSIX_SPAWN_SETSCHEDULER
       POSIX_SPAWN_SETSIGDEF
       POSIX_SPAWN_SETSIGMASK

       The following shall be declared as functions and may also be defined as
       macros. Function prototypes shall be provided.

           int   posix_spawn(pid_t *restrict, const char *restrict,
                     const posix_spawn_file_actions_t *,
                     const posix_spawnattr_t *restrict, char *const [restrict],
                     char *const [restrict]);
           int   posix_spawn_file_actions_addclose(posix_spawn_file_actions_t *,
                     int);
           int   posix_spawn_file_actions_adddup2(posix_spawn_file_actions_t *,
                     int, int);
           int   posix_spawn_file_actions_addopen(posix_spawn_file_actions_t *restrict,
                     int, const char *restrict, int, mode_t);
           int   posix_spawn_file_actions_destroy(posix_spawn_file_actions_t *);
           int   posix_spawn_file_actions_init(posix_spawn_file_actions_t *);
           int   posix_spawnattr_destroy(posix_spawnattr_t *);
           int   posix_spawnattr_getflags(const posix_spawnattr_t *restrict,
                     short *restrict);
           int   posix_spawnattr_getpgroup(const posix_spawnattr_t *restrict,
                     pid_t *restrict);
           int   posix_spawnattr_getschedparam(const posix_spawnattr_t *restrict,
                     struct sched_param *restrict);
           int   posix_spawnattr_getschedpolicy(const posix_spawnattr_t *restrict,
                     int *restrict);
           int   posix_spawnattr_getsigdefault(const posix_spawnattr_t *restrict,
                     sigset_t *restrict);
           int   posix_spawnattr_getsigmask(const posix_spawnattr_t *restrict,
                     sigset_t *restrict);
           int   posix_spawnattr_init(posix_spawnattr_t *);
           int   posix_spawnattr_setflags(posix_spawnattr_t *, short);
           int   posix_spawnattr_setpgroup(posix_spawnattr_t *, pid_t);
           int   posix_spawnattr_setschedparam(posix_spawnattr_t *restrict,
                     const struct sched_param *restrict);
           int   posix_spawnattr_setschedpolicy(posix_spawnattr_t *, int);
           int   posix_spawnattr_setsigdefault(posix_spawnattr_t *restrict,
                     const sigset_t *restrict);
           int   posix_spawnattr_setsigmask(posix_spawnattr_t *restrict,
                     const sigset_t *restrict);
           int   posix_spawnp(pid_t *restrict, const char *restrict,
                     const posix_spawn_file_actions_t *,
                     const posix_spawnattr_t *restrict,
                     char *const [restrict], char *const [restrict]);

       Inclusion  of  the <spawn.h> header may make visible symbols defined in
       the <sched.h> and <signal.h> headers.

       The following sections are informative.

APPLICATION USAGE
       None.

RATIONALE
       None.

FUTURE DIRECTIONS
       None.

SEE ALSO
       <sched.h>, <semaphore.h>, <signal.h>, <sys_types.h>

       The System Interfaces volume of POSIX.1‐2017, posix_spawn(),
       posix_spawn_file_actions_addclose(), posix_spawn_file_actions_ad‐
       ddup2(), posix_spawn_file_actions_destroy(), posix_spawnattr_destroy(),
       posix_spawnattr_getflags(), posix_spawnattr_getpgroup(), posix_spaw‐
       nattr_getschedparam(), posix_spawnattr_getschedpolicy(), posix_spaw‐
       nattr_getsigdefault(), posix_spawnattr_getsigmask()

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

IEEE/The Open Group                  2017                          spawn.h(0P)
