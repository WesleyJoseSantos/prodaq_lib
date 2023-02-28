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

#if !defined(__WINDOWS__) && (defined(WIN32) || defined(WIN64) || defined(_MSC_VER) || defined(_WIN32))
#define __WINDOWS__
#endif

#if !defined(__LINUX__) && defined __linux__
#define __LINUX__
#endif

#if !defined(__ARDUINO__) && (defined(__AVR__) || defined(ESP8266))
#define __ARDUINO__
#endif

#if !defined(__IDF__) && defined(IDF_VER)
#define __IDF__
#endif

#if !defined(__WINDOWS__) && !defined(__LINUX__) && !defined(__ARDUINO__) && !defined(__IDF__)
#error "System not supported!"
#endif

#define PRODAQ_FILENAME_WIFI "/wifi.bin"
#define PRODAQ_FILENAME_ETHERNET "/ethernet.bin"
#define PRODAQ_FILENAME_UART "/uart.bin"
#define PRODAQ_FILENAME_NTP "/ntp.bin"
#define PRODAQ_FILENAME_HTTP "/http.bin"
#define PRODAQ_FILENAME_MQTT "/mqtt.bin"
#define PRODAQ_FILENAME_SENSOR "/sensor.bin"
#define PRODAQ_FILENAME_GATEWAY "/gateway.bin"
#define PRODAQ_FILENAME_DATALOGGER "/datalogger.bin"

#define PRODAQ_SERVER_PORT 80
#define PRODAQ_SERVER_URL "/prodaq"
#define PRODAQ_SERVER_URL_SIZE 64
#define PRODAQ_SERVER_BODY_SIZE 1023
#define PRODAQ_SERVER_BUFFER_RX 1536
#define PRODAQ_SERVER_BUFFER_TX 1536

#endif  //!__PRODAQ_APP_CONFIG__H__