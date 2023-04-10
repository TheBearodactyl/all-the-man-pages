NL(1)                                                                                          User Commands                                                                                         NL(1)

NAME
       nl - number lines of files

SYNOPSIS
       nl [OPTION]... [FILE]...

DESCRIPTION
       Write each FILE to standard output, with line numbers added.

       With no FILE, or when FILE is -, read standard input.

       Mandatory arguments to long options are mandatory for short options too.

       -b, --body-numbering=STYLE
              use STYLE for numbering body lines

       -d, --section-delimiter=CC
              use CC for logical page delimiters

       -f, --footer-numbering=STYLE
              use STYLE for numbering footer lines

       -h, --header-numbering=STYLE
              use STYLE for numbering header lines

       -i, --line-increment=NUMBER
              line number increment at each line

       -l, --join-blank-lines=NUMBER
              group of NUMBER empty lines counted as one

       -n, --number-format=FORMAT
              insert line numbers according to FORMAT

       -p, --no-renumber
              do not reset line numbers for each section

       -s, --number-separator=STRING
              add STRING after (possible) line number

       -v, --starting-line-number=NUMBER
              first line number for each section

       -w, --number-width=NUMBER
              use NUMBER columns for line numbers

       --help display this help and exit

       --version
              output version information and exit

       Default options are: -bt -d'\:' -fn -hn -i1 -l1 -n'rn' -s<TAB> -v1 -w6

       CC  are two delimiter characters used to construct logical page delimiters; a missing second character implies ':'.  As a GNU extension one can specify more than two characters, and also specify‐
       ing the empty string (-d '') disables section matching.

       STYLE is one of:

       a      number all lines

       t      number only nonempty lines

       n      number no lines

       pBRE   number only lines that contain a match for the basic regular expression, BRE

       FORMAT is one of:

       ln     left justified, no leading zeros

       rn     right justified, no leading zeros

       rz     right justified, leading zeros

AUTHOR
       Written by Scott Bartram and David MacKenzie.

REPORTING BUGS
       GNU coreutils online help: <https://www.gnu.org/software/coreutils/>
       Report any translation bugs to <https://translationproject.org/team/>

COPYRIGHT
       Copyright © 2023 Free Software Foundation, Inc.  License GPLv3+: GNU GPL version 3 or later <https://gnu.org/licenses/gpl.html>.
       This is free software: you are free to change and redistribute it.  There is NO WARRANTY, to the extent permitted by law.

SEE ALSO
       Full documentation <https://www.gnu.org/software/coreutils/nl>
       or available locally via: info '(coreutils) nl invocation'

GNU coreutils 9.2                                                                               April 2023                                                                                           NL(1)
NL(1P)                                                                                   POSIX Programmer's Manual                                                                                  NL(1P)

PROLOG
       This  manual  page is part of the POSIX Programmer's Manual.  The Linux implementation of this interface may differ (consult the corresponding Linux manual page for details of Linux behavior), or
       the interface may not be implemented on Linux.

NAME
       nl — line numbering filter

SYNOPSIS
       nl [-p] [-b type] [-d delim] [-f type] [-h type] [-i incr] [-l num]
           [-n format] [-s sep] [-v startnum] [-w width] [file]

DESCRIPTION
       The nl utility shall read lines from the named file or the standard input if no file is named and shall reproduce the lines to standard output. Lines shall be numbered  on  the  left.  Additional
       functionality may be provided in accordance with the command options in effect.

       The  nl  utility views the text it reads in terms of logical pages. Line numbering shall be reset at the start of each logical page. A logical page consists of a header, a body, and a footer sec‐
       tion. Empty sections are valid. Different line numbering options are independently available for header, body, and footer (for example, no numbering of header and  footer  lines  while  numbering
       blank lines only in the body).

       The starts of logical page sections shall be signaled by input lines containing nothing but the following delimiter characters:

                                                                                            ┌───────────┬────────────┐
                                                                                            │   Line    │  Start of  │
                                                                                            ├───────────┼────────────┤
                                                                                            │\:\:\:     │ Header     │
                                                                                            │\:\:       │ Body       │
                                                                                            │\:         │ Footer     │
                                                                                            └───────────┴────────────┘
       Unless otherwise specified, nl shall assume the text being read is in a single logical page body.

