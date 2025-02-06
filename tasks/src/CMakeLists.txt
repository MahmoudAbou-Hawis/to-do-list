cmake_minimum_required(VERSION 3.14)
project(tasks)

# Sources and Headers
set(SOURCES 
    containers/storages.cpp
    core-initializer/coreinitializer.cpp    
    persistent_storage/taskmarsheller.cpp
    primitives/task.cpp
)

set(HEADERS 
    containers/storages.hpp
    core-initializer/coreinitializer.hpp
    persistent_storage/taskmarsheller.hpp
    primitives/task.hpp
    interfaces/AbstractCoreInitializer.hpp
    persistent_storage/store_helpers.hpp
)

# Create the static library
add_library(tasks STATIC ${SOURCES} ${HEADERS})

# Ensure the include directories are set correctly
target_include_directories(tasks PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}  # Adds the current directory
    ${CMAKE_CURRENT_SOURCE_DIR}/containers  # Add any other directories where headers reside
)

# Link tasks with utils (assuming utils is another library already created)
target_link_libraries(tasks PUBLIC utils)

# Optionally, if you have pre-defined compile definitions, uncomment as needed
# target_compile_definitions(tasks PRIVATE NO_MEMBER_FUNCTION_PARTIAL_SPECIALIZATION)

