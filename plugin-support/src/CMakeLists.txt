cmake_minimum_required(VERSION 3.22)
project(plugin-support)

find_package(nlohmann_json REQUIRED)
find_package(spdlog REQUIRED)


SET(PLUGIN_SUPPORT_HEADER
    own_deleter.hpp
    pluginhcommunicatorwrapper.hpp
    plugininterface.hpp
    pluginloader.hpp
    supportfunctions.hpp
)

SET(PLUGIN_SUPPORT_SOURCES
        pluginhcommunicatorwrapper.cpp
        plugininterface.cpp
        pluginloader.cpp
)


add_library(plugins-support-headers INTERFACE)
target_include_directories(plugins-support-headers INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(plugins-support-headers INTERFACE plugin-api)


add_library(plugins-support  STATIC ${PLUGIN_SUPPORT_SOURCES} ${PLUGIN_SUPPORT_HEADER})
target_link_libraries(plugins-support PUBLIC plugins-support-headers)
target_link_libraries(plugins-support PRIVATE   ${CMAKE_DL_LIBS}  nlohmann_json::nlohmann_json
spdlog::spdlog  dynalo-headers )


set_property(TARGET plugins-support PROPERTY POSITION_INDEPENDENT_CODE ON)

get_target_property(PLUGIN_API_SOURCE_DIR plugin-api SOURCE_DIR)

install(FILES  ${PLUGIN_API_SOURCE_DIR}/plugin.schema.json DESTINATION ".")


add_library(dynalo-headers INTERFACE)
target_include_directories(dynalo-headers INTERFACE /usr/local/include/dynalo)
