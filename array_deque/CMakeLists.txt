cmake_minimum_required(VERSION 2.8) 

project(array_deque LANGUAGES C)

set(SOURCE_LIB
    array_deque.c
)

add_library(${PROJECT_NAME} STATIC ${SOURCE_LIB})