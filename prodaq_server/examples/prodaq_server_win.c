#include <stdio.h>
#include <string.h>
#include "prodaq_server.h"

static prodaq_err_t on_request(message_t *msg);

int main(void)
{
    prodaq_server_on_request(on_request);

    int err = prodaq_server_start(80, "/prodaq");
    printf("Server closed with code %d", err);
    return err;
}

prodaq_err_t on_request(message_t *msg)
{
    cJSON *json = cJSON_CreateObject();
    message_to_json(msg, json);
    char *json_str = cJSON_PrintUnformatted(json);
    printf("message received: %s\n", json_str);
    cJSON_Delete(json);
    cJSON_free(json_str);

    switch (msg->id)
    {
    case MSG_ID_HARDWARE_CONFIG:
        printf("MSG_ID_HARDWARE_CONFIG\n");
        break;
    case MSG_ID_PROTOCOL_CONFIG:
        printf("MSG_ID_PROTOCOL_CONFIG\n");
        break;
    case MSG_ID_DEVICE_CONFIG:
        printf("MSG_ID_DEVICE_CONFIG\n");
        break;
    default:
        {
            printf("PRODAQ_ERR_INVALID_MESSAGE_ID\n");
            message_t response = {
                .id = MSG_ID_RESPONSE,
                .data = {
                    .response = {
                        .err = PRODAQ_ERR_INVALID_MESSAGE_ID,
                        .message = "Invalid Message ID"
                    }
                }
            };
            prodaq_server_set_response(&response);
            return PRODAQ_ERR_INVALID_MESSAGE_ID;
        }
    }

    return PRODAQ_OK;
}