OPTIONS
       The nl utility shall conform to the Base Definitions volume of POSIX.1‐2017, Section 12.2, Utility Syntax Guidelines.  Only one file can be named.

       The following options shall be supported:

       -b type   Specify which logical page body lines shall be numbered. Recognized types and their meaning are:

                 a       Number all lines.

                 t       Number only non-empty lines.

                 n       No line numbering.

                 pstring Number only lines that contain the basic regular expression specified in string.

                 The default type for logical page body shall be t (text lines numbered).

       -d delim  Specify  the  delimiter characters that indicate the start of a logical page section. These can be changed from the default characters "\:" to two user-specified characters. If only one
                 character is entered, the second character shall remain the default character ':'.

       -f type   Specify the same as b type except for footer. The default for logical page footer shall be n (no lines numbered).

       -h type   Specify the same as b type except for header. The default type for logical page header shall be n (no lines numbered).

       -i incr   Specify the increment value used to number logical page lines. The default shall be 1.

       -l num    Specify the number of blank lines to be considered as one. For example, -l 2 results in only the second adjacent blank line being numbered (if the appropriate -h a, -b a, or -f a option
                 is set). The default shall be 1.

       -n format Specify the line numbering format. Recognized values are: ln, left justified, leading zeros suppressed; rn, right justified, leading zeros suppressed; rz, right justified, leading zeros
                 kept. The default format shall be rn (right justified).

       -p        Specify that numbering should not be restarted at logical page delimiters.

       -s sep    Specify the characters used in separating the line number and the corresponding text line. The default sep shall be a <tab>.

       -v startnum
                 Specify the initial value used to number logical page lines. The default shall be 1.

       -w width  Specify the number of characters to be used for the line number. The default width shall be 6.

OPERANDS
       The following operand shall be supported:

       file      A pathname of a text file to be line-numbered.

STDIN
       The standard input shall be used if no file operand is specified, and shall be used if the file operand is '-' and the implementation treats the '-' as meaning  standard  input.   Otherwise,  the
       standard input shall not be used.  See the INPUT FILES section.

INPUT FILES
       The input file shall be a text file.

ENVIRONMENT VARIABLES
       The following environment variables shall affect the execution of nl:

       LANG      Provide  a default value for the internationalization variables that are unset or null. (See the Base Definitions volume of POSIX.1‐2017, Section 8.2, Internationalization Variables for
                 the precedence of internationalization variables used to determine the values of locale categories.)

       LC_ALL    If set to a non-empty string value, override the values of all the other internationalization variables.

       LC_COLLATE
                 Determine the locale for the behavior of ranges, equivalence classes, and multi-character collating elements within regular expressions.

       LC_CTYPE  Determine the locale for the interpretation of sequences of bytes of text data as characters (for example, single-byte as opposed to multi-byte characters in arguments and input files),
                 the behavior of character classes within regular expressions, and for deciding which characters are in character class graph (for the -b t, -f t, and -h t options).

       LC_MESSAGES
                 Determine the locale that should be used to affect the format and contents of diagnostic messages written to standard error.

       NLSPATH   Determine the location of message catalogs for the processing of LC_MESSAGES.

ASYNCHRONOUS EVENTS
       Default.

STDOUT
       The standard output shall be a text file in the following format:

           "%s%s%s", <line number>, <separator>, <input line>

       where <line number> is one of the following numeric formats:

       %6d       When the rn format is used (the default; see -n).

       %06d      When the rz format is used.

       %-6d      When the ln format is used.

       <empty>   When line numbers are suppressed for a portion of the page; the <separator> is also suppressed.

       In the preceding list, the number 6 is the default width; the -w option can change this value.

