project(plugin-api LANGUAGES CXX)
include(version.cmake)


add_library(plugin-api STATIC
    export/pluginaddressvalidator.hpp
    export/pluginapierrorcodes.hpp
    export/plugincommuincator.hpp
    export/pluginfacade.hpp
    inner/plugindef.hpp
    api-version.h.in
    plugin.schema.json
)


configure_file(api-version.h.in ${CMAKE_CURRENT_BINARY_DIR}/api-version.h @ONLY)
target_include_directories(plugin-api PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR} )
set_target_properties(plugin-api PROPERTIES LINKER_LANGUAGE CXX)
set_target_properties(plugin-api PROPERTIES SCHEMA_FILE ${CMAKE_CURRENT_SOURCE_DIR}/plugin.schema.json)
