/* **************************************************************************
 * test the file whole
 * using the lseek function
 * the lseek function can set the position over file length
 * then you write somothing trings input this position, there will be a whole
 * open->write->lseek->write->close
 * **************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>

int main(void)
{
	int fd;/* file descripter */

	/* open file */
	if((fd = open("whole.test", O_WRONLY | O_CREAT, 0666)) == -1){
		perror("open");
		exit(EXIT_FAILURE);
	}

	/* write something */
	if(write(fd,"Hello", 5) == -1){
		perror("write");
		exit(EXIT_FAILURE);
	}
	
	/* set the position  */
	if(lseek(fd,100,SEEK_END) == -1){
		perror("seek");
		exit(EXIT_FAILURE);
	}

	/* write again to get the whole */
	if(write(fd,"You", 3) == -1){
		perror("write2 ");
		exit(EXIT_FAILURE);
	}
	/* close file */
	if(close(fd) == -1){
		perror("close");
		exit(EXIT_FAILURE);
	}

	return 0;
}
