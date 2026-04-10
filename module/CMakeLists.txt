#
# AdvFS-NG: Cross-platform AdvFS for Linux/BSD
# Copyright (c) 2026, Dmitry Sednev <dmitry@sednev.ru>
#
# SPDX-License-Identifier: BSD-3-Clause
#
project(advfs-module)

cmake_host_system_information(RESULT DISTRIB_ID QUERY DISTRIB_ID)
cmake_host_system_information(RESULT DISTRIB_NAME QUERY DISTRIB_NAME)

execute_process(
        COMMAND uname -r
        OUTPUT_VARIABLE KERNEL_RELEASE
        OUTPUT_STRIP_TRAILING_WHITESPACE
)

if("${DISTRIB_ID}" STREQUAL "fedora")
    set(KERNEL_HEADERS /usr/src/kernels/${KERNEL_RELEASE})
else()
    message(FATAL_ERROR "Unsupported OS distribution: ${DISTRIB_NAME}")
endif()

message(STATUS "Distribution: ${DISTRIB_NAME} (${DISTRIB_ID})")
message(STATUS "Kernel release: ${KERNEL_RELEASE}")
message(STATUS "Kernel headers: ${KERNEL_HEADERS}")

if(NOT IS_DIRECTORY ${KERNEL_HEADERS})
    message(FATAL_ERROR "Kernel headers not found")
endif()

include_directories(
    ${KERNEL_HEADERS}/include
    ${KERNEL_HEADERS}/tools/include
)
add_definitions(-D__KERNEL__ -DMODULE)

set(MODULE_FILE advfs.ko)
set(MODULE_SOURCES src/advfs.c)

add_custom_command(
    OUTPUT ${MODULE_FILE}
    COMMAND $(MAKE)
        -C ${KERNEL_HEADERS} modules
        M=${CMAKE_CURRENT_BINARY_DIR}
        src=${CMAKE_CURRENT_SOURCE_DIR}
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    DEPENDS ${MODULE_SOURCES} VERBATIM)

add_custom_target(module ALL DEPENDS ${MODULE_FILE})
