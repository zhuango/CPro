#include<stdio.h>
#include<stdlib.h>

int main()
{
	int i = 100;
	srand(time(NULL));

	for(i = 0; i < 10; i++)
		printf("%d ", rand());

	printf("\n");
	exit(EXIT_SUCCESS);
}
