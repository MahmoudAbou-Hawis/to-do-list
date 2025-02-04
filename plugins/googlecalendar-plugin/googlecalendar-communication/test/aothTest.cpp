#include <gtest/gtest.h>
#include "calendaraouth.hpp"
#include "calendarapi.hpp"
#include <thread>
#include <chrono>

std::string eventId = ""; 

CalendarOauth test("",
"",
REDIRECT_URL);

TEST(CalendarApiTest, AddCalenderEventTest)
{

    test.authenticate();

    CalendarApi api;    

    Event meeting = {
    "Team Sync", 
    "Weekly team meeting to discuss progress and blockers.", 
    "2025-02-01T10:00:00Z", 
    "2025-02-01T11:00:00Z", 
    {"mahmoud.abohawis10@gmail.com"}
    };


    test.accessToken();

    auto [tockenType,tocken] = test.getAuthTocken();

    eventId = api.addEvent(meeting,tocken);
    ASSERT_NE(eventId.size(),0);

}




TEST(CalendarApiTest, UpdateCalenderEventTest)
{

    CalendarApi api;    

    Event meeting = {
    "Team Sync", 
    "Weekly team meeting to discuss progress and blockers.", 
    "2025-02-01T10:00:00Z", 
    "2025-02-01T11:00:00Z"
    };

    std::cout << eventId << '\n';


    auto [tockenType,tocken] = test.getAuthTocken();

    api.updateEvent(meeting,tocken,eventId);
}



TEST(CalendarApiTest, DeleteCalenderEventTest)
{
     std::this_thread::sleep_for(std::chrono::seconds(60));
    CalendarApi api;    
    auto [tockenType,tocken] = test.getAuthTocken();
    api.deleteEvent(eventId,tocken);
}