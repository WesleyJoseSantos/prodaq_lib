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

#include "prodaq_err.h"
#include "prodaq_config.h"
#include "prodaq_message.h"

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
    http_method_t method;               // HTTP method used for the request
    char url[PRODAQ_SERVER_URL_SIZE];   // URL requested
    char body[PRODAQ_SERVER_BODY_SIZE]; // body of the request
} http_request_t;

/**
 * @brief A struct representing an HTTP server.
 *
 */
typedef struct
{
    char *endpoint;                                                            //< A pointer to a string representing the endpoint.
    message_t response;                                                        //< A message_t representing the server's response.
    prodaq_err_t (*on_request)(message_t *);                                   //< A function pointer that takes a message_t pointer and returns a prodaq_err_t value. It is called when the server receives a request.
    prodaq_err_t (*send_response)(void *, const char *, const char *, char *); //< A function pointer that takes a void pointer, two strings, and a char pointer, and returns a prodaq_err_t value. It is called to send the server's response.
} http_server_t;

/**
 * @brief Processes an HTTP request received by the server.
 * 
 * @param server A pointer to the HTTP server.
 * @param request A char pointer representing the request.
 * @param client A void pointer representing the client.
 * @return prodaq_err_t A prodaq_err_t value indicating the success or failure of the operation.
 */
prodaq_err_t prodaq_http_process_request(http_server_t *server, char *request, void *client);

/**
 * @brief Builds an HTTP response.
 * 
 * @param status_code A const char pointer representing the status code.
 * @param content_type A const char pointer representing the content type.
 * @param body A char pointer representing the body.
 * @param buf A char pointer representing the buffer to write the response to.
 * @param len A size_t representing the length of the buffer.
 * @return int A size_t representing the length of the buffer.
 */
int prodaq_http_build_response(const char *status_code, const char *content_type, char *body, char *buf, size_t len);

/**
 * @brief Sends an HTTP error response to the client.
 *
 * This function takes a pointer to an HTTP server, a pointer to the client that sent the request, an error code, and
 * an HTTP status code as input. The function sends an HTTP error response to the client with the specified error and
 * status codes. The function returns a PRODAQ error code indicating whether the operation was successful or not.
 *
 * @param server Pointer to the HTTP server.
 * @param client Pointer to the client that sent the request.
 * @param err The PRODAQ error code associated with the error.
 * @param status_code The HTTP status code to send in the response.
 *
 * @return A PRODAQ error code indicating whether the operation was successful or not.
 */
prodaq_err_t prodaq_http_send_error(http_server_t *server, void *client, prodaq_err_t err, const char *status_code);

#endif //!__PRODAQ_HTTP__H__