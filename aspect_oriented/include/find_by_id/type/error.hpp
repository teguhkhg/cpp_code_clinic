#include "common.hpp"

class Error{
public:
    const int code;
    const std::string message;

    Error(int code, std::string message) : code(code), message(message){}
    Error(const Error &e) : code(e.code), message(e.message){}
};