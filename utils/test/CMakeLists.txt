cmake_minimum_required(VERSION 3.14)
project(utils_test)

find_package(GTest REQUIRED)



enable_testing()



add_executable(StorageTest storagetest.cpp)

target_include_directories(StorageTest PRIVATE
    ${PROJECT_INC}
    ${BERKELEYDB_INC}
)

target_link_libraries(StorageTest PRIVATE
    utils
    GTest::GTest                       
    GTest::Main                       
)

add_test(NAME StorageTest COMMAND StorageTest)
