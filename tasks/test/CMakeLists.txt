cmake_minimum_required(VERSION 3.14)
project(task_marsheller_test)

find_package(GTest REQUIRED)

set(PROJECT_INC /home/mahmoud/Documents/to-do-list/tasks/src/primitives
                /home/mahmoud/Documents/to-do-list/tasks/src/persistent_storage
                /home/mahmoud/Documents/to-do-list/utils/src
                /home/mahmoud/Documents/to-do-list/tasks/src/containers)

set(BERKELEYDB_INC /usr/local/BerkeleyDB.18.1/include)
set(BERKELEYDB_LIB /usr/local/BerkeleyDB.18.1/lib)

enable_testing()



add_executable(TaskMarshellerTest taskmarshellertest.cpp
                            /home/mahmoud/Documents/to-do-list/tasks/src/persistent_storage/taskmarsheller.cpp
                            /home/mahmoud/Documents/to-do-list/tasks/src/primitives/task.cpp
                            )

target_include_directories(TaskMarshellerTest PRIVATE
    ${PROJECT_INC}
)

target_link_libraries(TaskMarshellerTest PRIVATE 
    GTest::GTest                       
    GTest::Main                       
)

add_test(NAME TaskMarshellerTest COMMAND TaskMarshellerTest)



add_executable(TaskSavingTest tasksavingtest.cpp
                                /home/mahmoud/Documents/to-do-list/tasks/src/containers/storages.cpp
                                /home/mahmoud/Documents/to-do-list/tasks/src/primitives/task.cpp
                                /home/mahmoud/Documents/to-do-list/tasks/src/persistent_storage/taskmarsheller.cpp
                                /home/mahmoud/Documents/to-do-list/utils/src/dbFactory.cpp

                                )

add_test(NAME TaskSavingTest COMMAND TaskSavingTest)
target_include_directories(TaskSavingTest PRIVATE
    ${PROJECT_INC}
    ${BERKELEYDB_INC}
)

# target_link_libraries(TaskSavingTest PRIVATE
#     ${BERKELEYDB_LIB}/libdb_cxx.a      
#     ${BERKELEYDB_LIB}/libdb_stl.a      
#     GTest::GTest                       
#     GTest::Main                       
# )