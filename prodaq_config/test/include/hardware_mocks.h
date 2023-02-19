/**
 * @file mocks.h
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-02-15
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef __MOCKS__H__
#define __MOCKS__H__

#include <stdio.h>
#include "json.h"

#define HARDWARE_JSON_PATH JSON_PATH "/hardware/"

#define MOCK_IP_CONFIG_JSON HARDWARE_JSON_PATH "ip_config.json"
#define MOCK_WIFI_CONFIG_JSON HARDWARE_JSON_PATH "wifi_config.json"
#define MOCK_ETHERNET_CONFIG_JSON HARDWARE_JSON_PATH "ethernet_config.json"
#define MOCK_UART_CONFIG_JSON HARDWARE_JSON_PATH "uart_config.json"

#define MOCK_WIFI_MESSAGE_DATA_JSON HARDWARE_JSON_PATH "wifi_message_data.json"
#define MOCK_ETHERNET_MESSAGE_DATA_JSON HARDWARE_JSON_PATH "ethernet_message_data.json"
#define MOCK_UART_MESSAGE_DATA_JSON HARDWARE_JSON_PATH "uart_message_data.json"

#define MOCK_WIFI_MESSAGE_JSON HARDWARE_JSON_PATH "wifi_message.json"
#define MOCK_ETHERNET_MESSAGE_JSON HARDWARE_JSON_PATH "ethernet_message.json"
#define MOCK_UART_MESSAGE_JSON HARDWARE_JSON_PATH "uart_message.json"

#define MOCK_IP_CONFIG               \
    {                                \
        .address = {1, 2, 3, 4},     \
        .mask = {255, 255, 255, 0},  \
        .gateway = {192, 168, 0, 1}, \
        .dns = { 8,                  \
                 8,                  \
                 8,                  \
                 8 }                 \
    }

#define MOCK_UART_CONFIG          \
    {                             \
        .baud_rate = 115200,      \
        .data_bits = 8,           \
        .parity = 0,              \
        .stop_bits = 1,           \
        .flow_ctrl = 0,           \
        .rx_flow_ctrl_thresh = 10 \
    }

#define MOCK_ETHERNET_CONFIG \
    {                        \
        .ip = MOCK_IP_CONFIG \
    }

#define MOCK_WIFI_CONFIG                                                           \
    {                                                                              \
        .ssid = "my_wifi_ssid",                                                    \
        .password = "my_wifi_password",                                            \
        .ip = MOCK_IP_CONFIG,                                                      \
        .identity = "my_enterprise_identity", .username = "my_enterprise_username" \
    }

#define MOCK_WIFI_MESSAGE                      \
    {                                          \
        .id = MSG_ID_HARDWARE_CONFIG,          \
        .data = {                              \
            .hardware = {                      \
                .type = HW_INTERFACE_WIFI,     \
                .enabled = true,               \
                .config = {                    \
                    .wifi = MOCK_WIFI_CONFIG}} \
        }                                      \
    }

#define MOCK_ETHERNET_MESSAGE                          \
    {                                                  \
        .id = MSG_ID_HARDWARE_CONFIG,                  \
        .data = {                                      \
            .hardware = {                              \
                .type = HW_INTERFACE_ETHERNET,         \
                .enabled = true,                       \
                .config = {                            \
                    .ethernet = MOCK_ETHERNET_CONFIG}} \
        }                                              \
    }

#define MOCK_UART_MESSAGE                      \
    {                                          \
        .id = MSG_ID_HARDWARE_CONFIG,          \
        .data = {                              \
            .hardware = {                      \
                .type = HW_INTERFACE_UART,     \
                .enabled = true,               \
                .config = {                    \
                    .uart = MOCK_UART_CONFIG}} \
        }                                      \
    }

#endif //!__MOCKS__H__