cmake_minimum_required(VERSION 2.8) 

project(dyn_array LANGUAGES C)

set(SOURCE_LIB ${PROJECT_NAME}.c)

add_library(${PROJECT_NAME} STATIC ${SOURCE_LIB})