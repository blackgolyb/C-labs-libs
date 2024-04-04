cmake_minimum_required(VERSION 2.8) 

project(linked_list LANGUAGES C)

set(SOURCE_LIB
    linked_list.c
    linked_list_sort.c
    linked_list_utils.c
)

add_library(${PROJECT_NAME} STATIC ${SOURCE_LIB})