#include<stdio.h>
#include<stdlib.h>

int setnumber[100];
int top = 0;
int m = 4;
int set[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

void print(int array[])
{
	int i;
	for(i = 0; i < top; i++)
		printf("%d ", array[i]);
	printf("\n");
}
void mulnum(int k, int sum)
{
	int i;

	for(i = k; i < 100; i++) {
		sum += set[i];
		setnumber[top] = set[i];
		top ++;
		if(sum > m) {top --; return ;}
		else if(sum == m) {print(setnumber);}
		else {
			mulnum(i + 1, sum);
		}
		top --;
		sum -= set[i];
	}
}

int main(void)
{
	mulnum(0, 0);
	exit(EXIT_SUCCESS);
}
