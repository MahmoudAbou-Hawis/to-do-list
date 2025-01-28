#ifndef HTTPREQUEST_H_
#define HTTPREQUEST_H_

#include <string>
#include <tuple>
#include "httpcode.hpp"
#include "curlFactory.hpp"


class HttpRequest
{
public:
    std::tuple<HttpCode, std::string> get(const std::string &uri) const;
    std::tuple<HttpCode, std::string> get(
        const std::string &uri,
        std::initializer_list<HttpHeader> headers) const;

    std::tuple<HttpCode, std::string> post(const std::string &uri,
                                           const std::string &body) const;
    std::tuple<HttpCode, std::string> post(
        const std::string &uri,
        const std::string &body,
        std::initializer_list<HttpHeader> headers) const;

    std::tuple<HttpCode, std::string> put(const std::string &uri,
                                           const std::string &body) const;
    std::tuple<HttpCode, std::string> put(
        const std::string &uri,
        const std::string &body,
        std::initializer_list<HttpHeader> headers) const;

        std::tuple<HttpCode, std::string> del(const std::string &uri) const;
    std::tuple<HttpCode, std::string> del(
        const std::string &uri,
        std::initializer_list<HttpHeader> headers) const;

};

#endif