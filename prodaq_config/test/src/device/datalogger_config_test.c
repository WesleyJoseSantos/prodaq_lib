/**
 * @file datalogger_config_test.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-02-28
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "device/datalogger_config.h"
#include "device_mocks.h"
#include "json.h"
#include "unity.h"

void datalogger_config_from_json_test(void)
{
    // Arrange
    cJSON *json = json_read_file(MOCK_DATALOGGER_CONFIG_JSON);
    datalogger_config_t expected = { 0 };
    datalogger_config_t actual = { 0 };
    expected = (datalogger_config_t) MOCK_DATALOGGER_CONFIG;

    // Act
    prodaq_err_t err = datalogger_config_from_json(json, &actual);

    // Assert
    TEST_ASSERT_EQUAL(PRODAQ_OK, err);
    TEST_ASSERT_EQUAL_MEMORY(&expected, &actual, sizeof(datalogger_config_t));
}

void datalogger_config_to_json_test(void)
{
    // Arrange
    cJSON *json = cJSON_CreateObject();
    datalogger_config_t expected = { 0 };
    datalogger_config_t actual = { 0 };
    expected = (datalogger_config_t) MOCK_DATALOGGER_CONFIG;

    // Act
    prodaq_err_t err1 = datalogger_config_to_json(&expected, json);
    prodaq_err_t err2 = datalogger_config_from_json(json, &actual);

    // Assert
    TEST_ASSERT_EQUAL(PRODAQ_OK, err1);
    TEST_ASSERT_EQUAL(PRODAQ_OK, err2);
    TEST_ASSERT_EQUAL_MEMORY(&expected, &actual, sizeof(datalogger_config_t));

    cJSON_Delete(json);
}
