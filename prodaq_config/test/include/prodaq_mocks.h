/**
 * @file prodaq_mocks.h
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-02-17
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef __PRODAQ_MOCKS__H__
#define __PRODAQ_MOCKS__H__

#define PRODAQ_JSON_PATH JSON_PATH "/"

#define MOCK_RESPONSE_MESSAGE_JSON PRODAQ_JSON_PATH "response_message.json"
#define MOCK_RESPONSE_MESSAGE_DATA_JSON PRODAQ_JSON_PATH "response_data.json"

#define MOCK_RESPONSE \
    {                 \
        .err = 0,     \
    }

#define MOCK_RESPONSE_MESSAGE                \
    {                                        \
        .id = MSG_ID_RESPONSE,               \
        .data = {                            \
            .response = {                    \
                .err = PRODAQ_OK,            \
                .message = "Prodaq Message", \
            }                                \
        }                                    \
    }

#endif //!__PRODAQ_MOCKS__H__