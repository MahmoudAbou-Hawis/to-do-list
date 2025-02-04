#include "googleaddressvalidator.hpp"
#include <regex>
#include <chrono>
PluginApiErrorCodes GoogleAddressValidator::isValid(const char *time) const noexcept
{
    std::regex pattern("^[0-9]{4}-[0-9]{2}-[0-9]{2}T[0-9]{2}:[0-9]{2}:[0-9]{2}Z$");
    return (std::regex_match(time, pattern))  ? PluginApiErrorCodes::NoError :PluginApiErrorCodes::DateErrorFormat;
}