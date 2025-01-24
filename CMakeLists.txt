cmake_minimum_required(VERSION 3.14)

project(to-do-list VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Core Quick REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core Quick REQUIRED)


set(BERKELEYDB_INC /usr/local/BerkeleyDB.18.1/include)
set(BERKELEYDB_LIB /usr/local/BerkeleyDB.18.1/lib)


set(PROJECT_INC
    ${CMAKE_SOURCE_DIR}/tasks/src/primitives
    ${CMAKE_SOURCE_DIR}/tasks/src/persistent_storage
    ${CMAKE_SOURCE_DIR}/utils/src
    ${CMAKE_SOURCE_DIR}/tasks/src/containers
    ${CMAKE_SOURCE_DIR}/GUI/src/gui-initializer
    ${CMAKE_SOURCE_DIR}/tasks/src/interfaces
    ${CMAKE_SOURCE_DIR}/GUI/src/wrappers
    ${CMAKE_SOURCE_DIR}/GUI/src/utils
)

set(PROJECT_SOURCES
    ${CMAKE_SOURCE_DIR}/main/main.cpp
    ${CMAKE_SOURCE_DIR}/GUI/src/qml/qml.qrc
    ${CMAKE_SOURCE_DIR}/GUI/src/utils/gui_helper.hpp
    ${CMAKE_SOURCE_DIR}/GUI/src/wrappers/taskwrapper.hpp
    ${CMAKE_SOURCE_DIR}/GUI/src/wrappers/taskwrapper.cpp
    ${CMAKE_SOURCE_DIR}/tasks/src/primitives/task.hpp
    ${CMAKE_SOURCE_DIR}/tasks/src/primitives/task.cpp
    ${CMAKE_SOURCE_DIR}/GUI/src/gui-initalizer/guiinitializer.cpp
    ${CMAKE_SOURCE_DIR}/GUI/src/wrappers/taskstoragewrapper.cpp
    ${CMAKE_SOURCE_DIR}/GUI/src/wrappers/taskwrapper.cpp
    ${CMAKE_SOURCE_DIR}/tasks/src/persistent_storage/taskmarsheller.cpp
    ${CMAKE_SOURCE_DIR}/tasks/src/primitives/task.cpp
    ${CMAKE_SOURCE_DIR}/tasks/src/containers/storages.cpp
    ${CMAKE_SOURCE_DIR}/tasks/src/core-initializer/coreinitializer.cpp
    ${CMAKE_SOURCE_DIR}/utils/src/dbFactory.cpp
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
    ${BERKELEYDB_LIB}/libdb_cxx.a      
    ${BERKELEYDB_LIB}/libdb_stl.a     )