#ifndef __FOP_C_
#define __FOP_C_

loff_t scull_llseek(struct file *filp , loff_t offset, int num)
{
	return ;
}

ssize_t scull_read(struct file *filp, char __user *uc, size_t size, loff_t *offset)
{
	return ;
}

ssize_t scull_write(struct file *fifp, const char __user *uc, size_t size, loff_t *offset)
{
	return ;
}

int scull_ioctl(struct inode *i, struct file *filp, unsigned int n, unsigned long n2)
{
	return ;
}

int scull_open(struct inode *inode, struct file *filp)
{
	struct scull_dev *dev;
	dev = container_of(inode->i_cdev, struct scull_dev , cdev);
	filp->private_data = dev;

	if((filp->f_flags & O_ACCMODE) == O_WRONLY){
		scull_trim(dev);
	}
	return 0;
}

int scull_release(struct inode *i, struct file *fifp)
{
	return 0;
}

#endif
