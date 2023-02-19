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

#include "prodaq_response.h"
#include "prodaq_mocks.h"
#include "json.h"
#include "unity.h"

void response_message_from_json_test(void)
{
    // Arrange
    cJSON *json = json_read_file(MOCK_RESPONSE_MESSAGE_DATA_JSON);
    response_message_t expected = { 0 };
    response_message_t  actual = { 0 };
    expected = (response_message_t) MOCK_RESPONSE;

    // Act
    prodaq_err_t err = response_message_from_json(json, &actual);

    // Assert
    TEST_ASSERT_EQUAL(PRODAQ_OK, err);
    TEST_ASSERT_EQUAL_MEMORY(&expected, &actual, sizeof(response_message_t));
}

void response_message_to_json_test(void)
{
    // Arrange
    cJSON *json = cJSON_CreateObject();
    response_message_t expected = {0};
    response_message_t actual = {0};
    expected = (response_message_t)MOCK_RESPONSE;

    // Act
    prodaq_err_t err1 = response_message_to_json(&expected, json);
    prodaq_err_t err2 = response_message_from_json(json, &actual);

    // Assert
    TEST_ASSERT_EQUAL(PRODAQ_OK, err1);
    TEST_ASSERT_EQUAL(PRODAQ_OK, err2);
    TEST_ASSERT_EQUAL_MEMORY(&expected, &actual, sizeof(response_message_t));

    cJSON_Delete(json);
}