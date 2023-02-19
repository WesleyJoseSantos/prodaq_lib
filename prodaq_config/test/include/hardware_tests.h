/**
 * @file hardware_test.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-02-15
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef __HARDWARE_TEST__H__
#define __HARDWARE_TEST__H__

void ethernet_config_from_json_test(void);
void ethernet_config_to_json_test(void);

void ip_config_from_json_test(void);
void ip_config_to_json_test(void);

void wifi_config_from_json_test(void);
void wifi_config_to_json_test(void);

void uart_config_from_json_test(void);
void uart_config_to_json_test(void);

void hardware_config_wifi_type_from_json_test(void);
void hardware_config_ethernet_type_from_json_test(void);
void hardware_config_uart_type_from_json_test(void);
void hardware_config_wifi_type_to_json_test(void);
void hardware_config_ethernet_type_to_json_test(void);
void hardware_config_uart_type_to_json_test(void);

void hardware_message_wifi_type_from_json_test(void);
void hardware_message_ethernet_type_from_json_test(void);
void hardware_message_uart_type_from_json_test(void);
void hardware_message_wifi_type_to_json_test(void);
void hardware_message_ethernet_type_to_json_test(void);
void hardware_message_uart_type_to_json_test(void);

#endif  //!__HARDWARE_TEST__H__