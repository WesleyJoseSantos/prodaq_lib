/**
 * @file prodaq_http_test.c
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-02-18
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <unity.h>
#include <string.h>
#include "prodaq_http.h"

void prodaq_http_request_get_method_test(void)
{
    // Test case for HTTP_METHOD_GET
    char request_get[] = "GET /index.html HTTP/1.1";
    http_method_t method = prodaq_http_request_get_method(request_get);
    TEST_ASSERT_EQUAL(HTTP_METHOD_GET, method);

    // Test case for HTTP_METHOD_POST
    char request_post[] = "POST /index.html HTTP/1.1";
    method = prodaq_http_request_get_method(request_post);
    TEST_ASSERT_EQUAL(HTTP_METHOD_POST, method);

    // Test case for HTTP_METHOD_PUT
    char request_put[] = "PUT /index.html HTTP/1.1";
    method = prodaq_http_request_get_method(request_put);
    TEST_ASSERT_EQUAL(HTTP_METHOD_PUT, method);

    // Test case for HTTP_METHOD_DELETE
    char request_delete[] = "DELETE /index.html HTTP/1.1";
    method = prodaq_http_request_get_method(request_delete);
    TEST_ASSERT_EQUAL(HTTP_METHOD_DELETE, method);

    // Test case for HTTP_METHOD_UNKNOWN
    char request_unknown[] = "CONNECT /index.html HTTP/1.1";
    method = prodaq_http_request_get_method(request_unknown);
    TEST_ASSERT_EQUAL(HTTP_METHOD_UNKNOWN, method);
}

void prodaq_http_request_get_url_test(void)
{
    char buf[256];

    // Test case 1: URL parse success
    char request[] = "GET /api/data HTTP/1.1\r\nHost: localhost\r\n";
    http_err_t err = prodaq_http_request_get_url(request, buf, sizeof(buf));
    TEST_ASSERT_EQUAL_HEX(HTTP_OK, err);
    TEST_ASSERT_EQUAL_STRING("/api/data", buf);

    // Test case 2: URL parse fail - missing start space
    char request2[] = "GET/api/data HTTP/1.1\r\nHost: localhost\r\n";
    err = prodaq_http_request_get_url(request2, buf, sizeof(buf));
    TEST_ASSERT_EQUAL_HEX(HTTP_ERR_URL_PARSE_FAIL, err);

    // Test case 3: URL parse fail - missing end space
    char request3[] = "GET /api/dataHTTP/1.1\r\nHost: localhost\r\n";
    err = prodaq_http_request_get_url(request3, buf, sizeof(buf));
    TEST_ASSERT_EQUAL_HEX(HTTP_ERR_URL_PARSE_FAIL, err);

    // Test case 4: URL parse fail - missing URL
    char request4[] = "GET HTTP/1.1\r\nHost: localhost\r\n";
    err = prodaq_http_request_get_url(request4, buf, sizeof(buf));
    TEST_ASSERT_EQUAL_HEX(HTTP_ERR_URL_PARSE_FAIL, err);

    // Test case 5: URL parse fail - buffer too small
    char request5[] = "GET /api/data HTTP/1.1\r\nHost: localhost\r\n";
    char small_buf[2];
    err = prodaq_http_request_get_url(request5, small_buf, sizeof(small_buf));
    TEST_ASSERT_EQUAL_HEX(HTTP_ERR_BUFFER_TOO_SMALL, err);
}

void prodaq_http_request_get_body_success_test(void)
{
    char request[] = "GET /index.html HTTP/1.1\r\n"
                     "Host: www.example.com\r\n"
                     "Content-Length: 7\r\n"
                     "\r\n"
                     "abcdefg";
    char buffer[8];
    http_err_t result = prodaq_http_request_get_body(request, buffer, sizeof(buffer));
    TEST_ASSERT_EQUAL(HTTP_OK, result);
    TEST_ASSERT_EQUAL_STRING("abcdefg", buffer);
}

void prodaq_http_request_get_body_buffer_too_small_test(void)
{
    char request[] = "GET /index.html HTTP/1.1\r\n"
                     "Host: www.example.com\r\n"
                     "Content-Length: 7\r\n"
                     "\r\n"
                     "abcdefg";
    char buffer[6];
    http_err_t result = prodaq_http_request_get_body(request, buffer, sizeof(buffer));
    TEST_ASSERT_EQUAL(HTTP_ERR_BUFFER_TOO_SMALL, result);
}

void prodaq_http_request_get_body_parse_fail_test(void)
{
    char request[] = "GET /index.html HTTP/1.1\r\n"
                     "Host: www.example.com\r\n";
    char buffer[8];
    http_err_t result = prodaq_http_request_get_body(request, buffer, sizeof(buffer));
    TEST_ASSERT_EQUAL(HTTP_ERR_BODY_PARSE_FAIL, result);
}

void test_prodaq_http_parse_request_success(void)
{
    // Given
    char request_str[] = "GET /index.html HTTP/1.1\r\nContent-Length: 4\r\n\r\nbody";
    http_request_t request;
    http_err_t expected_err = HTTP_OK;

    // When
    http_err_t actual_err = prodaq_http_parse_request(request_str, &request);

    // Then
    TEST_ASSERT_EQUAL(expected_err, actual_err);
}

void test_prodaq_http_parse_request_url_parse_fail(void)
{
    // Given
    char request_str[] = "GET \r\nContent-Length: 4\r\n\r\nbody";
    http_request_t request;
    http_err_t expected_err = HTTP_ERR_URL_PARSE_FAIL;

    // When
    http_err_t actual_err = prodaq_http_parse_request(request_str, &request);

    // Then
    TEST_ASSERT_EQUAL(expected_err, actual_err);
}

void test_prodaq_http_parse_request_body_parse_fail(void)
{
    // Given
    char request_str[] = "GET /index.html HTTP/1.1\r\nContent-Length: 5\r\nbodyy";
    http_request_t request;
    http_err_t expected_err = HTTP_ERR_BODY_PARSE_FAIL;

    // When
    http_err_t actual_err = prodaq_http_parse_request(request_str, &request);

    // Then
    TEST_ASSERT_EQUAL(expected_err, actual_err);
}

void test_prodaq_http_parse_request_url_buffer_too_small(void)
{
    // Given
    char request_str[] = "GET /llllllllllllllllllllllllllllllllllllllllllllllllllllllooooooooooooooooooooooooooooooooooooooooooooooooooonnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnngggggggggggggggggggggggggggggggggggggguuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuurrrrrrrrrrrrrrrrrrrrrrrrrrlllllllllllllllllllllllllll.html HTTP/1.1\r\nContent-Length: 4\r\n\r\nbody";
    http_request_t request;
    http_err_t expected_err = HTTP_ERR_BUFFER_TOO_SMALL;

    // When
    http_err_t actual_err = prodaq_http_parse_request(request_str, &request);

    // Then
    TEST_ASSERT_EQUAL(expected_err, actual_err);
}

