/**
 * @file gateway_config_test.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-03-01
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "device/gateway_config.h"
#include "device_mocks.h"
#include "json.h"
#include "unity.h"

void gateway_config_from_json_test(void)
{
    // Arrange
    cJSON *json = json_read_file(MOCK_GATEWAY_CONFIG_JSON);
    gateway_config_t expected = { 0 };
    gateway_config_t actual = { 0 };
    expected = (gateway_config_t) MOCK_GATEWAY_CONFIG;

    // Act
    prodaq_err_t err = gateway_config_from_json(json, &actual);

    // Assert
    TEST_ASSERT_EQUAL(PRODAQ_OK, err);
    TEST_ASSERT_EQUAL_MEMORY(&expected, &actual, sizeof(gateway_config_t));
}

void gateway_config_to_json_test(void)
{
    // Arrange
    cJSON *json = cJSON_CreateObject();
    gateway_config_t expected = { 0 };
    gateway_config_t actual = { 0 };
    expected = (gateway_config_t) MOCK_GATEWAY_CONFIG;

    // Act
    prodaq_err_t err1 = gateway_config_to_json(&expected, json);
    prodaq_err_t err2 = gateway_config_from_json(json, &actual);

    // Assert
    TEST_ASSERT_EQUAL(PRODAQ_OK, err1);
    TEST_ASSERT_EQUAL(PRODAQ_OK, err2);
    TEST_ASSERT_EQUAL_MEMORY(&expected, &actual, sizeof(gateway_config_t));

    cJSON_Delete(json);
}
