/**
 * @file sensor_config_test.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-02-16
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "device/sensor_config.h"
#include "device_mocks.h"
#include "json.h"
#include "unity.h"

void sensor_config_from_json_test(void)
{
    // Arrange
    cJSON *json = json_read_file(MOCK_SENSOR_CONFIG_JSON);
    sensor_config_t expected = { 0 };
    sensor_config_t actual = { 0 };
    expected = (sensor_config_t) MOCK_SENSOR_CONFIG;

    // Act
    prodaq_err_t err = sensor_config_from_json(json, &actual);

    // Assert
    TEST_ASSERT_EQUAL(PRODAQ_OK, err);
    TEST_ASSERT_EQUAL_MEMORY(&expected, &actual, sizeof(sensor_config_t));
}

void sensor_config_to_json_test(void)
{
    // Arrange
    cJSON *json = cJSON_CreateObject();
    sensor_config_t expected = { 0 };
    sensor_config_t actual = { 0 };
    expected = (sensor_config_t) MOCK_SENSOR_CONFIG;

    // Act
    prodaq_err_t err1 = sensor_config_to_json(&expected, json);
    prodaq_err_t err2 = sensor_config_from_json(json, &actual);

    // Assert
    TEST_ASSERT_EQUAL(PRODAQ_OK, err1);
    TEST_ASSERT_EQUAL(PRODAQ_OK, err2);
    TEST_ASSERT_EQUAL_MEMORY(&expected, &actual, sizeof(sensor_config_t));

    cJSON_Delete(json);
}
