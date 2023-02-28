/**
 * @file prodaq_device.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-02-25
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "prodaq_config.h"

#if defined(__LINUX__) || defined(__WINDOWS__) || defined(PRODAQ_SERVER_FORCE_FM)

#include "prodaq_device.h"
#include "prodaq_fm.h"

prodaq_err_t prodaq_device_set_config(device_message_t *message)
{
    switch (message->type)
    {
    case DEVICE_SENSOR:
        printf("SET DEVICE_SENSOR\n");
        PRODAQ_ERROR_RETURN(prodaq_fm_save(message, sizeof(*message), PRODAQ_FILENAME_SENSOR));
        break;
    case DEVICE_GATEWAY:
        printf("SET DEVICE_GATEWAY\n");
        PRODAQ_ERROR_RETURN(prodaq_fm_save(message, sizeof(*message), PRODAQ_FILENAME_GATEWAY));
        break;
    case DEVICE_DATALOGGER:
        printf("SET DEVICE_DATALOGGER\n");
        PRODAQ_ERROR_RETURN(prodaq_fm_save(message, sizeof(*message), PRODAQ_FILENAME_DATALOGGER));
        break;
    default:
        printf("UNRECOGNIZED TYPE %d\n", message->type);
        PRODAQ_ERROR_RETURN(PRODAQ_ERR_INVALID_TYPE);
        break;
    }

    return PRODAQ_OK;
}
prodaq_err_t prodaq_device_get_config(device_message_t *message)
{
    switch (message->type)
    {
    case DEVICE_SENSOR:
        printf("GET DEVICE_SENSOR\n");
        PRODAQ_ERROR_RETURN(prodaq_fm_load(message, sizeof(*message), PRODAQ_FILENAME_SENSOR));
        break;
    case DEVICE_GATEWAY:
        printf("GET DEVICE_GATEWAY\n");
        PRODAQ_ERROR_RETURN(prodaq_fm_load(message, sizeof(*message), PRODAQ_FILENAME_GATEWAY));
        break;
    case DEVICE_DATALOGGER:
        printf("GET DEVICE_DATALOGGER\n");
        PRODAQ_ERROR_RETURN(prodaq_fm_load(message, sizeof(*message), PRODAQ_FILENAME_DATALOGGER));
        break;
    default:
        printf("UNRECOGNIZED TYPE %d\n", message->type);
        PRODAQ_ERROR_RETURN(PRODAQ_ERR_INVALID_TYPE);
        break;
    }

    return PRODAQ_OK;
}
prodaq_err_t prodaq_device_task(void)
{
    // TODO: implement device task
    return PRODAQ_OK;
}

#endif