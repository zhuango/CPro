#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main(void)
{
	int i;
	srandom(time(NULL));

	FILE *data = fopen("data", "w");
	for(i = 0; i < 5000000; i++) {
		fprintf(data, "%ld\n", random());
	}

	exit(EXIT_SUCCESS);
}
