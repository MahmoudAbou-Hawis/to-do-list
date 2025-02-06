#include "googlecalendarcommunicator.hpp"
#include <spdlog/spdlog.h>
#include "googlecalendar-communication/src/calendaraouth.hpp"
#include "googlecalendar-communication/src/calendarapi.hpp"

GoogleCalenderCommunicator::GoogleCalenderCommunicator()
{
}

GoogleCalenderCommunicator::~GoogleCalenderCommunicator()
{
}

PluginApiErrorCodes GoogleCalenderCommunicator::add(const char *TaskName,
                                                    const char *description,
                                                    const char *starttime,
                                                    const char *endtime,
                                                    const char *attendances[],
                                                    size_t size,
                                                    char **id) noexcept
{
    std::vector<std::string> attend;
    for (int i = 0; i < size; i++)
    {
        attend.push_back(attendances[i]);
    }
    Event event = {TaskName, description, starttime, endtime, attend};
    try
    {
        auto [type, tocken] = mCalendarOauth->getAuthTocken();
        std::string Id = mCalenderApi->addEvent(event, tocken);
        *id = new char[Id.size() + 1];
        std::strcpy(*id, Id.c_str());
    }
    catch (const std::exception &e)
    {
        auto logger = spdlog::get("calendar_logger");
        logger->warn("exception in {} ,for event {}", e.what(), event.eventName);
        return PluginApiErrorCodes::SendFailed;
    }
    return PluginApiErrorCodes::NoError;
}

PluginApiErrorCodes GoogleCalenderCommunicator::remove(const char *id) noexcept
{
    try
    {
        auto [type, tocken] = mCalendarOauth->getAuthTocken();
        mCalenderApi->deleteEvent(id, tocken);
    }
    catch (const std::exception &e)
    {
        auto logger = spdlog::get("calendar_logger");
        logger->warn("exeption in {} ,for event id = {}", id);
        return PluginApiErrorCodes::DeleteFailed;
    }
    return PluginApiErrorCodes::NoError;
}

PluginApiErrorCodes GoogleCalenderCommunicator::update(const char *id,
                                                       const char *TaskName,
                                                       const char *description,
                                                       const char *starttime,
                                                       const char *endtime,
                                                       const char *attendances[],
                                                       size_t size) noexcept
{
    try
    {
        std::vector<std::string> attend;
        for (int i = 0; i < size; i++)
        {
            attend.push_back(attendances[i]);
        }
        Event event = {TaskName, description, starttime, endtime, attend};
        auto [type, tocken] = mCalendarOauth->getAuthTocken();
        mCalenderApi->updateEvent(event,tocken,id);
    }
    catch (const std::exception &e)
    {
        auto logger = spdlog::get("calendar_logger");
        logger->warn("exeption in {} ,for event id = {}", id);
        return PluginApiErrorCodes::UpdateFailed;
    }

    return PluginApiErrorCodes::NoError;
}

PluginApiErrorCodes GoogleCalenderCommunicator::connect() noexcept
{
    try
    {
        mCalendarOauth = std::make_unique<CalendarOauth>(
          GOOGLE_CLIENT_ID, GOOGLE_CLIENT_SECRET, REDIRECT_URL);
        mCalenderApi = std::make_unique<CalendarApi>();
        mCalendarOauth->authenticate();
    }
    catch(const std::exception& e)
    {
        auto logger = spdlog::get("calendar_logger");
        logger->warn("exeption in {} , connection Failed",e.what());
        return PluginApiErrorCodes::Disconected;
    }
    
    return PluginApiErrorCodes::NoError;
}
