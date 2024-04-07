cmake_minimum_required(VERSION 2.8) 

project(ldeque LANGUAGES C)

set(SOURCE_LIB
    ldeque.c
)

add_library(${PROJECT_NAME} STATIC ${SOURCE_LIB})