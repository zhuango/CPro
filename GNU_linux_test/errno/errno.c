#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<math.h>

int main(void)
{
	double d;
	d = sqrt((double)-1);
	if(errno){
		perror("sqrt(-1) failied\n");
		errno = 0;
	}else{
		printf("sqrt(-1) = %f\n",d);
	}

	d = sqrt((double)2);
	if(errno){
		perror("sqrt(2) failed\n");
		errno = 0;
	}else{
		printf("sqrt(2) = %f\n",d);
	}

	exit(EXIT_SUCCESS);
}
