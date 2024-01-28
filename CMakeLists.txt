cmake_minimum_required(VERSION 3.26)
project(CSB VERSION 0.2)

set(CMAKE_CXX_STANDARD 17)

add_library(CSBlib INTERFACE)
target_include_directories(CSBlib INTERFACE
        $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>)

set_target_properties(CSBlib PROPERTIES PUBLIC_HEADER "include/Dynamic.h")

install(TARGETS CSBlib
        EXPORT CSBlibExport
        PUBLIC_HEADER DESTINATION include
        INCLUDES DESTINATION include) #Needed for proper EXPORT generation

include(CMakePackageConfigHelpers)

configure_package_config_file(
        "${PROJECT_SOURCE_DIR}/data/CSBlibConfig.cmake.in"
        "${CMAKE_CURRENT_BINARY_DIR}/CSBlibConfig.cmake"
        INSTALL_DESTINATION cmake)

write_basic_package_version_file(
        ${CMAKE_CURRENT_BINARY_DIR}/CSBlibConfigVersion.cmake
        COMPATIBILITY AnyNewerVersion)

install(EXPORT CSBlibExport
        DESTINATION cmake)

install(FILES "${CMAKE_CURRENT_BINARY_DIR}/CSBlibConfig.cmake"
        "${CMAKE_CURRENT_BINARY_DIR}/CSBlibConfigVersion.cmake"
        DESTINATION cmake)

install(FILES "${PROJECT_SOURCE_DIR}/data/config.sh"
        DESTINATION ${CMAKE_INSTALL_PREFIX})
