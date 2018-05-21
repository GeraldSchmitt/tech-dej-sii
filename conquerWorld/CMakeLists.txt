cmake_minimum_required (VERSION 2.6)

include_directories(${CMAKE_SOURCE_DIR}/azure-c-shared-utility/testtools/umock-c/inc)

project (conquerWorld)

set(SRC conquerWorld.c myMemory.c)

set(HEADER conquerWorld.h myMemory.h)

add_library(conquerWorld ${SRC} ${HEADERS})
target_link_libraries(conquerWorld aziotsharedutil)