cmake_minimum_required(VERSION 3.12)
project(storm_black)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -ftrapv -fsanitize=address -Werror=uninitialized")
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -O2")

add_compile_definitions(LOCAL)
add_executable(solution main.cpp)
