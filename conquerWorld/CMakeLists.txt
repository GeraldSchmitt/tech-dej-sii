cmake_minimum_required (VERSION 2.6)

project (conquerWorld)

set(SRC conquerWorld.c)

set(HEADER conquerWorld.h)

add_library(conquerWorld ${SRC} ${HEADERS})