cmake_minimum_required(VERSION 3.22)

set(TARGET_NAME Sandbox)

file(GLOB_RECURSE SDB_HDRS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "./src/*.h")
file(GLOB_RECURSE SDB_SRCS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "./src/*.cpp")

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_PREFIX_PATH})

set(WINDOWED_ARG)

# if(WIN32)
# set(WINDOWED_ARG WIN32)
# endif()

add_executable(${TARGET_NAME} ${WINDOWED_ARG} ${SDB_HDRS} ${SDB_SRCS})
target_include_directories(${TARGET_NAME} PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/src")
target_link_directories(${TARGET_NAME} PUBLIC "${CMAKE_PREFIX_PATH}/lib")
target_link_libraries(${TARGET_NAME} PRIVATE Hazel)

set_target_properties(${TARGET_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_PREFIX_PATH}/bin")
set_target_properties(${TARGET_NAME} PROPERTIES LIBRARY_OUTPUT_DIRECTORY "${CMAKE_PREFIX_PATH}/bin")
set_target_properties(${TARGET_NAME} PROPERTIES LIBRARY_OUTPUT_DIRECTORY_DEBUG "${CMAKE_PREFIX_PATH}/bin")
set_target_properties(${TARGET_NAME} PROPERTIES LIBRARY_OUTPUT_DIRECTORY_RELEASE "${CMAKE_PREFIX_PATH}/bin")
set_target_properties(${TARGET_NAME} PROPERTIES CXX_STANDARD 17)

add_custom_target(copy_resources ALL
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_CURRENT_SOURCE_DIR}/assets
        ${CMAKE_PREFIX_PATH}/bin/assets
        COMMENT "Copying resources into binary directory")

add_dependencies(${TARGET_NAME} copy_resources)

install(TARGETS ${TARGET_NAME}
        RUNTIME DESTINATION "${INSTALL_BIN_DIR}"
        ARCHIVE DESTINATION "${INSTALL_LIB_DIR}"
        LIBRARY DESTINATION "${INSTALL_LIB_DIR}")