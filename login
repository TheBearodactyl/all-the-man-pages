LOGIN(1)                                                                                       User Commands                                                                                      LOGIN(1)

NAME
       login - begin session on the system

SYNOPSIS
       login [-p] [-h host] [-H] [-f username|username]

DESCRIPTION
       login is used when signing onto a system. If no argument is given, login prompts for the username.

       The user is then prompted for a password, where appropriate. Echoing is disabled to prevent revealing the password. Only a number of password failures are permitted before login exits and the
       communications link is severed. See LOGIN_RETRIES in the CONFIG FILE ITEMS section.

       If password aging has been enabled for the account, the user may be prompted for a new password before proceeding. In such case old password must be provided and the new password entered before
       continuing. Please refer to passwd(1) for more information.

       The user and group ID will be set according to their values in the /etc/passwd file. There is one exception if the user ID is zero. In this case, only the primary group ID of the account is set.
       This should allow the system administrator to login even in case of network problems. The environment variable values for $HOME, $USER, $SHELL, $PATH, $LOGNAME, and $MAIL are set according to the
       appropriate fields in the password entry. $PATH defaults to /usr/local/bin:/bin:/usr/bin for normal users, and to /usr/local/sbin:/usr/local/bin:/sbin:/bin:/usr/sbin:/usr/bin for root, if not
       otherwise configured.

       The environment variable $TERM will be preserved, if it exists, else it will be initialized to the terminal type on your tty. Other environment variables are preserved if the -p option is given.

       The environment variables defined by PAM are always preserved.

       Then the user’s shell is started. If no shell is specified for the user in /etc/passwd, then /bin/sh is used. If there is no home directory specified in /etc/passwd, then / is used, followed by
       .hushlogin check as described below.

       If the file .hushlogin exists, then a "quiet" login is performed. This disables the checking of mail and the printing of the last login time and message of the day. Otherwise, if /var/log/lastlog
       exists, the last login time is printed, and the current login is recorded.

