#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	if(chown("te",500 , 500) == -1){
		perror("chown");
		exit(EXIT_FAILURE);
	}

	exit(EXIT_SUCCESS);
}
