#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>

//********************************************************
//Function: Set the lock info
//
//fd: For the file you open
//cmd: What you want(get lock? set lock? unlock?)
//type: In this case, type mean what lock do you wanna get
//offset: Offset relative the whence
//whence: Offset's start
//len: Number of byte you want to lock
//********************************************************
int lock_reg(int fd, int cmd, int type, off_t offset, int whence, off_t len)
{
	struct flock lock;

	/* Set the lock statu */
	lock.l_type = type;/*Type */
	lock.l_start = offset;/* Offset */
	lock.l_whence = whence;/* Whence */
	lock.l_len = len;/*Length of locked bytes */

	return (fcntl(fd, cmd, &lock));/* Return true or false */
}
/* Function write_lock's define */
#define write_lock(fd, offset, whence, len) \
	lock_reg((fd), F_SETLKW, F_WRLCK, (offset), (whence), (len))
//**************************************
//Function: Get the lock
//name: Which process call this function
//fd: File you want to lock
//offset:offset from the file
//**************************************
static void lockabyte(const char *name, int fd, off_t offset)
{
	/* call the write_lock function, and get the lock */
	if(write_lock(fd, offset, SEEK_SET, 1) < 0){/*error?*/
		perror("write_lock");
		exit(EXIT_FAILURE);
	}
	printf("%s get write lock\n", name);/*print info */
}

int main(void)
{
	int fd;/* file you want to open */
	pid_t pid;/* new peocess */

	if((fd = creat("templock", 0777)) < 0){/* create a new file named "templock" */
		perror("create");/* error? */
		exit(EXIT_FAILURE);
	}
	/* write two bytes */
	if(write(fd, "ab", 2) < 0){
		perror("write");/* error? */
		exit(EXIT_FAILURE);
	}

	/* create a new process */
	if((pid = fork()) < 0){
		perror("fork");
		exit(EXIT_FAILURE);
	}else if(pid == 0){/* child */
		lockabyte("child", fd, 1);/* child want to lock second bytes */
		sleep(2);/* sleep to wait parent */
		lockabyte("child", fd, 0);/* child want to lock first bytes */
	}else{
		sleep(1);/* wait for child */
		lockabyte("parent", fd, 0);/* want to lock the first bytes */
		lockabyte("parent", fd, 1);/* want to lock the second bytes */
	}

	exit(EXIT_SUCCESS);/* exit */
}

