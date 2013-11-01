/*************************
 * test the signal alarm
 * input something to file
 *************************/

#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<fcntl.h>
#include<time.h>

/* signal function */
static void print_message(int signum);
//void stop(int signum);

int main(void)
{
	signal(SIGALRM, print_message);
//	signal(SIGINT, stop);
	alarm(2);/* set the alarm time, touch the signal */
	while(1);
}

static void print_message(int signum)
{
	int fd;	/* use to point the file you want to input */
	char *string;/* string you want to input */
	time_t now;
	time(&now);
	string = ctime(&now);

	if((fd = open("test",O_WRONLY | O_CREAT | O_APPEND
					, 0666)) == -1){	/* open the file */

		perror("open file");
		exit(EXIT_FAILURE);
	}
	/* write the string into file */
	if(write(fd,string,25) == -1){
		perror("write");
		exit(EXIT_FAILURE);
	}
	close(fd);

	alarm(2);/* reset the alarm, for the next alarm */
	
}

/*
void stop(int signum)
{
	printf("Stop!!!\n");
	exit(EXIT_FAILURE);
}
*/
