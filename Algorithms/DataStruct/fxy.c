#include<stdio.h>
#include<stdlib.h>

int fxy(int x, int y)
{
	if(x > 0 && y > 0) {
		return fxy(x - 1, y) + fxy(x, y - 1);
	}else
		return x + y;
}
int main(void)
{
	int result;
	result = fxy(2, 1);
	printf("%d\n", result);

	exit(EXIT_SUCCESS);
}
