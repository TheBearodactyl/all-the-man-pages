curs_move(3X)                                                                                                                                                                                curs_move(3X)

NAME
       move, wmove - move curses window cursor

SYNOPSIS
       #include <curses.h>

       int move(int y, int x);
       int wmove(WINDOW *win, int y, int x);

DESCRIPTION
       These routines move the cursor associated with the window to line y and column x.  This routine does not move the physical cursor of the terminal until refresh(3X) is called.  The position speci‐
       fied is relative to the upper left-hand corner of the window, which is (0,0).

RETURN VALUE
       These routines return ERR upon failure and OK (SVr4 specifies only "an integer value other than ERR") upon successful completion.

       Specifically, they return an error if the window pointer is null, or if the position is outside the window.

NOTES
       Note that move may be a macro.

PORTABILITY
       These functions are described in the XSI Curses standard, Issue 4.

SEE ALSO
       curses(3X), curs_refresh(3X)

                                                                                                                                                                                             curs_move(3X)
