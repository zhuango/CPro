#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>

int main(void)
{
	char *args[] = {"/bin/ls",NULL};

	if( execve("/bin/ls",args,NULL) == -1){
		perror("execve");
		exit(EXIT_FAILURE);
	}

	puts("shouldn't get here");//if execve do successfully ,then this puts is can't be done.

	exit(EXIT_SUCCESS);
}
