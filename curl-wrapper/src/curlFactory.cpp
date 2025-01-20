#include "curlFactory.hpp"
#include "curlexceptions.hpp"
#include <vector>


void add_headers_to_request(HeaderHandler& handler,
                             const std::vector<HttpHeader>& headers)
{
    curl_slist* header_list = handler.get();
    for(const auto &[name,value] : headers)
    {
        auto header = name;
        header.append(":").append(value);
        if(auto tmp = curl_slist_append(header_list,header.c_str()); tmp)
        {
            header_list = tmp;
            handler.release();
            handler.reset(header_list);
        }
        else
        {
            throw CurlHttpHeaderError("Can't aooend header to the http request");
        }
    }

}

size_t read_curl_data(char* contents,
                      size_t size,
                      size_t nmemb,
                      std::string* s) {
  size_t newLength = size * nmemb;
  s->append(contents, newLength);
  return newLength;
}

CurlHandler make_curl()
{
    CURL * curl = curl_easy_init();
    if(!curl)
    {
        throw CurlInitError("Curl initialization failed");
    }
    else
    {
        CurlHandler ptr(curl, curl_easy_cleanup);
        /* Disables SSL peer verification. */
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L); 
        /*Disables SSL host verification*/ 
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);  
        /* Sets a callback function to handle the data received from the server.*/
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, read_curl_data);
        /**Disables verbose output. */
        curl_easy_setopt(curl, CURLOPT_VERBOSE,
                        0L);  
        return ptr;
    }
}


std::pair<CurlHandler,HeaderHandler>  curlFactory::make_get_curl(std::initializer_list<HttpHeader> headers)
{
    auto curl = make_curl();
    HeaderHandler headersHandler(nullptr, curl_slist_free_all);
    curl_easy_setopt(curl.get(), CURLOPT_HTTPGET, 1);
    if(headers.size() != 0)
    {
        add_headers_to_request(headersHandler, headers);
        curl_easy_setopt(curl.get(), CURLOPT_HTTPHEADER, headersHandler.get());
    }
    return std::make_pair(std::move(curl),std::move(headersHandler));
}

std::pair<CurlHandler,HeaderHandler>  curlFactory::make_post_curl(const std::string &body , std::initializer_list<HttpHeader> headers )
{
    auto curl = make_curl();
    curl_easy_setopt(curl.get(), CURLOPT_POSTFIELDS, body.c_str());
    HeaderHandler headersHandler(nullptr, curl_slist_free_all);
    if(headers.size() != 0)
    {
        add_headers_to_request(headersHandler, headers);
        curl_easy_setopt(curl.get(), CURLOPT_HTTPHEADER, headersHandler.get());
    }
    return std::make_pair(std::move(curl),std::move(headersHandler));
}