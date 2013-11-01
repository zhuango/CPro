#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(void)
{
	if(remove("fee_ro") < 0){
		perror("remove");
		exit(EXIT_FAILURE);
	}

	return 0;
}
