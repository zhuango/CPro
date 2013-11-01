#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(void)
{
	if(symlink("/usr/local/src", "fee_ro") < 0){
		perror("symlink");
		exit(EXIT_FAILURE);
	}

	if(symlink("Liu", "liu") < 0){
		perror("symlink");
		exit(EXIT_FAILURE);
	}

	return 0;
}
