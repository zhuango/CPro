#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	if(rename("foo","fee") < 0){
		perror("rename");
		exit(EXIT_FAILURE);
	}
	return 0;
}
