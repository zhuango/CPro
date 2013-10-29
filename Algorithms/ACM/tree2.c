#include<stdio.h>
#include<stdlib.h>
#include<string.h>

const int MAXD = 20;

int main()
{
	int D, I;

	while(scanf("%d %d", &D, &I) == 2) {
		if(D == 0 && I == 0) break;
		int i;
		int k = 1;

		for(i = 0; i < D - 1; i++)
			if(I % 2) { k = k * 2; I = (I + 1) / 2;}
			else { k = k * 2 + 1; I /= 2;}
		printf("%d\n", k);
	}

	exit(EXIT_SUCCESS);
}
