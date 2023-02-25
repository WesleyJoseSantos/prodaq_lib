/**
 * @file prodaq_hardware.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-02-25
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "prodaq_config.h"

#if defined(__ARDUINO__)

#include "prodaq_hardware.h"
#include "prodaq_fm.h"
#include <stdio.h>

#if defined(ESP8266)
#include <ESP8266WiFi.h>
#else
#include <WiFi.h>
#endif

prodaq_err_t prodaq_hardware_wifi_set_config(wifi_config_t *config);

prodaq_err_t prodaq_hardware_set_config(hardware_message_t *message)
{
    switch (message->type)
    {
    case HW_INTERFACE_WIFI:
        printf("SET HW_INTERFACE_WIFI\n");
        WiFi.disconnect();
        if(message->enabled) {
            PRODAQ_ERROR_RETURN(prodaq_hardware_wifi_set_config(&message->config.wifi));
            PRODAQ_ERROR_RETURN(prodaq_fm_save(message, sizeof(*message), PRODAQ_FILENAME_WIFI));
        }
        break;
    case HW_INTERFACE_ETHERNET:
        printf("SET HW_INTERFACE_ETHERNET\n");
        PRODAQ_ERROR_RETURN(PRODAQ_ERR_NOT_SUPPORTED);
        break;
    case HW_INTERFACE_UART:
        printf("SET HW_INTERFACE_UART\n");
        PRODAQ_ERROR_RETURN(PRODAQ_ERR_NOT_SUPPORTED);
        break;
    default:
        printf("UNRECOGNIZED TYPE %d\n", message->type);
        PRODAQ_ERROR_RETURN(PRODAQ_ERR_INVALID_TYPE);
        break;
    }

    return PRODAQ_OK;
}

prodaq_err_t prodaq_hardware_get_config(hardware_message_t *message)
{
    switch (message->type)
    {
    case HW_INTERFACE_WIFI:
        printf("GET HW_INTERFACE_WIFI\n");
        PRODAQ_ERROR_RETURN(prodaq_fm_load(message, sizeof(*message), PRODAQ_FILENAME_WIFI));
        break;
    case HW_INTERFACE_ETHERNET:
        printf("GET HW_INTERFACE_ETHERNET\n");
        PRODAQ_ERROR_RETURN(PRODAQ_ERR_NOT_SUPPORTED);
        break;
    case HW_INTERFACE_UART:
        printf("GET HW_INTERFACE_UART\n");
        PRODAQ_ERROR_RETURN(PRODAQ_ERR_NOT_SUPPORTED);
        break;
    default:
        printf("UNRECOGNIZED TYPE %d\n", message->type);
        PRODAQ_ERROR_RETURN(PRODAQ_ERR_INVALID_TYPE);
        break;
    }

    return PRODAQ_OK;
}

prodaq_err_t prodaq_hardware_wifi_set_config(wifi_config_t *config)
{
    // Connect to Wi-Fi
    WiFi.disconnect();
    if (config->enterprise) {
        // Connect with enterprise credentials
        PRODAQ_ERROR_RETURN(PRODAQ_ERR_NOT_IMPLEMENTED);
    } else {
        // Connect with normal credentials
        WiFi.begin(config->ssid, config->password);
    }

    // Wait for connection
    Serial.print("Connecting to Wi-Fi");
    int secs = 0;
    while (WiFi.status() != WL_CONNECTED && secs <= 10) {
        delay(1000);
        Serial.print(".");
        secs++;
    }

    if(WiFi.status() != WL_CONNECTED)
    {
        Serial.print("Connection error.\n");
        return PRODAQ_ERR_TIMEOUT;
    }

    if(config->ip.enabled) {
        IPAddress ip(config->ip.address);
        IPAddress gateway(config->ip.gateway);
        IPAddress subnet(config->ip.mask);
        IPAddress dns(config->ip.dns);
        
        WiFi.config(ip, gateway, subnet, dns);
        Serial.println("IP Configuration enabled");
        Serial.print("IP address: ");
        Serial.println(WiFi.localIP());
    }

    // Print connection details
    Serial.println("Connected to Wi-Fi");
    Serial.print("IP Address: ");
    Serial.println(WiFi.localIP());

    return PRODAQ_OK;
}

#endif