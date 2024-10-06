cmake_minimum_required(VERSION 3.12)
project(storm_black)

set(CMAKE_CXX_STANDARD 20)
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
# -fsanitize=address
# -Werror=uninitialized
# only on windows:
#set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,--stack,10000000")

add_compile_definitions(LOCAL)
add_executable(solution main.cpp)
