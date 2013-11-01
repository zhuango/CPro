#include<stdio.h>
#include<stdlib.h>
#define N 10

int array[N] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
void loop(int);
int main(int argc, char **argv)
{
	int i;
	if(argc != 2){
		printf("Usage : %s <number>\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	loop(atoi(argv[1]));

	for(i = 0; i < N; i++)
		printf("%d ", array[i]);
	printf("\n");
	return 0;
}

void reverse(int a, int b)
{
	int tmp;
	while(a < b){
		tmp = array[a];
		array[a] = array[b];
		array[b] = tmp;
		a++;
		b--;
	}
}
void loop(int pos)
{
	reverse(0, pos - 1);
	reverse(pos, N - 1);
	reverse(0, N - 1);
}

