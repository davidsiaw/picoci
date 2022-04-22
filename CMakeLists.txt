cmake_minimum_required(VERSION 3.18)

project(picoci C CXX)

include($ENV{PICO_SDK_PATH}/pico_sdk_init.cmake)
pico_sdk_init()

add_executable(main main.c)

pico_add_extra_outputs(main)
target_link_libraries(main pico_stdlib)


