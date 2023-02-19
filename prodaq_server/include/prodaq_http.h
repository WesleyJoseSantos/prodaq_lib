/**
 * @file prodaq_http.h
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-02-17
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef __PRODAQ_HTTP__H__
#define __PRODAQ_HTTP__H__

#define HTTP_STATUS_CONTINUE "100 Continue"
#define HTTP_STATUS_SWITCHING_PROTOCOLS "101 Switching Protocols"
#define HTTP_STATUS_OK "200 OK"
#define HTTP_STATUS_CREATED "201 Created"
#define HTTP_STATUS_ACCEPTED "202 Accepted"
#define HTTP_STATUS_NON_AUTHORITATIVE_INFORMATION "203 Non-Authoritative Information"
#define HTTP_STATUS_NO_CONTENT "204 No Content"
#define HTTP_STATUS_RESET_CONTENT "205 Reset Content"
#define HTTP_STATUS_PARTIAL_CONTENT "206 Partial Content"
#define HTTP_STATUS_MULTIPLE_CHOICES "300 Multiple Choices"
#define HTTP_STATUS_MOVED_PERMANENTLY "301 Moved Permanently"
#define HTTP_STATUS_FOUND "302 Found"
#define HTTP_STATUS_SEE_OTHER "303 See Other"
#define HTTP_STATUS_NOT_MODIFIED "304 Not Modified"
#define HTTP_STATUS_USE_PROXY "305 Use Proxy"
#define HTTP_STATUS_TEMPORARY_REDIRECT "307 Temporary Redirect"
#define HTTP_STATUS_BAD_REQUEST "400 Bad Request"
#define HTTP_STATUS_UNAUTHORIZED "401 Unauthorized"
#define HTTP_STATUS_PAYMENT_REQUIRED "402 Payment Required"
#define HTTP_STATUS_FORBIDDEN "403 Forbidden"
#define HTTP_STATUS_NOT_FOUND "404 Not Found"
#define HTTP_STATUS_METHOD_NOT_ALLOWED "405 Method Not Allowed"
#define HTTP_STATUS_NOT_ACCEPTABLE "406 Not Acceptable"
#define HTTP_STATUS_PROXY_AUTHENTICATION_REQUIRED "407 Proxy Authentication Required"
#define HTTP_STATUS_REQUEST_TIMEOUT "408 Request Timeout"
#define HTTP_STATUS_CONFLICT "409 Conflict"
#define HTTP_STATUS_GONE "410 Gone"
#define HTTP_STATUS_LENGTH_REQUIRED "411 Length Required"
#define HTTP_STATUS_PRECONDITION_FAILED "412 Precondition Failed"
#define HTTP_STATUS_REQUEST_ENTITY_TOO_LARGE "413 Request Entity Too Large"
#define HTTP_STATUS_REQUEST_URI_TOO_LONG "414 Request-URI Too Long"
#define HTTP_STATUS_UNSUPPORTED_MEDIA_TYPE "415 Unsupported Media Type"
#define HTTP_STATUS_REQUESTED_RANGE_NOT_SATISFIABLE "416 Requested Range Not Satisfiable"
#define HTTP_STATUS_EXPECTATION_FAILED "417 Expectation Failed"
#define HTTP_STATUS_INTERNAL_SERVER_ERROR "500 Internal Server Error"
#define HTTP_STATUS_NOT_IMPLEMENTED "501 Not Implemented"
#define HTTP_STATUS_BAD_GATEWAY "502 Bad Gateway"
#define HTTP_STATUS_SERVICE_UNAVAILABLE "503 Service Unavailable"
#define HTTP_STATUS_GATEWAY_TIMEOUT "504 Gateway Timeout"
#define HTTP_STATUS_VERSION_NOT_SUPPORTED "505 HTTP Version Not Supported"

#define HTTP_CONTENT_TYPE_HTML "text/html"
#define HTTP_CONTENT_TYPE_TEXT "text/plain"
#define HTTP_CONTENT_TYPE_JSON "application/json"
#define HTTP_CONTENT_TYPE_XML "application/xml"
#define HTTP_CONTENT_TYPE_PDF "application/pdf"
#define HTTP_CONTENT_TYPE_IMAGE_JPEG "image/jpeg"
#define HTTP_CONTENT_TYPE_IMAGE_PNG "image/png"
#define HTTP_CONTENT_TYPE_IMAGE_GIF "image/gif"
#define HTTP_CONTENT_TYPE_FORM_URLENCODED "application/x-www-form-urlencoded"
#define HTTP_CONTENT_TYPE_MULTIPART_FORM_DATA "multipart/form-data"

/**
 * @brief Define a custom enumeration for error codes returned by HTTP functions
 *
 */
typedef enum htt_err
{
    HTTP_OK = 0,                    // success
    HTTP_ERR_URL_PARSE_FAIL = -1,   // failed to parse URL from request
    HTTP_ERR_BODY_PARSE_FAIL = -2,  // failed to parse body from request
    HTTP_ERR_BUFFER_TOO_SMALL = -3, // the buffer to store the request body is too small
} http_err_t;

/**
 * @brief Define a custom enumeration for HTTP request methods
 *
 */
typedef enum http_method
{
    HTTP_METHOD_UNKNOWN, // unknown method
    HTTP_METHOD_GET,     // GET method
    HTTP_METHOD_POST,    // POST method
    HTTP_METHOD_PUT,     // PUT method
    HTTP_METHOD_DELETE   // DELETE method
    // ...
} http_method_t;

/**
 * @brief Define a custom structure to store an HTTP request
 *
 */
typedef struct
{
    http_method_t method; // HTTP method used for the request
    char url[256];        // URL requested
    char body[1023];      // body of the request
} http_request_t;

/**
 * Returns the HTTP method enum corresponding to the given request string.
 *
 * @param request The request string.
 * @return The HTTP method enum.
 */
http_method_t prodaq_http_request_get_method(char *request);

/**
 * Copies the URL from the request string to the buffer, ensuring that it is null-terminated
 * and does not exceed the buffer size.
 *
 * @param request The request string.
 * @param buf The buffer to copy the URL to.
 * @param len The size of the buffer.
 * @return An HTTP error code indicating success or failure.
 */
http_err_t prodaq_http_request_get_url(char *request, char *buf, size_t len);

/**
 * Copies the message body from the request string to the buffer, ensuring that it is null-terminated
 * and does not exceed the buffer size.
 *
 * @param request The request string.
 * @param buffer The buffer to copy the message body to.
 * @param len The size of the buffer.
 * @return An HTTP error code indicating success or failure.
 */
http_err_t prodaq_http_request_get_body(char *request, char *buffer, size_t len);

/**
 * Parses the given HTTP request string and populates an HTTP request struct with the method,
 * URL, and message body.
 *
 * @param request_str The HTTP request string.
 * @param request The HTTP request struct to populate.
 * @return An HTTP error code indicating success or failure.
 */
http_err_t prodaq_http_parse_request(char *request_str, http_request_t *request);

#endif //!__PRODAQ_HTTP__H__