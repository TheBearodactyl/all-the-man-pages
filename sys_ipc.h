sys_ipc.h(0P)              POSIX Programmer's Manual             sys_ipc.h(0P)

PROLOG
       This  manual  page is part of the POSIX Programmer's Manual.  The Linux
       implementation of this interface may differ (consult the  corresponding
       Linux  manual page for details of Linux behavior), or the interface may
       not be implemented on Linux.

NAME
       sys/ipc.h — XSI interprocess communication access structure

SYNOPSIS
       #include <sys/ipc.h>

DESCRIPTION
       The <sys/ipc.h> header is used by three mechanisms for XSI interprocess
       communication (IPC): messages, semaphores, and shared memory. All use a
       common structure type, ipc_perm, to pass information used in  determin‐
       ing permission to perform an IPC operation.

       The <sys/ipc.h> header shall define the ipc_perm structure, which shall
       include the following members:

           uid_t    uid    Owner's user ID.
           gid_t    gid    Owner's group ID.
           uid_t    cuid   Creator's user ID.
           gid_t    cgid   Creator's group ID.
           mode_t   mode   Read/write permission.

       The <sys/ipc.h> header shall define the uid_t, gid_t, mode_t, and key_t
       types as described in <sys/types.h>.

       The <sys/ipc.h> header shall define the following symbolic constants.

       Mode bits:

       IPC_CREAT   Create entry if key does not exist.

       IPC_EXCL    Fail if key exists.

       IPC_NOWAIT  Error if request must wait.

       Keys:

       IPC_PRIVATE Private key.

       Control commands:

       IPC_RMID    Remove identifier.

       IPC_SET     Set options.

       IPC_STAT    Get options.

       The  following  shall be declared as a function and may also be defined
       as a macro. A function prototype shall be provided.

           key_t  ftok(const char *, int);

       The following sections are informative.

APPLICATION USAGE
       None.

RATIONALE
       None.

FUTURE DIRECTIONS
       None.

SEE ALSO
       <sys_types.h>

       The System Interfaces volume of POSIX.1‐2017, ftok()

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

IEEE/The Open Group                  2017                        sys_ipc.h(0P)
