sys_sem.h(0P)              POSIX Programmer's Manual             sys_sem.h(0P)

PROLOG
       This  manual  page is part of the POSIX Programmer's Manual.  The Linux
       implementation of this interface may differ (consult the  corresponding
       Linux  manual page for details of Linux behavior), or the interface may
       not be implemented on Linux.

NAME
       sys/sem.h — XSI semaphore facility

SYNOPSIS
       #include <sys/sem.h>

DESCRIPTION
       The <sys/sem.h> header shall define the following symbolic constant for
       use as a semaphore operation flag:

       SEM_UNDO    Set up adjust on exit entry.

       The  <sys/sem.h>  header  shall define the following symbolic constants
       for use as commands for the semctl() function:

       GETNCNT     Get semncnt.

       GETPID      Get sempid.

       GETVAL      Get semval.

       GETALL      Get all cases of semval.

       GETZCNT     Get semzcnt.

       SETVAL      Set semval.

       SETALL      Set all cases of semval.

       The <sys/sem.h> header shall define the semid_ds structure, which shall
       include the following members:

           struct ipc_perm  sem_perm  Operation permission structure.
           unsigned short   sem_nsems Number of semaphores in set.
           time_t           sem_otime Last semop() time.
           time_t           sem_ctime Last time changed by semctl().

       The <sys/sem.h> header shall define the pid_t, size_t, and time_t types
       as described in <sys/types.h>.

       A semaphore shall be represented by an anonymous structure, which shall
       include the following members:

           unsigned short  semval   Semaphore value.
           pid_t           sempid   Process ID of last operation.
           unsigned short  semncnt  Number of processes waiting for semval
                                    to become greater than current value.
           unsigned short  semzcnt  Number of processes waiting for semval
                                    to become 0.

       The  <sys/sem.h>  header shall define the sembuf structure, which shall
       include the following members:

           unsigned short  sem_num   Semaphore number.
           short           sem_op    Semaphore operation.
           short           sem_flg   Operation flags.

       The following shall be declared as functions and may also be defined as
       macros. Function prototypes shall be provided.

           int   semctl(int, int, int, ...);
           int   semget(key_t, int, int);
           int   semop(int, struct sembuf *, size_t);

       In  addition,  the  <sys/sem.h>  header  shall  include the <sys/ipc.h>
       header.

       The following sections are informative.

APPLICATION USAGE
       None.

RATIONALE
       None.

FUTURE DIRECTIONS
       None.

SEE ALSO
       <sys_ipc.h>, <sys_types.h>

       The System Interfaces volume of POSIX.1‐2017, semctl(),  semget(),  se‐
       mop()

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

IEEE/The Open Group                  2017                        sys_sem.h(0P)
