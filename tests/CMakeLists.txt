cmake_minimum_required (VERSION 2.6)

enable_testing()

include_directories(${CMAKE_SOURCE_DIR}/azure-c-shared-utility/testtools/ctest/inc)
include_directories(${CMAKE_SOURCE_DIR}/azure-c-shared-utility/testtools/umock-c/inc)
include_directories(${CMAKE_SOURCE_DIR}/conquerWorld)
project(conquerTest)

add_executable(conquerTest main.c test.c)

target_link_libraries(conquerTest ctest umock_c conquerWorld)

