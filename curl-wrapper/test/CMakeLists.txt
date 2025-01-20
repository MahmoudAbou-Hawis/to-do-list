cmake_minimum_required(VERSION 3.14)
project(Curl_wrapper_test)

find_package(CURL REQUIRED)  
find_package(GTest REQUIRED)
find_package(nlohmann_json REQUIRED)

set(PROJECT_INC /home/mahmoud/Documents/to-do-list/curl-wrapper/src
                /home/mahmoud/Documents/to-do-list/utils/src/interfaces)

enable_testing()

add_executable(URIBuilderTest uribuildertest.cpp
                            /home/mahmoud/Documents/to-do-list/curl-wrapper/src/uri.cpp
                            /home/mahmoud/Documents/to-do-list/curl-wrapper/src/uribuilder.cpp)

target_include_directories(URIBuilderTest PRIVATE
    ${PROJECT_INC}
)

target_link_libraries(URIBuilderTest PRIVATE
    GTest::GTest                       
    GTest::Main          
    CURL::libcurl     
)

add_test(NAME UriBuilderTest COMMAND URIBuilderTest)

add_executable(HttpClientTest urirequesttest.cpp
                            /home/mahmoud/Documents/to-do-list/curl-wrapper/src/uri.cpp
                            /home/mahmoud/Documents/to-do-list/curl-wrapper/src/uribuilder.cpp
                            /home/mahmoud/Documents/to-do-list/curl-wrapper/src/httprequest.cpp
                            /home/mahmoud/Documents/to-do-list/curl-wrapper/src/curlFactory.cpp)

                            target_include_directories(HttpClientTest PRIVATE
                            ${PROJECT_INC}
                        )
                        
                        target_link_libraries(HttpClientTest PRIVATE
                            GTest::GTest                       
                            GTest::Main          
                            CURL::libcurl     
                            nlohmann_json::nlohmann_json
                        )
add_test(NAME HttpClientTest COMMAND HttpClientTest)