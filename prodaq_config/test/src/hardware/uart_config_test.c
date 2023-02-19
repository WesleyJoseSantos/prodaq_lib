/**
 * @file hardware_uart.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-02-14
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "uart_config.h"
#include "hardware_mocks.h"
#include "json.h"
#include "unity.h"

void uart_config_from_json_test(void)
{
    // Arrange
    cJSON *json = json_read_file(MOCK_UART_CONFIG_JSON);
    uart_config_t expected = {0};
    uart_config_t actual = {0};
    expected = (uart_config_t) MOCK_UART_CONFIG;

    uint8_t expected_bytes[sizeof(expected)];
    uint8_t actual_bytes[sizeof(actual)];
    memcpy(&expected_bytes, &expected, sizeof(expected));
    memcpy(&actual_bytes, &actual, sizeof(actual));

    // Act
    prodaq_err_t err = uart_config_from_json(json, &actual);

    // Assert
    TEST_ASSERT_EQUAL(PRODAQ_OK, err);

    memcpy(&expected_bytes, &expected, sizeof(expected));
    memcpy(&actual_bytes, &actual, sizeof(actual));

    TEST_ASSERT_EQUAL_MEMORY(&expected, &actual, sizeof(uart_config_t));
}

void uart_config_to_json_test(void)
{
    // Arrange
    cJSON *json = cJSON_CreateObject();
    uart_config_t expected = {0};
    uart_config_t actual = {0};
    expected = (uart_config_t) MOCK_UART_CONFIG;

    // Act
    prodaq_err_t err1 = uart_config_to_json(&expected, json);
    prodaq_err_t err2 = uart_config_from_json(json, &actual);

    // Assert
    TEST_ASSERT_EQUAL(PRODAQ_OK, err1);
    TEST_ASSERT_EQUAL(PRODAQ_OK, err2);
    TEST_ASSERT_EQUAL_MEMORY(&expected, &actual, sizeof(uart_config_t));

    cJSON_Delete(json);
}
