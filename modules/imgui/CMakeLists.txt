cmake_minimum_required(VERSION 3.20)

project(imgui LANGUAGES CXX)

set(BUILD_IMGUI_FILES 
    ./imgui/imgui_demo.cpp
    ./imgui/imgui_draw.cpp
    ./imgui/imgui_tables.cpp
    ./imgui/imgui_widgets.cpp
    ./imgui/imgui.cpp

    ./imgui/backends/imgui_impl_opengl3.cpp 
    ./imgui/backends/imgui_impl_glfw.cpp 
)


add_library(imgui STATIC ${BUILD_IMGUI_FILES})

target_include_directories(imgui PUBLIC ./imgui ./imgui/backends ${CMAKE_INSTALL_PREFIX}/include)

install(DIRECTORY imgui/ DESTINATION ${CMAKE_INSTALL_PREFIX}/include/imgui FILES_MATCHING
PATTERN imgui.h 
PATTERN imconfig.h 
PATTERN imgui_internal.h 
PATTERN imstb_rectpack.h 
PATTERN imstb_textedit.h
PATTERN imstb_truetype.h)

install(DIRECTORY imgui/backends/ DESTINATION ${CMAKE_INSTALL_PREFIX}/include/imgui/backends FILES_MATCHING
PATTERN imgui_impl_glfw.h
PATTERN imgui_impl_opengl3.h)

install(TARGETS imgui RUNTIME DESTINATION ${CMAKE_INSTALL_PREFIX})