cmake_minimum_required(VERSION 3.16)

project(c_linked_list C)

set(CMAKE_C_STANDARD 99)

include_directories(include)

add_executable(linked_list_example
    examples/main.c
    src/linked_list.c
)

add_executable(test_linked_list
    tests/test_linked_list.c
    src/linked_list.c
)
