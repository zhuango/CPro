#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

MODULE_INFO(vermagic, VERMAGIC_STRING);

struct module __this_module
__attribute__((section(".gnu.linkonce.this_module"))) = {
 .name = KBUILD_MODNAME,
 .init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
 .exit = cleanup_module,
#endif
 .arch = MODULE_ARCH_INIT,
};

static const struct modversion_info ____versions[]
__used
__attribute__((section("__versions"))) = {
	{ 0x41086e, "module_layout" },
	{ 0x9bedef39, "kobject_put" },
	{ 0xbef9fe65, "cdev_del" },
	{ 0x7d0bea0b, "per_cpu__current_task" },
	{ 0x12da5bb2, "__kmalloc" },
	{ 0xf28b622f, "cdev_init" },
	{ 0x6980fe91, "param_get_int" },
	{ 0xd8e484f0, "register_chrdev_region" },
	{ 0x8fde5204, "slab_buffer_size" },
	{ 0xc8b57c27, "autoremove_wake_function" },
	{ 0x8eb58c6e, "__wake_up_sync" },
	{ 0xc288f8ce, "malloc_sizes" },
	{ 0x684ba88a, "no_llseek" },
	{ 0x973873ab, "_spin_lock" },
	{ 0x105e2727, "__tracepoint_kmalloc" },
	{ 0xfc4f55f3, "down_interruptible" },
	{ 0xfd70aae, "kobject_set_name" },
	{ 0x7485e15e, "unregister_chrdev_region" },
	{ 0xff964b25, "param_set_int" },
	{ 0x76a22f8b, "tty_devnum" },
	{ 0x61c54c5a, "nonseekable_open" },
	{ 0x343a1a8, "__list_add" },
	{ 0xffc7c184, "__init_waitqueue_head" },
	{ 0x2bc95bd4, "memset" },
	{ 0xfc822e6e, "kmem_cache_alloc_notrace" },
	{ 0xb72397d5, "printk" },
	{ 0xa1c76e0a, "_cond_resched" },
	{ 0x2da418b5, "copy_to_user" },
	{ 0x4d80993a, "fasync_helper" },
	{ 0x521445b, "list_del" },
	{ 0x748caf40, "down" },
	{ 0x40c497a1, "cdev_add" },
	{ 0x7dceceac, "capable" },
	{ 0xb2fd5ceb, "__put_user_4" },
	{ 0x4292364c, "schedule" },
	{ 0x642e54ac, "__wake_up" },
	{ 0x37a0cba, "kfree" },
	{ 0x33d92f9a, "prepare_to_wait" },
	{ 0x3f1899f1, "up" },
	{ 0xe292647d, "kill_fasync" },
	{ 0x9ccb2622, "finish_wait" },
	{ 0xf2a644fb, "copy_from_user" },
	{ 0x29537c9e, "alloc_chrdev_region" },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";


MODULE_INFO(srcversion, "F18F83AE5B9B6E524974E86");

static const struct rheldata _rheldata __used
__attribute__((section(".rheldata"))) = {
	.rhel_major = 6,
	.rhel_minor = 3,
};
