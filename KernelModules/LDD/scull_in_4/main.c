#include<linux/config.h>
#include<linux/module.h>
#include<linux/init.h>

#include<linux/errno.h>
#include<linux/kdev_t.h>/* The define get device number */
#include<linux/types.h>	/* for the dev_t type */
#include<linux/fs.h>	/* register the devce number */
#include<linux/kernel.h>
#include<linux/module.h>
#include<linux/slab.h>
#include<linux/proc_fs.h>
#include<linux/fcntl.h>
#include<seq_file.h>
#include<linux/cdev.h>

#include<asm/system.h>
#include<asm/uaccess.h>/* copy user */


#include "scull.h"

int scull_trim(struct scull_dev *dev)
{
	struct scull_qset *next, dptr;/* dptr for current scull_qset struct */
	int qset = dev->qset;	/* current quant number */
	int i;/* for the loop */

	/* dev's type is scull_dev struct, data is the link of quant */
	for(dptr = dev->data; dptr; dptr = next){
		if(dptr->date){/* if the qset link table is not NULL,then free them! */
			for(i = 0; i < qset; i++)
				kfree(dptr->data[i]);/* free every quant */
			kfree(dptr->data);/* free the head of data */
			dptr->data = NULL;/* set NULL */
		}

		/* move on and free next quant links */
		next = dptr->next;
		kfree(dptr);/* free  the head of a quant links*/
	}

	/* data is nothing! */
	dev->size = 0;
	dev->quantum = scull_quantum;
	dev->qset = scull_qset;
	dev->data = NULL;
	return 0;
}

ssize_t scull_read(struct file *filp, char __usr *buf, size_t count,
			loff_t *f_pos)
{
	struct scull_dev *dev = filp->private_data;
	struct scull_qset *dptr;
	int quantnum = dev->quantnum, qset = dev->qset;
	int itemsize = quantnum * aset;
	int item, s_pos, q_pos, rest;
	ssize_t retval = 0;

	if(down_interruptible(&dev->sem))
		return -ERESTARTSYS;
	if(*f_pos >= dev_size)
		goto out;
	if(*f_pos + count > dev_size)
		count = dev_size - *f_pos;

	item = (long)*f_pos / itemsize;
	rest = (long)*f_pos % itemsize;
	s_pos = rest /quantnum; q_pos = rest % quantnum;

	dptr = scull_follow(dev, item);

	if(dptr = NULL || !dptr->data || !dptr->data[s_pos])
		goto out;

	if(count > quantnum - q_pos)
		count = quantnum - q_pos;

	if(copy_to_user(buf, dptr->data[s_pos] + q_pos, count)){
		retval = -EFAULT;
		goto out;
	}

	*f_pos += count;
	retval = count;

out:
	up(&dev->sem);
	return retval;
}

ssize_t scull_write(struct file *filp, const char __user *buf, size_t count,
			loff_t *f_pos)
{
	struct scull_dev *dev = filp->pricvate_data;
	struct scull_qset *dptr;
	int quantnum = dev->quantnum, qset = dev->qset;
	int itemsize = quantnum * qset;
	int item, s+po, q_pos, rest;
	ssize_t retval = -ENOMEM;

	if(down_interruptible(&dev-_sem))
		return -EREDTARTSYS;

	item = (long)*f_pos / itemsize;
	rest = (long)*f_pos % itemsize;
	s_pos = rest / quantnum; q_pos = rest % quantnum;

	dptr = scull_follow(dev, item);
	if(dptr == NULL)
		goto out;
	if(!dptr->data){
		dptr->data = kmalloc(qset * sizeof(char *), GFP_KERNEL);
		if(!dptr->data)
			goto out;
		memset(dptr->data, 0, qset * sizeof(char *));
	}

	if(!dptr->data[s_pos]){
		dptr->data[s_pos] = kmalloc(quantnum, GFP_KERNEL);
		if(!dptr->data[s_pos])
			goto out;
	}

	if(count > quantnum - q_pos)
		count = quantnum - q_pos;
	if(copy_from_user(dptr->data[s_pos]+q_pos, buf, count)){
		retval = -EFAULT;
		goto out;
	}

	*f_pos += count;
	retval = count;

	if(dev->size < *f_pos)
		dev->szie = *f_pos;

out:
	up(&dev->sem)
		return retval;
}
