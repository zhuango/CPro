#include<stdio.h>
#include<unistd.h>
int main(void)
{
	char *buf;
	buf = getlogin();/* get the user name you login */
	printf("user name: %s\n",buf);

	return 0;
}
