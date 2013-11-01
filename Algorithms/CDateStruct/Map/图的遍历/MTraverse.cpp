#include "MTraverse.h"
bool visited[MAX_VERTEX_NUM];

void (* VisitFunc)(VertexType);
/***深度优先搜索***/
void DFS(Graph G,int v)
{
	int w;
	visited[v] = TRUE;
	VisitFunc(GetVex(G,v));

	for (w = FirstAdjVex(G,v); w >= 0; w = NextAdjVex(G,v,w))
	{
		if (!visited[w])
		{
			DFS(G,w);
		}
	}
}

void DFSTraverse(Graph G,void(*Visit)(VertexType))
{
	int v;
	VisitFunc = Visit;
	for (v = 0; v < G.vexnum; ++v)
	{
		visited[v] = FALSE;
	}
	for (v = 0; v < G.vexnum; ++v)
	{
		if (!visited[v])
		{
			DFS(G,v);
		}
	}
	printf("\n");
}

/***广度优先搜索***/
#include "LinkQueue.h"

void BFSTraverse(Graph G,void (* Visit)(VertexType))
{
	int u,v,w;
	LinkQueue Q;
	InitQueue(Q);
	for (v = 0; v < G.vexnum; v++)
	{
		visited[v] = FALSE;
	}
	for (v = 0; v < G.vexnum; v++)
	{
		if (!visited[v])
		{
			visited[v] = TRUE;
			Visit(GetVex(G,v));
			EnQueue(Q,v);
			while (!IsQueueEmpty(Q))
			{
				DelQueue(Q,u);
				for (w = FirstAdjVex(G,u); w >= 0; w = NextAdjVex(G,u,w))
				{
					if (!visited[w])
					{
						visited[w] = TRUE;
						Visit(GetVex(G,w));
						EnQueue(Q,w);
					}
				}
			}
		}
	}
	printf("\n");
	
}