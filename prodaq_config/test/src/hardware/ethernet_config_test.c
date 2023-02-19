/**
 * @file hardware_ethernet.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-02-14
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "ethernet_config.h"
#include "hardware_mocks.h"
#include "json.h"
#include "unity.h"

void ethernet_config_from_json_test(void)
{
    // Arrange
    cJSON *json = json_read_file(MOCK_ETHERNET_CONFIG_JSON);
    ethernet_config_t expected = { 0 };
    ethernet_config_t actual = { 0 };
    expected = (ethernet_config_t) MOCK_ETHERNET_CONFIG;

    // Act
    prodaq_err_t err = ethernet_config_from_json(json, &actual);

    // Assert
    TEST_ASSERT_EQUAL(PRODAQ_OK, err);
    TEST_ASSERT_EQUAL_MEMORY(&expected, &actual, sizeof(ethernet_config_t));
}

void ethernet_config_to_json_test(void)
{
    // Arrange
    cJSON *json = cJSON_CreateObject();
    ethernet_config_t expected = { 0 };
    ethernet_config_t actual = { 0 };
    expected = (ethernet_config_t) MOCK_ETHERNET_CONFIG;

    // Act
    prodaq_err_t err1 = ethernet_config_to_json(&expected, json);
    prodaq_err_t err2 = ethernet_config_from_json(json, &actual);

    // Assert
    TEST_ASSERT_EQUAL(PRODAQ_OK, err1);
    TEST_ASSERT_EQUAL(PRODAQ_OK, err2);
    TEST_ASSERT_EQUAL_MEMORY(&expected, &actual, sizeof(ethernet_config_t));

    cJSON_Delete(json);
}
