sys_types.h(0P)            POSIX Programmer's Manual           sys_types.h(0P)

PROLOG
       This  manual  page is part of the POSIX Programmer's Manual.  The Linux
       implementation of this interface may differ (consult the  corresponding
       Linux  manual page for details of Linux behavior), or the interface may
       not be implemented on Linux.

NAME
       sys/types.h — data types

SYNOPSIS
       #include <sys/types.h>

DESCRIPTION
       The <sys/types.h> header shall define at least the following types:

       blkcnt_t        Used for file block counts.

       blksize_t       Used for block sizes.

       clock_t         Used for system times in clock ticks or CLOCKS_PER_SEC;
                       see <time.h>.

       clockid_t       Used  for  clock  ID  type in the clock and timer func‐
                       tions.

       dev_t           Used for device IDs.

       fsblkcnt_t      Used for file system block counts.

       fsfilcnt_t      Used for file system file counts.

       gid_t           Used for group IDs.

       id_t            Used as a general identifier; can be used to contain at
                       least a pid_t, uid_t, or gid_t.

       ino_t           Used for file serial numbers.

       key_t           Used for XSI interprocess communication.

       mode_t          Used for some file attributes.

       nlink_t         Used for link counts.

       off_t           Used for file sizes.

       pid_t           Used for process IDs and process group IDs.

       pthread_attr_t  Used to identify a thread attribute object.

       pthread_barrier_t
                       Used to identify a barrier.

       pthread_barrierattr_t
                       Used to define a barrier attributes object.

       pthread_cond_t  Used for condition variables.

       pthread_condattr_t
                       Used to identify a condition attribute object.

       pthread_key_t   Used for thread-specific data keys.

       pthread_mutex_t Used for mutexes.

       pthread_mutexattr_t
                       Used to identify a mutex attribute object.

       pthread_once_t  Used for dynamic package initialization.

       pthread_rwlock_t
                       Used for read-write locks.

       pthread_rwlockattr_t
                       Used for read-write lock attributes.

       pthread_spinlock_t
                       Used to identify a spin lock.

       pthread_t       Used to identify a thread.

       size_t          Used for sizes of objects.

       ssize_t         Used for a count of bytes or an error indication.

       suseconds_t     Used for time in microseconds.

       time_t          Used for time in seconds.

       timer_t         Used for timer ID returned by timer_create().

       trace_attr_t    Used to identify a trace stream attributes object

       trace_event_id_t
                       Used to identify a trace event type.

       trace_event_set_t
                       Used to identify a trace event type set.

       trace_id_t      Used to identify a trace stream.

       uid_t           Used for user IDs.

       All of the types shall be defined as arithmetic types of an appropriate
       length, with the following exceptions:

       pthread_attr_t
       pthread_barrier_t
       pthread_barrierattr_t
       pthread_cond_t
       pthread_condattr_t
       pthread_key_t
       pthread_mutex_t
       pthread_mutexattr_t
       pthread_once_t
       pthread_rwlock_t
       pthread_rwlockattr_t
       pthread_spinlock_t
       pthread_t
       timer_t
       trace_attr_t
       trace_event_id_t
       trace_event_set_t
       trace_id_t

       Additionally:

        *  mode_t shall be an integer type.

        *  dev_t shall be an integer type.

        *  nlink_t, uid_t, gid_t, and id_t shall be integer types.

        *  blkcnt_t and off_t shall be signed integer types.

        *  fsblkcnt_t, fsfilcnt_t, and ino_t shall be defined as unsigned  in‐
           teger types.

        *  size_t shall be an unsigned integer type.

        *  blksize_t, pid_t, and ssize_t shall be signed integer types.

        *  clock_t shall be an integer or real-floating type.  time_t shall be
           an integer type.

       The type ssize_t shall be capable of storing values  at  least  in  the
       range [-1, {SSIZE_MAX}].

       The  type suseconds_t shall be a signed integer type capable of storing
       values at least in the range [-1, 1000000].

       The implementation shall support one or more  programming  environments
       in  which  the  widths of blksize_t, pid_t, size_t, ssize_t, and susec‐
       onds_t are no greater than the width of type long.  The names of  these
       programming  environments  can be obtained using the confstr() function
       or the getconf utility.

       There are no defined comparison or assignment operators for the follow‐
       ing types:

       pthread_attr_t
       pthread_barrier_t
       pthread_barrierattr_t
       pthread_cond_t
       pthread_condattr_t
       pthread_mutex_t
       pthread_mutexattr_t
       pthread_rwlock_t
       pthread_rwlockattr_t
       pthread_spinlock_t
       timer_t
       trace_attr_t

       The following sections are informative.

APPLICATION USAGE
       None.

RATIONALE
       None.

FUTURE DIRECTIONS
       None.

SEE ALSO
       <time.h>

       The System Interfaces volume of POSIX.1‐2017, confstr()

       The Shell and Utilities volume of POSIX.1‐2017, getconf

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

IEEE/The Open Group                  2017                      sys_types.h(0P)
