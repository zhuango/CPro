#include<stdio.h>
#include<stdlib.h>


void hanoi(int n, int start, int middle, int end)
{
	if(n == 0) {
		return ;
	}else {
		hanoi(n - 1, start, end, middle);
		printf("Move %d from %d to %d\n", n, start, end);
		hanoi(n - 1, middle, start, end);
	}
}
int main(void)
{
	int n = 3;
	hanoi(n, 1, 2, 3);
	exit(EXIT_SUCCESS);
}
