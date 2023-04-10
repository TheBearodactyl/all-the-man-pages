OPENSSL-CORE.H(7ssl)                                                                              OpenSSL                                                                             OPENSSL-CORE.H(7ssl)

NAME
       openssl/core.h - OpenSSL Core types

SYNOPSIS
        #include <openssl/core.h>

DESCRIPTION
       The <openssl/core.h> header defines a number of public types that are used to communicate between the OpenSSL libraries and implementation providers.  These types are designed to minimise the
       need for intimate knowledge of internal structures between the OpenSSL libraries and the providers.

       The types are:

       OSSL_DISPATCH(3)
       OSSL_ITEM(3)
       OSSL_ALGORITHM(3)
       OSSL_PARAM(3)
       OSSL_CALLBACK(3)
       OSSL_PASSPHRASE_CALLBACK(3)

SEE ALSO
       openssl-core_dispatch.h(7)

HISTORY
       The types described here were added in OpenSSL 3.0.

COPYRIGHT
       Copyright 2019-2021 The OpenSSL Project Authors. All Rights Reserved.

       Licensed under the Apache License 2.0 (the "License").  You may not use this file except in compliance with the License.  You can obtain a copy in the file LICENSE in the source distribution or
       at <https://www.openssl.org/source/license.html>.

3.0.8                                                                                           2023-02-07                                                                            OPENSSL-CORE.H(7ssl)
