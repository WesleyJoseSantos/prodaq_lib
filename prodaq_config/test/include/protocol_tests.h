/**
 * @file protocol_tests.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-02-16
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef __PROTOCOL_TESTS__H__
#define __PROTOCOL_TESTS__H__

void ntp_config_from_json_test(void);
void ntp_config_to_json_test(void);

void http_auth_config_from_json_test(void);
void http_auth_config_to_json_test(void);

void http_config_from_json_test(void);
void http_config_to_json_test(void);

void mqtt_config_from_json_test(void);
void mqtt_config_to_json_test(void);

void protocol_config_http_type_from_json_test(void);
void protocol_config_ntp_type_from_json_test(void);
void protocol_config_mqtt_type_from_json_test(void);
void protocol_config_http_type_to_json_test(void);
void protocol_config_ntp_type_to_json_test(void);
void protocol_config_mqtt_type_to_json_test(void);

void protocol_message_http_type_from_json_test(void);
void protocol_message_ntp_type_from_json_test(void);
void protocol_message_mqtt_type_from_json_test(void);
void protocol_message_http_type_to_json_test(void);
void protocol_message_ntp_type_to_json_test(void);
void protocol_message_mqtt_type_to_json_test(void);

#endif  //!__PROTOCOL_TESTS__H__