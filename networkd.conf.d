NETWORKD.CONF(5)                                                                               networkd.conf                                                                              NETWORKD.CONF(5)

NAME
       networkd.conf, networkd.conf.d - Global Network configuration files

SYNOPSIS
       /etc/systemd/networkd.conf

       /etc/systemd/networkd.conf.d/*.conf

       /usr/lib/systemd/networkd.conf.d/*.conf

DESCRIPTION
       These configuration files control global network parameters. Currently the DHCP Unique Identifier (DUID).

CONFIGURATION DIRECTORIES AND PRECEDENCE
       The default configuration is set during compilation, so configuration is only needed when it is necessary to deviate from those defaults. Initially, the main configuration file in /etc/systemd/
       contains commented out entries showing the defaults as a guide to the administrator. Local overrides can be created by editing this file or by creating drop-ins, as described below. Using
       drop-ins for local configuration is recommended over modifications to the main configuration file.

       In addition to the "main" configuration file, drop-in configuration snippets are read from /usr/lib/systemd/*.conf.d/, /usr/local/lib/systemd/*.conf.d/, and /etc/systemd/*.conf.d/. Those drop-ins
       have higher precedence and override the main configuration file. Files in the *.conf.d/ configuration subdirectories are sorted by their filename in lexicographic order, regardless of in which of
       the subdirectories they reside. When multiple files specify the same option, for options which accept just a single value, the entry in the file sorted last takes precedence, and for options
       which accept a list of values, entries are collected as they occur in the sorted files.

       When packages need to customize the configuration, they can install drop-ins under /usr/. Files in /etc/ are reserved for the local administrator, who may use this logic to override the
       configuration files installed by vendor packages. Drop-ins have to be used to override package drop-ins, since the main configuration file has lower precedence. It is recommended to prefix all
       filenames in those subdirectories with a two-digit number and a dash, to simplify the ordering of the files.

       To disable a configuration file supplied by the vendor, the recommended way is to place a symlink to /dev/null in the configuration directory in /etc/, with the same filename as the vendor
       configuration file.

[NETWORK] SECTION OPTIONS
       The following options are available in the [Network] section:

       SpeedMeter=
           Takes a boolean. If set to yes, then systemd-networkd measures the traffic of each interface, and networkctl status INTERFACE shows the measured speed. Defaults to no.

       SpeedMeterIntervalSec=
           Specifies the time interval to calculate the traffic speed of each interface. If SpeedMeter=no, the value is ignored. Defaults to 10sec.

       ManageForeignRoutingPolicyRules=
           A boolean. When true, systemd-networkd will remove rules that are not configured in .network files (except for rules with protocol "kernel"). When false, it will not remove any foreign rules,
           keeping them even if they are not configured in a .network file. Defaults to yes.

       ManageForeignRoutes=
           A boolean. When true, systemd-networkd will remove routes that are not configured in .network files (except for routes with protocol "kernel", "dhcp" when KeepConfiguration= is true or
           "dhcp", and "static" when KeepConfiguration= is true or "static"). When false, it will not remove any foreign routes, keeping them even if they are not configured in a .network file. Defaults
           to yes.

       RouteTable=
           Defines the route table name. Takes a whitespace-separated list of the pairs of route table name and number. The route table name and number in each pair are separated with a colon, i.e.,
           "name:number". The route table name must not be "default", "main", or "local", as these route table names are predefined with route table number 253, 254, and 255, respectively. The route
           table number must be an integer in the range 1...4294967295. This setting can be specified multiple times. If an empty string is specified, then the list specified earlier are cleared.
           Defaults to unset.

[DHCPV4] SECTION OPTIONS
       This section configures the DHCP Unique Identifier (DUID) value used by DHCP protocol. DHCPv4 client protocol sends IAID and DUID to the DHCP server when acquiring a dynamic IPv4 address if
       ClientIdentifier=duid. IAID and DUID allows a DHCP server to uniquely identify the machine and the interface requesting a DHCP IP address. To configure IAID and ClientIdentifier, see
       systemd.network(5).

       The following options are understood:

       DUIDType=
           Specifies how the DUID should be generated. See RFC 3315[1] for a description of all the options.

           The following values are understood:

           vendor
               If "DUIDType=vendor", then the DUID value will be generated using "43793" as the vendor identifier (systemd) and hashed contents of machine-id(5). This is the default if DUIDType= is not
               specified.

           uuid
               If "DUIDType=uuid", and DUIDRawData= is not set, then the product UUID is used as a DUID value. If a system does not have valid product UUID, then an application-specific machine-id(5) is
               used as a DUID value. About the application-specific machine ID, see sd_id128_get_machine_app_specific(3).

           link-layer-time[:TIME], link-layer
               If "link-layer-time" or "link-layer" is specified, then the MAC address of the interface is used as a DUID value. The value "link-layer-time" can take additional time value after a colon,
               e.g.  "link-layer-time:2018-01-23 12:34:56 UTC". The default time value is "2000-01-01 00:00:00 UTC".

           In all cases, DUIDRawData= can be used to override the actual DUID value that is used.

       DUIDRawData=
           Specifies the DHCP DUID value as a single newline-terminated, hexadecimal string, with each byte separated by ":". The DUID that is sent is composed of the DUID type specified by DUIDType=
           and the value configured here.

           The DUID value specified here overrides the DUID that systemd-networkd.service(8) generates from the machine ID. To configure DUID per-network, see systemd.network(5). The configured DHCP
           DUID should conform to the specification in RFC 3315[2], RFC 6355[3]. To configure IAID, see systemd.network(5).

           Example 1. A DUIDType=vendor with a custom value

               DUIDType=vendor
               DUIDRawData=00:00:ab:11:f9:2a:c2:77:29:f9:5c:00

           This specifies a 14 byte DUID, with the type DUID-EN ("00:02"), enterprise number 43793 ("00:00:ab:11"), and identifier value "f9:2a:c2:77:29:f9:5c:00".

[DHCPV6] SECTION OPTIONS
       This section configures the DHCP Unique Identifier (DUID) value used by DHCPv6 protocol. DHCPv6 client protocol sends the DHCP Unique Identifier and the interface Identity Association Identifier
       (IAID) to a DHCPv6 server when acquiring a dynamic IPv6 address. IAID and DUID allows a DHCPv6 server to uniquely identify the machine and the interface requesting a DHCP IP address. To configure
       IAID, see systemd.network(5).

       The following options are understood:

       DUIDType=, DUIDRawData=
           As in the [DHCPv4] section.

SEE ALSO
       systemd(1), systemd.network(5), systemd-networkd.service(8), machine-id(5), sd_id128_get_machine_app_specific(3)

NOTES
        1. RFC 3315
           https://tools.ietf.org/html/rfc3315#section-9

        2. RFC 3315
           http://tools.ietf.org/html/rfc3315#section-9

        3. RFC 6355
           http://tools.ietf.org/html/rfc6355

systemd 253                                                                                                                                                                               NETWORKD.CONF(5)
