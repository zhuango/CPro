#ifndef __DATA_H_
#define __DATA_H_

#define SCULL_MAJOR 0
#define SCULL_MINOR 0
#define SCULL_N		4
#define SCULL_QUANTUM 4000
#define SCULL_QSET 1000

struct scull_qset{
	void **data;
	struct scull_qset *next;
};

struct scull_dev{
	struct scull_qset *data;
	int quantum;
	int qset;
	unsigned long size;
	unsigned int access_key;
	struct semaphore sem;
	struct cdev cdev;
};
struct scull_dev *scull_devices;
int scull_trim(struct scull_dev *dev);

#include"fop.c"
/* devices number */
extern int scull_major = SCULL_MAJOR;
extern int scull_minor = SCULL_MINOR;
extern int scull_nr_devs = SCULL_N;
extern int scull_quantum = SCULL_QUANTUM;
extern int scull_qset = SCULL_QSET;


/* kernel struct named file_operations  */
struct file_operations scull_fops = {
	.owner	= THIS_MODULE,
	.llseek	= scull_llseek,
	.read	= scull_read,
	.write	= scull_write,
	.ioctl	= scull_ioctl,
	.open	= scull_open,
	.release= scull_release,
};

#include "scull_func.c"

#endif
