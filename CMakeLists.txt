cmake_minimum_required (VERSION 2.6)

include_directories ("${PROJECT_SOURCE_DIR}/conquerWorld")
add_subdirectory (conquerWorld) 

project (TechDej)
add_executable(TechDej main.c)
target_link_libraries (TechDej conquerWorld)