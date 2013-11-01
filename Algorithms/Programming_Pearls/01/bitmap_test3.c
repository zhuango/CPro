#include<stdio.h>
#include "bitmap_1.c"

int main(void)
{
	int *a, i, j;
	char *b;
	b = malloc(1000000 * sizeof(char));
	a = malloc(1000000 * sizeof(int));

	for(i = 0; i < 1000000; i++){
		scanf("%d", &a[i]);
		b[i] = 0;
		clr(i);
	}

	for(i = 0; i < 1000000; i++){
		set(a[i]);
		b[a[i]] ++;
	}
	for(i = 0; i < 1000000; i++)
		if(test(i))
			for(j = 0; j < b[i]; j++){
				printf("%d\n", i);
			}
	return 0;
}
