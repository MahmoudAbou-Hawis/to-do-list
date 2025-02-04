#ifndef PLUGINMESSAGECOMMUNICATOR_H
#define PLUGINMESSAGECOMMUNICATOR_H

#include "export-definition.hpp"
#include "pluginapierrorcodes.hpp"
#include <string>
#include <optional>


class EXPORTED PluginCommunicator
{
public:
    virtual ~PluginCommunicator() = default;

public:
    [[nodiscard]] virtual PluginApiErrorCodes add(
        const char *TaskName,
        const char *description,
        const char *starttime,
        const char *endtime,
        const char * attendances[],
        size_t size,
        char **id) noexcept = 0;
    [[nodiscard]] virtual PluginApiErrorCodes remove(const char *id) noexcept = 0;
    [[nodiscard]] virtual PluginApiErrorCodes update(const char *id,        
        const char *TaskName,
        const char *description,
        const char *starttime,
        const char *endtime,
        const char *attendances[],
        size_t size)  noexcept = 0;
    [[nodiscard]] virtual PluginApiErrorCodes connect() noexcept = 0;
};

#endif // PLUGINMESSAGECOMMUNICATOR_H
