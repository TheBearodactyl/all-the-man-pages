sys_shm.h(0P)              POSIX Programmer's Manual             sys_shm.h(0P)

PROLOG
       This  manual  page is part of the POSIX Programmer's Manual.  The Linux
       implementation of this interface may differ (consult the  corresponding
       Linux  manual page for details of Linux behavior), or the interface may
       not be implemented on Linux.

NAME
       sys/shm.h — XSI shared memory facility

SYNOPSIS
       #include <sys/shm.h>

DESCRIPTION
       The <sys/shm.h> header shall define the following symbolic constants:

       SHM_RDONLY  Attach read-only (else read-write).

       SHM_RND     Round attach address to SHMLBA.

       SHMLBA      Segment low boundary address multiple.

       The <sys/shm.h> header shall define the following  data  types  through
       typedef:

       shmatt_t    Unsigned  integer  used  for the number of current attaches
                   that must be able to store values at least as  large  as  a
                   type unsigned short.

       The <sys/shm.h> header shall define the shmid_ds structure, which shall
       include the following members:

           struct ipc_perm shm_perm   Operation permission structure.
           size_t          shm_segsz  Size of segment in bytes.
           pid_t           shm_lpid   Process ID of last shared memory operation.
           pid_t           shm_cpid   Process ID of creator.
           shmatt_t        shm_nattch Number of current attaches.
           time_t          shm_atime  Time of last shmat().
           time_t          shm_dtime  Time of last shmdt().
           time_t          shm_ctime  Time of last change by shmctl().

       The <sys/shm.h> header shall define the pid_t, size_t, and time_t types
       as described in <sys/types.h>.

       The following shall be declared as functions and may also be defined as
       macros. Function prototypes shall be provided.

           void *shmat(int, const void *, int);
           int   shmctl(int, int, struct shmid_ds *);
           int   shmdt(const void *);
           int   shmget(key_t, size_t, int);

       In addition, the  <sys/shm.h>  header  shall  include  the  <sys/ipc.h>
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

       The  System  Interfaces  volume  of  POSIX.1‐2017,  shmat(),  shmctl(),
       shmdt(), shmget()

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

IEEE/The Open Group                  2017                        sys_shm.h(0P)
