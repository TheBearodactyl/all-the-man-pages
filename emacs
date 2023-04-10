EMACS(1)                                                                                            GNU                                                                                           EMACS(1)

NAME
       emacs - GNU project Emacs editor

SYNOPSIS
       emacs [ command-line switches ] [ files ... ]

DESCRIPTION
       GNU  Emacs  is  a version of Emacs, written by the author of the original (PDP-10) Emacs, Richard Stallman.  The user functionality of GNU Emacs encompasses everything other editors do, and it is
       easily extensible since its editing commands are written in Lisp.

       The primary documentation of GNU Emacs is in the GNU Emacs Manual, which you can read using Info, either from Emacs or as a standalone program.  Please look there for complete and up-to-date doc‐
       umentation.  This man page is updated only when someone volunteers to do so.

       Emacs has an extensive interactive help facility, but the facility assumes that you know how to manipulate Emacs windows and buffers.  CTRL-h or F1 enters the Help facility.  Help Tutorial (CTRL-
       h t) starts an interactive tutorial to quickly teach beginners the fundamentals of Emacs.  Help Apropos (CTRL-h a) helps you find a command with a name matching a given pattern, Help Key  (CTRL-h
       k) describes a given key sequence, and Help Function (CTRL-h f) describes a given Lisp function.

       GNU  Emacs's  many  special packages handle mail reading (RMail) and sending (Mail), outline editing (Outline), compiling (Compile), running subshells within Emacs windows (Shell), running a Lisp
       read-eval-print loop (Lisp-Interaction-Mode), automated psychotherapy (Doctor), and much more.

   Emacs Options
       The following options are of general interest:

              file    Edit file.

              --file=file, --find-file=file, --visit=file
                      The same as specifying file directly as an argument.

              +number Go to the line specified by number (do not insert a space between the "+" sign and the number).  This applies only to the next file specified.

              +line:column
                      Go to the specified line and column.

              --chdir=directory
                      Change to directory.

              -q, --no-init-file
                      Do not load an init file.

              -nl, --no-shared-memory
                      Do not use shared memory.

              --no-site-file
                      Do not load the site-wide startup file.

              -nsl, --no-site-lisp
                      Do not add site-lisp directories to load-path.

              --no-desktop
                      Do not load a saved desktop.

              -Q, --quick
                      Similar to "-q --no-site-file --no-splash".  Also, avoid processing X resources.

              --no-splash
                      Do not display a splash screen during start-up.

              --debug-init
                      Enable Emacs Lisp debugger during the processing of the user init file ~/.emacs.  This is useful for debugging problems in the init file.

              -u user, --user=user
                      Load user's init file.

              -t file, --terminal=file
                      Use specified file as the terminal instead of using stdin/stdout.  This must be the first argument specified in the command line.

              --daemon[=name], --bg-daemon[=name]
                      Start Emacs as a daemon, enabling the Emacs server and disconnecting from the terminal.  You can then use the emacsclient (see emacsclient(1)) command  to  connect  to  the  server
                      (with optional name).

              --fg-daemon[=name]
                      Like "--bg-daemon", but don't disconnect from the terminal.

              --version
                      Display Emacs version information and exit.

              --help  Display this help and exit.

       The following options are Lisp-oriented (these options are processed in the order encountered):

              -f function, --funcall=function
                      Execute the lisp function function.

              -l file, --load=file
                      Load the lisp code in the file file.

              --eval=expr, --execute=expr
                      Evaluate the Lisp expression expr.

       The following options are useful when running Emacs as a batch editor:

              --batch Edit in batch mode.  The editor will send messages to stderr.  You must use -l and -f options to specify files to execute and functions to call.

              --script file
                      Run file as an Emacs Lisp script.

              --insert=file
                      Insert contents of file into the current buffer.

              --kill  Exit Emacs while in batch mode.

              -L dir, --directory=dir
                      Add dir to the list of directories Emacs searches for Lisp files.

   Using Emacs with X
       Emacs  has  been tailored to work well with the X Window System.  If you run Emacs from under X windows, it will create its own X window to display in.  You will probably want to start the editor
       as a background process so that you can continue using your original window.

       Emacs can be started with the following X switches:

              --name=name
                      Specify the name which should be assigned to the initial Emacs window.  This controls looking up X resources as well as the window title.

              --no-x-resources
                      Do not load X resources.

              -T name, --title=name
                      Specify the title for the initial X window.

              -r, -rv, --reverse-video
                      Display the Emacs window in reverse video.

              -fn font, --font=font
                      Set the Emacs window's font to that specified by font.  You will find the various X fonts in the /usr/lib/X11/fonts directory.  Note that Emacs will only accept fixed width  fonts.
                      Under the X11 Release 4 font-naming conventions, any font with the value "m" or "c" in the eleventh field of the font name is a fixed width font.  Furthermore, fonts whose name are
                      of the form widthxheight are generally fixed width, as is the font fixed.  See xlsfonts(1) for more information.

                      When you specify a font, be sure to put a space between the switch and the font name.

              --xrm=resources
                      Set additional X resources.

              --color, --color=mode
                      Override color mode for character terminals; mode defaults to "auto", and can also be "never", "auto", "always", or a mode name like "ansi8".

              -bw pixels, --border-width=pixels
                      Set the Emacs window's border width to the number of pixels specified by pixels.  Defaults to one pixel on each side of the window.

              -ib pixels, --internal-border=pixels
                      Set the window's internal border width to the number of pixels specified by pixels.  Defaults to one pixel of padding on each side of the window.

              -g geometry, --geometry=geometry
                      Set the Emacs window's width, height, and position as specified.  The geometry specification is in the standard X format; see X(7) for more information.  The width and  height  are
                      specified in characters; the default for GUI frames is a width of 80 and a height between 35 and 40, depending on the OS and the window manager.  See the Emacs manual, section "Op‐
                      tions for Window Size and Position", for information on how window sizes interact with selecting or deselecting the tool bar, tab bar and menu bar.

              -lsp pixels, --line-spacing=pixels
                      Additional space to put between lines.

              -vb, --vertical-scroll-bars
                      Enable vertical scrollbars.

              -fh, --fullheight
                      Make the first frame as high as the screen.

              -fs, --fullscreen
                      Make the first frame fullscreen.

              -fw, --fullwidth
                      Make the first frame as wide as the screen.

              -mm, --maximized
                      Maximize the first frame, like "-fw -fh".

              -fg color, --foreground-color=color
                      On color displays, set the color of the text.

                      Use the command M-x list-colors-display for a list of valid color names.

              -bg color, --background-color=color
                      On color displays, set the color of the window's background.

              -bd color, --border-color=color
                      On color displays, set the color of the window's border.

              -cr color, --cursor-color=color
                      On color displays, set the color of the window's text cursor.

              -ms color, --mouse-color=color
                      On color displays, set the color of the window's mouse cursor.

              -d displayname, --display=displayname
                      Create the Emacs window on the display specified by displayname.  Must be the first option specified in the command line.

              -nbi, --no-bitmap-icon
                      Do not use picture of gnu for Emacs icon.

              --iconic
                      Start Emacs in iconified state.

              -nbc, --no-blinking-cursor
                      Disable blinking cursor.

              --parent-id=xid
                      Set parent window.

              -nw, --no-window-system
                      Tell Emacs not to create a graphical frame.  If you use this switch when invoking Emacs from an xterm(1) window, display is done in that window.

              -D, --basic-display
                      This option disables many display features; use it for debugging Emacs.

       You can set X default values for your Emacs windows in your .Xresources file (see xrdb(1)).  Use the following format:

              emacs.keyword:value

       where value specifies the default value of keyword.  Emacs lets you set default values for the following keywords:

              background (class Background)
                      For color displays, sets the window's background color.

              bitmapIcon (class BitmapIcon)
                      If bitmapIcon's value is set to on, the window will iconify into the "kitchen sink."

              borderColor (class BorderColor)
                      For color displays, sets the color of the window's border.

              borderWidth (class BorderWidth)
                      Sets the window's border width in pixels.

              cursorColor (class Foreground)
                      For color displays, sets the color of the window's text cursor.

              cursorBlink (class CursorBlink)
                      Specifies whether to make the cursor blink.  The default is on.  Use off or false to turn cursor blinking off.

              font (class Font)
                      Sets the window's text font.

              foreground (class Foreground)
                      For color displays, sets the window's text color.

              fullscreen (class Fullscreen)
                      The desired fullscreen size.  The value can be one of fullboth, maximized, fullwidth, or fullheight, which correspond to the command-line options "-fs", "-mm",  "-fw",  and  "-fh",
                      respectively.  Note that this applies to the initial frame only.

              geometry (class Geometry)
                      Sets the geometry of the Emacs window (as described above).

              iconName (class Title)
                      Sets the icon name for the Emacs window icon.

              internalBorder (class BorderWidth)
                      Sets the window's internal border width in pixels.

              lineSpacing (class LineSpacing)
                      Additional space ("leading") between lines, in pixels.

              menuBar (class MenuBar)
                      Gives  frames  menu  bars if on; don't have menu bars if off.  See the Emacs manual, sections "Lucid Resources" and "Motif Resources", for how to control the appearance of the menu
                      bar if you have one.

              minibuffer (class Minibuffer)
                      If none, don't make a minibuffer in this frame.  It will use a separate minibuffer frame instead.

              paneFont (class Font)
                      Font name for menu pane titles, in non-toolkit versions of Emacs.

              pointerColor (class Foreground)
                      For color displays, sets the color of the window's mouse cursor.

              privateColormap (class PrivateColormap)
                      If on, use a private color map, in the case where the "default visual" of class PseudoColor and Emacs is using it.

              reverseVideo (class ReverseVideo)
                      If reverseVideo's value is set to on, the window will be displayed in reverse video.

              screenGamma (class ScreenGamma)
                      Gamma correction for colors, equivalent to the frame parameter "screen-gamma".

              scrollBarWidth (class ScrollBarWidth)
                      The scroll bar width in pixels, equivalent to the frame parameter "scroll-bar-width".

              selectionFont (class SelectionFont)
                      Font name for pop-up menu items, in non-toolkit versions of Emacs.  (For toolkit versions, see the Emacs manual, sections "Lucid Resources" and "Motif Resources".)

              selectionTimeout (class SelectionTimeout)
                      Number of milliseconds to wait for a selection reply.  A value of 0 means wait as long as necessary.

              synchronous (class Synchronous)
                      Run Emacs in synchronous mode if on.  Synchronous mode is useful for debugging X problems.

              title (class Title)
                      Sets the title of the Emacs window.

              toolBar (class ToolBar)
                      Number of lines to reserve for the tool bar.

              tabBar (class TabBar)
                      Number of lines to reserve for the tab bar.

              useXIM (class UseXIM)
                      Turns off use of X input methods (XIM) if false or off.

              verticalScrollBars (class ScrollBars)
                      Gives frames scroll bars if on; suppresses scroll bars if off.

              visualClass (class VisualClass)
                      Specify the "visual" that X should use.  This tells X how to handle colors.  The value should start with one of TrueColor, PseudoColor,  DirectColor,  StaticColor,  GrayScale,  and
                      StaticGray, followed by -depth, where depth is the number of color planes.

