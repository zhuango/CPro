#include<stdio.h>
#include<stdlib.h>

#define GRAPHSIZE 100
typedef struct Closedge {
	int Lowcost;
	int Vex;
}Closedge;

typedef struct TE {
	int head;
	int tail;
	int cost;
}TE;

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
		edge[tail][head] = cost;
	}

	return m;
}

#define MAX 10000
void Prim(int ora, int edge[GRAPHSIZE][GRAPHSIZE], TE te[], int n)
{
	int i, j, count, min, v = ora;
	Closedge *closedge = malloc(sizeof(Closedge) * n);

	/* Some node's cost most be change to be the MAX */
	for(i = 1; i <= n; i++)
		for(j = 1; j <= n; j++)
			if(edge[i][j] == 0) edge[i][j] = MAX;
	/* the adjacent of ora node */
	for(i = 1; i <= n; i++) {
		closedge[i].Lowcost = edge[v][i];
		closedge[i].Vex = v;
	}
	closedge[v].Vex = -1;/* ora node in U */
	count = 1;

	for(i = 2; i <= n; i++) {
		min = MAX;
		v = 0;

		/* Find the min node */
		for(j = 1; j <= n; j++)
			if(closedge[j].Vex != -1 && closedge[j].Lowcost < min) {
				v = j;
				min = closedge[i].Lowcost;
			}
		if(v != 0) {
			te[count].head = closedge[v].Vex;
			te[count].tail = v;
			te[count].cost = closedge[v].Lowcost;

			count ++;

			closedge[v].Vex = -1;
			closedge[v].Lowcost = 0;

			for(j = 1; j <= n; j++)
				if(closedge[j].Vex != -1 && closedge[j].Lowcost > edge[v][j]) {
					closedge[j].Vex = v;
					closedge[j].Lowcost = edge[v][j];
				}
		}
	}
}

void Kruskal(int edge[GRAPHSIZE][GRAPHSIZE], TE te[], int n)
{
	int i, j, k, tmp;
	int min, from, to, count = 1;
	int *kind = malloc(sizeof(int) * n);

	/* Each node in one set */
	for(i = 0; i <= n; i++)
		kind[i] = i;

	for(i = 1; i <= n; i++) {
		min = MAX;
		from = 0;
		to = 0;
		/* The most edge whose two ends in different set */
		for(j = 0; j <= n; j++)
			for(k = 0; k <= n; k++)
				if(kind[j] != kind[k] && edge[j][k] > 0  && edge[j][k] < min) {
					from = j;
					to = k;
					min = edge[j][k];
				}

		if(from != 0 && to != 0 && min != MAX) {
			/* This edge is good, store it */
			te[count].head = from;
			te[count].tail = to;
			te[count].cost = min;
			count ++;

			/* Be the same set */
			tmp = kind[to];
			for(j = 0; j <= n; j++)
				if(kind[j] == tmp)
					kind[j] = kind[from];
		}
	}
}

int main()
{
	int edge[GRAPHSIZE][GRAPHSIZE];
	int n, i, j;
	TE *te;

	n = CreateGra(edge);
	te = malloc(sizeof(TE) * n);
	for(i = 0; i <= n; i++) {
		for(j = 0; j <= n; j++) {
			printf("%d ", edge[i][j]);
		}
		printf("\n");
	}
	Prim(1, edge, te, n);

	for(i = 1; i < n; i++)
		printf("<%d, %d, %d>\n", te[i].head, te[i].tail, te[i].cost);
	Kruskal(edge, te, n);
	for(i = 1; i < n; i++)
		printf("<%d, %d, %d>\n", te[i].head, te[i].tail, te[i].cost);


	exit(EXIT_SUCCESS);
}
