#include "calendarapi.hpp"
#include <nlohmann/json.hpp>
#include "uribuilder.hpp"
#include <spdlog/spdlog.h>
#include <iostream>

const std::string api = "https://www.googleapis.com/calendar/v3/calendars";

nlohmann::json make_event(const Event &eventDetails)
{
    nlohmann::json event;
    event["summary"]     = eventDetails.eventName;
    event["description"] = eventDetails.eventDescription;
    event["start"]["dateTime"] = eventDetails.startTime;
    event["end"]["dateTime"] = eventDetails.endTime;
    for (const auto& attendee : eventDetails.attendees) {
        event["attendees"].push_back({{"email", attendee}});
    }
    return event;
}



std::string CalendarApi::addEvent(const Event &event, const std::string &accessToken)
{
    auto eventJson = make_event(event);
    UriBuilder apibuilder(api);
    apibuilder.addPath("primary").addPath("events");
    auto [statuscode , response ] = mRequest.post(apibuilder.uri(),eventJson.dump(),
        {{"Content-Type", "application/json"},
         {"Authorization", "Bearer " + accessToken}});
    if(statuscode != HttpCode::OK)
    {
        auto logger = spdlog::get("calendar_logger");
        logger->error("Failed to set the event with response: {}, code: {}",
                    response,static_cast<int>(statuscode));
        throw std::runtime_error("Faield to set the event");
    }
    return nlohmann::json::parse(response)["id"];
}

void CalendarApi::deleteEvent(const std::string &eventId, const std::string &accessToken)
{
    UriBuilder apibuilder(api);
    apibuilder.addPath("primary").addPath("events").addPath(eventId);
    auto [statusCode , response] = mRequest.del(apibuilder.uri(),
        {{"Authorization", "Bearer " + accessToken}});
    if(statusCode != HttpCode::NO_CONTENT)
    {
        auto logger = spdlog::get("calendar_logger");
        logger->error("Failed to delete the event with response: {}, code: {}",
                    response,static_cast<int>(statusCode));
        throw std::runtime_error("Faield to delete the event");
    }
}

void CalendarApi::updateEvent(const Event &event, const std::string &accessToken,
                              const std::string &eventId)
{
    auto eventJson = make_event(event);
    UriBuilder apibuilder(api);
    apibuilder.addPath("primary").addPath("events").addPath(eventId);
    auto [statuscode , response ] = mRequest.put(apibuilder.uri(),eventJson.dump(),
        {{"Content-Type", "application/json"},
         {"Authorization", "Bearer " + accessToken}});
    if(statuscode != HttpCode::OK)
    {
        auto logger = spdlog::get("calendar_logger");
        logger->error("Failed to update the event with response: {}, code: {}",
                    response,static_cast<int>(statuscode));
        throw std::runtime_error("Faield to update the event");
    }
}
