cmake_minimum_required(VERSION 3.22)

project(stb LANGUAGES C)

add_library(stb INTERFACE)
target_include_directories(stb INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/stb")

install(
    DIRECTORY ${PROJECT_SOURCE_DIR}/stb
    DESTINATION ${CMAKE_INSTALL_PREFIX}/include
)