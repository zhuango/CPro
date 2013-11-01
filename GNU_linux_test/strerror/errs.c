#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<errno.h>

int main(void)
{
	double d;
	char *p;

	errno = 0;
	d = sqrt(-1);
	if(errno){
		p = strerror(errno);
		fprintf(stderr,"sqrt(-1) L %s\n",p);
	}

	errno = 0;

	d = sqrt(-2);
	if(errno)
		perror("sqrt(-2)");

	exit(EXIT_SUCCESS);
}
