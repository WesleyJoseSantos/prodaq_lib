/**
 * @file hardware_ethernet_test.c
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-02-14
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "hardware/ip_config.h"
#include "hardware_mocks.h"
#include "json.h"
#include "unity.h"

void ip_config_from_json_test(void)
{
    // Arrange
    cJSON *json = json_read_file(MOCK_IP_CONFIG_JSON);
    ip_config_t expected = { 0 };
    ip_config_t actual = { 0 };
    expected = (ip_config_t) MOCK_IP_CONFIG;

    // Act
    prodaq_err_t err = ip_config_from_json(json, &actual);

    // Assert
    TEST_ASSERT_EQUAL(PRODAQ_OK, err);
    TEST_ASSERT_EQUAL_MEMORY(&expected, &actual, sizeof(ip_config_t));
}

void ip_config_to_json_test(void) 
{
    // Arrange
    cJSON *json = cJSON_CreateObject();
    ip_config_t expected = { 0 };
    ip_config_t actual = { 0 };
    expected = (ip_config_t) MOCK_IP_CONFIG;

    // Act
    prodaq_err_t err1 = ip_config_to_json(&expected, json);
    prodaq_err_t err2 = ip_config_from_json(json, &actual);

    // Assert
    TEST_ASSERT_EQUAL(PRODAQ_OK, err1);
    TEST_ASSERT_EQUAL(PRODAQ_OK, err2);
    TEST_ASSERT_EQUAL_MEMORY(&expected, &actual, sizeof(ip_config_t));

    cJSON_Delete(json);
}
