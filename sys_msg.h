sys_msg.h(0P)              POSIX Programmer's Manual             sys_msg.h(0P)

PROLOG
       This  manual  page is part of the POSIX Programmer's Manual.  The Linux
       implementation of this interface may differ (consult the  corresponding
       Linux  manual page for details of Linux behavior), or the interface may
       not be implemented on Linux.

NAME
       sys/msg.h — XSI message queue structures

SYNOPSIS
       #include <sys/msg.h>

DESCRIPTION
       The <sys/msg.h> header shall define the following  data  types  through
       typedef:

       msgqnum_t     Used for the number of messages in the message queue.

       msglen_t      Used for the number of bytes allowed in a message queue.

       These types shall be unsigned integer types that are able to store val‐
       ues at least as large as a type unsigned short.

       The <sys/msg.h> header shall define the following symbolic constant  as
       a message operation flag:

       MSG_NOERROR   No error if big message.

       The <sys/msg.h> header shall define the msqid_ds structure, which shall
       include the following members:

           struct ipc_perm msg_perm   Operation permission structure.
           msgqnum_t       msg_qnum   Number of messages currently on queue.
           msglen_t        msg_qbytes Maximum number of bytes allowed on queue.
           pid_t           msg_lspid  Process ID of last msgsnd().
           pid_t           msg_lrpid  Process ID of last msgrcv().
           time_t          msg_stime  Time of last msgsnd().
           time_t          msg_rtime  Time of last msgrcv().
           time_t          msg_ctime  Time of last change.

       The <sys/msg.h> header shall define the  pid_t,  size_t,  ssize_t,  and
       time_t types as described in <sys/types.h>.

       The following shall be declared as functions and may also be defined as
       macros. Function prototypes shall be provided.

           int       msgctl(int, int, struct msqid_ds *);
           int       msgget(key_t, int);
           ssize_t   msgrcv(int, void *, size_t, long, int);
           int       msgsnd(int, const void *, size_t, int);

       In addition, the  <sys/msg.h>  header  shall  include  the  <sys/ipc.h>
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

       The  System  Interfaces volume of POSIX.1‐2017, msgctl(), msgget(), ms‐
       grcv(), msgsnd()

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

IEEE/The Open Group                  2017                        sys_msg.h(0P)
