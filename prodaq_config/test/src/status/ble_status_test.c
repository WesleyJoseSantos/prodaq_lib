/**
 * @file ble_status_test.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-03-06
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "status/ble_status.h"
#include "status_mocks.h"
#include "json.h"
#include "unity.h"

void ble_status_from_json_test(void)
{
    // Arrange
    cJSON *json = json_read_file(MOCK_BLE_STATUS_JSON);
    ble_status_t expected = {0};
    ble_status_t actual = {0};
    expected = (ble_status_t) MOCK_BLE_STATUS;

    // Act
    prodaq_err_t err = ble_status_from_json(json, &actual);

    // Assert
    TEST_ASSERT_EQUAL(PRODAQ_OK, err);
    TEST_ASSERT_EQUAL_MEMORY(&expected, &actual, sizeof(ble_status_t));
}

void ble_status_to_json_test(void) {
    // Arrange
    cJSON *json = cJSON_CreateObject();
    ble_status_t expected = {0};
    ble_status_t actual = {0};
    expected = (ble_status_t) MOCK_BLE_STATUS;

    // Act
    prodaq_err_t err1 = ble_status_to_json(&expected, json);
    prodaq_err_t err2 = ble_status_from_json(json, &actual);

    // Assert
    TEST_ASSERT_EQUAL(PRODAQ_OK, err1);
    TEST_ASSERT_EQUAL(PRODAQ_OK, err2);
    TEST_ASSERT_EQUAL_MEMORY(&expected, &actual, sizeof(ble_status_t));

    cJSON_Delete(json);
}
