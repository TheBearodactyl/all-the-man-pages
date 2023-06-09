ASP(1)                                                                                          asp manual                                                                                          ASP(1)

NAME
       asp - Manage Arch Linux build sources

SYNOPSIS
       asp [options] command [targets...]

DESCRIPTION
       Manage the version-controlled sources for the build scripts used to create Arch Linux packages. This program provides a thin wrapper over the svntogit repositories hosted at
       https://github.com/archlinux. It aims to provide a replacement for abs which favors a sparse checkout.

COMMANDS
       The following commands are understood:

       checkout TARGET...
           Create a new git repository containing the full source and history for each of the given targets. The new repository will pull from the repository in $ASPROOT and must be updated separately
           after using asp update. If a checkout occurs on the same filesystem as $ASPROOT, most of the metadata can be hard linked, making this a relatively cheap copy.

       difflog TARGET
           Show the full revision history of the target, with file diffs.

       disk-usage
           Report the approximate disk usage for locally tracked packages.

       export TARGET...
           Dump the build source files for each target into a directory of the target’s name in $PWD. Targets can be specified simply as package to check out the source files at HEAD, or in
           repository/package format to checkout the source files which were used to push the package which exists in repository.

       gc
           Perform housekeeping procedures on the local repo, optimizing and compacting the repo to free disk space.

       help
           Display the command line usage and exit.

       list-all
           List all known packages in the repositories.

       list-arches TARGET...
           List the architectures the given targets are available for.

       list-local
           List all packages which are tracked locally.

       list-repos TARGET...
           List the repositories the given targets exist in.

       log TARGET
           Show the revision history of the target.

       ls-files TARGET
           List source files for the given target.

       set-git-protocol PROTOCOL
           Set the protocol used to communicate with the remote git repositories. Must be one of git, http, or https.

       shortlog TARGET
           Show a condensed revision history of the target.

       show TARGET [FILE]
           Show the file content of the target, which may be in the format package or repository/package. If an additional file argument is provided, attempt to display that file rather than the
           PKGBUILD. If the repository is not specified, the file will be shown at the most recent revision (which may be newer than what is in the repositories).

       untrack TARGET...
           Remove a remote tracking branch from the local repository. Disk usage for the removed package(s) may not be freed until garbage collection has taken place.

       update [TARGET...]
           For each target, if the package is not known to the local repository, attempt to track it. If the package is tracked, update the package to the newest version. If no targets are provided, all
           locally known packages will be updated.

OPTIONS
       -a architecture
           When relevant, specify an architecture other than that of the current host.

       -h
           Print a short help text and exit.

       -V
           Print a short version string and exit.

ENVIRONMENT
       ASPROOT
           Determines where the metadata is stored for locally tracked packages. Defaults to ${XDG_CACHE_HOME:-$HOME/.cache}/asp.

       ASPCACHE
           Determines where cached data is stored. Defaults to $ASPROOT/cache. Data in this directory can always be safely deleted.

AUTHORS
       Dave Reisner <d@falconindy.com>

  asp v8                                                                                        11/03/2021                                                                                          ASP(1)
