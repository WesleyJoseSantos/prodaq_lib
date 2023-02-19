/**
 * @file device_config.c
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-02-14
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "device_config.h"
#include "device_mocks.h"
#include "json.h"
#include "unity.h"

void device_config_sensor_type_from_json_test(void)
{
    // Arrange
    cJSON *json = json_read_file(MOCK_SENSOR_CONFIG_JSON);
    sensor_config_t expected = {0};
    device_config_t actual = {0};
    expected = (sensor_config_t)MOCK_SENSOR_CONFIG;

    // Act
    prodaq_err_t err = device_config_from_json(json, &actual, DEVICE_SENSOR);

    // Assert
    TEST_ASSERT_EQUAL(PRODAQ_OK, err);
    TEST_ASSERT_EQUAL_MEMORY(&expected, &actual, sizeof(sensor_config_t));
}

void device_config_sensor_type_to_json_test(void)
{
    // Arrange
    cJSON *json = cJSON_CreateObject();
    device_config_t expected = {0};
    device_config_t actual = {0};
    expected.sensor = (sensor_config_t)MOCK_SENSOR_CONFIG;

    // Act
    prodaq_err_t err1 = device_config_to_json(&expected, json, DEVICE_SENSOR);
    prodaq_err_t err2 = device_config_from_json(json, &actual, DEVICE_SENSOR);

    // Assert
    TEST_ASSERT_EQUAL(PRODAQ_OK, err1);
    TEST_ASSERT_EQUAL(PRODAQ_OK, err2);
    TEST_ASSERT_EQUAL_MEMORY(&expected, &actual, sizeof(device_config_t));

    cJSON_Delete(json);
}
