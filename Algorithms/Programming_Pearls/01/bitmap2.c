#include<stdio.h>
#include<stdlib.h>
#include"bitmap_1.c"
int main(void)
{
	int s[] = {12, 32, 123, 543, 765, 23, 65, 23, 0, 0};
	int i;
	for(i = 0; i < 1000; i++)
		clr(i);

	for(i = 0; i < 10; i++)
		set(s[i]);
	for(i = 0; i < 1000; i++)
		if(test(i))
			printf("%d ", i);
	printf("\n");
	return 0;
}
