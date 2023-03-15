/**
 * @file wifi_status_test.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-03-06
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "network/wifi_status.h"
#include "network_mocks.h"
#include "json.h"
#include "unity.h"

void wifi_status_from_json_test(void)
{
    // Arrange
    cJSON *json = json_read_file(MOCK_WIFI_STATUS_JSON);
    wifi_status_t expected = {0};
    wifi_status_t actual = {0};
    expected = (wifi_status_t) MOCK_WIFI_STATUS;

    // Act
    prodaq_err_t err = wifi_status_from_json(json, &actual);

    // Assert
    TEST_ASSERT_EQUAL(PRODAQ_OK, err);
    TEST_ASSERT_EQUAL_MEMORY(&expected, &actual, sizeof(wifi_status_t));
}

void wifi_status_to_json_test(void) {
    // Arrange
    cJSON *json = cJSON_CreateObject();
    wifi_status_t expected = {0};
    wifi_status_t actual = {0};
    expected = (wifi_status_t) MOCK_WIFI_STATUS;

    // Act
    prodaq_err_t err1 = wifi_status_to_json(&expected, json);
    prodaq_err_t err2 = wifi_status_from_json(json, &actual);

    // Assert
    TEST_ASSERT_EQUAL(PRODAQ_OK, err1);
    TEST_ASSERT_EQUAL(PRODAQ_OK, err2);
    TEST_ASSERT_EQUAL_MEMORY(&expected, &actual, sizeof(wifi_status_t));

    cJSON_Delete(json);
}