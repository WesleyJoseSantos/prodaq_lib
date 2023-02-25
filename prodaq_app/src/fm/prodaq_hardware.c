/**
 * @file prodaq_hardware.c
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-02-19
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "prodaq_config.h"

#if defined(__LINUX__) || defined(__WINDOWS__) || defined(PRODAQ_SERVER_FORCE_FM)

#include "prodaq_hardware.h"
#include "prodaq_fm.h"
#include <stdio.h>

prodaq_err_t prodaq_hardware_set_config(hardware_message_t *message)
{
    switch (message->type)
    {
    case HW_INTERFACE_WIFI:
        printf("SET HW_INTERFACE_WIFI\n");
        PRODAQ_ERROR_RETURN(prodaq_fm_save(message, sizeof(*message), PRODAQ_FILENAME_WIFI));
        break;
    case HW_INTERFACE_ETHERNET:
        printf("SET HW_INTERFACE_ETHERNET\n");
        PRODAQ_ERROR_RETURN(prodaq_fm_save(message, sizeof(*message), PRODAQ_FILENAME_ETHERNET));
        break;
    case HW_INTERFACE_UART:
        printf("SET HW_INTERFACE_UART\n");
        PRODAQ_ERROR_RETURN(prodaq_fm_save(message, sizeof(*message), PRODAQ_FILENAME_UART));
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
        PRODAQ_ERROR_RETURN(prodaq_fm_load(message, sizeof(*message), PRODAQ_FILENAME_ETHERNET));
        break;
    case HW_INTERFACE_UART:
        printf("GET HW_INTERFACE_UART\n");
        PRODAQ_ERROR_RETURN(prodaq_fm_load(message, sizeof(*message), PRODAQ_FILENAME_UART));
        break;
    default:
        printf("UNRECOGNIZED TYPE %d\n", message->type);
        PRODAQ_ERROR_RETURN(PRODAQ_ERR_INVALID_TYPE);
        break;
    }

    return PRODAQ_OK;
}

#endif // PRODAQ_TARGET_FM
