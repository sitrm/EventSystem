cmake_minimum_required(VERSION 3.28)
project(EventSystem_glfw)
#--------help-----------
#mkdir build && cd build
#cmake .. 
#cmake --build . --config debug/release
#-----------------------


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON) 


set(LIB_DIR "${PROJECT_SOURCE_DIR}/lib")
set(LIB_NAME "glfw3")


# Найдите библиотеку core
#HINTS доп подсказки где искать библиотеку 
find_library(LIB_PATH NAMES ${LIB_NAME} HINTS ${LIB_DIR})


include_directories(
        ${PROJECT_SOURCE_DIR}/src
        ${PROJECT_SOURCE_DIR}/include
)

file(GLOB all_SRCS
        "${PROJECT_SOURCE_DIR}/include/*.h"
        "${PROJECT_SOURCE_DIR}/include/GLFW/*.h"
        "${PROJECT_SOURCE_DIR}/src/*.cpp"
)

link_directories(${LIB_DIR})

add_executable(EventSystem ${all_SRCS})


if(NOT LIB_PATH)
    message(FATAL_ERROR "Library 'glfw3' not found in ${LIB_DIR}")
else()
    message(STATUS "Library '${LIB_NAME}' found at ${LIB_PATH}")
    target_link_libraries(EventSystem ${LIB_PATH})
    link_directories(${LIB_DIR})
endif()

