#ifndef AWS_HTTP_IMPL_H
#define AWS_HTTP_IMPL_H

/*
 * Copyright 2010-2018 Amazon.com, Inc. or its affiliates. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License").
 * You may not use this file except in compliance with the License.
 * A copy of the License is located at
 *
 *  http://aws.amazon.com/apache2.0
 *
 * or in the "license" file accompanying this file. This file is distributed
 * on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either
 * express or implied. See the License for the specific language governing
 * permissions and limitations under the License.
 */

#include <aws/http/http.h>

/**
 * Methods that affect internal processing.
 * This is NOT a definitive list of methods.
 */
enum aws_http_method {
    AWS_HTTP_METHOD_UNKNOWN, /* Unrecognized value. */
    AWS_HTTP_METHOD_GET,
    AWS_HTTP_METHOD_HEAD,
    AWS_HTTP_METHOD_CONNECT,
    AWS_HTTP_METHOD_COUNT, /* Number of enums */
};

/**
 * Headers that affect internal processing.
 * This is NOT a definitive list of headers.
 */
enum aws_http_header_name {
    AWS_HTTP_HEADER_UNKNOWN, /* Unrecognized value */

    /* Request pseudo-headers */
    AWS_HTTP_HEADER_METHOD,
    AWS_HTTP_HEADER_SCHEME,
    AWS_HTTP_HEADER_AUTHORITY,
    AWS_HTTP_HEADER_PATH,

    /* Response pseudo-headers */
    AWS_HTTP_HEADER_STATUS,

    /* Regular headers */
    AWS_HTTP_HEADER_CONNECTION,
    AWS_HTTP_HEADER_CONTENT_LENGTH,
    AWS_HTTP_HEADER_EXPECT,
    AWS_HTTP_HEADER_TRANSFER_ENCODING,
    AWS_HTTP_HEADER_COOKIE,
    AWS_HTTP_HEADER_HOST,

    AWS_HTTP_HEADER_COUNT, /* Number of enums */
};

AWS_EXTERN_C_BEGIN

AWS_HTTP_API void aws_http_fatal_assert_library_initialized(void);

AWS_HTTP_API struct aws_byte_cursor aws_http_version_to_str(enum aws_http_version version);

/**
 * Returns appropriate enum, or AWS_HTTP_METHOD_UNKNOWN if no match found.
 * Case-sensitive
 */
AWS_HTTP_API enum aws_http_method aws_http_str_to_method(struct aws_byte_cursor cursor);

/**
 * Returns appropriate enum, or AWS_HTTP_HEADER_UNKNOWN if no match found.
 * Not case-sensitive
 */
AWS_HTTP_API enum aws_http_header_name aws_http_str_to_header_name(struct aws_byte_cursor cursor);

/**
 * Returns appropriate enum, or AWS_HTTP_HEADER_UNKNOWN if no match found.
 * Case-sensitive (ex: "Connection" -> AWS_HTTP_HEADER_UNKNOWN because we looked for "connection").
 */
AWS_HTTP_API enum aws_http_header_name aws_http_lowercase_str_to_header_name(struct aws_byte_cursor cursor);

AWS_EXTERN_C_END

#endif /* AWS_HTTP_IMPL_H */
