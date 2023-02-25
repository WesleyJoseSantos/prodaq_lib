/**
 * @file ProdaqServer.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-02-20
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "prodaq_config.h"
#include "prodaq_server.h"
#include "prodaq_http.h"

#ifdef __ARDUINO__

#ifdef ESP8266
#include <ESP8266WiFi.h>
#elif defined(ESP32)
#include <WiFi.h>
#else
#error "Board not defined"
#endif

WiFiServer server = WiFiServer(80);
http_server_t http;

static prodaq_err_t prodaq_server_handle_client(Client &client);
static prodaq_err_t prodaq_server_send_response(void *client, const char *status_code, const char *content_type, char *body);

prodaq_err_t prodaq_server_start(int port, char *endpoint)
{
    http.endpoint = endpoint;
    http.send_response = prodaq_server_send_response;

    server.begin(port);
    Serial.print("Prodaq HTTP Server Started at ");
    Serial.println(port);

    return PRODAQ_OK;
}

prodaq_err_t prodaq_server_task(void)
{
    WiFiClient client = server.accept();
    if (client)
    {
        PRODAQ_ERROR_RETURN(prodaq_server_handle_client(client));
    }
    return PRODAQ_OK;
}

prodaq_err_t prodaq_server_stop(void)
{
    server.stop();
    return PRODAQ_OK;
}

void prodaq_server_on_request(prodaq_err_t (*callback)(message_t *))
{
    http.on_request = callback;
}

void prodaq_server_set_response(message_t *message)
{
    http.response = *message;
}

static prodaq_err_t prodaq_server_handle_client(Client &client)
{
    char *req_buf = (char*)calloc(PRODAQ_SERVER_BUFFER_RX, sizeof(char));

    while (!client.available())
    {
        delay(1);
    }
    
    if(client.available() > PRODAQ_SERVER_BUFFER_RX) 
    {
        PRODAQ_ERROR_CHECK(prodaq_http_send_error(&http, &client, PRODAQ_ERR_BUFFER_OVERFLOW, HTTP_STATUS_INTERNAL_SERVER_ERROR));
    }
    else
    {
        client.readBytes(req_buf, client.available());
        Serial.printf("request: %s\n", req_buf);
        PRODAQ_ERROR_CHECK(prodaq_http_process_request(&http, req_buf, &client));
    }

    free(req_buf);
    client.stop();
    return PRODAQ_OK;
}

static prodaq_err_t prodaq_server_send_response(void *client_ptr, const char *status_code, const char *content_type, char *body)
{
    Client *client = (Client*)client_ptr;

    client->printf("HTTP/1.1 %s\n", status_code);
    client->printf("Content-type:%s\n", content_type);
    client->printf("Content-Length: %d\n", strlen(body));
    client->println();
    client->printf("%s", body);
    
    return PRODAQ_OK;
}

#endif // PRODAQ_TARGET_INO
