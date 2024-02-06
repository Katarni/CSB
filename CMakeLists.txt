cmake_minimum_required(VERSION 3.26)
project(CSB VERSION 0.5)

set(CMAKE_CXX_STANDARD 14)

add_library(CSB INTERFACE
        include/functionsOperators.h)
target_include_directories(CSB INTERFACE
        $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>)

set_target_properties(CSB PROPERTIES PUBLIC_HEADER "include/Dynamic.h")
set_target_properties(CSB PROPERTIES PUBLIC_HEADER "include/VUpdate.h")
set_target_properties(CSB PROPERTIES PUBLIC_HEADER "include/VWrite.h")
set_target_properties(CSB PROPERTIES PUBLIC_HEADER "include/VRead.h")
set_target_properties(CSB PROPERTIES PUBLIC_HEADER "include/SystemState.h")
set_target_properties(CSB PROPERTIES PUBLIC_HEADER "include/Particle.h")
set_target_properties(CSB PROPERTIES PUBLIC_HEADER "include/Vector3.h")
set_target_properties(CSB PROPERTIES PUBLIC_HEADER "include/implem/Read/FileRead.h")
set_target_properties(CSB PROPERTIES PUBLIC_HEADER "include/implem/Read/StreamRead.h")
set_target_properties(CSB PROPERTIES PUBLIC_HEADER "include/implem/Write/FileWrite.h")
set_target_properties(CSB PROPERTIES PUBLIC_HEADER "include/implem/Write/StreamWrite.h")
set_target_properties(CSB PROPERTIES PUBLIC_HEADER "include/implem/Read/StdCinRead.h")
set_target_properties(CSB PROPERTIES PUBLIC_HEADER "include/implem/Write/StdCoutWrite.h")
set_target_properties(CSB PROPERTIES PUBLIC_HEADER "include/implem/Update/NoCollisionsUpdate.h")


install(TARGETS CSB
        EXPORT CSBExport
        PUBLIC_HEADER DESTINATION include
        INCLUDES DESTINATION include)

include(CMakePackageConfigHelpers)

configure_package_config_file(
        "${PROJECT_SOURCE_DIR}/data/CSBConfig.cmake.in"
        "${CMAKE_CURRENT_BINARY_DIR}/CSBConfig.cmake"
        INSTALL_DESTINATION cmake)

write_basic_package_version_file(
        ${CMAKE_CURRENT_BINARY_DIR}/CSBConfigVersion.cmake
        COMPATIBILITY AnyNewerVersion)

install(EXPORT CSBExport
        DESTINATION cmake)

install(FILES "${CMAKE_CURRENT_BINARY_DIR}/CSBConfig.cmake"
        "${CMAKE_CURRENT_BINARY_DIR}/CSBConfigVersion.cmake"
        DESTINATION cmake)

install(FILES "${PROJECT_SOURCE_DIR}/data/config.sh"
        DESTINATION ${CMAKE_INSTALL_PREFIX})