STDERR
       The standard error shall be used only for diagnostic messages.

OUTPUT FILES
       None.

EXTENDED DESCRIPTION
       None.

EXIT STATUS
       The following exit values shall be returned:

        0    Successful completion.

       >0    An error occurred.

CONSEQUENCES OF ERRORS
       Default.

       The following sections are informative.

APPLICATION USAGE
       In using the -d delim option, care should be taken to escape characters that have special meaning to the command interpreter.

EXAMPLES
       The command:

           nl -v 10 -i 10 -d \!+ file1

       numbers  file1 starting at line number 10 with an increment of 10. The logical page delimiter is "!+".  Note that the '!'  has to be escaped when using csh as a command interpreter because of its
       history substitution syntax.  For ksh and sh the escape is not necessary, but does not do any harm.

RATIONALE
       None.

FUTURE DIRECTIONS
       None.

SEE ALSO
       pr

       The Base Definitions volume of POSIX.1‐2017, Chapter 8, Environment Variables, Section 12.2, Utility Syntax Guidelines

COPYRIGHT
       Portions of this text are reprinted and reproduced in electronic form from IEEE Std 1003.1-2017, Standard for Information Technology -- Portable Operating System Interface (POSIX), The Open Group
       Base  Specifications Issue 7, 2018 Edition, Copyright (C) 2018 by the Institute of Electrical and Electronics Engineers, Inc and The Open Group.  In the event of any discrepancy between this ver‐
       sion and the original IEEE and The Open Group Standard, the original IEEE and The Open Group Standard is the referee document. The original Standard can be  obtained  online  at  http://www.open‐
       group.org/unix/online.html .

       Any  typographical  or  formatting errors that appear in this page are most likely to have been introduced during the conversion of the source files to man page format. To report such errors, see
       https://www.kernel.org/doc/man-pages/reporting_bugs.html .

IEEE/The Open Group                                                                                2017                                                                                             NL(1P)
curs_inopts(3X)                                                                                                                                                                            curs_inopts(3X)

NAME
       cbreak, nocbreak, echo, noecho, halfdelay, intrflush, keypad, meta, nl, nonl, nodelay, notimeout, raw, noraw, qiflush, noqiflush, timeout, wtimeout, typeahead - curses input options

SYNOPSIS
       #include <curses.h>

       int cbreak(void);
       int nocbreak(void);

       int echo(void);
       int noecho(void);

       int intrflush(WINDOW *win, bool bf);
       int keypad(WINDOW *win, bool bf);
       int meta(WINDOW *win, bool bf);
       int nodelay(WINDOW *win, bool bf);
       int notimeout(WINDOW *win, bool bf);

       int nl(void);
       int nonl(void);

       int raw(void);
       int noraw(void);

       void qiflush(void);
       void noqiflush(void);

       int halfdelay(int tenths);
       void timeout(int delay);
       void wtimeout(WINDOW *win, int delay);

       int typeahead(int fd);

