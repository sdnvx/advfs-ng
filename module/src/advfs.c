//
// AdvFS-NG: Cross-platform AdvFS for Linux/BSD
// Copyright (c) 2026, Dmitry Sednev <dmitry@sednev.ru>
//
// SPDX-License-Identifier: BSD-3-Clause
//
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>

MODULE_DESCRIPTION("AdvFS filesystem");
MODULE_VERSION("0.1");
MODULE_AUTHOR("Dmitry Sednev");
MODULE_LICENSE("Dual BSD/GPL");

static int __init advfs_start(void)
{
    printk(KERN_INFO "Loading AdvFS module...\n");
    return 0;
}

static void __exit advfs_end(void)
{
    printk(KERN_INFO "Unloading AdvFS module\n");
}

module_init(advfs_start);
module_exit(advfs_end);
