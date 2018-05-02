cmake_minimum_required (VERSION 2.6)

add_subdirectory(./azure-c-shared-utility/testtools/ctest/ EXCLUDE_FROM_ALL)

include_directories ("${PROJECT_SOURCE_DIR}/conquerWorld")
#include_directories (${CMAKE_SOURCE_DIR}/azure-c-shared-utility/inc/azure_c_shared_utility/)
include_directories (${CMAKE_SOURCE_DIR}/azure-c-shared-utility/inc/)

add_subdirectory (conquerWorld) 

add_subdirectory (azure-c-shared-utility)

add_subdirectory (tests)

project (TechDej)
add_executable(TechDej main.c)
target_link_libraries (TechDej conquerWorld aziotsharedutil)