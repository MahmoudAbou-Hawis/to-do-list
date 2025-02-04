cmake_minimum_required(VERSION 3.14)
project(Curl_wrapper_test)

find_package(CURL REQUIRED)  
find_package(nlohmann_json REQUIRED)
find_package(spdlog REQUIRED)
find_package(GTest REQUIRED)


set(PROJECT_INC /home/mahmoud/Documents/to-do-list/curl-wrapper/src
                /home/mahmoud/Documents/to-do-list/utils/src/interfaces
                /home/mahmoud/Pictures/to-do-list/plugins/googlecalendar-plugin/googlecalender-communication/src)


enable_testing()

add_executable(tokenTest /home/mahmoud/Pictures/to-do-list/plugins/googlecalendar-plugin/googlecalender-communication/test/aothTest.cpp
                        /home/mahmoud/Documents/to-do-list/curl-wrapper/src/uri.cpp
                        /home/mahmoud/Documents/to-do-list/curl-wrapper/src/uribuilder.cpp
                        /home/mahmoud/Documents/to-do-list/curl-wrapper/src/httprequest.cpp
                        /home/mahmoud/Documents/to-do-list/curl-wrapper/src/curlFactory.cpp
                        /home/mahmoud/Pictures/to-do-list/plugins/googlecalendar-plugin/googlecalender-communication/src/calendaraouth.cpp
                        /home/mahmoud/Pictures/to-do-list/plugins/googlecalendar-plugin/googlecalender-communication/src/calendarapi.cpp
                        )


add_test(NAME tokenTest COMMAND tokenTest)

target_include_directories(tokenTest PRIVATE
${PROJECT_INC})

target_link_libraries(tokenTest PRIVATE
    nlohmann_json::nlohmann_json
    CURL::libcurl     
    spdlog::spdlog
    GTest::GTest        
    GTest::Main               
)