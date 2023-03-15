/**
 * @file network_mocks.h
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-03-06
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef __NETWORK_MOCKS__H__
#define __NETWORK_MOCKS__H__

#include <stdio.h>
#include "json.h"

#define MOCK_NETWORK_JSON_PATH JSON_PATH "/network/"

#define MOCK_BLE_STATUS_JSON MOCK_NETWORK_JSON_PATH "ble_status.json"
#define MOCK_BLE_STATUS_MESSAGE_JSON MOCK_NETWORK_JSON_PATH "ble_status_message.json"
#define MOCK_BLE_STATUS_MESSAGE_DATA_JSON MOCK_NETWORK_JSON_PATH "ble_status_message_data.json"

#define MOCK_NETWORK_STATUS_JSON MOCK_NETWORK_JSON_PATH "network_status.json"
#define MOCK_NETWORK_STATUS_MESSAGE_JSON MOCK_NETWORK_JSON_PATH "network_status_message.json"
#define MOCK_NETWORK_STATUS_MESSAGE_DATA_JSON MOCK_NETWORK_JSON_PATH "network_status_message_data.json"

#define MOCK_TCP_STATUS_JSON MOCK_NETWORK_JSON_PATH "tcp_status.json"
#define MOCK_TCP_STATUS_MESSAGE_JSON MOCK_NETWORK_JSON_PATH "tcp_status_message.json"
#define MOCK_TCP_STATUS_MESSAGE_DATA_JSON MOCK_NETWORK_JSON_PATH "tcp_status_message_data.json"

#define MOCK_WIFI_STATUS_JSON MOCK_NETWORK_JSON_PATH "wifi_status.json"
#define MOCK_WIFI_STATUS_MESSAGE_JSON MOCK_NETWORK_JSON_PATH "wifi_status_message.json"
#define MOCK_WIFI_STATUS_MESSAGE_DATA_JSON MOCK_NETWORK_JSON_PATH "wifi_status_message_data.json"

#define MOCK_BLE_STATUS ((ble_status_t){.rssi = -50, .connected = true})

#define MOCK_TCP_STATUS ((tcp_status_t){.ip = {192, 168, 1, 1}, .connected = true})

#define MOCK_WIFI_STATUS ((wifi_status_t) { .tcp = MOCK_TCP_STATUS, .ssid = "my_wifi_network", .rssi = -70 })

#define MOCK_NETWORK_STATUS ((network_status_t) { .ethernet = MOCK_TCP_STATUS, .wifi = MOCK_WIFI_STATUS, .ble = MOCK_BLE_STATUS, .mqtt = true, .ntp = false })

#endif //!__NETWORK_MOCKS__H__