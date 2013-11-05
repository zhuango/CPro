#include<stdio.h>
#include<stdlib.h>

#define GRAPHSIZE 100
int CreateGra(int edge[GRAPHSIZE][GRAPHSIZE])
{
	int n,m;
	int i, j, head, tail, cost;
	scanf("%d", &m);
	scanf("%d", &n);
	for(i = 0; i < GRAPHSIZE; i++)
		for(j = 0; j < GRAPHSIZE; j++)
			edge[i][j] = 0;
	for(i = 0; i < n; i++) {
		scanf("%d %d %d", &head, &tail, &cost);
		edge[head][tail] = cost;
	}

	return m;
}

int stack[100];
int top = -2;
void printstack(int tmp){
	if(tmp != -2){
		printstack(stack[tmp]);
		printf("%d ", tmp);
	}
}
int count = 0;
void DFSS(int edge[GRAPHSIZE][GRAPHSIZE], int from, int to, int n)
{
	int i;
	int tmp;
	stack[from] = top;
	top = from;
	for(i = 0; i <= n; i++) {
		if(edge[from][i] != 0 && i == to){
			count++;
			printstack(top);
			printf("%d\n", i);
		}
		if(edge[from][i] != 0 && stack[i] == -1) {
			DFSS(edge, i, to, n);
			top = stack[top];
			stack[i] = -1;
		}
	}

}
int main()
{
	int edge[GRAPHSIZE][GRAPHSIZE];
	int n;
	for(n = 0; n < GRAPHSIZE; n++)
		stack[n] = -1;
	n = CreateGra(edge);
	DFSS(edge, 2, 5, n);
	printf("\n");
	printf("%d\n", count);

	exit(EXIT_SUCCESS);
}
