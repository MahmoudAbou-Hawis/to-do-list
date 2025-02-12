#ifndef CALENDERAPI_H
#define CALENDERAPI_H

#include <string>
#include <vector>

#include "httprequest.hpp"


struct Event
{
    std::string eventName;
    std::string eventDescription;
    std::string startTime;
    std::string endTime;
    std::vector<std::string> attendees;
};

class CalendarApi
{
    public:
       explicit CalendarApi(){};

    public:
        std::string addEvent(const Event &event, const std::string &accessToken);

        void deleteEvent(const std::string &eventId, const std::string &accessToken);

        void updateEvent(const Event &event, const std::string &accessToken,
                         const std::string &eventId);
    private:
        HttpRequest mRequest;
};


#endif