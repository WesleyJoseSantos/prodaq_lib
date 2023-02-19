/**
 * @file prodaq_tests.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-02-16
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef __PRODAQ_TESTS__H__
#define __PRODAQ_TESTS__H__

void prodaq_fm_save_test(void);
void prodaq_fm_load_test(void);

void message_data_hardware_type_from_json_test(void);
void message_data_protocol_type_from_json_test(void);
void message_data_device_type_from_json_test(void);
void message_data_hardware_type_to_json_test(void);
void message_data_protocol_type_to_json_test(void);
void message_data_device_type_to_json_test(void);

void message_wifi_from_json_test(void);
void message_wifi_to_json_test(void);
void message_ethernet_from_json_test(void);
void message_ethernet_to_json_test(void);
void message_uart_from_json_test(void);
void message_uart_to_json_test(void);
void response_message_from_json_test(void);
void response_message_to_json_test(void);

void message_ntp_from_json_test(void);
void message_ntp_to_json_test(void);
void message_http_from_json_test(void);
void message_http_to_json_test(void);
void message_mqtt_from_json_test(void);
void message_mqtt_to_json_test(void);
void message_response_from_json_test(void);
void message_response_to_json_test(void);

#endif  //!__PRODAQ_TESTS__H__