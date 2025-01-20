#ifndef URI_H
#define URI_H

#include <string>
#include <vector>

class Uri
{
public:
    std::vector<std::pair<std::string, std::string>> mQueries;
    std::vector<std::string> mPaths;
    std::string mUri;
    std::string uri();
};
#endif