static void scull_setup_cdev(struct scull_dev *dev, int index)
{
	int err, devno = MKDEV(scull_major, scull_minor + index);/* get the dev number */
	cdev_init(&dev->cdev, &scull_fops);/* init the cdev */
	dev->cdev.owner = THIS_MODULE;	/* owner */
	dev->cdev.ops = &scull_fops;	/* file_operations */
	err = cdev_add(&dev->cdev, devno, 1);/* tell kernel about the  */

	if(err)
		printk(KERN_NOTICE "Error %d adding scull%d\n", err, index);
}

int scull_trim(struct scull_dev *dev)
{
	struct scull_qset *dptr, *next;/* get the dataof scull_dev */
	int qset = dev->qset;/*number */
	int i;

	for(dptr = dev->data; dptr; dptr = next){
		if(dptr->data) {
			for(i = 0; i < qset; i++)
				kfree(dptr->data[i]);
			kfree(dptr->data);
			dptr->data = NULL;
		}
		next = dptr->next;
		kfree(dptr);
	}
	dev->size = 0;
	dev->quantum = scull_quantum;
	dev->qset = scull_qset;
	dev->data = NULL;
	return 0;
}
