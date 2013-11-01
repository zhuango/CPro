#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>

int main(void)
{
	if(lseek(STDIN_FILENO,0,SEEK_CUR) == -1){
		puts("cannot seek");
	}else	puts("seek OK");

	exit(EXIT_FAILURE);
}
