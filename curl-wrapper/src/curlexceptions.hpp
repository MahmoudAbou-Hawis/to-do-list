#ifndef CURLEXCEPTIONS_H_
#define CURLEXCEPTIONS_H_

#include <stdexcept>

class CurlEscapeError : public std::runtime_error
{
public:
    using runtime_error::runtime_error;
};

class CurlHttpSendError : public std::runtime_error
{
public:
    using runtime_error::runtime_error;
};

class CurlHttpHeaderError : public std::runtime_error
{
public:
    using runtime_error::runtime_error;
};

class CurlInitError : public std::runtime_error
{
public:
    using runtime_error::runtime_error;
};

#endif