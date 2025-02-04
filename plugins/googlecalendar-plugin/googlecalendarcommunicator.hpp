#ifndef GOOGLECALENDARCOMMUNICATOR_H_
#define GOOGLECALENDARCOMMUNICATOR_H_

#include <memory>
#include "export/plugincommuincator.hpp"

class CalendarApi;
class CalendarOauth;

class GoogleCalenderCommunicator final: public PluginCommunicator
{
    public:
        GoogleCalenderCommunicator();
        ~GoogleCalenderCommunicator() override;


     virtual PluginApiErrorCodes add(
        const char *TaskName,
        const char *description,
        const char *starttime,
        const char *endtime,
        const char *attendances[],
        size_t size,
        char **id) noexcept override;
    virtual PluginApiErrorCodes remove(const char *id) noexcept override;
    virtual PluginApiErrorCodes update(const char *id,        
        const char *TaskName,
        const char *description,
        const char *starttime,
        const char *endtime,
        const char *attendances[],
        size_t size) noexcept override;
    virtual PluginApiErrorCodes connect() noexcept override;

    private:   
        std::unique_ptr<CalendarApi> mCalenderApi;
        std::unique_ptr<CalendarOauth> mCalendarOauth;
};


#endif