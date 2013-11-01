#include<stdio.h>

int main(void)
{
	int i, j, k, m, sum;

	for(i = 0; i < 4; i++)
		for(j = 0; j < 4; j++)
			for(k = 0; k < 4; k++)
				for(m = 0; m < 4; m++){
					printf("_____________________\n");
					sum = i * 1000 + j * 100 + k * 10 + m;
					printf("D");
				}
	return 0;
}
