/**
 * @file prodaq_protocol.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-02-20
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "prodaq_config.h"

#if defined(__LINUX__) || defined(__WINDOWS__) || defined(PRODAQ_SERVER_FORCE_FM)

#include "prodaq_protocol.h"
#include "prodaq_fm.h"
#include <stdio.h>

prodaq_err_t prodaq_protocol_set_config(protocol_message_t *message)
{
    switch (message->type)
    {
    case PROTOCOL_NTP:
        printf("SET PROTOCOL_NTP\n");
        PRODAQ_ERROR_RETURN(prodaq_fm_save(message, sizeof(*message), PRODAQ_FILENAME_NTP));
        break;
    case PROTOCOL_HTTP:
        printf("SET PROTOCOL_HTTP\n");
        PRODAQ_ERROR_RETURN(prodaq_fm_save(message, sizeof(*message), PRODAQ_FILENAME_HTTP));
        break;
    case PROTOCOL_MQTT:
        printf("SET PROTOCOL_MQTT\n");
        PRODAQ_ERROR_RETURN(prodaq_fm_save(message, sizeof(*message), PRODAQ_FILENAME_MQTT));
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

#endif // PRODAQ_TARGET_FM
