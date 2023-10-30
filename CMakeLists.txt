cmake_minimum_required(VERSION 3.22.1)
project("Ridesharing")

include_directories(mylib/include)

add_subdirectory(mylib)
add_executable(result main.c)
target_compile_options(result PRIVATE -Wall -O2 -lm)
target_link_libraries(result mylibry m)

