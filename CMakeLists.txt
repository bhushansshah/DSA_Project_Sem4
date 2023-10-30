cmake_minimum_required(VERSION 3.22.1)
project("Ridesharing")

include_directories(mylib)

add_executable(result main.c)

target_link_libraries(result mylibry)

add_subdirectory(mylib)
