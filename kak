KAK(1)                                                                                  BSD General Commands Manual                                                                                 KAK(1)

NAME
     kak — a vim-inspired, selection oriented code editor

SYNOPSIS
     kak [-d] [-n] [-ro] [-c session_id | -s session_id] [-ui ui_type] [-e command] [-E command] [+line[:column] | +:] [file ...]
     kak -f keys [-q] [-i suffix] [file ...]
     kak -p session_id
     kak -l
     kak -clear
     kak -version
     kak -help

DESCRIPTION
     Kakoune is a code editor heavily inspired by vim(1) and vi(1).  As such, most of its commands are similar to vi(1)'s, sharing its “keystrokes as a text editing language” model.

     Kakoune operates in two modes, normal and insertion.  In insertion mode, keys are directly inserted into the current buffer.  In normal mode, keys are used to manipulate the current selection and
     to enter insertion mode.

     Kakoune has a strong focus on interactivity.  Most commands provide immediate and incremental results, while still being competitive in keystroke count with vim.

     Kakoune works on selections, which are oriented, inclusive ranges of characters.  Selections have an anchor and a cursor.  Most commands move both of them except when extending selection, where the
     anchor character stays fixed and the cursor moves around.

     The options are as follows:

     -help   Display a help message and quit.

     -version
             Display Kakoune version and quit.

     -n      Do not load the system's kakrc.  (often, /usr/share/kak/kakrc)

     -l      List existing sessions.

     -d      Run as a headless session (requires -s).

     -e command
             Execute command after the client initialization phase.

     -E command
             Execute command after the server initialization phase.

     -f keys
             Run Kakoune in ‘filter mode’, like sed(1).  For standard input and each file named on the command line, the whole buffer is selected (as with %) then keys are executed.  The filtered ver‐
             sion of standard input is written to standard output.  Any files mentioned on the command line are modified in-place, but if -i is provided then Kakoune makes a backup of the original ver‐
             sion.

     -i suffix
             Backup the files on which a filter is applied, using the given suffix.

     -q      When in ‘filter mode’, don't print any errors

     -p session_id
             Send the commands written on the standard input to session session_id.

     -c session_id
             Connect to the given session session_id.

     -s session_id
             Set the current session name to session_id.

     -ui type
             Select the user interface type, which can be terminal, dummy, or json.

     -clear  Remove sessions that were terminated in an incorrect state (e.g. after a crash).

     -ro     Begin in readonly mode, all the buffers opened will not be written to disk.

     +line[:column] | +:
             Specify a target line and column for the first file.  When the plus sign is followed by only a colon, then the cursor is sent to the last line of the file.

     file ...
             One or more file(s) to edit.

ENVIRONMENT
     KAKOUNE_POSIX_SHELL
             Overrides the POSIX shell used for %sh{...} expansion, which is /bin/sh (sh(1)) if unset.

     KAKOUNE_CONFIG_DIR
             Overrides the location of the directory containing Kakoune user configuration.  If unset, $XDG_CONFIG_HOME/kak is used.

     XDG_CONFIG_HOME
             Path to the user's configuration directory.  If unset, $HOME/.config is used.

     XDG_RUNTIME_DIR
             Path to the user's session's sockets.  If unset, $TMPDIR/kakoune is used.

FILES
     In the paths documented below, <rtdir> refers to the runtime directory, whose value is determined in relation to the path to kak's binary location: <rtdir> = <path_to_kak_binary>/../share/kak.

     If not started with the -n switch, kak will first load <rtdir>/kakrc, which will in turn load the following additional files:

     •   If the $KAKOUNE_CONFIG_DIR/autoload directory exists, recursively load every *.kak file in it, and its sub-directories.

     •   If it does not exist, fall back to the system-wide autoload directory in <rtdir>/autoload, and recursively load all files in a similar way.

     •   <rtdir>/kakrc.local, if it exists; this is a user-defined system-wide configuration.

     •   $KAKOUNE_CONFIG_DIR/kakrc, if it exists; this is the user configuration.

     Consequently, if the $KAKOUNE_CONFIG_DIR/autoload directory exists, only scripts stored within that directory will be loaded — the built-in *.kak files will not be.

     Users who still want the built-in scripts to be loaded along their own can create a symbolic link to <rtdir>/autoload (or to individual scripts in it) in their user-configuration directory:

           ln -s <rtdir>/autoload ${XDG_CONFIG_HOME:-$HOME/.config} /kak/autoload

EXAMPLES
     Edit a file:
             kak /path/to/file

     Edit multiple files (multiple buffers will be created):
             kak ./file1.txt /path/to/file2.c

     Prepend a modeline that sets the tabstop to multiple files:
             kak -f "ggO// kak: tabstop=8<esc>" *.c

SEE ALSO
     For the complete on-line documentation, use the :doc command after starting kak.

     The Kakoune wiki: https://github.com/mawww/kakoune/wiki

     The main Kakoune web site: https://kakoune.org

     vi(1), vim(1), sam(1plan9).

AUTHORS
     Maxime Coste <frrrwww@gmail.com> and many others.

BSD                                                                                            June 15, 2021                                                                                           BSD
