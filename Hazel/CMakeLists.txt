cmake_minimum_required(VERSION 3.22)

set(TARGET_NAME Hazel)

file(GLOB_RECURSE HZ_HDRS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "./src/*.h")
file(GLOB_RECURSE HZ_SRCS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "./src/*.cpp")

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_PREFIX_PATH})

find_package(spdlog REQUIRED)
find_package(glfw3 REQUIRED)
find_package(glad REQUIRED)
find_package(glm REQUIRED)

if(WIN32)
find_library(OS_TARGET NAMES imgui REQUIRED)
endif()

find_file(STB_TARGET NAMES "stb_image.h" PATHS "${CMAKE_INSTALL_PREFIX}/include/stb" REQUIRED)

add_library(${TARGET_NAME} STATIC ${HZ_HDRS} ${HZ_SRCS})
target_precompile_headers(${TARGET_NAME} PRIVATE ./src/hzpch.h)
target_include_directories(${TARGET_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src" "${CMAKE_PREFIX_PATH}/include" "${CMAKE_PREFIX_PATH}/include/imgui")
target_link_directories(${TARGET_NAME} PUBLIC "${CMAKE_PREFIX_PATH}/lib")
target_link_libraries(${TARGET_NAME} PUBLIC spdlog::spdlog glad::gladstatic opengl32 glfw imgui)
# if(WIN32)
# target_link_libraries(${TARGET_NAME} PUBLIC)
# endif()
target_compile_definitions(${TARGET_NAME} PUBLIC _CRT_SECURE_NO_WARNINGS)

if(WIN32)
    target_compile_definitions(${TARGET_NAME} PUBLIC HZ_PLATFORM_WINDOWS GLFW_INCLUDE_NONE)
    #HZ_DYNAMIC_LINK
    #target_compile_definitions(${TARGET_NAME} PRIVATE HZ_BUILD_DLL)
    #set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
endif()

if(${CMAKE_BUILD_TYPE} STREQUAL "Debug")
target_compile_definitions(${TARGET_NAME} PUBLIC HZ_DEBUG)
else()
target_compile_definitions(${TARGET_NAME} PUBLIC HZ_RELEASE)
endif()

set_target_properties(${TARGET_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_PREFIX_PATH}/bin")
set_target_properties(${TARGET_NAME} PROPERTIES LIBRARY_OUTPUT_DIRECTORY "${CMAKE_PREFIX_PATH}/bin")
set_target_properties(${TARGET_NAME} PROPERTIES LIBRARY_OUTPUT_DIRECTORY_DEBUG "${CMAKE_PREFIX_PATH}/bin")
set_target_properties(${TARGET_NAME} PROPERTIES LIBRARY_OUTPUT_DIRECTORY_RELEASE "${CMAKE_PREFIX_PATH}/bin")
set_target_properties(${TARGET_NAME} PROPERTIES CXX_STANDARD 17)

install(TARGETS ${TARGET_NAME}
        RUNTIME DESTINATION "${INSTALL_BIN_DIR}"
        ARCHIVE DESTINATION "${INSTALL_LIB_DIR}"
        LIBRARY DESTINATION "${INSTALL_LIB_DIR}")