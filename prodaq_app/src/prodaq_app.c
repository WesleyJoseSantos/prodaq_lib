/**
 * @file prodaq_app.c
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-02-18
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <sys/stat.h>
#include <stdio.h>

#include "prodaq_config.h"
#include "prodaq_app.h"
#include "prodaq_server.h"
#include "prodaq_hardware.h"
#include "prodaq_protocol.h"
#include "prodaq_fm.h"
#include "prodaq_err.h"

prodaq_err_t prodaq_app_load_config(const char *filename, message_t *message, message_id_t id, size_t size);
prodaq_err_t prodaq_app_process_request(request_message_t *request);

prodaq_err_t prodaq_app_start(void)
{
    message_t message = {0};

    // Load Hardware Settings
    PRODAQ_ERROR_CHECK(prodaq_app_load_config(PRODAQ_FILENAME_WIFI, &message, MSG_ID_HARDWARE_CONFIG, sizeof(message.data.hardware)));
    PRODAQ_ERROR_CHECK(prodaq_app_load_config(PRODAQ_FILENAME_ETHERNET, &message, MSG_ID_HARDWARE_CONFIG, sizeof(message.data.hardware)));
    PRODAQ_ERROR_CHECK(prodaq_app_load_config(PRODAQ_FILENAME_UART, &message, MSG_ID_HARDWARE_CONFIG, sizeof(message.data.hardware)));

    // Load Protocol Settings
    PRODAQ_ERROR_CHECK(prodaq_app_load_config(PRODAQ_FILENAME_NTP, &message, MSG_ID_PROTOCOL_CONFIG, sizeof(message.data.protocol)));
    PRODAQ_ERROR_CHECK(prodaq_app_load_config(PRODAQ_FILENAME_HTTP, &message, MSG_ID_PROTOCOL_CONFIG, sizeof(message.data.protocol)));
    PRODAQ_ERROR_CHECK(prodaq_app_load_config(PRODAQ_FILENAME_MQTT, &message, MSG_ID_PROTOCOL_CONFIG, sizeof(message.data.protocol)));

    prodaq_server_on_request(prodaq_app_send_message);
    PRODAQ_ERROR_RETURN(prodaq_server_start(PRODAQ_SERVER_PORT, PRODAQ_SERVER_URL));

    return PRODAQ_OK;
}

prodaq_err_t prodaq_app_task(void)
{
    PRODAQ_ERROR_RETURN(prodaq_server_task());
    return PRODAQ_OK;
}

prodaq_err_t prodaq_app_send_message(message_t *message)
{
    switch (message->id)
    {
    case MSG_ID_HARDWARE_CONFIG:
        printf("SET MSG_ID_HARDWARE_CONFIG\n");
        PRODAQ_ERROR_RETURN(prodaq_hardware_set_config(&message->data.hardware));
        break;
    case MSG_ID_PROTOCOL_CONFIG:
        printf("SET MSG_ID_PROTOCOL_CONFIG\n");
        PRODAQ_ERROR_RETURN(prodaq_protocol_set_config(&message->data.protocol));
        break;
    case MSG_ID_DEVICE_CONFIG:
        printf("SET MSG_ID_DEVICE_CONFIG\n");
        PRODAQ_ERROR_RETURN(PRODAQ_ERR_NOT_IMPLEMENTED);
        break;
    case MSG_ID_REQUEST:
        printf("MSG_ID_REQUEST\n");
        PRODAQ_ERROR_RETURN(prodaq_app_process_request(&message->data.request));
        break;
    default:
        printf("UNRECOGNIZED MSG_ID %d\n", message->id);
        PRODAQ_ERROR_RETURN(PRODAQ_ERR_INVALID_MESSAGE_ID);
        break;
    }

    return PRODAQ_OK;
}

prodaq_err_t prodaq_app_process_request(request_message_t *request)
{
    message_t message = {0};
    message.id = request->id;

    switch (request->id)
    {
    case MSG_ID_HARDWARE_CONFIG:
        printf("GET MSG_ID_HARDWARE_CONFIG\n");
        message.data.hardware.type = request->type;
        PRODAQ_ERROR_RETURN(prodaq_hardware_get_config(&message.data.hardware));
        break;
    case MSG_ID_PROTOCOL_CONFIG:
        printf("GET MSG_ID_PROTOCOL_CONFIG\n");
        message.data.protocol.type = request->type;
        PRODAQ_ERROR_RETURN(prodaq_protocol_get_config(&message.data.protocol));
        break;
    case MSG_ID_DEVICE_CONFIG:
        printf("GET MSG_ID_DEVICE_CONFIG\n");
        PRODAQ_ERROR_RETURN(PRODAQ_ERR_NOT_IMPLEMENTED);
        break;
    case MSG_ID_REQUEST:
        printf("GET MSG_ID_REQUEST\n");
        return PRODAQ_ERR_NOT_SUPPORTED;
    default:
        printf("UNRECOGNIZED MSG_ID %d\n", request->id);
        PRODAQ_ERROR_RETURN(PRODAQ_ERR_INVALID_MESSAGE_ID);
        break;
    }

    prodaq_server_set_response(&message);
    return PRODAQ_OK;
}

prodaq_err_t prodaq_app_wait_message_processing(message_id_t message_id, uint32_t timeout)
{
    return PRODAQ_ERR_NOT_SUPPORTED;
}

prodaq_err_t prodaq_app_load_config(const char *filename, message_t *message, message_id_t id, size_t size)
{
    if (prodaq_fm_load(&message->data, size, filename) == PRODAQ_OK)
    {
        message->id = id;
        prodaq_app_send_message(message);
        return PRODAQ_OK;
    }
    else
    {
        return PRODAQ_ERR_NOT_FOUND;
    }
}
