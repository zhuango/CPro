#include<linux/init.h>
#include<linux/module.h>
#include<linux/fs.h>/* for the file_operations struct */
#include<linux/cdev.h>


#include"data.h"

MODULE_LICENSE("Dual BSD/GPL");

static void scull_cleanup_module(void)
{
	int i;
	dev_t devno = MKDEV(scull_major, scull_minor);

	if(scull_devices){
		for(i = 0; i < scull_nr_devs; i++){
//			scull_trim(scull_devices + i);
			cdev_del(&scull_devices[i].cdev);
		}
		kfree(scull_devices);
	}
	unregister_chrdev_region(devno, scull_nr_devs);
}

static int scull_init_module(void)
{
	int result, i;
	dev_t devnum = 0;

	/* get the space for device */
	if(scull_major){/* get the dev number and register */
		devnum = MKDEV(scull_major, scull_minor);
		if((result = register_chrdev_region(devnum, scull_nr_devs, "scull")) < 0)
			printk(KERN_ALERT"Register_chrdev_region Bad!");
	}else {/* have no dev number then alloc one */
		if((result = alloc_chrdev_region(&devnum, 0, 2, "scull")) < 0)
			printk(KERN_ALERT"Alloc_chrdev_region Bad!\n");
	}

	if(result < 0){/* Error? */
		return result;
	}

	scull_devices = kmalloc(scull_nr_devs * sizeof(struct scull_dev), GFP_KERNEL);
	if(!scull_devices){
		result = -ENOMEM;
		goto fail;
	}
	memset(scull_devices, 0, scull_nr_devs * sizeof(struct scull_dev));

	for(i = 0; i < scull_nr_devs; i++){
		scull_devices[i].quantum = scull_quantum;
		scull_devices[i].qset = scull_qset;
		init_MUTEX(&scull_devices[i].sem);
		scull_setup_cdev(&scull_devices[i], i);
	}

	return 0;

fail:
	scull_cleanup_module();
	return result;
}


module_init(scull_init_module);
module_exit(scull_cleanup_module);
