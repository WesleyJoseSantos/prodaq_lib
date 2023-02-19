/**
 * @file prodaq_http_test.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-02-18
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef __PRODAQ_HTTP_TEST__H__
#define __PRODAQ_HTTP_TEST__H__

void prodaq_http_request_get_method_test(void);
void prodaq_http_request_get_url_test(void);
void prodaq_http_request_get_body_success_test(void);
void prodaq_http_request_get_body_buffer_too_small_test(void);
void prodaq_http_request_get_body_parse_fail_test(void);
void test_prodaq_http_parse_request_success(void);
void test_prodaq_http_parse_request_url_parse_fail(void);
void test_prodaq_http_parse_request_body_parse_fail(void);
void test_prodaq_http_parse_request_url_buffer_too_small(void);

#endif  //!__PRODAQ_HTTP_TEST__H__