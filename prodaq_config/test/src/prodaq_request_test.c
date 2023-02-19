/**
 * @file prodaq_response_test.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-02-17
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "prodaq_request.h"
#include "prodaq_mocks.h"
#include "json.h"
#include "unity.h"

void request_message_from_json_test(void)
{
    // Arrange
    cJSON *json = json_read_file(MOCK_REQUEST_MESSAGE_DATA_JSON);
    request_message_t expected = { 0 };
    request_message_t  actual = { 0 };
    expected = (request_message_t) MOCK_REQUEST;

    // Act
    prodaq_err_t err = request_message_from_json(json, &actual);

    // Assert
    TEST_ASSERT_EQUAL(PRODAQ_OK, err);
    TEST_ASSERT_EQUAL_MEMORY(&expected, &actual, sizeof(request_message_t));
}

void request_message_to_json_test(void)
{
    // Arrange
    cJSON *json = cJSON_CreateObject();
    request_message_t expected = {0};
    request_message_t actual = {0};
    expected = (request_message_t) MOCK_REQUEST;

    // Act
    prodaq_err_t err1 = request_message_to_json(&expected, json);
    prodaq_err_t err2 = request_message_from_json(json, &actual);

    // Assert
    TEST_ASSERT_EQUAL(PRODAQ_OK, err1);
    TEST_ASSERT_EQUAL(PRODAQ_OK, err2);
    TEST_ASSERT_EQUAL_MEMORY(&expected, &actual, sizeof(request_message_t));

    cJSON_Delete(json);
}