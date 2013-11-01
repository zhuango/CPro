/*********************************************
 * test the fucntion dup
 * copy a file description
 * 
 * use the old_fd open a file
 * copy the file descripter called new_fd
 * use write function to write into the new_fd
 * *******************************************/
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>

int main(void)
{
	int fd;	/* point the file you want to open  */
	int new_fd;/* new fd point to the same file */

	/* open file */
	if((fd = open("test",O_WRONLY)) == -1){
		perror("open");
		exit(EXIT_FAILURE);
	}

	/* same file, different fd */
	new_fd = dup(fd);
	printf("old_fd = %d\n",fd);
	printf("new_fd = %d\n", new_fd);

	/* write something */
	if(write(new_fd, "Hello,I'm new_fd\n", 16) == -1){
		perror("write");
		exit(EXIT_FAILURE);
	}

	return 0;
}
