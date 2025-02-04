cmake_minimum_required(VERSION 3.22)
project(curl-wrapper)

find_package( CURL REQUIRED)


set(HEADERS
    curlexceptions.hpp
    curlFactory.hpp
    httpcode.hpp
    httprequest.hpp
    uri.hpp
    uribuilder.hpp
)

set(SOURCES
    uribuilder.cpp
    uri.cpp
    httprequest.cpp
    curlFactory.cpp
)


add_library(curl-wrapper STATIC ${SOURCES} ${HEADERS})
link_directories( ${CURL_LIBRARIES} )
target_include_directories(curl-wrapper PUBLIC  ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(curl-wrapper PUBLIC  curl)

if(WIN32)
    message("Used for windows build")
    target_link_libraries(curl-wrapper PUBLIC wldap32 ws2_32)
endif()

set_target_properties(curl-wrapper PROPERTIES POSITION_INDEPENDENT_CODE ON)
add_library(curl-wrapper-headers INTERFACE)
target_include_directories(curl-wrapper-headers INTERFACE ${CMAKE_CURRENT_SOURCE_DIR} 
                                                          ${CURL_INCLUDE_DIR})