/**
 * @file protocol_message_test.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-02-16
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "protocol/protocol_message.h"
#include "protocol_mocks.h"
#include "unity.h"
#include "json.h"

void protocol_message_ntp_type_from_json_test(void)
{
    // Arrange
    cJSON *json = json_read_file(MOCK_NTP_MESSAGE_DATA_JSON);
    ntp_config_t expected = { 0 };
    protocol_message_t  actual = { 0 };
    expected = (ntp_config_t) MOCK_NTP_CONFIG;

    // Act
    prodaq_err_t err = protocol_message_from_json(json, &actual);

    // Assert
    TEST_ASSERT_EQUAL(PRODAQ_OK, err);
    TEST_ASSERT_EQUAL_MEMORY(&expected, &actual.config, sizeof(ntp_config_t));
}

void protocol_message_http_type_from_json_test(void)
{
    // Arrange
    cJSON *json = json_read_file(MOCK_HTTP_MESSAGE_DATA_JSON);
    http_config_t expected = { 0 };
    protocol_message_t  actual = { 0 };
    expected = (http_config_t) MOCK_HTTP_CONFIG;

    // Act
    prodaq_err_t err = protocol_message_from_json(json, &actual);

    uint8_t expected_bytes[sizeof(http_config_t)];
    uint8_t actual_bytes[sizeof(http_config_t)];

    memcpy(expected_bytes, &expected, sizeof(http_config_t));
    memcpy(actual_bytes, &actual.config, sizeof(http_config_t));

    // Assert
    TEST_ASSERT_EQUAL(PRODAQ_OK, err);
    TEST_ASSERT_EQUAL_MEMORY(&expected, &actual.config, sizeof(http_config_t));
}

void protocol_message_mqtt_type_from_json_test(void)
{
    // Arrange
    cJSON *json = json_read_file(MOCK_MQTT_MESSAGE_DATA_JSON);
    mqtt_config_t expected = { 0 };
    protocol_message_t  actual = { 0 };
    expected = (mqtt_config_t) MOCK_MQTT_CONFIG;

    // Act
    prodaq_err_t err = protocol_message_from_json(json, &actual);

    // Assert
    TEST_ASSERT_EQUAL(PRODAQ_OK, err);
    TEST_ASSERT_EQUAL_MEMORY(&expected, &actual.config, sizeof(mqtt_config_t));
}

void protocol_message_ntp_type_to_json_test(void)
{
    // Arrange
    cJSON *json = cJSON_CreateObject();
    protocol_message_t expected = {0};
    protocol_message_t actual = {0};
    expected.enabled = true;
    expected.type = PROTOCOL_NTP;
    expected.config.ntp = (ntp_config_t)MOCK_NTP_CONFIG;

    // Act
    prodaq_err_t err1 = protocol_message_to_json(&expected, json);
    prodaq_err_t err2 = protocol_message_from_json(json, &actual);

    // Assert
    TEST_ASSERT_EQUAL(PRODAQ_OK, err1);
    TEST_ASSERT_EQUAL(PRODAQ_OK, err2);
    TEST_ASSERT_EQUAL_MEMORY(&expected, &actual, sizeof(protocol_message_t));

    cJSON_Delete(json);
}

void protocol_message_http_type_to_json_test(void)
{
    // Arrange
    cJSON *json = cJSON_CreateObject();
    protocol_message_t expected = {0};
    protocol_message_t actual = {0};
    expected.enabled = true;
    expected.type = PROTOCOL_HTTP;
    expected.config.http = (http_config_t)MOCK_HTTP_CONFIG;

    // Act
    prodaq_err_t err1 = protocol_message_to_json(&expected, json);
    prodaq_err_t err2 = protocol_message_from_json(json, &actual);

    // Assert
    TEST_ASSERT_EQUAL(PRODAQ_OK, err1);
    TEST_ASSERT_EQUAL(PRODAQ_OK, err2);
    TEST_ASSERT_EQUAL_MEMORY(&expected, &actual, sizeof(protocol_message_t));

    cJSON_Delete(json);
}

void protocol_message_mqtt_type_to_json_test(void)
{
    // Arrange
    cJSON *json = cJSON_CreateObject();
    protocol_message_t expected = {0};
    protocol_message_t actual = {0};
    expected.enabled = true;
    expected.type = PROTOCOL_MQTT;
    expected.config.mqtt = (mqtt_config_t)MOCK_MQTT_CONFIG;

    // Act
    prodaq_err_t err1 = protocol_message_to_json(&expected, json);
    prodaq_err_t err2 = protocol_message_from_json(json, &actual);

    // Assert
    TEST_ASSERT_EQUAL(PRODAQ_OK, err1);
    TEST_ASSERT_EQUAL(PRODAQ_OK, err2);
    TEST_ASSERT_EQUAL_MEMORY(&expected, &actual, sizeof(protocol_message_t));

    cJSON_Delete(json);
}