DESCRIPTION
       The  ncurses library provides several functions which let an application change the way input from the terminal is handled.  Some are global, applying to all windows.  Others apply only to a spe‐
       cific window.  Window-specific settings are not automatically applied to new or derived windows.  An application must apply these to each window, if the same behavior is needed.

   cbreak/nocbreak
       Normally, the tty driver buffers typed characters until a newline or carriage return is typed.  The cbreak routine disables line buffering and erase/kill character-processing (interrupt and  flow
       control characters are unaffected), making characters typed by the user immediately available to the program.  The nocbreak routine returns the terminal to normal (cooked) mode.

       Initially  the terminal may or may not be in cbreak mode, as the mode is inherited; therefore, a program should call cbreak or nocbreak explicitly.  Most interactive programs using curses set the
       cbreak mode.  Note that cbreak overrides raw.  [See curs_getch(3X) for a discussion of how these routines interact with echo and noecho.]

   echo/noecho
       The echo and noecho routines control whether characters typed by the user are echoed by getch(3X) as they are typed.  Echoing by the tty driver is always disabled, but initially getch is in  echo
       mode,  so  characters  typed are echoed.  Authors of most interactive programs prefer to do their own echoing in a controlled area of the screen, or not to echo at all, so they disable echoing by
       calling noecho.  [See curs_getch(3X) for a discussion of how these routines interact with cbreak and nocbreak.]

   halfdelay
       The halfdelay routine is used for half-delay mode, which is similar to cbreak mode in that characters typed by the user are immediately available to the  program.   However,  after  blocking  for
       tenths tenths of seconds, ERR is returned if nothing has been typed.  The value of tenths must be a number between 1 and 255.  Use nocbreak to leave half-delay mode.

   intrflush
       If the intrflush option is enabled (bf is TRUE), and an interrupt key is pressed on the keyboard (interrupt, break, quit), all output in the tty driver queue will be flushed, giving the effect of
       faster response to the interrupt, but causing curses to have the wrong idea of what is on the screen.  Disabling the option (bf is FALSE) prevents the flush.  The default for the option is inher‐
       ited from the tty driver settings.  The window argument is ignored.

   keypad
       The  keypad option enables the keypad of the user's terminal.  If enabled (bf is TRUE), the user can press a function key (such as an arrow key) and wgetch(3X) returns a single value representing
       the function key, as in KEY_LEFT.  If disabled (bf is FALSE), curses does not treat function keys specially and the program has to interpret the escape sequences itself.  If  the  keypad  in  the
       terminal  can  be  turned on (made to transmit) and off (made to work locally), turning on this option causes the terminal keypad to be turned on when wgetch(3X) is called.  The default value for
       keypad is FALSE.

   meta
       Initially, whether the terminal returns 7 or 8 significant bits on input depends on the control mode of the tty driver [see termios(3)].  To force 8 bits to be returned, invoke  meta(win,  TRUE);
       this is equivalent, under POSIX, to setting the CS8 flag on the terminal.  To force 7 bits to be returned, invoke meta(win, FALSE); this is equivalent, under POSIX, to setting the CS7 flag on the
       terminal.  The window argument, win, is always ignored.  If the terminfo capabilities smm (meta_on) and rmm (meta_off) are defined for the terminal, smm is sent to  the  terminal  when  meta(win,
       TRUE) is called and rmm is sent when meta(win, FALSE) is called.

   nl/nonl
       The nl and nonl routines control whether the underlying display device translates the return key into newline on input.

   nodelay
       The nodelay option causes getch to be a non-blocking call.  If no input is ready, getch returns ERR.  If disabled (bf is FALSE), getch waits until a key is pressed.

   notimeout
       When interpreting an escape sequence, wgetch(3X) sets a timer while waiting for the next character.  If notimeout(win, TRUE) is called, then wgetch does not set a timer.  The purpose of the time‐
       out is to differentiate between sequences received from a function key and those typed by a user.

   raw/noraw
       The raw and noraw routines place the terminal into or out of raw mode.  Raw mode is similar to cbreak mode, in that characters typed are immediately passed through to the user program.  The  dif‐
       ferences  are  that in raw mode, the interrupt, quit, suspend, and flow control characters are all passed through uninterpreted, instead of generating a signal.  The behavior of the BREAK key de‐
       pends on other bits in the tty driver that are not set by curses.

   qiflush/noqiflush
       When the noqiflush routine is used, normal flush of input and output queues associated with the INTR, QUIT and SUSP characters will not be done [see termios(3)].   When  qiflush  is  called,  the
       queues  will  be flushed when these control characters are read.  You may want to call noqiflush in a signal handler if you want output to continue as though the interrupt had not occurred, after
       the handler exits.

   timeout/wtimeout
       The timeout and wtimeout routines set blocking or non-blocking read for a given window.  If delay is negative, blocking read is used (i.e., waits indefinitely for input).  If delay is zero,  then
       non-blocking  read  is  used  (i.e.,  read returns ERR if no input is waiting).  If delay is positive, then read blocks for delay milliseconds, and returns ERR if there is still no input.  Hence,
       these routines provide the same functionality as nodelay, plus the additional capability of being able to block for only delay milliseconds (where delay is positive).

   typeahead
       The curses library does “line-breakout optimization” by looking for typeahead periodically while updating the screen.  If input is found, and it is coming from a tty, the current update is  post‐
       poned  until  refresh(3X)  or  doupdate  is called again.  This allows faster response to commands typed in advance.  Normally, the input FILE pointer passed to newterm, or stdin in the case that
       initscr was used, will be used to do this typeahead checking.  The typeahead routine specifies that the file descriptor fd is to be used to check for typeahead instead.  If fd is -1, then no  ty‐
       peahead checking is done.

