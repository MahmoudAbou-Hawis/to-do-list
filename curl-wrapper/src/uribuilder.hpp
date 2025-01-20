#ifndef URIBUILDE_H_
#define URIBUILDE_H_

#include <memory>
#include <string>
#include "uri.hpp"

class UriBuilder
{
private:
    std::unique_ptr<Uri> mUri;

public:
    UriBuilder(std::string url) ;
    UriBuilder& addPath(std::string path);
    UriBuilder& addQuery(std::string key , std::string value) ;
    std::string uri() const;
};

#endif