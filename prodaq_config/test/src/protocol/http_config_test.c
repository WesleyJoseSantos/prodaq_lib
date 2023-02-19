/**
 * @file http_config_test.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-02-16
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "http_config.h"
#include "protocol_mocks.h"
#include "json.h"
#include "unity.h"

void http_config_from_json_test(void)
{
    // Arrange
    cJSON *json = json_read_file(MOCK_HTTP_CONFIG_JSON);
    http_config_t expected = {0};
    http_config_t actual = {0};
    expected = (http_config_t) MOCK_HTTP_CONFIG;

    // Act
    prodaq_err_t err = http_config_from_json(json, &actual);

    // Assert
    TEST_ASSERT_EQUAL(PRODAQ_OK, err);
    TEST_ASSERT_EQUAL_MEMORY(&expected, &actual, sizeof(http_config_t));
}

void http_config_to_json_test(void) {
    // Arrange
    cJSON *json = cJSON_CreateObject();
    http_config_t expected = {0};
    http_config_t actual = {0};
    expected = (http_config_t) MOCK_HTTP_CONFIG;

    // Act
    prodaq_err_t err1 = http_config_to_json(&expected, json);
    prodaq_err_t err2 = http_config_from_json(json, &actual);

    // Assert
    TEST_ASSERT_EQUAL(PRODAQ_OK, err1);
    TEST_ASSERT_EQUAL(PRODAQ_OK, err2);
    TEST_ASSERT_EQUAL_MEMORY(&expected, &actual, sizeof(http_config_t));

    cJSON_Delete(json);
}
