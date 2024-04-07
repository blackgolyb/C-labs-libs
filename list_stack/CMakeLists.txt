cmake_minimum_required(VERSION 2.8) 

project(list_stack LANGUAGES C)

set(SOURCE_LIB
    list_stack.c
)

add_library(${PROJECT_NAME} STATIC ${SOURCE_LIB})