RETURN VALUE
       All routines that return an integer return ERR upon failure and OK (SVr4 specifies only “an integer value other than ERR”) upon successful completion, unless otherwise noted in the preceding rou‐
       tine descriptions.

       X/Open does not define any error conditions.  In this implementation, functions with a window parameter will return an error if it is null.  Any function will also return an error if the terminal
       was not initialized.  Also,

              halfdelay
                   returns an error if its parameter is outside the range 1..255.

PORTABILITY
       These functions are described in the XSI Curses standard, Issue 4.

       The ncurses library obeys the XPG4 standard and the historical practice of the AT&T curses implementations, in that the echo bit is cleared when curses initializes the terminal state.  BSD curses
       differed from this slightly; it left the echo bit on at initialization, but the BSD raw call turned it off as a side-effect.  For best portability, set echo or noecho explicitly just  after  ini‐
       tialization, even if your program remains in cooked mode.

       The  XSI  Curses  standard is ambiguous on the question of whether raw should disable the CRLF translations controlled by nl and nonl.  BSD curses did turn off these translations; AT&T curses (at
       least as late as SVr1) did not.  We chose to do so, on the theory that a programmer requesting raw input wants a clean (ideally 8-bit clean) connection that the operating system will not alter.

       When keypad is first enabled, ncurses loads the key-definitions for the current terminal description.  If the terminal description includes extended string capabilities, e.g., from using  the  -x
       option of tic, then ncurses also defines keys for the capabilities whose names begin with “k”.  The corresponding keycodes are generated and (depending on previous loads of terminal descriptions)
       may differ from one execution of a program to the next.  The generated keycodes are recognized by the keyname function (which will then return a name beginning with “k” denoting the terminfo  ca‐
       pability name rather than “K”, used for curses key-names).  On the other hand, an application can use define_key to establish a specific keycode for a given string.  This makes it possible for an
       application to check for an extended capability's presence with tigetstr, and reassign the keycode to match its own needs.

       Low-level applications can use tigetstr to obtain the definition of any particular string capability.  Higher-level applications which use the curses wgetch and similar functions to  return  key‐
       codes  rely  upon the order in which the strings are loaded.  If more than one key definition has the same string value, then wgetch can return only one keycode.  Most curses implementations (in‐
       cluding ncurses) load key definitions in the order defined by the array of string capability names.  The last key to be loaded determines the keycode which will be returned.  In ncurses, you  may
       also  have  extended  capabilities  interpreted as key definitions.  These are loaded after the predefined keys, and if a capability's value is the same as a previously-loaded key definition, the
       later definition is the one used.

NOTES
       Note that echo, noecho, halfdelay, intrflush, meta, nl, nonl, nodelay, notimeout, noqiflush, qiflush, timeout, and wtimeout may be macros.

       The noraw and nocbreak calls follow historical practice in that they attempt to restore to normal (“cooked”) mode from raw and cbreak modes respectively.   Mixing  raw/noraw  and  cbreak/nocbreak
       calls leads to tty driver control states that are hard to predict or understand; it is not recommended.

SEE ALSO
       curses(3X), curs_getch(3X), curs_initscr(3X), curs_util(3X), define_key(3X), termios(3)

                                                                                                                                                                                           curs_inopts(3X)
