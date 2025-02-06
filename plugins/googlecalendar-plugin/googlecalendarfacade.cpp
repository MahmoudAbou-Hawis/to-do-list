#include "googlecalendarfacade.hpp"

#include "googleaddressvalidator.hpp"
#include "googlecalendarcommunicator.hpp"
#include "googlecalendarplugin.hpp"
#include <spdlog/spdlog.h>
#include <spdlog/sinks/rotating_file_sink.h>

GoogleCalendarFacade::GoogleCalendarFacade() : 
                        mGoogleAddressValidator(std::make_unique<GoogleAddressValidator>())
{
    spdlog::rotating_logger_mt("calendar_logger", "googlecalendar-plugin.log", 1048576 * 5,
                             3);
}

PluginCommunicator *GoogleCalendarFacade::makeCommunicator() noexcept
{
    return new GoogleCalenderCommunicator;
}


const PluginAddressValidator *GoogleCalendarFacade::getAddressValidator() const noexcept
{
    return mGoogleAddressValidator.get();
}

const char *GoogleCalendarFacade::getId() const noexcept
{
    return ::getPluginId();
}

void GoogleCalendarFacade::release(PluginCommunicator *comm) noexcept
{
    delete comm;
}
