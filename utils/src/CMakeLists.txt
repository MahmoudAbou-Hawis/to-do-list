cmake_minimum_required(VERSION 3.14)
project(utils)



set(SOURCES 
    dbFactory.cpp
)


set(HEADERS

    dbFactory.hpp
    storage.hpp
)

set(BERKELEYDB_INC /usr/local/BerkeleyDB.18.1/include)
set(BERKELEYDB_LIB /usr/local/BerkeleyDB.18.1/lib)



add_library(utils STATIC ${SOURCES} ${HEADERS})
target_include_directories(utils PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} ${BERKELEYDB_INC})
target_link_libraries(utils PRIVATE
    ${BERKELEYDB_LIB}/libdb_cxx.a      
    ${BERKELEYDB_LIB}/libdb_stl.a     )
set_property(TARGET utils PROPERTY POSITION_INDEPENDENT_CODE ON)
add_library(utils-headers INTERFACE)
target_include_directories(utils-headers INTERFACE ${CMAKE_CURRENT_SOURCE_DIR} ${BERKELEYDB_INC})