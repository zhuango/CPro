#include<stdio.h>
#include<time.h>


int main(void)
{
	time_t time_start;
	char *time_buf;
	time(&time_start);

	time_buf = ctime(&time_start);
	printf("%s\n",time_buf);

	return 0;
}
