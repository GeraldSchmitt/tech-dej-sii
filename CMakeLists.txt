cmake_minimum_required (VERSION 2.6)

SET(GCC_COVERAGE_COMPILE_FLAGS "-fprofile-arcs -ftest-coverage")
SET(GCC_COVERAGE_LINK_FLAGS    "-lgcov")

SET( CMAKE_C_FLAGS  "${CMAKE_C_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}" )
SET( CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} ${GCC_COVERAGE_LINK_FLAGS}" )


add_subdirectory(./azure-c-shared-utility/testtools/ctest/ EXCLUDE_FROM_ALL)
add_subdirectory(./azure-c-shared-utility/testtools/umock-c/ EXCLUDE_FROM_ALL)

include_directories ("${PROJECT_SOURCE_DIR}/conquerWorld")
include_directories (${CMAKE_SOURCE_DIR}/azure-c-shared-utility/inc/)

add_subdirectory (conquerWorld) 

add_subdirectory (azure-c-shared-utility)

add_subdirectory (tests)

project (TechDej)
add_executable(TechDej main.c)
target_link_libraries (TechDej conquerWorld aziotsharedutil)