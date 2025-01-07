cmake_minimum_required(VERSION 3.14)
project(utils_test)

find_package(GTest REQUIRED)

set(PROJECT_INC /home/mahmoud/Documents/to-do-list/utils/src
                /home/mahmoud/Documents/to-do-list/utils/src/interfaces)
set(BERKELEYDB_INC /usr/local/BerkeleyDB.18.1/include)
set(BERKELEYDB_LIB /usr/local/BerkeleyDB.18.1/lib)

enable_testing()



add_executable(StorageTest storagetest.cpp
                            /home/mahmoud/Documents/to-do-list/utils/src/dbFactory.cpp)

target_include_directories(StorageTest PRIVATE
    ${PROJECT_INC}
    ${BERKELEYDB_INC}
)

target_link_libraries(StorageTest PRIVATE
    ${BERKELEYDB_LIB}/libdb_cxx.a      
    ${BERKELEYDB_LIB}/libdb_stl.a      
    GTest::GTest                       
    GTest::Main                       
)

add_test(NAME StorageTest COMMAND StorageTest)
