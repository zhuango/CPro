#include "DFSForest.h"

bool visited[MAX_VERTEX_NUM];
typedef ALGraph Graph;

void DFSTree(Graph G,int v,CSTree &T)//
{
	bool first = TRUE;
	int w;
	CSTree p,q;
	visited[v] = TRUE;
	for (w = FirstAdjVex(G,v); w >= 0; w = NextAdjVex(G,v,w))
	{
		if(!visited[w])
		{
			p = (CSTree)malloc(sizeof(CSNode));
			p->data = GetVex(G,w);
			p->firstchild = NULL;
			p->nextsibling = NULL;
			if (first)
			{
				T ->firstchild = p;
				first = FALSE;
			}
			else
			{
				q->nextsibling = p;
			}
			q = p;
			DFSTree(G,w,q);
		}
	}
}

void DFSForest(Graph G,CSTree &T)//深度优先生成森林
{
	CSTree p,q;
	int v;
	T = NULL;
	for (v = 0; v < G.vexnum; ++v)
	{
		visited[v] = FALSE;
	}
	for (v = 0; v < G.vexnum; ++v)
	{
		if (!visited[v])
		{
			p = (CSTree)malloc(sizeof(CSNode));
			p->data = GetVex(G,v);
			p->firstchild = NULL;
			p->nextsibling = NULL;
			if (!T)
			{
				T = p;
			}
			else
			{
				q->nextsibling = p;
			}
			q = p;
			DFSTree(G,v,p);	
		}
	}
}