MANUALS
       You can order printed copies of the GNU Emacs Manual from the Free Software Foundation, which develops GNU software.  See the online store at <https://shop.fsf.org/>.
       Your  local  administrator might also have copies available.  As with all software and publications from FSF, everyone is permitted to make and distribute copies of the Emacs manual.  The Texinfo
       source to the manual is also included in the Emacs source distribution.

FILES
       /usr/local/share/info — files for the Info documentation browser.  The complete text of the Emacs reference manual is included in a convenient tree structured form.  This includes the Emacs  Lisp
       Reference Manual, useful to anyone wishing to write programs in the Emacs Lisp extension language, and the Introduction to Programming in Emacs Lisp.

       /usr/local/share/emacs/$VERSION/lisp — Lisp source files and compiled files that define most editing commands.  Some are preloaded; others are autoloaded from this directory when used.

       /usr/local/libexec/emacs/$VERSION/$ARCH — various programs that are used with GNU Emacs.

       /usr/local/share/emacs/$VERSION/etc — various files of information.

       /usr/local/share/emacs/$VERSION/etc/DOC.* — contains the documentation strings for the Lisp primitives and preloaded Lisp functions of GNU Emacs.  They are stored here to reduce the size of Emacs
       proper.

BUGS
       There is a mailing list, bug-gnu-emacs@gnu.org, for reporting Emacs bugs and fixes.  But before reporting something as a bug, please try to be sure that it really is a bug, not a misunderstanding
       or a deliberate feature.  We ask you to read the section "Reporting Bugs" in the Emacs manual for hints on how and when to report bugs.  Also, include the version number of the Emacs you are run‐
       ning in every bug report that you send in.  Bugs tend actually to be fixed if they can be isolated, so it is in your interest to report them in such a way that they can be easily reproduced.

       Do not expect a personal answer to a bug report.  The purpose of reporting bugs is to get them fixed for everyone in the next release, if possible.  For personal assistance, consult  the  service
       directory at <https://www.fsf.org/resources/service/> for a list of people who offer it.

       Please do not send anything but bug reports to this mailing list.  For other Emacs lists, see <https://savannah.gnu.org/mail/?group=emacs>.

