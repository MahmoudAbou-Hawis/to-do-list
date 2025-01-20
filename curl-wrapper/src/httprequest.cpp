#include "httprequest.hpp"
#include <curl/curl.h>
#include <functional>
#include <memory>
#include "curlexceptions.hpp"
#include "curlFactory.hpp"

/**
 * @brief Creates and configures a CURL handle with default settings.
 *
 * This function initializes a CURL handle, configures it to disable SSL peer and host 
 * verification,
 * sets a callback function for writing received data, and disables verbose output.
 *
 * @return CurlHandler A `std::unique_ptr` wrapping the configured CURL 
 *          handle with a custom deleter.
 * @throws std::runtime_error If the CURL handle initialization fails.
 */


std::tuple<HttpCode, std::string> do_request(const std::string& uri,
                                             const CurlHandler& handler)
{
    std::string response_data;
    response_data.reserve(100);
    curl_easy_setopt(handler.get(), CURLOPT_URL, uri.c_str());
    curl_easy_setopt(handler.get(), CURLOPT_WRITEDATA, &response_data);
    if(CURLcode res = curl_easy_perform(handler.get()); res != CURLE_OK)
    {
        throw CurlHttpSendError(curl_easy_strerror(res));
    }
    auto response_code{0L};
    curl_easy_getinfo(handler.get(), CURLINFO_RESPONSE_CODE, &response_code);
    return std::make_tuple(static_cast<HttpCode>(response_code),
                         std::move(response_data));
}



std::tuple<HttpCode, std::string> HttpRequest::get(const std::string &uri) const
{   
    auto [curl,headerHandler] = curlFactory::make_get_curl();
    return do_request(uri,curl);
}

std::tuple<HttpCode, std::string> HttpRequest::get(const std::string &uri,
                                                    std::initializer_list<HttpHeader> 
                                                    headers) const
{
    auto [curl,headerHandler] = curlFactory::make_get_curl(headers);
    return do_request(uri,curl);
}

std::tuple<HttpCode, std::string> HttpRequest::post(const std::string &uri, 
                                                    const std::string &body) const
{
    auto [curl,headerHandler] = curlFactory::make_post_curl(body);
    return do_request(uri,curl);
}

std::tuple<HttpCode, std::string> HttpRequest::post(const std::string &uri, 
                                                    const std::string &body, 
                                                    std::initializer_list<HttpHeader> 
                                                    headers) const
{
    auto [curl,headerHandler] =  curlFactory::make_post_curl(body,headers);
    return do_request(uri,curl);
}
