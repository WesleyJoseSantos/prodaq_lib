/**
 * @file main.c
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-02-15
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "unity.h"
#include "hardware_tests.h"
#include "protocol_tests.h"
#include "device_tests.h"
#include "prodaq_tests.h"

void setUp(void) {}

void tearDown(void) {}

int main(void)
{
    UNITY_BEGIN();

    // Hardware tests
    RUN_TEST(uart_config_from_json_test);
    RUN_TEST(uart_config_to_json_test);
    RUN_TEST(ip_config_from_json_test);
    RUN_TEST(ip_config_to_json_test);
    RUN_TEST(ethernet_config_from_json_test);
    RUN_TEST(ethernet_config_to_json_test);
    RUN_TEST(wifi_config_from_json_test);
    RUN_TEST(wifi_config_to_json_test);
    RUN_TEST(hardware_config_wifi_type_from_json_test);
    RUN_TEST(hardware_config_ethernet_type_from_json_test);
    RUN_TEST(hardware_config_uart_type_from_json_test);
    RUN_TEST(hardware_config_wifi_type_to_json_test);
    RUN_TEST(hardware_config_ethernet_type_to_json_test);
    RUN_TEST(hardware_config_uart_type_to_json_test);
    RUN_TEST(hardware_message_wifi_type_from_json_test);
    RUN_TEST(hardware_message_ethernet_type_from_json_test);
    RUN_TEST(hardware_message_uart_type_from_json_test);
    RUN_TEST(hardware_message_wifi_type_to_json_test);
    RUN_TEST(hardware_message_ethernet_type_to_json_test);
    RUN_TEST(hardware_message_uart_type_to_json_test);

    // Protocol tests
    RUN_TEST(ntp_config_from_json_test);
    RUN_TEST(ntp_config_to_json_test);
    RUN_TEST(http_auth_config_from_json_test);
    RUN_TEST(http_auth_config_to_json_test);
    RUN_TEST(http_config_from_json_test);
    RUN_TEST(http_config_to_json_test);
    RUN_TEST(mqtt_config_from_json_test);
    RUN_TEST(mqtt_config_to_json_test);
    RUN_TEST(protocol_config_http_type_from_json_test);
    RUN_TEST(protocol_config_ntp_type_from_json_test);
    RUN_TEST(protocol_config_mqtt_type_from_json_test);
    RUN_TEST(protocol_config_http_type_to_json_test);
    RUN_TEST(protocol_config_ntp_type_to_json_test);
    RUN_TEST(protocol_config_mqtt_type_to_json_test);
    RUN_TEST(protocol_message_http_type_from_json_test);
    RUN_TEST(protocol_message_ntp_type_from_json_test);
    RUN_TEST(protocol_message_mqtt_type_from_json_test);
    RUN_TEST(protocol_message_http_type_to_json_test);
    RUN_TEST(protocol_message_ntp_type_to_json_test);
    RUN_TEST(protocol_message_mqtt_type_to_json_test);

    // Device tests
    RUN_TEST(sensor_config_from_json_test);
    RUN_TEST(sensor_config_to_json_test);
    RUN_TEST(device_config_sensor_type_from_json_test);
    RUN_TEST(device_config_sensor_type_to_json_test);
    RUN_TEST(device_message_sensor_type_from_json_test);
    RUN_TEST(device_message_sensor_type_to_json_test);

    // ProDAQ tests
    RUN_TEST(prodaq_fm_save_test);
    RUN_TEST(prodaq_fm_load_test);
    RUN_TEST(message_data_hardware_type_from_json_test);
    RUN_TEST(message_data_hardware_type_to_json_test);
    RUN_TEST(message_data_protocol_type_from_json_test);
    RUN_TEST(message_data_protocol_type_to_json_test);
    RUN_TEST(message_data_device_type_from_json_test);
    RUN_TEST(message_data_device_type_to_json_test);
    RUN_TEST(message_data_request_type_from_json_test);
    RUN_TEST(message_data_request_type_to_json_test);
    RUN_TEST(message_data_response_type_from_json_test);
    RUN_TEST(message_data_response_type_to_json_test);
    RUN_TEST(request_message_from_json_test);
    RUN_TEST(request_message_to_json_test);
    RUN_TEST(response_message_from_json_test);
    RUN_TEST(response_message_to_json_test);
    RUN_TEST(message_wifi_from_json_test);
    RUN_TEST(message_wifi_to_json_test);
    RUN_TEST(message_ethernet_from_json_test);
    RUN_TEST(message_ethernet_to_json_test);
    RUN_TEST(message_uart_from_json_test);
    RUN_TEST(message_uart_to_json_test);
    RUN_TEST(message_ntp_from_json_test);
    RUN_TEST(message_ntp_to_json_test);
    RUN_TEST(message_http_from_json_test);
    RUN_TEST(message_http_to_json_test);
    RUN_TEST(message_mqtt_from_json_test);
    RUN_TEST(message_mqtt_to_json_test);
    RUN_TEST(message_request_from_json_test);
    RUN_TEST(message_request_to_json_test);
    RUN_TEST(message_response_from_json_test);
    RUN_TEST(message_response_to_json_test);

    UNITY_END();
    return 0;
}
