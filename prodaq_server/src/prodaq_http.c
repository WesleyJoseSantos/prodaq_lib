/**
 * @file prodaq_http.c
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-02-18
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <stdio.h>
#include <string.h>
#include "prodaq_http.h"

http_method_t prodaq_http_request_get_method(char *request)
{
    if (strncmp(request, "GET", 3) == 0)
    {
        return HTTP_METHOD_GET;
    }
    else if (strncmp(request, "POST", 4) == 0)
    {
        return HTTP_METHOD_POST;
    }
    else if (strncmp(request, "PUT", 3) == 0)
    {
        return HTTP_METHOD_PUT;
    }
    else if (strncmp(request, "DELETE", 6) == 0)
    {
        return HTTP_METHOD_DELETE;
    }
    else
    {
        return HTTP_METHOD_UNKNOWN;
    }
}

http_err_t prodaq_http_request_get_url(char *request, char *buf, size_t len)
{
    const char *first_space = strchr(request, ' ');
    if (!first_space || first_space[1] != '/')
    {
        return HTTP_ERR_URL_PARSE_FAIL;
    }
    const char *url_start = first_space + 1;

    const char *url_end = strchr(url_start, ' ');
    if (!url_end || url_end[1] != 'H')
    {
        return HTTP_ERR_URL_PARSE_FAIL;
    }

    size_t url_len = (url_end - url_start) * sizeof(char);

    if (url_len > len)
    {
        return HTTP_ERR_BUFFER_TOO_SMALL;
    }

    memcpy(buf, url_start, url_len);
    buf[url_len] = '\0';

    return HTTP_OK;
}

http_err_t prodaq_http_request_get_body(char *request, char *buffer, size_t len)
{
    size_t pos = strlen(request);
    int crlf_count = 0;

    while (pos >= 3 && crlf_count < 2)
    {
        if (request[pos] == '\n' &&
            request[pos - 1] == '\r' &&
            request[pos - 2] == '\n' &&
            request[pos - 3] == '\r')
        {
            crlf_count = 2;
            pos++;
            break;
        }
        pos--;
    }

    if (crlf_count < 2)
    {
        return HTTP_ERR_BODY_PARSE_FAIL;
    }

    size_t body_len = strlen(request + pos);
    if (body_len > len)
    {
        return HTTP_ERR_BUFFER_TOO_SMALL;
    }
    memcpy(buffer, request + pos, body_len);
    buffer[body_len] = '\0';

    return HTTP_OK;
}

http_err_t prodaq_http_parse_request(char *request_str, http_request_t *request)
{
    request->method = prodaq_http_request_get_method(request_str);

    http_err_t err = prodaq_http_request_get_url(request_str, request->url, sizeof(request->url));
    if (err != HTTP_OK)
    {
        return err;
    }

    err = prodaq_http_request_get_body(request_str, request->body, sizeof(request->body));
    if (err != HTTP_OK)
    {
        return err;
    }

    return HTTP_OK;
}
