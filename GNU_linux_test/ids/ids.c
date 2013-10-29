#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main(void)
{
	printf("Real user ID: %d\n",getuid());
	printf("Effective user ID: %d\n",geteuid());
	printf("Readl group ID: %d\n",getgid());
	printf("Effective group ID : %d\n",getegid());

	exit(EXIT_SUCCESS);
}
