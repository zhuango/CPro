#include<stdio.h>
#include<string.h>
#include<stdlib.h>
/* Edge node type */
typedef struct Edge {
	int veradj;
	int cost;
	struct Edge *link;
}Edge;
/* 顶点表节点 */
typedef struct Vertex {
	int VerName;
	Edge *adjacent;
}Vertex;
/* Grap struct , a Node table, a size of Grap*/
typedef struct Gra {
	Vertex *head;
	int graphsize;
}Gra;

Gra *CreateG()
{
	int e, from, to, weight, i, size;
	Vertex *Head;
	Gra *G = malloc(sizeof(Gra));
	/* Get size of grap nodes */
	scanf("%d", &size);
	/* Init the Gra struct  */
	G->graphsize = size;
	G->head = Head = malloc(sizeof(Vertex) * size);

	/* Init node table */
	for(i = 0; i < size; i++) {
		Head[i].VerName = i;
		Head[i].adjacent = NULL;
	}

	/* Get the number of edge */
	scanf("%d", &e);
	/* Create each edge */
	for(i = 0; i < e; i++) {
		/* Get edge's info, from - - > to, edge's weight */
		scanf("%d %d %d", &from, &to, &weight);
		/* Init the new edge */
		Edge *p = malloc(sizeof(Edge));
		p->veradj = to;
		p->cost = weight;
		p->link = NULL;

		Edge *q = Head[from].adjacent;
		if(q == NULL)/* has no edge */
			Head[from].adjacent = p;
		else {
			while(q->link != NULL)/* Add new edge to the end of list */
				q = q->link;
			q->link = p;
		}
	}

	return G;
}
/* DFS: 深度优先遍历 */
void DepthFirstSearch(Vertex *Head, int v, int visited[])
{
	int i;
	Edge *p;

	printf("%c ", v + 'A');
	visited[v] = 1;
	p = Head[v].adjacent;

	while(p != NULL) {
		if(visited[p->veradj] != 1)
			DepthFirstSearch(Head, p->veradj, visited);
		p = p->link;
	}
}


#define QSIZE 100
int queue[QSIZE];
int qhead = 0, qtail = 0;
/* Enter the queue */
void Equeue(int v)
{
	queue[qtail] = v;
	qtail = (qtail + 1) % QSIZE;
}
/* Out the queue */
int Oqueue()
{
	int ret;
	ret = queue[qhead];
	qhead = (qhead + 1) % QSIZE;
	return ret;
}
/* BFS: 广度优先遍历 */
void BFS(Vertex *Head, int v0, int visited[])
{
	int v, i;
	Edge *p;

	Equeue(v0);
	visited[v0] = 1;
	while(qhead != qtail) {/* Until queue is empty */
		v = Oqueue();
		printf("%c ", v + 'A');
		p = Head[v].adjacent;

		while(p != NULL) {
			if(visited[p->veradj] == 0) {
				Equeue(p->veradj);
				visited[p->veradj] = 1;
			}
			p = p->link;
		}
	}
}

int TopoOrder(Vertex *Head, int n, int topo[] )
{
	int *count;
	int i, j, k, top;
	int topoc = 0;
	Edge *p;

	count = malloc(sizeof(int) * n);

	for(i = 0; i < n; i++) count[i] = 0;
	/* Compute 入度 */
	for(i = 0; i < n; i++) {
		p = Head[i].adjacent;
		while(p != NULL) {
			count[p->veradj] += 1;/* 每一个边节点都有一个入度增量 */
			p = p->link;
		}
	}
	/* Init stack top */
	top = -1;
	for(i = 0; i < n; i++)
		if(count[i] == 0) {/* 入度为零的节点 */
			count[i] = top;/* save the old top */
			top = i;/* New top */
		}
	for(i = 0; i < n; i++) {
		if(top == -1) { printf("NOT AOV\n"); return 0;}/* There is a loop in graph */
		else {
			j = top;/* Out stack */
			top = count[top];/* change the top */

			printf("%c ", j + 'A');/* print the node that has no 入度 */
			topo[j] = topoc;
			topoc ++;
			/* Delete all the edge that begin with this node */
			p = Head[j].adjacent;
			while(p != NULL) {
				k = p->veradj;
				count[k] = count[k] - 1;

				if(count[k] == 0) {/* 入度为零的节点入栈 */
					count[k] = top;
					top = k;
				}
				p = p->link;
			}
		}
	}
	return 1;
}

