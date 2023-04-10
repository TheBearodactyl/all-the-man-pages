setjmp.h(0P)               POSIX Programmer's Manual              setjmp.h(0P)

PROLOG
       This  manual  page is part of the POSIX Programmer's Manual.  The Linux
       implementation of this interface may differ (consult the  corresponding
       Linux  manual page for details of Linux behavior), or the interface may
       not be implemented on Linux.

NAME
       setjmp.h — stack environment declarations

SYNOPSIS
       #include <setjmp.h>

DESCRIPTION
       Some of the functionality described on this reference page extends  the
       ISO C  standard. Applications shall define the appropriate feature test
       macro (see the System Interfaces volume of POSIX.1‐2017,  Section  2.2,
       The  Compilation Environment) to enable the visibility of these symbols
       in this header.

       The  <setjmp.h>  header  shall  define  the  array  types  jmp_buf  and
       sigjmp_buf.

       The following shall be declared as functions and may also be defined as
       macros. Function prototypes shall be provided.

           void   _longjmp(jmp_buf, int);
           void   longjmp(jmp_buf, int);
           void   siglongjmp(sigjmp_buf, int);

       The following may be declared as functions, or defined  as  macros,  or
       both. If functions are declared, function prototypes shall be provided.

           int    _setjmp(jmp_buf);
           int    setjmp(jmp_buf);
           int    sigsetjmp(sigjmp_buf, int);

       The following sections are informative.

APPLICATION USAGE
       None.

RATIONALE
       None.

FUTURE DIRECTIONS
       None.

SEE ALSO
       The System Interfaces volume of POSIX.1‐2017, Section 2.2, The Compila‐
       tion  Environment,  _longjmp(),  longjmp(),   setjmp(),   siglongjmp(),
       sigsetjmp()

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

IEEE/The Open Group                  2017                         setjmp.h(0P)
