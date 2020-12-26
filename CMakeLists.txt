cmake_minimum_required(VERSION 2.8)

project(craft)

FILE(GLOB SOURCE_FILES src/*.c)

add_executable(
    main
    ${SOURCE_FILES})

add_definitions(-std=c99 -O3)

find_package(CURL REQUIRED)
include_directories(${CURL_INCLUDE_DIR})



