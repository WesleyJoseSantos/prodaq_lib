/**
 * @file tcp_status_test.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-03-06
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "status/tcp_status.h"
#include "status_mocks.h"
#include "json.h"
#include "unity.h"

void tcp_status_from_json_test(void)
{
    // Arrange
    cJSON *json = json_read_file(MOCK_TCP_STATUS_JSON);
    tcp_status_t expected = {0};
    tcp_status_t actual = {0};
    expected = (tcp_status_t) MOCK_TCP_STATUS;

    // Act
    prodaq_err_t err = tcp_status_from_json(json, &actual);

    // Assert
    TEST_ASSERT_EQUAL(PRODAQ_OK, err);
    TEST_ASSERT_EQUAL_MEMORY(&expected, &actual, sizeof(tcp_status_t));
}

void tcp_status_to_json_test(void) {
    // Arrange
    cJSON *json = cJSON_CreateObject();
    tcp_status_t expected = {0};
    tcp_status_t actual = {0};
    expected = (tcp_status_t) MOCK_TCP_STATUS;

    // Act
    prodaq_err_t err1 = tcp_status_to_json(&expected, json);
    prodaq_err_t err2 = tcp_status_from_json(json, &actual);

    // Assert
    TEST_ASSERT_EQUAL(PRODAQ_OK, err1);
    TEST_ASSERT_EQUAL(PRODAQ_OK, err2);
    TEST_ASSERT_EQUAL_MEMORY(&expected, &actual, sizeof(tcp_status_t));

    cJSON_Delete(json);
}