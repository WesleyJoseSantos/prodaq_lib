/**
 * @file prodaq_protocol.cpp
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

#include "prodaq_protocol.h"
#include "prodaq_fm.h"
#include <stdio.h>

#if defined(ESP8266)
#include <ESP8266WiFi.h>
#else
#include <WiFi.h>
#endif

#include <WiFiUdp.h>
#include <NTPClient.h>
#include <PubSubClient.h>
#include "prodaq_app.h"

prodaq_err_t prodaq_protocol_ntp_set_config(ntp_config_t *config);
prodaq_err_t prodaq_protocol_mqtt_set_config(mqtt_config_t *config);
void prodaq_protocol_mqtt_callback(char *topic, byte *payload, unsigned int length);
prodaq_err_t prodaq_protocol_mqtt_send_error(prodaq_err_t err);
prodaq_err_t prodaq_protocol_mqtt_send_message(message_t *message);

WiFiUDP ntpUDP;
NTPClient ntp(ntpUDP);
WiFiClient wifiClient;
PubSubClient mqtt(wifiClient);

char mqtt_rx_topic[48];
char mqtt_tx_topic[48];

message_t message_recv;
message_t message_resp;

prodaq_err_t prodaq_protocol_set_config(protocol_message_t *message)
{
    switch (message->type)
    {
    case PROTOCOL_NTP:
        printf("SET PROTOCOL_NTP\n");
        ntp.end();
        if (message->enabled)
        {
            PRODAQ_ERROR_RETURN(prodaq_protocol_ntp_set_config(&message->config.ntp));
            PRODAQ_ERROR_RETURN(prodaq_fm_save(message, sizeof(*message), PRODAQ_FILENAME_NTP));
        }
        break;
    case PROTOCOL_HTTP:
        printf("SET PROTOCOL_HTTP\n");
        PRODAQ_ERROR_RETURN(prodaq_fm_save(message, sizeof(*message), PRODAQ_FILENAME_HTTP));
        break;
    case PROTOCOL_MQTT:
        printf("SET PROTOCOL_MQTT\n");
        if (message->enabled)
        {
            PRODAQ_ERROR_RETURN(prodaq_protocol_mqtt_set_config(&message->config.mqtt));
            PRODAQ_ERROR_RETURN(prodaq_fm_save(message, sizeof(*message), PRODAQ_FILENAME_MQTT));
        }
        break;
    default:
        printf("UNRECOGNIZED TYPE %d\n", message->type);
        PRODAQ_ERROR_RETURN(PRODAQ_ERR_INVALID_TYPE);
        break;
    }

    return PRODAQ_OK;
}

prodaq_err_t prodaq_protocol_get_config(protocol_message_t *message)
{
    switch (message->type)
    {
    case PROTOCOL_NTP:
        printf("GET PROTOCOL_NTP\n");
        PRODAQ_ERROR_RETURN(prodaq_fm_load(message, sizeof(*message), PRODAQ_FILENAME_NTP));
        break;
    case PROTOCOL_HTTP:
        printf("GET PROTOCOL_HTTP\n");
        PRODAQ_ERROR_RETURN(prodaq_fm_load(message, sizeof(*message), PRODAQ_FILENAME_HTTP));
        break;
    case PROTOCOL_MQTT:
        printf("GET PROTOCOL_MQTT\n");
        PRODAQ_ERROR_RETURN(prodaq_fm_load(message, sizeof(*message), PRODAQ_FILENAME_MQTT));
        break;
    default:
        printf("UNRECOGNIZED TYPE %d\n", message->type);
        PRODAQ_ERROR_RETURN(PRODAQ_ERR_INVALID_TYPE);
        break;
    }

    return PRODAQ_OK;
}

void prodaq_protocol_mqtt_set_response(message_t *response)
{
    message_resp = *response;
}

prodaq_err_t prodaq_protocol_task(void)
{
    ntp.update();
    mqtt.loop();

    if(message_recv.id != MSG_ID_INVALID)
    {
        prodaq_err_t err = prodaq_app_send_message(&message_recv);
        message_recv.id = MSG_ID_INVALID;
        if (message_resp.id == MSG_ID_INVALID)
        {
            err = prodaq_protocol_mqtt_send_error(err);
        }
        else
        {
            err = prodaq_protocol_mqtt_send_message(&message_resp);
            message_resp.id = MSG_ID_INVALID;
        }
        return err;
    }

    return PRODAQ_OK;
}

prodaq_err_t prodaq_protocol_ntp_set_config(ntp_config_t *config)
{
    if (WiFi.status() != WL_CONNECTED)
    {
        return PRODAQ_ERR_DISCONNECTED;
    }

    ntp.begin();
    ntp.setPoolServerName(config->server1);
    ntp.setUpdateInterval(config->sync_interval);

    if (!ntp.update())
    {
        return PRODAQ_FAIL;
    }

    return PRODAQ_OK;
}

prodaq_err_t prodaq_protocol_mqtt_set_config(mqtt_config_t *config)
{
    if (WiFi.status() != WL_CONNECTED)
    {
        return PRODAQ_ERR_DISCONNECTED;
    }

    mqtt.setServer(config->host, config->port);
    mqtt.setKeepAlive(15);

    if (!mqtt.connected())
    {
        uint8_t mac[6];
        char client_id[15];
        uint32_t randNum = random(0xFFFFFFFF);
        WiFi.macAddress(mac);
        sprintf(client_id, "%x%x%x%x%x%x%d", mac[0], mac[1], mac[2], mac[3], mac[4], mac[5], randNum);
        if (!mqtt.connect(client_id, config->username, config->password))
        {
            return PRODAQ_FAIL;
        }
    }

    memcpy(mqtt_rx_topic, config->rx_topic, sizeof(mqtt_rx_topic));
    memcpy(mqtt_tx_topic, config->tx_topic, sizeof(mqtt_tx_topic));

    mqtt.subscribe(mqtt_rx_topic, config->qos);
    mqtt.setCallback(prodaq_protocol_mqtt_callback);

    prodaq_protocol_mqtt_send_error(PRODAQ_OK);

    return PRODAQ_OK;
}

void prodaq_protocol_mqtt_callback(char *topic, byte *payload, unsigned int length)
{
    char *data = (char *)calloc(1, PRODAQ_SERVER_BUFFER_RX);

    if(length > PRODAQ_SERVER_BUFFER_RX) 
    {
        prodaq_protocol_mqtt_send_error(PRODAQ_ERR_BUFFER_OVERFLOW);
    }
    else
    {
        for (unsigned int i = 0; i < length; i++)
        {
            data[i] = (char)payload[i];
        }
        cJSON *json = cJSON_Parse(data);
        message_from_json(json, &message_recv);
    }
}

prodaq_err_t prodaq_protocol_mqtt_send_error(prodaq_err_t err)
{
    message_t message = {};
    message.id = MSG_ID_RESPONSE;
    message.data.response.err = err;
    sprintf(message.data.response.message, PRODAQ_ERROR_TO_MESSAGE(message.data.response.err));
    return prodaq_protocol_mqtt_send_message(&message);
}

prodaq_err_t prodaq_protocol_mqtt_send_message(message_t *message)
{
    cJSON *json = cJSON_CreateObject();
    message_to_json(message, json);
    char *data = cJSON_PrintUnformatted(json);
    cJSON_Delete(json);
    mqtt.publish(mqtt_tx_topic, data);
    cJSON_free(data);
    return PRODAQ_OK;
}

#endif