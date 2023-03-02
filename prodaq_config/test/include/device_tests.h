/**
 * @file device_tests.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-02-16
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef __DEVICE_TESTS__H__
#define __DEVICE_TESTS__H__

void sensor_config_from_json_test(void);
void sensor_config_to_json_test(void);

void gateway_config_from_json_test(void);
void gateway_config_to_json_test(void);

void datalogger_config_from_json_test(void);
void datalogger_config_to_json_test(void);

void device_config_sensor_type_from_json_test(void);
void device_config_sensor_type_to_json_test(void);

void device_message_sensor_type_from_json_test(void);
void device_message_sensor_type_to_json_test(void);

void device_message_gateway_type_from_json_test(void);
void device_message_gateway_type_to_json_test(void);

void device_message_datalogger_type_from_json_test(void);
void device_message_datalogger_type_to_json_test(void);

#endif  //!__DEVICE_TESTS__H__