/**
 * @file device_message.c
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-02-14
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "device/device_message.h"
#include "device_mocks.h"
#include "unity.h"
#include "json.h"

void device_message_sensor_type_from_json_test(void)
{
    // Arrange
    cJSON *json = json_read_file(MOCK_SENSOR_MESSAGE_JSON);
    sensor_config_t expected = { 0 };
    device_message_t  actual = { 0 };
    expected = (sensor_config_t) MOCK_SENSOR_CONFIG;

    // Act
    prodaq_err_t err = device_message_from_json(json, &actual);

    // Assert
    TEST_ASSERT_EQUAL(PRODAQ_OK, err);
    TEST_ASSERT_EQUAL_MEMORY(&expected, &actual.config, sizeof(sensor_config_t));
}

void device_message_sensor_type_to_json_test(void)
{
    // Arrange
    cJSON *json = cJSON_CreateObject();
    device_message_t expected = {0};
    device_message_t actual = {0};
    expected.enabled = true;
    expected.type = DEVICE_SENSOR;
    expected.config.sensor = (sensor_config_t)MOCK_SENSOR_CONFIG;

    // Act
    prodaq_err_t err1 = device_message_to_json(&expected, json);
    prodaq_err_t err2 = device_message_from_json(json, &actual);

    // Assert
    TEST_ASSERT_EQUAL(PRODAQ_OK, err1);
    TEST_ASSERT_EQUAL(PRODAQ_OK, err2);
    TEST_ASSERT_EQUAL_MEMORY(&expected, &actual, sizeof(device_message_t));

    cJSON_Delete(json);
}