void CriticalPath(Vertex *Head, int n)
{
	int *ve = malloc(sizeof(int) * n);
	int *vl = malloc(sizeof(int) * n);
	int i, j, k, e, l;
	Edge *p;
	
	for(i = 0; i < n; i++)/* Init early time */
		ve[i] = 0;
	for(i = 0; i < n - 1; i++) {
		p = Head[i].adjacent;
		while(p != NULL) {
			k = p->veradj;
			if(ve[i] + p->cost > ve[k])/* early time */
				ve[k] = ve[i] + p->cost;
			p = p->link;
		}
	}
	for(i = 0; i < n; i++)
		vl[i] = ve[n - 1];
	for(i = n - 2; i >= 0; i--) {
		p = Head[i].adjacent;
		while(p != NULL) {
			k = p->veradj;
			if(vl[k] - p->cost < vl[i])/* Late time */
				vl[i] = vl[k] - p->cost;
			p = p->link;
		}
	}

	for(i = 0; i < n; i++) {
		p = Head[i].adjacent;
		while(p != NULL) {
			k = p->veradj;
			e = ve[i];
			l = vl[k] - p->cost;
			if(e == l)
				printf("<%c, %c> is CirTical Activity!\n", i + 'A' , k + 'A');
			p = p->link;
		}
	}
}

void ShortestPath(Vertex *Head, int v, int n, int path[], int dist[])
{
	int *queue = malloc(sizeof(int) * n);
	int head = 0, tail = 0;
	int i, u, k;
	Edge *p;

	for(i = 0; i < n; i++) {
		path[i] = -1;
		dist[i] = -1;
	}
	dist[v] = 0;
	queue[tail] = v;
	tail = (tail + 1) % n;

	while(head != tail) {
		u = queue[head];
		head = (head + 1) % n;

		p = Head[u].adjacent;
		while(p != NULL) {
			k = p->veradj;
			if(dist[k] == -1) {
				queue[tail] = k;
				tail = (tail + 1) % n;
				dist[k] = dist[u] + 1;
				path[k] = u;
			}
			p = p->link;
		}
	}
}

#define MAXNUMBER 1000000
void ShortestPath2(Vertex *Head, int v, int n, int path[], int dist[])
{
	int *s = malloc(sizeof(int) * n);
	int i, j, u, k, ldist;
	Edge *p;

	for(i = 0; i < n; i++) {
		path[i] = -1;
		dist[i] = MAXNUMBER;
		s[i] = 0;
	}
	dist[v] = 0;/* node of beginning distanve is 0 */
	s[v] = 1;/*See the beginning node*/
	p = Head[v].adjacent;/* Neighbor nodes of beginning */
	u = v;/* Current node */
	for(i = 0; i < n; i++) {
		while(p != NULL) {
			k = p->veradj;
			if(s[k] != 1 && dist[k] > dist[u] + p->cost) {/* Havn't seen this node , and rechange the distance */
				dist[k] = dist[u] + p->cost;
				path[k] = u;/* u->k */
			}
			p = p->link;
		}
		
		ldist = MAXNUMBER;
		for(j = 0; j < n; j++)
			if(dist[j] > 0 && dist[j] < ldist && s[j] == 0) {/* Find the shortest path node in the havn't seen nodes*/
				ldist = dist[j];
				u = j;
			}
		s[u] = 1;/* Seen this node */
		p = Head[u].adjacent;/* Next move */
	}
}
int main()
{
	Gra *g;
	int *visited, i;
	char *topo;
	Edge *p, *tmp, *index;
	/* Create Gra */
	g = CreateG();
	
	visited = malloc(sizeof(int) * g->graphsize);
	
	/* DFS */
	DepthFirstSearch(g->head, 0, visited);
	printf("\n");


	/* BFS */
	for(i = 0; i < g->graphsize; i++)
		visited[i] = 0;
	BFS(g->head, 0, visited);
	printf("\n");
	
	/* Topo order*/
	TopoOrder(g->head, g->graphsize, visited);
	printf("\n");

	/* CriticalPath */
	/*
	Vertex *head = malloc(sizeof(Vertex) * g->graphsize);
	for(i = 0; i < g->graphsize; i++) {
		p = g->head[i].adjacent;
		index = head[visited[i]].adjacent;
		head[visited[i]].VerName = visited[i];
		while(p != NULL) {
			tmp = malloc(sizeof(Edge));
			tmp->veradj = visited[p->veradj];
			tmp->cost = p->cost;
			tmp->link = NULL;
			if(index == NULL) {head[visited[i]].adjacent = tmp; index = tmp;}
			else index->link = tmp; index = tmp;
			p = p->link;
		}
	}
	CriticalPath(head, g->graphsize);
	*/

	/* ShortestPath */
	int *dist = malloc(sizeof(int) * g->graphsize);
	int *path = malloc(sizeof(int) * g->graphsize);
	ShortestPath(g->head, 2, g->graphsize, path, dist);
	for(i = 0; i < g->graphsize; i++)
		printf("%d ", dist[i]);
	printf("\n");

	ShortestPath2(g->head, 0 ,g->graphsize , path, dist);
	for(i = 0; i < g->graphsize; i++)
		printf("%d ", dist[i]);
	printf("\n");

	exit(EXIT_SUCCESS);
}
