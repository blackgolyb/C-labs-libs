cmake_minimum_required(VERSION 2.8) 

project(queue LANGUAGES C)

set(SOURCE_LIB
    queue.c
)

add_library(${PROJECT_NAME} STATIC ${SOURCE_LIB})