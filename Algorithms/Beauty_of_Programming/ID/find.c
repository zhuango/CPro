#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	FILE *pf1, *pf2;
	int a = 0, b = 0;
	/* The first file */
	if((pf1 = fopen("result", "r")) == NULL){
		printf("open error\n");
		exit(EXIT_FAILURE);
	}

	/* The second file */
	if((pf2 = fopen("result1", "r")) == NULL){
		printf("oper error pf2\n");
		exit(EXIT_FAILURE);
	}

	while(fscanf(pf1, "%d\n", &a) == 1)
		b ^= a;
	while(fscanf(pf2, "%d\n", &a) == 1)
		b ^= a;

	printf("%d\n", b);

	exit(EXIT_FAILURE);
}
