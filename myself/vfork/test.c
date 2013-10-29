#include<stdio.h>
#include<errno.h>

int main(void){
	printf("dgfldgfl: %s!\n",strerror(errno));
	perror("sdfsdfsfsdfs\n");
	return 0;
}
