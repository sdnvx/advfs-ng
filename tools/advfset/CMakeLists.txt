#
# AdvFS-NG: Cross-platform AdvFS for Linux/BSD
# Copyright (c) 2026, Dmitry Sednev <dmitry@sednev.ru>
#
# SPDX-License-Identifier: BSD-3-Clause
#
project(advfs-tools-advfset)

include_directories(include)

add_executable(advfset
    src/main.c
    src/command/create.c
    src/command/show.c
    src/command/rename.c
    src/command/change.c
    src/command/clone.c
    src/command/remove.c
)
