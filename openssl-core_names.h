OPENSSL-CORE_NAMES.H(7ssl)                                                                        OpenSSL                                                                       OPENSSL-CORE_NAMES.H(7ssl)

NAME
       openssl/core_names.h - OpenSSL provider parameter names

SYNOPSIS
        #include <openssl/core_names.h>

DESCRIPTION
       The <openssl/core_names.h> header defines a multitude of macros for OSSL_PARAM(3) names, algorithm names and other known names used with OpenSSL's providers, made available for practical purposes
       only.

       Existing names are further described in the manuals for OpenSSL's providers (see "SEE ALSO") and the manuals for each algorithm they provide (listed in those provider manuals).

SEE ALSO
       OSSL_PROVIDER-default(7), OSSL_PROVIDER-FIPS(7), OSSL_PROVIDER-legacy(7)

HISTORY
       The macros described here were added in OpenSSL 3.0.

CAVEATS
       This header file does not constitute a general registry of names.  Providers that implement new algorithms are to be responsible for their own parameter names.

       However, authors of provider that implement their own variants of algorithms that OpenSSL providers support will want to pay attention to the names provided in this header to work in a compatible
       manner.

COPYRIGHT
       Copyright 2020 The OpenSSL Project Authors. All Rights Reserved.

       Licensed under the Apache License 2.0 (the "License").  You may not use this file except in compliance with the License.  You can obtain a copy in the file LICENSE in the source distribution or
       at <https://www.openssl.org/source/license.html>.

3.0.8                                                                                           2023-02-07                                                                      OPENSSL-CORE_NAMES.H(7ssl)
