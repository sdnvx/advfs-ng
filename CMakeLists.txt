#
# AdvFS-NG: AdvFS for Linux
# Copyright (c) 2026, Dmitry Sednev <dmitry@sednev.ru>
#
# SPDX-License-Identifier: BSD-3-Clause
#
cmake_minimum_required(VERSION 3.25)

project(advfs-ng
        VERSION 0.1.0
        DESCRIPTION "AdvFS for Linux"
        HOMEPAGE_URL https://github.com/sdnvx/advfs-ng
        LANGUAGES C)

set(ADVFS_VERSION "${CMAKE_PROJECT_VERSION}")

set(ADVFS_VERSION_MAJOR "${CMAKE_PROJECT_VERSION_MAJOR}")
set(ADVFS_VERSION_MINOR "${CMAKE_PROJECT_VERSION_MINOR}")
set(ADVFS_VERSION_PATCH "${CMAKE_PROJECT_VERSION_PATCH}")

if(NOT ADVFS_RELEASE_DATE)
    string(TIMESTAMP ADVFS_RELEASE_DATE "%Y-%m-%d")
endif()

set(CMAKE_C_STANDARD 23)
set(CMAKE_C_EXTENSIONS ON)

set(CMAKE_COMPILE_WARNING_AS_ERROR ON)

if("${CMAKE_BUILD_TYPE}" STREQUAL "")
    set(CMAKE_BUILD_TYPE Debug)
endif()

if("${CMAKE_BUILD_TYPE}" STREQUAL "Debug")
    add_compile_options(-g -fsanitize=address -fno-omit-frame-pointer)
    add_link_options(-fsanitize=address)
else()
    add_compile_options(-O2)
    add_compile_definitions(NDEBUG)
endif()

add_subdirectory(tools)
