#
# AdvFS-NG: Cross-platform AdvFS for Linux/BSD
# Copyright (c) 2026, Dmitry Sednev <dmitry@sednev.ru>
#
# SPDX-License-Identifier: BSD-3-Clause
#
project(advfs-tools-advfdmn)

include_directories(include)

add_executable(advfdmn
    src/main.c
    src/command/list.c
    src/command/create.c
    src/command/show.c
    src/command/addvol.c
    src/command/chvol.c
    src/command/rmvol.c
    src/command/balance.c
    src/command/stripe.c
    src/command/switchlog.c
    src/command/remove.c
)
