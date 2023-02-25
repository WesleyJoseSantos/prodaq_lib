/**
 * @file hardware_config.c
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-02-14
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "hardware/hardware_config.h"
#include "hardware_mocks.h"
#include "json.h"
#include "unity.h"

void hardware_config_wifi_type_from_json_test(void)
{
    // Arrange
    cJSON *json = json_read_file(MOCK_WIFI_CONFIG_JSON);
    wifi_config_t expected = {0};
    hardware_config_t actual = {0};
    expected = (wifi_config_t)MOCK_WIFI_CONFIG;

    // Act
    prodaq_err_t err = hardware_config_from_json(json, &actual, HW_INTERFACE_WIFI);

    // Assert
    TEST_ASSERT_EQUAL(PRODAQ_OK, err);
    TEST_ASSERT_EQUAL_MEMORY(&expected, &actual, sizeof(wifi_config_t));
}

void hardware_config_ethernet_type_from_json_test(void)
{
    // Arrange
    cJSON *json = json_read_file(MOCK_ETHERNET_CONFIG_JSON);
    ethernet_config_t expected = {0};
    hardware_config_t actual = {0};
    expected = (ethernet_config_t)MOCK_ETHERNET_CONFIG;

    // Act
    prodaq_err_t err = hardware_config_from_json(json, &actual, HW_INTERFACE_ETHERNET);

    // Assert
    TEST_ASSERT_EQUAL(PRODAQ_OK, err);
    TEST_ASSERT_EQUAL_MEMORY(&expected, &actual, sizeof(ethernet_config_t));
}

void hardware_config_uart_type_from_json_test(void)
{
    // Arrange
    cJSON *json = json_read_file(MOCK_UART_CONFIG_JSON);
    uart_config_t expected = {0};
    hardware_config_t actual = {0};
    expected = (uart_config_t)MOCK_UART_CONFIG;

    // Act
    prodaq_err_t err = hardware_config_from_json(json, &actual, HW_INTERFACE_UART);

    // Assert
    TEST_ASSERT_EQUAL(PRODAQ_OK, err);
    TEST_ASSERT_EQUAL_MEMORY(&expected, &actual, sizeof(uart_config_t));
}

void hardware_config_wifi_type_to_json_test(void)
{
    // Arrange
    cJSON *json = cJSON_CreateObject();
    hardware_config_t expected = {0};
    hardware_config_t actual = {0};
    expected.wifi = (wifi_config_t)MOCK_WIFI_CONFIG;

    // Act
    prodaq_err_t err1 = hardware_config_to_json(&expected, json, HW_INTERFACE_WIFI);
    prodaq_err_t err2 = hardware_config_from_json(json, &actual, HW_INTERFACE_WIFI);

    // Assert
    TEST_ASSERT_EQUAL(PRODAQ_OK, err1);
    TEST_ASSERT_EQUAL(PRODAQ_OK, err2);
    TEST_ASSERT_EQUAL_MEMORY(&expected, &actual, sizeof(hardware_config_t));

    cJSON_Delete(json);
}

void hardware_config_ethernet_type_to_json_test(void)
{
    // Arrange
    cJSON *json = cJSON_CreateObject();
    hardware_config_t expected = {0};
    hardware_config_t actual = {0};
    expected.ethernet = (ethernet_config_t)MOCK_ETHERNET_CONFIG;

    // Act
    prodaq_err_t err1 = hardware_config_to_json(&expected, json, HW_INTERFACE_ETHERNET);
    prodaq_err_t err2 = hardware_config_from_json(json, &actual, HW_INTERFACE_ETHERNET);

    // Assert
    TEST_ASSERT_EQUAL(PRODAQ_OK, err1);
    TEST_ASSERT_EQUAL(PRODAQ_OK, err2);
    TEST_ASSERT_EQUAL_MEMORY(&expected, &actual, sizeof(hardware_config_t));

    cJSON_Delete(json);
}

void hardware_config_uart_type_to_json_test(void)
{
    // Arrange
    cJSON *json = cJSON_CreateObject();
    hardware_config_t expected = {0};
    hardware_config_t actual = {0};
    expected.uart = (uart_config_t)MOCK_UART_CONFIG;

    // Act
    prodaq_err_t err1 = hardware_config_to_json(&expected, json, HW_INTERFACE_UART);
    prodaq_err_t err2 = hardware_config_from_json(json, &actual, HW_INTERFACE_UART);

    // Assert
    TEST_ASSERT_EQUAL(PRODAQ_OK, err1);
    TEST_ASSERT_EQUAL(PRODAQ_OK, err2);
    TEST_ASSERT_EQUAL_MEMORY(&expected, &actual, sizeof(hardware_config_t));

    cJSON_Delete(json);
}
