cmake_minimum_required(VERSION 3.14)

project(gui VERSION 0.1 LANGUAGES CXX)


set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Core Quick REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core Quick REQUIRED)





set(PROJECT_INC
    gui-initalizer/guiinitializer.hpp
   wrappers/taskstoragewrapper.hpp
   utils/gui_helper.hpp
   wrappers/taskwrapper.hpp
)

set(PROJECT_SOURCES
    wrappers/taskwrapper.cpp
    gui-initalizer/guiinitializer.cpp
    wrappers/taskstoragewrapper.cpp
    wrappers/taskwrapper.cpp
)

add_library(gui-headers INTERFACE)
target_include_directories(gui-headers INTERFACE ${CMAKE_CURRENT_SOURCE_DIR} ${Qt5Widgets_INCLUDE_DIRS})
target_link_libraries(gui-headers INTERFACE tasks-headers utils-headers )



add_library(gui STATIC
          ${PROJECT_SOURCES}
        )

target_link_libraries(gui
  PRIVATE Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Quick)



target_compile_definitions(gui PRIVATE NO_MEMBER_FUNCTION_PARTIAL_SPECIALIZATION)
target_link_libraries(gui PUBLIC gui-headers)
set_property(TARGET gui PROPERTY POSITION_INDEPENDENT_CODE ON)