UNRESTRICTIONS
       Emacs is free; anyone may redistribute copies of Emacs to anyone under the terms stated in the GNU General Public License, a copy of which accompanies each copy of Emacs and which also appears in
       the reference manual.

       Copies of Emacs may sometimes be received packaged with distributions of Unix systems, but it is never included in the scope of any license covering those systems.  Such  inclusion  violates  the
       terms on which distribution is permitted.  In fact, the primary purpose of the GNU General Public License is to prohibit anyone from attaching any other restrictions to redistribution of Emacs.

       Richard  Stallman encourages you to improve and extend Emacs, and urges that you contribute your extensions to the GNU library.  Eventually GNU (Gnu's Not Unix) will be a complete replacement for
       Unix.  Everyone will be free to use, copy, study and change the GNU system.

SEE ALSO
       emacsclient(1), etags(1), X(7), xlsfonts(1), xterm(1), xrdb(1)

AUTHORS
       Emacs was written by Richard Stallman and the Free Software Foundation.  For detailed credits and acknowledgments, see the GNU Emacs manual.

COPYING
       Copyright 1995, 1999-2022 Free Software Foundation, Inc.

       Permission is granted to make and distribute verbatim copies of this document provided the copyright notice and this permission notice are preserved on all copies.

       Permission is granted to copy and distribute modified versions of this document under the conditions for verbatim copying, provided that the entire resulting derived work is distributed under the
       terms of a permission notice identical to this one.

       Permission  is  granted  to  copy  and  distribute translations of this document into another language, under the above conditions for modified versions, except that this permission notice may be
       stated in a translation approved by the Free Software Foundation.

GNU Emacs 28.2                                                                                  2021-09-28                                                                                        EMACS(1)
