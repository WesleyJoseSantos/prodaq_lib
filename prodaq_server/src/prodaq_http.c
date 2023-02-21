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
#include "cJSON.h"

http_method_t prodaq_http_request_get_method(char *request);
prodaq_err_t prodaq_http_request_get_url(char *request, char *buf, size_t len);
prodaq_err_t prodaq_http_request_get_body(char *request, char *buffer, size_t len);
prodaq_err_t prodaq_http_parse_request(char *request_str, http_request_t *request);
prodaq_err_t prodaq_http_send_error(http_server_t *server, void *client, prodaq_err_t err, const char *status_code);
prodaq_err_t prodaq_http_send_message(http_server_t *server, void *client, message_t *message, const char *status_code);

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

prodaq_err_t prodaq_http_request_get_url(char *request, char *buf, size_t len)
{
    const char *first_space = strchr(request, ' ');
    if (!first_space || first_space[1] != '/')
    {
        return PRODAQ_ERR_HTTP_REQUEST_PARSE_FAIL;
    }
    const char *url_start = first_space + 1;

    const char *url_end = strchr(url_start, ' ');
    if (!url_end || url_end[1] != 'H')
    {
        return PRODAQ_ERR_HTTP_REQUEST_PARSE_FAIL;
    }

    size_t url_len = (url_end - url_start) * sizeof(char);

    if (url_len > len)
    {
        return PRODAQ_ERR_BUFFER_OVERFLOW;
    }

    memcpy(buf, url_start, url_len);
    buf[url_len] = '\0';

    return PRODAQ_OK;
}

prodaq_err_t prodaq_http_request_get_body(char *request, char *buffer, size_t len)
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
        return PRODAQ_ERR_HTTP_REQUEST_PARSE_FAIL;
    }

    size_t body_len = strlen(request + pos);
    if (body_len > len)
    {
        return PRODAQ_ERR_BUFFER_OVERFLOW;
    }
    memcpy(buffer, request + pos, body_len);
    buffer[body_len] = '\0';

    return PRODAQ_OK;
}

prodaq_err_t prodaq_http_parse_request(char *request_str, http_request_t *request)
{
    request->method = prodaq_http_request_get_method(request_str);
    PRODAQ_ERROR_RETURN(prodaq_http_request_get_url(request_str, request->url, sizeof(request->url)));
    PRODAQ_ERROR_RETURN(prodaq_http_request_get_body(request_str, request->body, sizeof(request->body)));
    return PRODAQ_OK;
}

prodaq_err_t prodaq_http_process_request(http_server_t *server, char *request, void *client)
{
    http_request_t req_data;
    prodaq_err_t err = prodaq_http_parse_request(request, &req_data);
    if(err != PRODAQ_OK)
    {
        PRODAQ_ERROR_RETURN(prodaq_http_send_error(server, client, err, HTTP_STATUS_INTERNAL_SERVER_ERROR));
    }

    if (err == PRODAQ_OK && server->on_request != NULL && server->endpoint != NULL)
    {
        if (req_data.method == HTTP_METHOD_POST && strcmp(req_data.url, server->endpoint) == 0)
        {
            cJSON *json = cJSON_Parse(req_data.body);
            message_t message;
            prodaq_err_t err = message_from_json(json, &message);
            if (err == PRODAQ_OK)
            {
                err = server->on_request(&message);
                const char *status_code = err == PRODAQ_OK ? HTTP_STATUS_OK : HTTP_STATUS_INTERNAL_SERVER_ERROR;
                if (server->response.id == MSG_ID_INVALID)
                {
                    prodaq_http_send_error(server, client, err, status_code);
                }
                else
                {
                    prodaq_http_send_message(server, client, &server->response, status_code);
                    server->response.id = MSG_ID_INVALID;
                }
            }
            else
            {
                prodaq_http_send_error(server, client, err, HTTP_STATUS_UNSUPPORTED_MEDIA_TYPE);
            }
        }
        else
        {
            prodaq_http_send_error(server, client, PRODAQ_ERR_HTTP_NOT_FOUND, HTTP_STATUS_NOT_FOUND);
        }
    }
    else
    {
        prodaq_http_send_error(server, client, PRODAQ_ERR_HTTP_NULL_REQUEST_HANDLER, HTTP_STATUS_INTERNAL_SERVER_ERROR);
    }

    return err;
}

prodaq_err_t prodaq_http_send_error(http_server_t *server, void *client, prodaq_err_t err, const char *status_code)
{
    message_t message = {0};
    message.id = MSG_ID_RESPONSE;
    message.data.response.err = err;
    sprintf(message.data.response.message, prodaq_err_to_msg[message.data.response.err]);
    return prodaq_http_send_message(server, client, &message, status_code);
}

prodaq_err_t prodaq_http_send_message(http_server_t *server, void *client, message_t *message, const char *status_code)
{
    cJSON *json = cJSON_CreateObject();
    message_to_json(message, json);
    char *body = cJSON_PrintUnformatted(json);
    cJSON_Delete(json);
    prodaq_err_t err = server->send_response(client, status_code, HTTP_CONTENT_TYPE_JSON, body);
    cJSON_free(body);
    return err;
}

int prodaq_http_build_response(const char *status_code, const char *content_type, char *body, char *buf, size_t len)
{
    return snprintf(buf, len, "HTTP/1.1 %s\r\nContent-Type: %s\r\nContent-Length: %d\r\n\r\n%s",
                          status_code,
                          content_type,
                          strlen(body),
                          body);
}