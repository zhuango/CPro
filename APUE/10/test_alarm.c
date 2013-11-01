#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>

int main(void)
{
	int i;
	alarm(15);
	sleep(2);
	i = alarm(1);/* after 2 seconds the process will abort */
	printf("rest is %d\n", i);
	for( ; ; );

	return 0;
}
