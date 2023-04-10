OPENSSL-CORE_DISPATCH.H(7ssl)                                                                     OpenSSL                                                                    OPENSSL-CORE_DISPATCH.H(7ssl)

NAME
       openssl/core_dispatch.h - OpenSSL provider dispatch numbers and function types

SYNOPSIS
        #include <openssl/core_dispatch.h>

DESCRIPTION
       The <openssl/core_dispatch.h> header defines all the operation numbers, dispatch numbers and provider interface function types currently available.

       The operation and dispatch numbers are represented with macros, which are named as follows:

       operation numbers
           These macros have the form "OSSL_OP_opname".

       dipatch numbers
           These macros have the form "OSSL_FUNC_opname_funcname", where "opname" is the same as in the macro for the operation this function belongs to.

       With every dispatch number, there is an associated function type.

       For further information, please see the provider(7)

SEE ALSO
       provider(7)

HISTORY
       The types and macros described here were added in OpenSSL 3.0.

COPYRIGHT
       Copyright 2020 The OpenSSL Project Authors. All Rights Reserved.

       Licensed under the Apache License 2.0 (the "License").  You may not use this file except in compliance with the License.  You can obtain a copy in the file LICENSE in the source distribution or
       at <https://www.openssl.org/source/license.html>.

3.0.8                                                                                           2023-02-07                                                                   OPENSSL-CORE_DISPATCH.H(7ssl)
