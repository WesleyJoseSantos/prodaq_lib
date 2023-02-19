/**
 * @file prodaq_server.c
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-02-16
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <stdio.h>
#include <string.h>

#include "prodaq_server.h"
#include "prodaq_http.h"
#include "winsock2.h"

#define REQUEST_BUFFER_RX 2048
#define REQUEST_BUFFER_TX 512

typedef struct
{
    char *endpoint;
    SOCKET socket;
    prodaq_err_t (*on_request)(message_t *);
    message_t response;
} prodaq_server_t;

static prodaq_err_t prodaq_server_loop(void);
static prodaq_err_t prodaq_server_send_error(SOCKET *client, prodaq_err_t err, const char *status_code);
static prodaq_err_t prodaq_server_send_message(SOCKET *client, message_t *message, const char *status_code);
static prodaq_err_t prodaq_server_send_response(SOCKET *client, const char *status_code, const char *content_type, char *body);

static prodaq_server_t this;

prodaq_err_t prodaq_server_start(int port, char *endpoint)
{
    WSADATA wsa_data;
    this.endpoint = endpoint;

    int err = WSAStartup(MAKEWORD(2, 2), &wsa_data);
    if (err != 0)
    {
        return PRODAQ_ERR_HTTP_INIT;
    }

    this.socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (this.socket == INVALID_SOCKET)
    {
        WSACleanup();
        return PRODAQ_ERR_HTTP_SOCKET_CREATE;
    }

    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(port);

    err = bind(this.socket, (SOCKADDR *)&server_address, sizeof(server_address));
    if (err == SOCKET_ERROR)
    {
        prodaq_server_stop();
        return PRODAQ_ERR_HTTP_SOCKET_BIND;
    }

    err = listen(this.socket, SOMAXCONN);
    if (err == SOCKET_ERROR)
    {
        prodaq_server_stop();
        return PRODAQ_ERR_HTTP_SOCKET_LISTEN;
    }

    printf("Prodaq HTTP Server Started at %d\n", port);

    prodaq_server_loop();
}

prodaq_err_t prodaq_server_stop(void)
{
    closesocket(this.socket);
    WSACleanup();
}

void prodaq_server_on_request(prodaq_err_t (*callback)(message_t *))
{
    this.on_request = callback;
}

void prodaq_server_set_response(message_t *message)
{
    this.response = *message;
}

static prodaq_err_t prodaq_server_loop(void)
{
    while (1)
    {
        SOCKET client = accept(this.socket, NULL, NULL);
        if (client == INVALID_SOCKET)
        {
            prodaq_server_stop();
            return PRODAQ_ERR_HTTP_CONNECTION_FAIL;
        }

        char request[REQUEST_BUFFER_RX];
        int req_size = recv(client, request, sizeof(request), 0);
        if (req_size == SOCKET_ERROR)
        {
            closesocket(client);
            prodaq_server_stop();
            return PRODAQ_ERR_HTTP_RECEIVE;
        }

        http_request_t req_data;
        prodaq_err_t err = prodaq_http_parse_request(request, &req_data);
        if (err != PRODAQ_OK)
        {
            prodaq_server_send_error(&client, err, HTTP_STATUS_INTERNAL_SERVER_ERROR);
        }

        if (err == PRODAQ_OK && this.on_request != NULL && this.endpoint != NULL)
        {
            if (req_data.method == HTTP_METHOD_POST && strcmp(req_data.url, this.endpoint) == 0)
            {
                cJSON *json = cJSON_Parse(req_data.body);
                message_t message;
                prodaq_err_t err = message_from_json(json, &message);
                if (err == PRODAQ_OK)
                {
                    err = this.on_request(&message);
                    const char *status_code = err == PRODAQ_OK ? HTTP_STATUS_OK : HTTP_STATUS_INTERNAL_SERVER_ERROR;
                    if (this.response.id == MSG_ID_INVALID)
                    {
                        prodaq_server_send_error(&client, err, status_code);
                    }
                    else
                    {
                        prodaq_server_send_message(&client, &this.response, status_code);
                        this.response.id = MSG_ID_INVALID;
                    }
                }
                else
                {
                    prodaq_server_send_error(&client, err, HTTP_STATUS_UNSUPPORTED_MEDIA_TYPE);
                }
            }
            else
            {
                prodaq_server_send_error(&client, PRODAQ_ERR_HTTP_NOT_FOUND, HTTP_STATUS_NOT_FOUND);
            }
        }
        else
        {
            prodaq_server_send_error(&client, PRODAQ_ERR_HTTP_NULL_REQUEST_HANDLER, HTTP_STATUS_INTERNAL_SERVER_ERROR);
        }

        closesocket(client);
    }
}

static prodaq_err_t prodaq_server_send_error(SOCKET *client, prodaq_err_t err, const char *status_code)
{
    message_t message = {0};
    message.id = MSG_ID_RESPONSE;
    message.data.response.err = err;
    prodaq_server_send_message(client, &message, status_code);
}

static prodaq_err_t prodaq_server_send_message(SOCKET *client, message_t *message, const char *status_code)
{
    cJSON *json = cJSON_CreateObject();
    message_to_json(message, json);
    char *body = cJSON_Print(json);
    cJSON_Delete(json);
    prodaq_err_t err = prodaq_server_send_response(client, status_code, HTTP_CONTENT_TYPE_JSON, body);
    cJSON_free(body);
    return err;
}

static prodaq_err_t prodaq_server_send_response(SOCKET *client, const char *status_code, const char *content_type, char *body)
{
    char response[REQUEST_BUFFER_TX];
    size_t len = snprintf(response, sizeof(response), "HTTP/1.1 %s\r\nContent-Type: %s\r\nContent-Length: %d\r\n\r\n%s",
                          status_code,
                          content_type,
                          strlen(body),
                          body);

    int result = send(*client, response, len, 0);
    if (result == SOCKET_ERROR)
    {
        closesocket(*client);
        prodaq_server_stop();
        return PRODAQ_ERR_HTTP_SEND_RESPONSE_FAIL;
    }
    else
    {
        return PRODAQ_OK;
    }
}