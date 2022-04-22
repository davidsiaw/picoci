cmake_minimum_required(VERSION 3.18)

include($ENV{PICO_SDK_PATH}/pico_sdk_init.cmake)
project(picoci C CXX ASM)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

pico_sdk_init()

add_executable(main main.c)

pico_add_extra_outputs(main)
target_link_libraries(main pico_stdlib)


