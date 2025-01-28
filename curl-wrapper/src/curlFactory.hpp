#ifndef CURLFACTORY_HPP
#define CURLFACTORY_HPP

#include <curl/curl.h>
#include <memory>
#include <string>

using CurlHandler = std::unique_ptr<CURL, decltype(curl_easy_cleanup)*>;
using HeaderHandler = std::unique_ptr<curl_slist, decltype(curl_slist_free_all) *>;

struct HttpHeader
{
    std::string name;
    std::string value;
};

class curlFactory
{
private:
    curlFactory();
public:
    static std::pair<CurlHandler,HeaderHandler>  make_get_curl(std::initializer_list<HttpHeader> headers = {}) ;
    static std::pair<CurlHandler,HeaderHandler>  make_post_curl(const std::string &body , std::initializer_list<HttpHeader> headers ={}) ;
    static std::pair<CurlHandler,HeaderHandler>  make_put_curl(const std::string &body , std::initializer_list<HttpHeader> headers ={}) ;
    static std::pair<CurlHandler,HeaderHandler>  make_delete_curl(std::initializer_list<HttpHeader> headers ={}) ;
};


#endif 