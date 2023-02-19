### PRODAQ_FROM_JSON_PARAMETERS(type_t) and PRODAQ_TO_JSON_PARAMETERS(type_t)
The macros PRODAQ_FROM_JSON_PARAMETERS(type_t) and PRODAQ_TO_JSON_PARAMETERS(type_t) are used to facilitate the definition of parameters for the from_json and to_json serialization functions, which make use of the other macros defined in the prodaq_json.h file.

Here's an example of how to use this macro:

````c
typedef struct
{
    uint8_t address[4]; // Device IP address
    uint8_t mask[4];    // Network IP mask
    uint8_t gateway[4]; // Network Gateway IP
    uint8_t dns[4];     // Network DNS IP
} hardware_ip_config_t;

prodaq_err_t hardware_ip_config_from_json(PRODAQ_FROM_JSON_PARAMETERS(hardware_ip_config_t))
{
    PRODAQ_JSON_CHECK_PARAMETERS();
    PRODAQ_FROM_JSON_NUMBER_ARRAY(address);
    PRODAQ_FROM_JSON_NUMBER_ARRAY(mask);
    PRODAQ_FROM_JSON_NUMBER_ARRAY(gateway);
    PRODAQ_FROM_JSON_NUMBER_ARRAY(dns);
    return PRODAQ_OK;
}

prodaq_err_t hardware_ip_config_to_json(PRODAQ_TO_JSON_PARAMETERS(hardware_ip_config_t))
{
    PRODAQ_JSON_CHECK_PARAMETERS();
    PRODAQ_TO_JSON_NUMBER_ARRAY(address);
    PRODAQ_TO_JSON_NUMBER_ARRAY(mask);
    PRODAQ_TO_JSON_NUMBER_ARRAY(gateway);
    PRODAQ_TO_JSON_NUMBER_ARRAY(dns);
    return PRODAQ_OK;
}
````

### PRODAQ_JSON_CHECK_PARAMETERS()
The macro PRODAQ_JSON_CHECK_PARAMETERS() is used to check the parameters of the to_json and from_json serialization functions created using the previously described macros. This macro checks if the parameters are valid, returning the error PRODAQ_ERR_INVALID_ARG if the arguments are not valid, or allowing the other macros to perform the serialization/deserialization functions if the parameters are valid. This macro should be declared at the beginning of all serialization/deserialization functions to ensure that the parameters are valid. To use it, it is recommended that the function where this macro is called returns a prodaq_err_t type.