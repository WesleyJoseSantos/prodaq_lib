/**
 * @file main.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-02-18
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <unity.h>

#include "prodaq_http_test.h"

void setUp(void) {}

void tearDown(void) {}

int main() {
    UNITY_BEGIN();
    RUN_TEST(prodaq_http_request_get_method_test);
    RUN_TEST(prodaq_http_request_get_url_test);
    RUN_TEST(prodaq_http_request_get_body_success_test);
    RUN_TEST(prodaq_http_request_get_body_buffer_too_small_test);
    RUN_TEST(prodaq_http_request_get_body_parse_fail_test);
    RUN_TEST(test_prodaq_http_parse_request_success);
    RUN_TEST(test_prodaq_http_parse_request_url_parse_fail);
    RUN_TEST(test_prodaq_http_parse_request_body_parse_fail);
    RUN_TEST(test_prodaq_http_parse_request_url_buffer_too_small);
    UNITY_END();
    return 0;
}