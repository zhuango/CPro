#include<stdio.h>
#include<stdlib.h>

struct {
	unsigned char a:4;
	unsigned char b:4;
}i;

int main(void)
{
	for(i.a = 1; i.a < 10; i.a++)
		for(i.b = 1; i.b < 10; i.b++)
			if(i.a % 3 == i.b % 3)
				printf("a = %d, b = %d\n", i.a, i.b);

	return 0;
}
