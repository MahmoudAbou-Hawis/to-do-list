#include "uribuilder.hpp"
#include "uri.hpp"
#include <memory>


UriBuilder::UriBuilder(std::string url) 
{
    mUri = std::make_unique<Uri>();
    mUri->mUri = std::move(url);
}

UriBuilder &UriBuilder::addPath(std::string path) 
{
    mUri->mPaths.emplace_back(std::move(path));
    return *this;
}

UriBuilder &UriBuilder::addQuery(std::string key, std::string value) 
{
    mUri->mQueries.emplace_back(std::make_pair(std::move(key), std::move(value)));
    return *this;
}

std::string UriBuilder::uri() const
{
    return mUri->uri();
}
