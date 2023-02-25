/**
 * @file wifi_config_test.c
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-02-14
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "hardware/wifi_config.h"
#include "hardware_mocks.h"
#include "json.h"
#include "unity.h"

void wifi_config_from_json_test(void)
{
    // Arrange
    cJSON *json = json_read_file(MOCK_WIFI_CONFIG_JSON);
    wifi_config_t expected = {0};
    wifi_config_t actual = {0};
    expected = (wifi_config_t) MOCK_WIFI_CONFIG;

    // Act
    prodaq_err_t err = wifi_config_from_json(json, &actual);

    // Assert
    TEST_ASSERT_EQUAL(PRODAQ_OK, err);
    TEST_ASSERT_EQUAL_MEMORY(&expected, &actual, sizeof(wifi_config_t));
}

void wifi_config_to_json_test(void) {
    // Arrange
    cJSON *json = cJSON_CreateObject();
    wifi_config_t expected = {0};
    wifi_config_t actual = {0};
    expected = (wifi_config_t) MOCK_WIFI_CONFIG;

    // Act
    prodaq_err_t err1 = wifi_config_to_json(&expected, json);
    prodaq_err_t err2 = wifi_config_from_json(json, &actual);

    // Assert
    TEST_ASSERT_EQUAL(PRODAQ_OK, err1);
    TEST_ASSERT_EQUAL(PRODAQ_OK, err2);
    TEST_ASSERT_EQUAL_MEMORY(&expected, &actual, sizeof(wifi_config_t));

    cJSON_Delete(json);
}
