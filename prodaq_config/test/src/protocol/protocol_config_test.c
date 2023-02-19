/**
 * @file protocol_config_test.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-02-16
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "protocol_config.h"
#include "protocol_mocks.h"
#include "json.h"
#include "unity.h"

void protocol_config_ntp_type_from_json_test(void)
{
    // Arrange
    cJSON *json = json_read_file(MOCK_NTP_CONFIG_JSON);
    ntp_config_t expected = {0};
    protocol_config_t actual = {0};
    expected = (ntp_config_t)MOCK_NTP_CONFIG;

    // Act
    prodaq_err_t err = protocol_config_from_json(json, &actual, PROTOCOL_NTP);

    // Assert
    TEST_ASSERT_EQUAL(PRODAQ_OK, err);
    TEST_ASSERT_EQUAL_MEMORY(&expected, &actual, sizeof(ntp_config_t));
}

void protocol_config_http_type_from_json_test(void)
{
    // Arrange
    cJSON *json = json_read_file(MOCK_HTTP_CONFIG_JSON);
    http_config_t expected = {0};
    protocol_config_t actual = {0};
    expected = (http_config_t)MOCK_HTTP_CONFIG;

    // Act
    prodaq_err_t err = protocol_config_from_json(json, &actual, PROTOCOL_HTTP);

    // Assert
    TEST_ASSERT_EQUAL(PRODAQ_OK, err);
    TEST_ASSERT_EQUAL_MEMORY(&expected, &actual, sizeof(http_config_t));
}

void protocol_config_mqtt_type_from_json_test(void)
{
    // Arrange
    cJSON *json = json_read_file(MOCK_MQTT_CONFIG_JSON);
    mqtt_config_t expected = {0};
    protocol_config_t actual = {0};
    expected = (mqtt_config_t)MOCK_MQTT_CONFIG;

    // Act
    prodaq_err_t err = protocol_config_from_json(json, &actual, PROTOCOL_MQTT);

    // Assert
    TEST_ASSERT_EQUAL(PRODAQ_OK, err);
    TEST_ASSERT_EQUAL_MEMORY(&expected, &actual, sizeof(mqtt_config_t));
}

void protocol_config_ntp_type_to_json_test(void)
{
    // Arrange
    cJSON *json = cJSON_CreateObject();
    protocol_config_t expected = {0};
    protocol_config_t actual = {0};
    expected.ntp = (ntp_config_t)MOCK_NTP_CONFIG;

    // Act
    prodaq_err_t err1 = protocol_config_to_json(&expected, json, PROTOCOL_NTP);
    prodaq_err_t err2 = protocol_config_from_json(json, &actual, PROTOCOL_NTP);

    // Assert
    TEST_ASSERT_EQUAL(PRODAQ_OK, err1);
    TEST_ASSERT_EQUAL(PRODAQ_OK, err2);
    TEST_ASSERT_EQUAL_MEMORY(&expected, &actual, sizeof(protocol_config_t));

    cJSON_Delete(json);
}

void protocol_config_http_type_to_json_test(void)
{
    // Arrange
    cJSON *json = cJSON_CreateObject();
    protocol_config_t expected = {0};
    protocol_config_t actual = {0};
    expected.http = (http_config_t)MOCK_HTTP_CONFIG;

    // Act
    prodaq_err_t err1 = protocol_config_to_json(&expected, json, PROTOCOL_HTTP);
    prodaq_err_t err2 = protocol_config_from_json(json, &actual, PROTOCOL_HTTP);

    // Assert
    TEST_ASSERT_EQUAL(PRODAQ_OK, err1);
    TEST_ASSERT_EQUAL(PRODAQ_OK, err2);
    TEST_ASSERT_EQUAL_MEMORY(&expected, &actual, sizeof(protocol_config_t));

    cJSON_Delete(json);
}

void protocol_config_mqtt_type_to_json_test(void)
{
    // Arrange
    cJSON *json = cJSON_CreateObject();
    protocol_config_t expected = {0};
    protocol_config_t actual = {0};
    expected.mqtt = (mqtt_config_t)MOCK_MQTT_CONFIG;

    // Act
    prodaq_err_t err1 = protocol_config_to_json(&expected, json, PROTOCOL_MQTT);
    prodaq_err_t err2 = protocol_config_from_json(json, &actual, PROTOCOL_MQTT);

    // Assert
    TEST_ASSERT_EQUAL(PRODAQ_OK, err1);
    TEST_ASSERT_EQUAL(PRODAQ_OK, err2);
    TEST_ASSERT_EQUAL_MEMORY(&expected, &actual, sizeof(protocol_config_t));

    cJSON_Delete(json);
}
