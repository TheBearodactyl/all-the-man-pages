inttypes.h(0P)                                                                           POSIX Programmer's Manual                                                                          inttypes.h(0P)

PROLOG
       This  manual  page is part of the POSIX Programmer's Manual.  The Linux implementation of this interface may differ (consult the corresponding Linux manual page for details of Linux behavior), or
       the interface may not be implemented on Linux.

NAME
       inttypes.h — fixed size integer types

SYNOPSIS
       #include <inttypes.h>

DESCRIPTION
       Some of the functionality described on this reference page extends the ISO C standard. Applications shall define  the  appropriate  feature  test  macro  (see  the  System  Interfaces  volume  of
       POSIX.1‐2017, Section 2.2, The Compilation Environment) to enable the visibility of these symbols in this header.

       The <inttypes.h> header shall include the <stdint.h> header.

       The <inttypes.h> header shall define at least the following types:

       imaxdiv_t   Structure type that is the type of the value returned by the imaxdiv() function.

       wchar_t     As described in <stddef.h>.

       The  <inttypes.h>  header shall define the following macros. Each expands to a character string literal containing a conversion specifier, possibly modified by a length modifier, suitable for use
       within the format argument of a formatted input/output function when converting the corresponding integer type. These macros have the general form  of  PRI  (character  string  literals  for  the
       fprintf()  and fwprintf() family of functions) or SCN (character string literals for the fscanf() and fwscanf() family of functions), followed by the conversion specifier, followed by a name cor‐
       responding to a similar type name in <stdint.h>.  In these names, N represents the width of the type as described in <stdint.h>.  For example, PRIdFAST32 can be used in a format string  to  print
       the value of an integer of type int_fast32_t.

       The fprintf() macros for signed integers are:

              PRIdN        PRIdLEASTN   PRIdFASTN    PRIdMAX      PRIdPTR
              PRIiN        PRIiLEASTN   PRIiFASTN    PRIiMAX      PRIiPTR

       The fprintf() macros for unsigned integers are:

              PRIoN        PRIoLEASTN   PRIoFASTN    PRIoMAX      PRIoPTR
              PRIuN        PRIuLEASTN   PRIuFASTN    PRIuMAX      PRIuPTR
              PRIxN        PRIxLEASTN   PRIxFASTN    PRIxMAX      PRIxPTR
              PRIXN        PRIXLEASTN   PRIXFASTN    PRIXMAX      PRIXPTR

       The fscanf() macros for signed integers are:

              SCNdN        SCNdLEASTN   SCNdFASTN    SCNdMAX      SCNdPTR
              SCNiN        SCNiLEASTN   SCNiFASTN    SCNiMAX      SCNiPTR

       The fscanf() macros for unsigned integers are:

              SCNoN        SCNoLEASTN   SCNoFASTN    SCNoMAX      SCNoPTR
              SCNuN        SCNuLEASTN   SCNuFASTN    SCNuMAX      SCNuPTR
              SCNxN        SCNxLEASTN   SCNxFASTN    SCNxMAX      SCNxPTR

       For  each  type that the implementation provides in <stdint.h>, the corresponding fprintf() and fwprintf() macros shall be defined and the corresponding fscanf() and fwscanf() macros shall be de‐
       fined unless the implementation does not have a suitable modifier for the type.

       The following shall be declared as functions and may also be defined as macros. Function prototypes shall be provided.

           intmax_t  imaxabs(intmax_t);
           imaxdiv_t imaxdiv(intmax_t, intmax_t);
           intmax_t  strtoimax(const char *restrict, char **restrict, int);
           uintmax_t strtoumax(const char *restrict, char **restrict, int);
           intmax_t  wcstoimax(const wchar_t *restrict, wchar_t **restrict, int);
           uintmax_t wcstoumax(const wchar_t *restrict, wchar_t **restrict, int);

       The following sections are informative.

EXAMPLES
       #include <inttypes.h>
       #include <wchar.h>
       int main(void)
       {
           uintmax_t i = UINTMAX_MAX; // This type always exists.
           wprintf(L"The largest integer value is %020"
               PRIxMAX "\n", i);
           return 0;
       }

APPLICATION USAGE
       The purpose of <inttypes.h> is to provide a set of integer types whose definitions are consistent across machines and independent of operating systems and other implementation idiosyncrasies.  It
       defines,  through  typedef, integer types of various sizes. Implementations are free to typedef them as ISO C standard integer types or extensions that they support. Consistent use of this header
       will greatly increase the portability of applications across platforms.

RATIONALE
       The ISO/IEC 9899:1990 standard specified that the language should support four signed and unsigned integer data types—char, short, int, and long—but placed very little requirement on  their  size
       other  than  that  int  and short be at least 16 bits and long be at least as long as int and not smaller than 32 bits. For 16-bit systems, most implementations assigned 8, 16, 16, and 32 bits to
       char, short, int, and long, respectively. For 32-bit systems, the common practice has been to assign 8, 16, 32, and 32 bits to these types. This difference in int size can  create  some  problems
       for  users  who  migrate from one system to another which assigns different sizes to integer types, because the ISO C standard integer promotion rule can produce silent changes unexpectedly.  The
       need for defining an extended integer type increased with the introduction of 64-bit systems.

FUTURE DIRECTIONS
       Macro names beginning with PRI or SCN followed by any lowercase letter or 'X' may be added to the macros defined in the <inttypes.h> header.

SEE ALSO
       <stddef.h>

       The System Interfaces volume of POSIX.1‐2017, Section 2.2, The Compilation Environment, imaxabs(), imaxdiv(), strtoimax(), wcstoimax()

COPYRIGHT
       Portions of this text are reprinted and reproduced in electronic form from IEEE Std 1003.1-2017, Standard for Information Technology -- Portable Operating System Interface (POSIX), The Open Group
       Base  Specifications Issue 7, 2018 Edition, Copyright (C) 2018 by the Institute of Electrical and Electronics Engineers, Inc and The Open Group.  In the event of any discrepancy between this ver‐
       sion and the original IEEE and The Open Group Standard, the original IEEE and The Open Group Standard is the referee document. The original Standard can be  obtained  online  at  http://www.open‐
       group.org/unix/online.html .

       Any  typographical  or  formatting errors that appear in this page are most likely to have been introduced during the conversion of the source files to man page format. To report such errors, see
       https://www.kernel.org/doc/man-pages/reporting_bugs.html .

IEEE/The Open Group                                                                                2017                                                                                     inttypes.h(0P)
