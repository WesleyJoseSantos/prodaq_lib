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

#include "prodaq_config.h"

#ifdef  __WINDOWS__

#include <stdio.h>
#include <string.h>

#include "prodaq_server.h"
#include "prodaq_http.h"
#include "winsock2.h"

typedef struct
{
    SOCKET socket;
    http_server_t server;
} prodaq_server_t;

static prodaq_err_t prodaq_server_send_response(void *client, const char *status_code, const char *content_type, char *body);

static prodaq_server_t this;

prodaq_err_t prodaq_server_start(int port, char *endpoint)
{
    WSADATA wsa_data;

    this.server.endpoint = endpoint;
    this.server.send_response = prodaq_server_send_response;

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

    return PRODAQ_OK;
}

prodaq_err_t prodaq_server_task(void)
{
    SOCKET client = accept(this.socket, NULL, NULL);
    if (client == INVALID_SOCKET)
    {
        prodaq_server_stop();
        return PRODAQ_ERR_HTTP_CONNECTION_FAIL;
    }

    char request[PRODAQ_SERVER_BUFFER_RX + 1] = { 0 };
    int req_size = recv(client, request, sizeof(request), 0);
    if (req_size == SOCKET_ERROR)
    {
        closesocket(client);
        prodaq_server_stop();
        return PRODAQ_ERR_HTTP_RECEIVE;
    }

    if (req_size > PRODAQ_SERVER_BUFFER_RX)
    {
        while (req_size > PRODAQ_SERVER_BUFFER_RX)
        {
            req_size = recv(client, request, sizeof(request), 0);
        }
        PRODAQ_ERROR_CHECK(prodaq_http_send_error(&this.server, &client, PRODAQ_ERR_BUFFER_OVERFLOW, HTTP_STATUS_INTERNAL_SERVER_ERROR));
    }
    else
    {
        PRODAQ_ERROR_CHECK(prodaq_http_process_request(&this.server, request, &client));
    }

    closesocket(client);    
    return PRODAQ_OK;
}

prodaq_err_t prodaq_server_stop(void)
{
    closesocket(this.socket);
    WSACleanup();
    return PRODAQ_OK;
}

void prodaq_server_on_request(prodaq_err_t (*callback)(message_t *))
{
    this.server.on_request = callback;
}

void prodaq_server_set_response(message_t *message)
{
    this.server.response = *message;
}

static prodaq_err_t prodaq_server_send_response(void *client, const char *status_code, const char *content_type, char *body)
{
    SOCKET *client_socket = (SOCKET*)client;
    char response[PRODAQ_SERVER_BUFFER_TX] = { 0 };
    size_t len = prodaq_http_build_response(status_code, content_type, body, response, sizeof(response));

    int result = send(*client_socket, response, len, 0);
    if (result == SOCKET_ERROR)
    {
        return PRODAQ_ERR_HTTP_SEND_RESPONSE_FAIL;
    }
    else
    {
        return PRODAQ_OK;
    }
}

#endif  //PRODAQ_TARGET_WIN