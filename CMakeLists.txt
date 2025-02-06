cmake_minimum_required(VERSION 3.14)

project(to-do-list VERSION 0.1 LANGUAGES CXX)

add_subdirectory(utils)


add_subdirectory(plugins-api)
add_subdirectory(curl-wrapper)
add_subdirectory(plugins)
add_subdirectory(plugin-support)



set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Core Quick REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core Quick REQUIRED)
find_package(Boost  REQUIRED system)
find_package(spdlog REQUIRED)





set(PROJECT_INC
    ${CMAKE_SOURCE_DIR}/tasks/src/primitives
    ${CMAKE_SOURCE_DIR}/tasks/src/persistent_storage
    ${CMAKE_SOURCE_DIR}/tasks/src/containers
    ${CMAKE_SOURCE_DIR}/gui/src/gui-initializer
    ${CMAKE_SOURCE_DIR}/tasks/src/interfaces
    ${CMAKE_SOURCE_DIR}/gui/src/wrappers
    ${CMAKE_SOURCE_DIR}/gui/src/utils
    ${CMAKE_SOURCE_DIR}/tasks/src/adapters
)

set(PROJECT_SOURCES
    ${CMAKE_SOURCE_DIR}/main/main.cpp
    ${CMAKE_SOURCE_DIR}/gui/src/qml/qml.qrc
    ${CMAKE_SOURCE_DIR}/gui/src/utils/gui_helper.hpp
    ${CMAKE_SOURCE_DIR}/gui/src/wrappers/taskwrapper.cpp
    ${CMAKE_SOURCE_DIR}/gui/src/wrappers/loaderwrapper.cpp
    ${CMAKE_SOURCE_DIR}/gui/src/gui-initalizer/loginintalizer.cpp
    ${CMAKE_SOURCE_DIR}/tasks/src/primitives/task.cpp
    ${CMAKE_SOURCE_DIR}/gui/src/gui-initalizer/guiinitializer.cpp
    ${CMAKE_SOURCE_DIR}/gui/src/wrappers/taskstoragewrapper.cpp
    ${CMAKE_SOURCE_DIR}/gui/src/wrappers/taskchannel.cpp
    ${CMAKE_SOURCE_DIR}/gui/src/wrappers/taskwrapper.cpp
    ${CMAKE_SOURCE_DIR}/tasks/src/persistent_storage/taskmarsheller.cpp
    ${CMAKE_SOURCE_DIR}/tasks/src/primitives/task.cpp
    ${CMAKE_SOURCE_DIR}/tasks/src/containers/storages.cpp
    ${CMAKE_SOURCE_DIR}/tasks/src/core-initializer/coreinitializer.cpp
    ${CMAKE_SOURCE_DIR}/tasks/src/adapters/pluginAdapter.cpp
)


if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(to-do-list
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET to-do-list APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(to-do-list SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(to-do-list
          ${PROJECT_SOURCES}
        )
    endif()
endif()

target_compile_definitions(to-do-list
  PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)
target_link_libraries(to-do-list
  PRIVATE Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Quick)

set_target_properties(to-do-list PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_import_qml_plugins(to-do-list)
    qt_finalize_executable(to-do-list)
endif()

target_include_directories(to-do-list PRIVATE
    ${PROJECT_INC}
    ${BERKELEYDB_INC}
)

target_link_libraries(to-do-list PRIVATE 
    utils
    plugin-api
    plugins-support
    curl-wrapper
    spdlog::spdlog
    ${Boost_SYSTEM_LIBRARY}
    )



    ##target_link_libraries(to-do-list PRIVATE ${CMAKE_CURRENT_BINARY_DIR}/src/plugin-support plugin-api plugins curl-wrapper)