OPTIONS
       -p
           Used by getty(8) to tell login to preserve the environment.

       -f
           Used to skip a login authentication. This option is usually used by the getty(8) autologin feature.

       -h
           Used by other servers (such as telnetd(8) to pass the name of the remote host to login so that it can be placed in utmp and wtmp. Only the superuser is allowed use this option.

           Note that the -h option has an impact on the PAM service name. The standard service name is login, but with the -h option, the name is remote. It is necessary to create proper PAM config
           files (for example, /etc/pam.d/login and /etc/pam.d/remote).

       -H
           Used by other servers (for example, telnetd(8)) to tell login that printing the hostname should be suppressed in the login: prompt. See also LOGIN_PLAIN_PROMPT below.

       -h, --help
           Display help text and exit.

       -V, --version
           Print version and exit.

CONFIG FILE ITEMS
       login reads the /etc/login.defs configuration file (see login.defs(5)). Note that the configuration file could be distributed with another package (usually shadow-utils). The following
       configuration items are relevant for login:

       MOTD_FILE (string)
           Specifies a ":" delimited list of "message of the day" files and directories to be displayed upon login. If the specified path is a directory then displays all files with .motd file extension
           in version-sort order from the directory.

           The default value is /usr/share/misc/motd:/run/motd:/etc/motd. If the MOTD_FILE item is empty or a quiet login is enabled, then the message of the day is not displayed. Note that the same
           functionality is also provided by the pam_motd(8) PAM module.

           The directories in the MOTD_FILE are supported since version 2.36.

           Note that login does not implement any filenames overriding behavior like pam_motd (see also MOTD_FIRSTONLY), but all content from all files is displayed. It is recommended to keep extra
           logic in content generators and use /run/motd.d rather than rely on overriding behavior hardcoded in system tools.

       MOTD_FIRSTONLY (boolean)
           Forces login to stop display content specified by MOTD_FILE after the first accessible item in the list. Note that a directory is one item in this case. This option allows login semantics to
           be configured to be more compatible with pam_motd. The default value is no.

       LOGIN_PLAIN_PROMPT (boolean)
           Tell login that printing the hostname should be suppressed in the login: prompt. This is an alternative to the -H command line option. The default value is no.

       LOGIN_TIMEOUT (number)
           Maximum time in seconds for login. The default value is 60.

       LOGIN_RETRIES (number)
           Maximum number of login retries in case of a bad password. The default value is 3.

       LOGIN_KEEP_USERNAME (boolean)
           Tell login to only re-prompt for the password if authentication failed, but the username is valid. The default value is no.

       FAIL_DELAY (number)
           Delay in seconds before being allowed another three tries after a login failure. The default value is 5.

       TTYPERM (string)
           The terminal permissions. The default value is 0600 or 0620 if tty group is used.

       TTYGROUP (string)
           The login tty will be owned by the TTYGROUP. The default value is tty. If the TTYGROUP does not exist, then the ownership of the terminal is set to the user’s primary group.

           The TTYGROUP can be either the name of a group or a numeric group identifier.

       HUSHLOGIN_FILE (string)
           If defined, this file can inhibit all the usual chatter during the login sequence. If a full pathname (for example, /etc/hushlogins) is specified, then hushed mode will be enabled if the
           user’s name or shell are found in the file. If this global hush login file is empty then the hushed mode will be enabled for all users.

           If a full pathname is not specified, then hushed mode will be enabled if the file exists in the user’s home directory.

           The default is to check /etc/hushlogins and if it does not exist then ~/.hushlogin.

           If the HUSHLOGIN_FILE item is empty, then all the checks are disabled.

       DEFAULT_HOME (boolean)
           Indicate if login is allowed if we cannot change directory to the home directory. If set to yes, the user will login in the root (/) directory if it is not possible to change directory to
           their home. The default value is yes.

       LASTLOG_UID_MAX (unsigned number)
           Highest user ID number for which the lastlog entries should be updated. As higher user IDs are usually tracked by remote user identity and authentication services there is no need to create a
           huge sparse lastlog file for them. No LASTLOG_UID_MAX option present in the configuration means that there is no user ID limit for writing lastlog entries. The default value is ULONG_MAX.

       LOG_UNKFAIL_ENAB (boolean)
           Enable display of unknown usernames when login failures are recorded. The default value is no.

           Note that logging unknown usernames may be a security issue if a user enters their password instead of their login name.

       ENV_PATH (string)
           If set, it will be used to define the PATH environment variable when a regular user logs in. The default value is /usr/local/bin:/bin:/usr/bin.

       ENV_ROOTPATH (string), ENV_SUPATH (string)
           If set, it will be used to define the PATH environment variable when the superuser logs in. ENV_ROOTPATH takes precedence. The default value is
           /usr/local/sbin:/usr/local/bin:/sbin:/bin:/usr/sbin:/usr/bin.

FILES
       /var/run/utmp, /var/log/wtmp, /var/log/lastlog, /var/spool/mail/*, /etc/motd, /etc/passwd, /etc/nologin, /etc/pam.d/login, /etc/pam.d/remote, /etc/hushlogins, $HOME/.hushlogin

BUGS
       The undocumented BSD -r option is not supported. This may be required by some rlogind(8) programs.

       A recursive login, as used to be possible in the good old days, no longer works; for most purposes su(1) is a satisfactory substitute. Indeed, for security reasons, login does a vhangup(2) system
       call to remove any possible listening processes on the tty. This is to avoid password sniffing. If one uses the command login, then the surrounding shell gets killed by vhangup(2) because it’s no
       longer the true owner of the tty. This can be avoided by using exec login in a top-level shell or xterm.

AUTHORS
       Derived from BSD login 5.40 (5/9/89) by Michael Glad <glad@daimi.dk> for HP-UX. Ported to Linux 0.12: Peter Orbaek <poe@daimi.aau.dk>. Rewritten to a PAM-only version by Karel Zak
       <kzak@redhat.com>

SEE ALSO
       mail(1), passwd(1), passwd(5), utmp(5), environ(7), getty(8), init(8), lastlog(8), shutdown(8)

REPORTING BUGS
       For bug reports, use the issue tracker at https://github.com/util-linux/util-linux/issues.

AVAILABILITY
       The login command is part of the util-linux package which can be downloaded from Linux Kernel Archive <https://www.kernel.org/pub/linux/utils/util-linux/>.

util-linux 2.38.1                                                                               2022-05-11                                                                                        LOGIN(1)
login(3)                                                                                 Library Functions Manual                                                                                 login(3)

NAME
       login, logout - write utmp and wtmp entries

LIBRARY
       System utilities library (libutil, -lutil)

SYNOPSIS
       #include <utmp.h>

       void login(const struct utmp *ut);
       int logout(const char *ut_line);

DESCRIPTION
       The utmp file records who is currently using the system.  The wtmp file records all logins and logouts.  See utmp(5).

       The function login() takes the supplied struct utmp, ut, and writes it to both the utmp and the wtmp file.

       The function logout() clears the entry in the utmp file again.

   GNU details
       More precisely, login() takes the argument ut struct, fills the field ut->ut_type (if there is such a field) with the value USER_PROCESS, and fills the field ut->ut_pid (if there is such a field)
       with the process ID of the calling process.  Then it tries to fill the field ut->ut_line.  It takes the first of stdin, stdout, stderr that is a terminal, and stores  the  corresponding  pathname
       minus  a possible leading /dev/ into this field, and then writes the struct to the utmp file.  On the other hand, if no terminal name was found, this field is filled with "???"  and the struct is
       not written to the utmp file.  After this, the struct is written to the wtmp file.

       The logout() function searches the utmp file for an entry matching the ut_line argument.  If a record is found, it is updated by zeroing out the ut_name and ut_host  fields,  updating  the  ut_tv
       timestamp field and setting ut_type (if there is such a field) to DEAD_PROCESS.

RETURN VALUE
       The logout() function returns 1 if the entry was successfully written to the database, or 0 if an error occurred.

FILES
       /var/run/utmp
              user accounting database, configured through _PATH_UTMP in <paths.h>

       /var/log/wtmp
              user accounting log file, configured through _PATH_WTMP in <paths.h>

ATTRIBUTES
       For an explanation of the terms used in this section, see attributes(7).

       ┌──────────────────┬───────────────┬───────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┐
       │Interface         │ Attribute     │ Value                                                                                                                                                         │
       ├──────────────────┼───────────────┼───────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┤
       │login(), logout() │ Thread safety │ MT-Unsafe race:utent sig:ALRM timer                                                                                                                           │
       └──────────────────┴───────────────┴───────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘
       In  the  above  table,  utent in race:utent signifies that if any of the functions setutent(3), getutent(3), or endutent(3) are used in parallel in different threads of a program, then data races
       could occur.  login() and logout() calls those functions, so we use race:utent to remind users.

VERSIONS
       The member ut_user of struct utmp is called ut_name in BSD.  Therefore, ut_name is defined as an alias for ut_user in <utmp.h>.

STANDARDS
       BSD.

SEE ALSO
       getutent(3), utmp(5)

Linux man-pages 6.04                                                                            2023-03-30                                                                                        login(3)
