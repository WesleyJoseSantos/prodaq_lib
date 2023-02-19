/**
 * @file message_data_test.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-02-16
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "prodaq_message_data.h"
#include "hardware_mocks.h"
#include "protocol_mocks.h"
#include "device_mocks.h"
#include "prodaq_mocks.h"
#include "json.h"
#include "unity.h"

void message_data_hardware_type_from_json_test(void)
{
    // Arrange
    cJSON *json = json_read_file(MOCK_WIFI_MESSAGE_DATA_JSON);
    hardware_message_t expected = { 0 };
    message_data_t  actual = { 0 };
    expected.type = HW_INTERFACE_WIFI;
    expected.enabled = true;
    expected.config.wifi = (wifi_config_t) MOCK_WIFI_CONFIG;

    // Act
    prodaq_err_t err = message_data_from_json(json, &actual, MSG_ID_HARDWARE_CONFIG);

    // Assert
    TEST_ASSERT_EQUAL(PRODAQ_OK, err);
    TEST_ASSERT_EQUAL_MEMORY(&expected, &actual.hardware, sizeof(hardware_message_t));
}

void message_data_protocol_type_from_json_test(void)
{
    // Arrange
    cJSON *json = json_read_file(MOCK_MQTT_MESSAGE_DATA_JSON);
    protocol_message_t expected = { 0 };
    message_data_t  actual = { 0 };
    expected.type = PROTOCOL_MQTT;
    expected.enabled = true;
    expected.config.mqtt = (mqtt_config_t) MOCK_MQTT_CONFIG;

    // Act
    prodaq_err_t err = message_data_from_json(json, &actual, MSG_ID_PROTOCOL_CONFIG);

    // Assert
    TEST_ASSERT_EQUAL(PRODAQ_OK, err);
    TEST_ASSERT_EQUAL_MEMORY(&expected, &actual.protocol, sizeof(protocol_message_t));
}

void message_data_device_type_from_json_test(void)
{
    // Arrange
    cJSON *json = json_read_file(MOCK_SENSOR_MESSAGE_JSON);
    device_message_t expected = { 0 };
    message_data_t  actual = { 0 };
    expected.type = DEVICE_SENSOR;
    expected.enabled = true;
    expected.config.sensor = (sensor_config_t) MOCK_SENSOR_CONFIG;

    // Act
    prodaq_err_t err = message_data_from_json(json, &actual, MSG_ID_DEVICE_CONFIG);

    // Assert
    TEST_ASSERT_EQUAL(PRODAQ_OK, err);
    TEST_ASSERT_EQUAL_MEMORY(&expected, &actual.device, sizeof(device_message_t));
}

void message_data_request_type_from_json_test(void)
{
    // Arrange
    cJSON *json = json_read_file(MOCK_REQUEST_MESSAGE_DATA_JSON);
    message_data_t expected = { 0 };
    message_data_t  actual = { 0 };
    expected.request = (request_message_t) MOCK_REQUEST;

    // Act
    prodaq_err_t err = message_data_from_json(json, &actual, MSG_ID_REQUEST);

    // Assert
    TEST_ASSERT_EQUAL(PRODAQ_OK, err);
    TEST_ASSERT_EQUAL_MEMORY(&expected, &actual.request, sizeof(request_message_t));
}

void message_data_response_type_from_json_test(void)
{
    // Arrange
    cJSON *json = json_read_file(MOCK_RESPONSE_MESSAGE_DATA_JSON);
    message_data_t expected = { 0 };
    message_data_t  actual = { 0 };
    expected.response = (response_message_t) MOCK_RESPONSE;

    // Act
    prodaq_err_t err = message_data_from_json(json, &actual, MSG_ID_RESPONSE);

    // Assert
    TEST_ASSERT_EQUAL(PRODAQ_OK, err);
    TEST_ASSERT_EQUAL_MEMORY(&expected, &actual.response, sizeof(response_message_t));
}


void message_data_hardware_type_to_json_test(void)
{
    // Arrange
    cJSON *json = cJSON_CreateObject();
    message_data_t expected = {0};
    message_data_t actual = {0};
    expected.hardware.enabled = true;
    expected.hardware.type = HW_INTERFACE_WIFI;
    expected.hardware.config.wifi = (wifi_config_t)MOCK_WIFI_CONFIG;

    // Act
    prodaq_err_t err1 = message_data_to_json(&expected, json, MSG_ID_HARDWARE_CONFIG);
    prodaq_err_t err2 = message_data_from_json(json, &actual, MSG_ID_HARDWARE_CONFIG);

    // Assert
    TEST_ASSERT_EQUAL(PRODAQ_OK, err1);
    TEST_ASSERT_EQUAL(PRODAQ_OK, err2);
    TEST_ASSERT_EQUAL_MEMORY(&expected, &actual, sizeof(message_data_t));

    cJSON_Delete(json);
}

void message_data_protocol_type_to_json_test(void)
{
    // Arrange
    cJSON *json = cJSON_CreateObject();
    message_data_t expected = {0};
    message_data_t actual = {0};
    expected.protocol.enabled = true;
    expected.protocol.type = PROTOCOL_MQTT;
    expected.protocol.config.mqtt = (mqtt_config_t)MOCK_MQTT_CONFIG;

    // Act
    prodaq_err_t err1 = message_data_to_json(&expected, json, MSG_ID_PROTOCOL_CONFIG);
    prodaq_err_t err2 = message_data_from_json(json, &actual, MSG_ID_PROTOCOL_CONFIG);

    // Assert
    TEST_ASSERT_EQUAL(PRODAQ_OK, err1);
    TEST_ASSERT_EQUAL(PRODAQ_OK, err2);
    TEST_ASSERT_EQUAL_MEMORY(&expected, &actual, sizeof(message_data_t));

    cJSON_Delete(json);
}

void message_data_device_type_to_json_test(void)
{
    // Arrange
    cJSON *json = cJSON_CreateObject();
    message_data_t expected = {0};
    message_data_t actual = {0};
    expected.device.enabled = true;
    expected.device.type = DEVICE_SENSOR;
    expected.device.config.sensor = (sensor_config_t)MOCK_SENSOR_CONFIG;

    // Act
    prodaq_err_t err1 = message_data_to_json(&expected, json, MSG_ID_DEVICE_CONFIG);
    prodaq_err_t err2 = message_data_from_json(json, &actual, MSG_ID_DEVICE_CONFIG);

    // Assert
    TEST_ASSERT_EQUAL(PRODAQ_OK, err1);
    TEST_ASSERT_EQUAL(PRODAQ_OK, err2);
    TEST_ASSERT_EQUAL_MEMORY(&expected, &actual, sizeof(message_data_t));

    cJSON_Delete(json);
}

void message_data_request_type_to_json_test(void)
{
    // Arrange
    cJSON *json = cJSON_CreateObject();
    message_data_t expected = {0};
    message_data_t actual = {0};
    expected.request = (request_message_t) MOCK_REQUEST;

    // Act
    prodaq_err_t err1 = message_data_to_json(&expected, json, MSG_ID_REQUEST);
    prodaq_err_t err2 = message_data_from_json(json, &actual, MSG_ID_REQUEST);

    // Assert
    TEST_ASSERT_EQUAL(PRODAQ_OK, err1);
    TEST_ASSERT_EQUAL(PRODAQ_OK, err2);
    TEST_ASSERT_EQUAL_MEMORY(&expected, &actual, sizeof(message_data_t));

    cJSON_Delete(json);
}

void message_data_response_type_to_json_test(void)
{
    // Arrange
    cJSON *json = cJSON_CreateObject();
    message_data_t expected = {0};
    message_data_t actual = {0};
    expected.response = (response_message_t) MOCK_RESPONSE;

    // Act
    prodaq_err_t err1 = message_data_to_json(&expected, json, MSG_ID_RESPONSE);
    prodaq_err_t err2 = message_data_from_json(json, &actual, MSG_ID_RESPONSE);

    // Assert
    TEST_ASSERT_EQUAL(PRODAQ_OK, err1);
    TEST_ASSERT_EQUAL(PRODAQ_OK, err2);
    TEST_ASSERT_EQUAL_MEMORY(&expected, &actual, sizeof(message_data_t));

    cJSON_Delete(json);
}
