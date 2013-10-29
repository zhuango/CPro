#include<stdio.h>
#include<stdlib.h>

void shift_left(int *number, int start, int end)
{
	int tmp = number[start];
	int i;

	for( i = start; i < end; i++)
		number[i] = number[i + 1];
	number[i] = tmp;
}

void shift_right(int *number, int start, int end)
{
	int tmp = number[end];
	int i;
	
	for(i = end; i > start; i--)
		number[i] = number[i - 1];
	number[i] = tmp;
}

int find(int *number, int num, int ele)
{
	int i;
	
	for(i = 1; i <= num; i++) 
		if(number[i] == ele) return i;
}	
int main()
{
	int n, m, X, Y;
	char cmd;
	int p, q;
	int *number, i;

	scanf("%d %d", &n, &m);
	number = malloc(sizeof(int) * n + 2);

	for(i = 1; i < n + 1; i++)
		number[i] = i;

	for(i = 0; i < m; i++) {
		while(getchar() != '\n') ;
		scanf("%c %d %d", &cmd, &X, &Y);
		
		p = find(number, n, X);
		q = find(number, n, Y);

		if(cmd == 'A') {
			if(p < q)
				shift_left(number, p, q - 1);
			else
				shift_right(number, q, p);
		}
		if(cmd == 'B') {
			if(p < q)
				shift_left(number, p, q);
			else
				shift_right(number, q + 1, p);
		}
	}

	for(i = 1; i < n + 1; i++)
		printf("%d ", number[i]);
	printf("\n");
	return 0;
}
