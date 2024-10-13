cmake_minimum_required(VERSION 3.12)
project(storm_black)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -fsanitize=address -Werror=uninitialized")

add_compile_definitions(LOCAL)
add_executable(solution main.cpp)
