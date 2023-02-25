/**
 * @file prodaq_err.h
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-02-16
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef __PRODAQ_ERR__H__
#define __PRODAQ_ERR__H__

#include "prodaq_config.h"
#include <stdio.h>

typedef enum
{
    PRODAQ_OK = 0x0,

    // PRODAQ_ERR_BASE = 0x100,
    PRODAQ_ERR_NOT_IMPLEMENTED,
    PRODAQ_ERR_INVALID_ARG,
    PRODAQ_ERR_INVALID_MESSAGE_ID,
    PRODAQ_ERR_INVALID_TYPE,
    PRODAQ_ERR_NOT_FOUND,
    PRODAQ_ERR_INVALID_SIZE,
    PRODAQ_ERR_WRITE_OPERATION_FAILED,
    PRODAQ_ERR_READ_OPERATION_FAILED,
    PRODAQ_ERR_NOT_SUPPORTED,
    PRODAQ_ERR_NO_MEMORY,
    PRODAQ_ERR_BUFFER_OVERFLOW,
    PRODAQ_ERR_FILE_OPEN_FAILED,

    // PRODAQ_ERR_HTTP_BASE = 0x200,
    PRODAQ_ERR_HTTP_INIT,
    PRODAQ_ERR_HTTP_SOCKET_CREATE,
    PRODAQ_ERR_HTTP_SOCKET_BIND,
    PRODAQ_ERR_HTTP_SOCKET_LISTEN,
    PRODAQ_ERR_HTTP_CONNECTION_FAIL,
    PRODAQ_ERR_HTTP_RECEIVE,
    PRODAQ_ERR_HTTP_REQUEST_PARSE_FAIL,
    PRODAQ_ERR_HTTP_SEND_RESPONSE_FAIL,
    PRODAQ_ERR_HTTP_NOT_FOUND,
    PRODAQ_ERR_HTTP_NULL_REQUEST_HANDLER,

    // PRODAQ_ERR_UART_BASE = 0x300,
    PRODAQ_ERR_UART_GET_STATE,
    PRODAQ_ERR_UART_SET_STATE,
    PRODAQ_ERR_SET_TIMEOUT,
    PRODAQ_ERR_COUNT,
} prodaq_err_t;

static const char *const prodaq_error_messages[] = {
    "No error",
    "Function not implemented",
    "Invalid argument",
    "Invalid message ID",
    "Invalid type",
    "Not found",
    "Invalid size",
    "Write operation failed",
    "Read operation failed",
    "Not supported",
    "No memory",
    "Buffer overflow",
    "File open failed",
    // HTTP
    "Failed to initialize HTTP",
    "Failed to create HTTP socket",
    "Failed to bind HTTP socket",
    "Failed to listen on HTTP socket",
    "HTTP connection failed",
    "Failed to receive HTTP request",
    "Failed to parse HTTP request",
    "Failed to send HTTP response",
    "HTTP resource not found",
    "Null HTTP request handler",
    // UART
    "Failed to get UART state",
    "Failed to set UART state",
    "Failed to set timeout",
};

#define PRODAQ_ERROR_TO_MESSAGE(x) (x >= 0 && x < PRODAQ_ERR_COUNT) ? prodaq_error_messages[x] : "Unknown Error"

#define PRODAQ_ERROR_CHECK(x)                                                                                             \
    do                                                                                                                    \
    {                                                                                                                     \
        prodaq_err_t prodaq_err = x;                                                                                      \
        if (prodaq_err != PRODAQ_OK)                                                                                      \
        {                                                                                                                 \
            printf(__FILE__ ":%d: Error %d \"%s\" at " #x "\n", __LINE__, prodaq_err, prodaq_error_messages[prodaq_err]); \
        }                                                                                                                 \
    } while (0)

#define PRODAQ_ERROR_RETURN(x)                                                                                            \
    do                                                                                                                    \
    {                                                                                                                     \
        prodaq_err_t prodaq_err = x;                                                                                      \
        if (prodaq_err != PRODAQ_OK)                                                                                      \
        {                                                                                                                 \
            printf(__FILE__ ":%d: Error %d \"%s\" at " #x "\n", __LINE__, prodaq_err, prodaq_error_messages[prodaq_err]); \
            return prodaq_err;                                                                                            \
        }                                                                                                                 \
    } while (0)

#endif //!__PRODAQ_ERR__H__