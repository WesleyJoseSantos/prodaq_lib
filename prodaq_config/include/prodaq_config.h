/**
 * @file prodaq_app_config.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-02-19
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef __PRODAQ_APP_CONFIG__H__
#define __PRODAQ_APP_CONFIG__H__

// #define PRODAQ_TARGET_WIN
// #define PDODAQ_TARGET_IDF
#define PRODAQ_TARGET_INO

#ifdef  PRODAQ_TARGET_WIN
#define PRODAQ_TARGET_SELECTED
#endif  //PRODAQ_TARGET_FM

#ifdef  PRODAQ_TARGET_INO
#define PRODAQ_TARGET_SELECTED
#endif  //PRODAQ_TARGET_INO

#ifdef  PDODAQ_TARGET_IDF
#define PRODAQ_TARGET_SELECTED
#endif  //PRODAQ_TARGET_FM

#if !defined(PRODAQ_TARGET_SELECTED)
#error "Target is not selected"
#endif

#define PRODAQ_FILENAME_WIFI "wifi.bin"
#define PRODAQ_FILENAME_ETHERNET "ethernet.bin"
#define PRODAQ_FILENAME_UART "uart.bin"
#define PRODAQ_FILENAME_NTP "ntp.bin"
#define PRODAQ_FILENAME_HTTP "http.bin"
#define PRODAQ_FILENAME_MQTT "mqtt.bin"

#define PRODAQ_SERVER_PORT 80
#define PRODAQ_SERVER_URL "/prodaq"
#define PRODAQ_SERVER_URL_SIZE 64
#define PRODAQ_SERVER_BODY_SIZE 1023
#define PRODAQ_SERVER_BUFFER_RX 1536
#define PRODAQ_SERVER_BUFFER_TX 1536

#endif  //!__PRODAQ_APP_CONFIG__H__