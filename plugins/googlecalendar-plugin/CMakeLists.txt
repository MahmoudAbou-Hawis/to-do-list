project(googleCalender-plugin)

find_package(nlohmann_json REQUIRED)
find_package(spdlog REQUIRED)
find_package(Boost REQUIRED)

include( ${CMAKE_SOURCE_DIR}/secrets.txt)
get_target_property(PLUGIN_API_SOURCE_DIR plugin-api SOURCE_DIR)
include(${PLUGIN_API_SOURCE_DIR}/version.cmake)

add_library(googleCalendar-plugin MODULE
    googlecalendarplugin.hpp
    googlecalendarplugin.cpp
    googlecalendarfacade.hpp
    googlecalendarfacade.cpp
    googlecalendarcommunicator.hpp
    googlecalendarcommunicator.cpp
    googleaddressvalidator.hpp
    googleaddressvalidator.cpp
    googlecalendar-communication/src/calendaraouth.cpp
    googlecalendar-communication/src/calendaraouth.hpp
    googlecalendar-communication/src/calendarapi.hpp
    googlecalendar-communication/src/calendarapi.cpp

    desc.json.in
)

file(MAKE_DIRECTORY  "${CMAKE_CURRENT_BINARY_DIR}/GoogleCalender.plugin")
configure_file(desc.json.in "${CMAKE_CURRENT_BINARY_DIR}/description.json.pred")
file(GENERATE OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/GoogleCalender.plugin/description.json" INPUT "${CMAKE_CURRENT_BINARY_DIR}/description.json.pred" )


target_include_directories(googleCalendar-plugin PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})


target_link_libraries(googleCalendar-plugin PRIVATE plugin-api
                      curl-wrapper nlohmann_json::nlohmann_json
                      spdlog::spdlog plugin-api curl-wrapper utils
                      ${Boost_SYSTEM_LIBRARY})

if(WIN32)
    target_link_libraries(googleCalendar-plugin PUBLIC intl)
endif()

set_target_properties(googleCalendar-plugin PROPERTIES
    PREFIX ""
    POSITION_INDEPENDENT_CODE ON)



install(DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/GoogleCalender.plugin" DESTINATION "plugins")

if(WIN32)
    target_compile_definitions(GoogleCalender-plugin PRIVATE WIN_EXPORT)
endif()
