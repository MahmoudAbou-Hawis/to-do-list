#include "uri.hpp"
#include <memory>
#include "curlexceptions.hpp"
#include <curl/curl.h>

using CurlHandler = std::unique_ptr<CURL, void (*)(CURL*)>;
static CurlHandler CURL_HANDLER(curl_easy_init(), curl_easy_cleanup);


void appendEscape(const std::string& param, std::string& out, CURL* curl) {
  if (char* output =
          curl_easy_escape(curl, param.c_str(), static_cast<int>(param.size()));
      output) {
    out.append(output);
    curl_free(output);
    return;
  }
  throw CurlEscapeError("Failed eascape path");
}

std::string Uri::uri()
{
    if (!CURL_HANDLER) {
        throw CurlInitError("Failed init curl in UriBuilder");
    }
    for(auto &path : mPaths)
    {
        mUri.append("/");
        appendEscape(path,mUri,CURL_HANDLER.get());
    }
    if(!mQueries.empty())
    {
        mUri.append("?");
    }
    for(auto &[key,value] : mQueries)
    {
        if(mUri[mUri.size() - 1] != '?') mUri.append("&");
        appendEscape(key,mUri,CURL_HANDLER.get());
        mUri.append("=");
        appendEscape(value,mUri,CURL_HANDLER.get());
    }
    return mUri;
}   