/**
 * @file protocol_mocks.h
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-02-16
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef __PROTOCOL_MOCKS__H__
#define __PROTOCOL_MOCKS__H__

#include <stdio.h>
#include "json.h"

#define MOCK_PROTOCOL_JSON_PATH JSON_PATH "/protocol/"

#define MOCK_HTTP_AUTH_CONFIG_JSON MOCK_PROTOCOL_JSON_PATH "http_auth_config.json"
#define MOCK_HTTP_CONFIG_JSON MOCK_PROTOCOL_JSON_PATH "http_config.json"
#define MOCK_HTTP_MESSAGE_JSON MOCK_PROTOCOL_JSON_PATH "http_message.json"
#define MOCK_HTTP_MESSAGE_DATA_JSON MOCK_PROTOCOL_JSON_PATH "http_message_data.json"

#define MOCK_MQTT_CONFIG_JSON MOCK_PROTOCOL_JSON_PATH "mqtt_config.json"
#define MOCK_MQTT_MESSAGE_JSON MOCK_PROTOCOL_JSON_PATH "mqtt_message.json"
#define MOCK_MQTT_MESSAGE_DATA_JSON MOCK_PROTOCOL_JSON_PATH "mqtt_message_data.json"

#define MOCK_NTP_CONFIG_JSON MOCK_PROTOCOL_JSON_PATH "ntp_config.json"
#define MOCK_NTP_MESSAGE_JSON MOCK_PROTOCOL_JSON_PATH "ntp_message.json"
#define MOCK_NTP_MESSAGE_DATA_JSON MOCK_PROTOCOL_JSON_PATH "ntp_message_data.json"

#define MOCK_HTTP_AUTH_CONFIG      \
    {                              \
        .auth_type = 2,            \
        .username = "user123",     \
        .password = "password123", \
        .token = NULL              \
    }

#define MOCK_HTTP_CONFIG                 \
    {                                    \
        .port = 80,                      \
        .url = "http://example.com/api", \
        .cert_file = "cert.pem",         \
        .transport_type = 1,             \
        .auth = {                        \
            .auth_type = 2,              \
            .username = "user123",       \
            .password = "password123",   \
            .token = NULL                \
        }                                \
    }

#define MOCK_MQTT_CONFIG            \
    {                               \
        .host = "mqtt.example.com", \
        .port = 8883,               \
        .username = "user123",      \
        .password = "password123",  \
        .transport = 1,             \
        .qos = 0,                   \
        .rx_topic = "rx_topic",     \
        .tx_topic = "tx_topic"      \
    }

#define MOCK_NTP_CONFIG                \
    {                                  \
        .op_mode = 1,                  \
        .sync_interval = 3600,         \
        .sync_mode = 1,                \
        .server1 = "ntp1.example.com", \
        .server2 = "ntp2.example.com", \
        .server3 = "ntp3.example.com"  \
    }

#define MOCK_HTTP_MESSAGE                      \
    {                                          \
        .id = MSG_ID_PROTOCOL_CONFIG,          \
        .data = {                              \
            .protocol = {                      \
                .type = PROTOCOL_HTTP,         \
                .enabled = true,               \
                .config = {                    \
                    .http = MOCK_HTTP_CONFIG}} \
        }                                      \
    }

#define MOCK_MQTT_MESSAGE                      \
    {                                          \
        .id = MSG_ID_PROTOCOL_CONFIG,          \
        .data = {                              \
            .protocol = {                      \
                .type = PROTOCOL_MQTT,         \
                .enabled = true,               \
                .config = {                    \
                    .mqtt = MOCK_MQTT_CONFIG}} \
        }                                      \
    }

#define MOCK_NTP_MESSAGE                     \
    {                                        \
        .id = MSG_ID_PROTOCOL_CONFIG,        \
        .data = {                            \
            .protocol = {                    \
                .type = PROTOCOL_NTP,        \
                .enabled = true,             \
                .config = {                  \
                    .ntp = MOCK_NTP_CONFIG}} \
        }                                    \
    }

#endif //!__PROTOCOL_MOCKS__H__