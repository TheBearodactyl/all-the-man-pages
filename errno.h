errno.h(0P)                                                                              POSIX Programmer's Manual                                                                             errno.h(0P)

PROLOG
       This  manual  page is part of the POSIX Programmer's Manual.  The Linux implementation of this interface may differ (consult the corresponding Linux manual page for details of Linux behavior), or
       the interface may not be implemented on Linux.

NAME
       errno.h — system error numbers

SYNOPSIS
       #include <errno.h>

DESCRIPTION
       Some of the functionality described on this reference page extends the ISO C standard. Any conflict between the requirements described here and the ISO C standard is unintentional. This volume of
       POSIX.1‐2017 defers to the ISO C standard.

       The ISO C standard only requires the symbols [EDOM], [EILSEQ], and [ERANGE] to be defined.

       The  <errno.h>  header  shall  provide  a declaration or definition for errno.  The symbol errno shall expand to a modifiable lvalue of type int.  It is unspecified whether errno is a macro or an
       identifier declared with external linkage. If a macro definition is suppressed in order to access an actual object, or a program defines an identifier with the name errno, the behavior  is  unde‐
       fined.

       The <errno.h> header shall define the following macros which shall expand to integer constant expressions with type int, distinct positive values (except as noted below), and which shall be suit‐
       able for use in #if preprocessing directives:

       E2BIG  Argument list too long.

       EACCES Permission denied.

       EADDRINUSE
              Address in use.

       EADDRNOTAVAIL
              Address not available.

       EAFNOSUPPORT
              Address family not supported.

       EAGAIN Resource unavailable, try again (may be the same value as [EWOULDBLOCK]).

       EALREADY
              Connection already in progress.

       EBADF  Bad file descriptor.

       EBADMSG
              Bad message.

       EBUSY  Device or resource busy.

       ECANCELED
              Operation canceled.

       ECHILD No child processes.

       ECONNABORTED
              Connection aborted.

       ECONNREFUSED
              Connection refused.

       ECONNRESET
              Connection reset.

       EDEADLK
              Resource deadlock would occur.

       EDESTADDRREQ
              Destination address required.

       EDOM   Mathematics argument out of domain of function.

       EDQUOT Reserved.

       EEXIST File exists.

       EFAULT Bad address.

       EFBIG  File too large.

       EHOSTUNREACH
              Host is unreachable.

       EIDRM  Identifier removed.

       EILSEQ Illegal byte sequence.

       EINPROGRESS
              Operation in progress.

       EINTR  Interrupted function.

       EINVAL Invalid argument.

       EIO    I/O error.

       EISCONN
              Socket is connected.

       EISDIR Is a directory.

       ELOOP  Too many levels of symbolic links.

       EMFILE File descriptor value too large.

       EMLINK Too many links.

       EMSGSIZE
              Message too large.

       EMULTIHOP
              Reserved.

       ENAMETOOLONG
              Filename too long.

       ENETDOWN
              Network is down.

       ENETRESET
              Connection aborted by network.

       ENETUNREACH
              Network unreachable.

       ENFILE Too many files open in system.

       ENOBUFS
              No buffer space available.

       ENODATA
              No message is available on the STREAM head read queue.

       ENODEV No such device.

       ENOENT No such file or directory.

       ENOEXEC
              Executable file format error.

       ENOLCK No locks available.

       ENOLINK
              Reserved.

       ENOMEM Not enough space.

       ENOMSG No message of the desired type.

       ENOPROTOOPT
              Protocol not available.

       ENOSPC No space left on device.

       ENOSR  No STREAM resources.

       ENOSTR Not a STREAM.

       ENOSYS Functionality not supported.

       ENOTCONN
              The socket is not connected.

       ENOTDIR
              Not a directory or a symbolic link to a directory.

       ENOTEMPTY
              Directory not empty.

       ENOTRECOVERABLE
              State not recoverable.

       ENOTSOCK
              Not a socket.

       ENOTSUP
              Not supported (may be the same value as [EOPNOTSUPP]).

       ENOTTY Inappropriate I/O control operation.

       ENXIO  No such device or address.

       EOPNOTSUPP
              Operation not supported on socket (may be the same value as [ENOTSUP]).

       EOVERFLOW
              Value too large to be stored in data type.

       EOWNERDEAD
              Previous owner died.

       EPERM  Operation not permitted.

       EPIPE  Broken pipe.

       EPROTO Protocol error.

       EPROTONOSUPPORT
              Protocol not supported.

       EPROTOTYPE
              Protocol wrong type for socket.

       ERANGE Result too large.

       EROFS  Read-only file system.

       ESPIPE Invalid seek.

       ESRCH  No such process.

       ESTALE Reserved.

       ETIME  Stream ioctl() timeout.

       ETIMEDOUT
              Connection timed out.

       ETXTBSY
              Text file busy.

       EWOULDBLOCK
              Operation would block (may be the same value as [EAGAIN]).

       EXDEV  Cross-device link.

       The following sections are informative.

APPLICATION USAGE
       Additional error numbers may be defined on conforming systems; see the System Interfaces volume of POSIX.1‐2017.

RATIONALE
       None.

FUTURE DIRECTIONS
       None.

SEE ALSO
       The System Interfaces volume of POSIX.1‐2017, Section 2.3, Error Numbers

COPYRIGHT
       Portions of this text are reprinted and reproduced in electronic form from IEEE Std 1003.1-2017, Standard for Information Technology -- Portable Operating System Interface (POSIX), The Open Group
       Base  Specifications Issue 7, 2018 Edition, Copyright (C) 2018 by the Institute of Electrical and Electronics Engineers, Inc and The Open Group.  In the event of any discrepancy between this ver‐
       sion and the original IEEE and The Open Group Standard, the original IEEE and The Open Group Standard is the referee document. The original Standard can be  obtained  online  at  http://www.open‐
       group.org/unix/online.html .

       Any  typographical  or  formatting errors that appear in this page are most likely to have been introduced during the conversion of the source files to man page format. To report such errors, see
       https://www.kernel.org/doc/man-pages/reporting_bugs.html .

IEEE/The Open Group                                                                                2017                                                                                        errno.h(0P)
