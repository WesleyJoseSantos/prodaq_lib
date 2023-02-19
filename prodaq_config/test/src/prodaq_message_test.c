/**
 * @file prodaq_message_test.c
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-02-17
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "prodaq_message.h"
#include "hardware_mocks.h"
#include "protocol_mocks.h"
#include "device_mocks.h"
#include "prodaq_mocks.h"
#include "json.h"
#include "unity.h"

void message_wifi_from_json_test(void)
{
    // Arrange
    cJSON *json = json_read_file(MOCK_WIFI_MESSAGE_JSON);
    message_t expected = {0};
    message_t actual = {0};
    expected = (message_t) MOCK_WIFI_MESSAGE;

    // Act
    prodaq_err_t err = message_from_json(json, &actual);

    // Assert
    TEST_ASSERT_EQUAL(PRODAQ_OK, err);
    TEST_ASSERT_EQUAL_MEMORY(&expected, &actual, sizeof(message_t));
}

void message_wifi_to_json_test(void)
{
    // Arrange
    cJSON *json = cJSON_CreateObject();
    message_t expected = {0};
    message_t actual = {0};
    expected = (message_t) MOCK_WIFI_MESSAGE;

    // Act
    prodaq_err_t err1 = message_to_json(&expected, json);
    prodaq_err_t err2 = message_from_json(json, &actual);

    // Assert
    TEST_ASSERT_EQUAL(PRODAQ_OK, err1);
    TEST_ASSERT_EQUAL(PRODAQ_OK, err2);
    TEST_ASSERT_EQUAL_MEMORY(&expected, &actual, sizeof(message_t));

    cJSON_Delete(json);
}

void message_ethernet_from_json_test(void)
{
    // Arrange
    cJSON *json = json_read_file(MOCK_ETHERNET_MESSAGE_JSON);
    message_t expected = {0};
    message_t actual = {0};
    expected = (message_t) MOCK_ETHERNET_MESSAGE;

    // Act
    prodaq_err_t err = message_from_json(json, &actual);

    // Assert
    TEST_ASSERT_EQUAL(PRODAQ_OK, err);
    TEST_ASSERT_EQUAL_MEMORY(&expected, &actual, sizeof(message_t));
}

void message_ethernet_to_json_test(void)
{
    // Arrange
    cJSON *json = cJSON_CreateObject();
    message_t expected = {0};
    message_t actual = {0};
    expected = (message_t) MOCK_ETHERNET_MESSAGE;

    // Act
    prodaq_err_t err1 = message_to_json(&expected, json);
    prodaq_err_t err2 = message_from_json(json, &actual);

    // Assert
    TEST_ASSERT_EQUAL(PRODAQ_OK, err1);
    TEST_ASSERT_EQUAL(PRODAQ_OK, err2);
    TEST_ASSERT_EQUAL_MEMORY(&expected, &actual, sizeof(message_t));

    cJSON_Delete(json);
}

void message_uart_from_json_test(void)
{
    // Arrange
    cJSON *json = json_read_file(MOCK_UART_MESSAGE_JSON);
    message_t expected = {0};
    message_t actual = {0};
    expected = (message_t) MOCK_UART_MESSAGE;

    // Act
    prodaq_err_t err = message_from_json(json, &actual);

    // Assert
    TEST_ASSERT_EQUAL(PRODAQ_OK, err);
    TEST_ASSERT_EQUAL_MEMORY(&expected, &actual, sizeof(message_t));
}

void message_uart_to_json_test(void)
{
    // Arrange
    cJSON *json = cJSON_CreateObject();
    message_t expected = {0};
    message_t actual = {0};
    expected = (message_t) MOCK_UART_MESSAGE;

    // Act
    prodaq_err_t err1 = message_to_json(&expected, json);
    prodaq_err_t err2 = message_from_json(json, &actual);

    // Assert
    TEST_ASSERT_EQUAL(PRODAQ_OK, err1);
    TEST_ASSERT_EQUAL(PRODAQ_OK, err2);
    TEST_ASSERT_EQUAL_MEMORY(&expected, &actual, sizeof(message_t));

    cJSON_Delete(json);
}

void message_ntp_from_json_test(void)
{
    // Arrange
    cJSON *json = json_read_file(MOCK_NTP_MESSAGE_JSON);
    message_t expected = {0};
    message_t actual = {0};
    expected = (message_t) MOCK_NTP_MESSAGE;

    // Act
    prodaq_err_t err = message_from_json(json, &actual);

    // Assert
    TEST_ASSERT_EQUAL(PRODAQ_OK, err);
    TEST_ASSERT_EQUAL_MEMORY(&expected, &actual, sizeof(message_t));
}

void message_ntp_to_json_test(void)
{
    // Arrange
    cJSON *json = cJSON_CreateObject();
    message_t expected = {0};
    message_t actual = {0};
    expected = (message_t) MOCK_NTP_MESSAGE;

    // Act
    prodaq_err_t err1 = message_to_json(&expected, json);
    prodaq_err_t err2 = message_from_json(json, &actual);

    // Assert
    TEST_ASSERT_EQUAL(PRODAQ_OK, err1);
    TEST_ASSERT_EQUAL(PRODAQ_OK, err2);
    TEST_ASSERT_EQUAL_MEMORY(&expected, &actual, sizeof(message_t));

    cJSON_Delete(json);
}

void message_http_from_json_test(void)
{
    // Arrange
    cJSON *json = json_read_file(MOCK_HTTP_MESSAGE_JSON);
    message_t expected = {0};
    message_t actual = {0};
    expected = (message_t) MOCK_HTTP_MESSAGE;

    // Act
    prodaq_err_t err = message_from_json(json, &actual);

    // Assert
    TEST_ASSERT_EQUAL(PRODAQ_OK, err);
    TEST_ASSERT_EQUAL_MEMORY(&expected, &actual, sizeof(message_t));
}

void message_http_to_json_test(void)
{
    // Arrange
    cJSON *json = cJSON_CreateObject();
    message_t expected = {0};
    message_t actual = {0};
    expected = (message_t) MOCK_HTTP_MESSAGE;

    // Act
    prodaq_err_t err1 = message_to_json(&expected, json);
    prodaq_err_t err2 = message_from_json(json, &actual);

    // Assert
    TEST_ASSERT_EQUAL(PRODAQ_OK, err1);
    TEST_ASSERT_EQUAL(PRODAQ_OK, err2);
    TEST_ASSERT_EQUAL_MEMORY(&expected, &actual, sizeof(message_t));

    cJSON_Delete(json);
}

void message_mqtt_from_json_test(void)
{
    // Arrange
    cJSON *json = json_read_file(MOCK_MQTT_MESSAGE_JSON);
    message_t expected = {0};
    message_t actual = {0};
    expected = (message_t) MOCK_MQTT_MESSAGE;

    // Act
    prodaq_err_t err = message_from_json(json, &actual);

    // Assert
    TEST_ASSERT_EQUAL(PRODAQ_OK, err);
    TEST_ASSERT_EQUAL_MEMORY(&expected, &actual, sizeof(message_t));
}

void message_mqtt_to_json_test(void)
{
    // Arrange
    cJSON *json = cJSON_CreateObject();
    message_t expected = {0};
    message_t actual = {0};
    expected = (message_t) MOCK_MQTT_MESSAGE;

    // Act
    prodaq_err_t err1 = message_to_json(&expected, json);
    prodaq_err_t err2 = message_from_json(json, &actual);

    // Assert
    TEST_ASSERT_EQUAL(PRODAQ_OK, err1);
    TEST_ASSERT_EQUAL(PRODAQ_OK, err2);
    TEST_ASSERT_EQUAL_MEMORY(&expected, &actual, sizeof(message_t));

    cJSON_Delete(json);
}


void message_request_from_json_test(void)
{
    // Arrange
    cJSON *json = json_read_file(MOCK_REQUEST_MESSAGE_JSON);
    message_t expected = {0};
    message_t actual = {0};
    expected = (message_t) MOCK_REQUEST_MESSAGE;

    // Act
    prodaq_err_t err = message_from_json(json, &actual);

    // Assert
    TEST_ASSERT_EQUAL(PRODAQ_OK, err);
    TEST_ASSERT_EQUAL_MEMORY(&expected, &actual, sizeof(message_t));
}

void message_request_to_json_test(void)
{
    // Arrange
    cJSON *json = cJSON_CreateObject();
    message_t expected = {0};
    message_t actual = {0};
    expected = (message_t) MOCK_REQUEST_MESSAGE;

    // Act
    prodaq_err_t err1 = message_to_json(&expected, json);
    prodaq_err_t err2 = message_from_json(json, &actual);

    // Assert
    TEST_ASSERT_EQUAL(PRODAQ_OK, err1);
    TEST_ASSERT_EQUAL(PRODAQ_OK, err2);
    TEST_ASSERT_EQUAL_MEMORY(&expected, &actual, sizeof(message_t));

    cJSON_Delete(json);
}

void message_response_from_json_test(void)
{
    // Arrange
    cJSON *json = json_read_file(MOCK_RESPONSE_MESSAGE_JSON);
    message_t expected = {0};
    message_t actual = {0};
    expected = (message_t) MOCK_RESPONSE_MESSAGE;

    // Act
    prodaq_err_t err = message_from_json(json, &actual);

    // Assert
    TEST_ASSERT_EQUAL(PRODAQ_OK, err);
    TEST_ASSERT_EQUAL_MEMORY(&expected, &actual, sizeof(message_t));
}

void message_response_to_json_test(void)
{
    // Arrange
    cJSON *json = cJSON_CreateObject();
    message_t expected = {0};
    message_t actual = {0};
    expected = (message_t) MOCK_RESPONSE_MESSAGE;

    // Act
    prodaq_err_t err1 = message_to_json(&expected, json);
    prodaq_err_t err2 = message_from_json(json, &actual);

    // Assert
    TEST_ASSERT_EQUAL(PRODAQ_OK, err1);
    TEST_ASSERT_EQUAL(PRODAQ_OK, err2);
    TEST_ASSERT_EQUAL_MEMORY(&expected, &actual, sizeof(message_t));

    cJSON_Delete(json);
}
