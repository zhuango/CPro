#include<linux/init.h>
#include<linux/module.h>
#include<linux/sched.h>

MODULE_LICENSE("Dual BSD/GPL");

static int hello_init(void)
{
/*	current->state = TASK_UNINTERRUPTIBLE;*/
	printk(KERN_ALERT "Hello, LiuZhuang %d\n", current->pid);
	return 0;
}

static void hello_exit(void)
{
	printk(KERN_ALERT "Goodbye, cruel world\n");
}

module_init(hello_init);
module_exit(hello_exit);
