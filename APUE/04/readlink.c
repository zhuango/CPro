#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>


#define STRING 100

int main(void)
{
	char buf[STRING];
	memset(buf,0,STRING);
	if(readlink("liu", buf, STRING) < 0){
		perror("readlink");
		exit(EXIT_FAILURE);
	}
	printf("liu -> %s\n",buf);

	return 0;
}
