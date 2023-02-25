/**
 * @file hardware_message.c
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-02-14
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "hardware/hardware_message.h"
#include "hardware_mocks.h"
#include "json.h"
#include "unity.h"

void hardware_message_wifi_type_from_json_test(void)
{
    // Arrange
    cJSON *json = json_read_file(MOCK_WIFI_MESSAGE_DATA_JSON);
    wifi_config_t expected = { 0 };
    hardware_message_t  actual = { 0 };
    expected = (wifi_config_t) MOCK_WIFI_CONFIG;

    // Act
    prodaq_err_t err = hardware_message_from_json(json, &actual);

    // Assert
    TEST_ASSERT_EQUAL(PRODAQ_OK, err);
    TEST_ASSERT_EQUAL_MEMORY(&expected, &actual.config, sizeof(wifi_config_t));
}

void hardware_message_ethernet_type_from_json_test(void)
{
    // Arrange
    cJSON *json = json_read_file(MOCK_ETHERNET_MESSAGE_DATA_JSON);
    ethernet_config_t expected = { 0 };
    hardware_message_t  actual = { 0 };
    expected = (ethernet_config_t) MOCK_ETHERNET_CONFIG;

    // Act
    prodaq_err_t err = hardware_message_from_json(json, &actual);

    // Assert
    TEST_ASSERT_EQUAL(PRODAQ_OK, err);
    TEST_ASSERT_EQUAL_MEMORY(&expected, &actual.config, sizeof(ethernet_config_t));
}

void hardware_message_uart_type_from_json_test(void)
{
    // Arrange
    cJSON *json = json_read_file(MOCK_UART_MESSAGE_DATA_JSON);
    uart_config_t expected = { 0 };
    hardware_message_t  actual = { 0 };
    expected = (uart_config_t) MOCK_UART_CONFIG;

    // Act
    prodaq_err_t err = hardware_message_from_json(json, &actual);

    // Assert
    TEST_ASSERT_EQUAL(PRODAQ_OK, err);
    TEST_ASSERT_EQUAL_MEMORY(&expected, &actual.config, sizeof(uart_config_t));
}

void hardware_message_wifi_type_to_json_test(void)
{
    // Arrange
    cJSON *json = cJSON_CreateObject();
    hardware_message_t expected = {0};
    hardware_message_t actual = {0};
    expected.enabled = true;
    expected.type = HW_INTERFACE_WIFI;
    expected.config.wifi = (wifi_config_t)MOCK_WIFI_CONFIG;

    // Act
    prodaq_err_t err1 = hardware_message_to_json(&expected, json);
    prodaq_err_t err2 = hardware_message_from_json(json, &actual);

    // Assert
    TEST_ASSERT_EQUAL(PRODAQ_OK, err1);
    TEST_ASSERT_EQUAL(PRODAQ_OK, err2);
    TEST_ASSERT_EQUAL_MEMORY(&expected, &actual, sizeof(hardware_message_t));

    cJSON_Delete(json);
}

void hardware_message_ethernet_type_to_json_test(void)
{
    // Arrange
    cJSON *json = cJSON_CreateObject();
    hardware_message_t expected = {0};
    hardware_message_t actual = {0};
    expected.enabled = true;
    expected.type = HW_INTERFACE_ETHERNET;
    expected.config.ethernet = (ethernet_config_t)MOCK_ETHERNET_CONFIG;

    // Act
    prodaq_err_t err1 = hardware_message_to_json(&expected, json);
    prodaq_err_t err2 = hardware_message_from_json(json, &actual);

    // Assert
    TEST_ASSERT_EQUAL(PRODAQ_OK, err1);
    TEST_ASSERT_EQUAL(PRODAQ_OK, err2);
    TEST_ASSERT_EQUAL_MEMORY(&expected, &actual, sizeof(hardware_message_t));

    cJSON_Delete(json);
}

void hardware_message_uart_type_to_json_test(void)
{
    // Arrange
    cJSON *json = cJSON_CreateObject();
    hardware_message_t expected = {0};
    hardware_message_t actual = {0};
    expected.enabled = true;
    expected.type = HW_INTERFACE_UART;
    expected.config.uart = (uart_config_t)MOCK_UART_CONFIG;

    // Act
    prodaq_err_t err1 = hardware_message_to_json(&expected, json);
    prodaq_err_t err2 = hardware_message_from_json(json, &actual);

    // Assert
    TEST_ASSERT_EQUAL(PRODAQ_OK, err1);
    TEST_ASSERT_EQUAL(PRODAQ_OK, err2);
    TEST_ASSERT_EQUAL_MEMORY(&expected, &actual, sizeof(hardware_message_t));

    cJSON_Delete(json);
}
