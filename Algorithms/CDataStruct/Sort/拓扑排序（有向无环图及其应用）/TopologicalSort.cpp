#include"TopologicalSort.h"

void FindIndegree(ALGraph G,int indegree[])
{//求顶点的入度 
	int i;
	ArcNode *p;
	for (i = 0; i < G.vexnum; ++i)
	{
		indegree[i] = 0;//将所有的顶点的入度初始化为0
	}
	for (i = 0; i < G.vexnum; ++i)
	{//对所有顶点统计入度
		p = G.vertices[i].firstarc;//p指向邻接表的头指针
		while (p)//p不空
		{
			indegree[p->data.adjvex]++;//p所指的邻接节点入度加1
			p = p->nextarc;//p指向下一邻接点		
		}
	}
}

Status TopologicalSort(ALGraph G)
{
	int i,k,count = 0;
	int indegree[MAX_VERTEX_NUM];//入度数组,存放各顶当前入度数
	SqStack S;//零入度栈 也可用队列代替
	ArcNode *p;
	FindIndegree(G,indegree);//对G的各顶点求入度indegree[]
	InitStack(S);//初始化零入度栈
	for(i = 0; i < G.vexnum; ++i)//将零入度的顶点序号入栈
	{
		if (!indegree[i])//入度为零
		{
			Push(S,i);
		}
	}
	while (!StackEmpty(S))//当栈不空时
	{
		Pop(S,i);//出栈一个零入度顶点的序号,并将其赋值给i
		printf("%s ",G.vertices[i].data.name);//输出顶点号
		++count;//已输出顶点数+1
		for (p = G.vertices[i].firstarc; p; p = p->nextarc)//对i号的顶点的每个邻接顶点
		{
			k = p->data.adjvex;//其序号为K
			if (!(--indegree[k]))//k的入度减1,若减为0,则将k入栈S
			{
				Push(S,k);
			}
		}
	}
	if (count < G.vexnum)//零入度顶点栈S已空,图还有顶点未输出
	{
		printf("此有向图有回路！\n");
		return ERROR;
	}
	else
	{
		printf("这是一个拓扑排序。\n");
		return OK;
	}
}


/***深度优先搜索***/
extern bool visited[MAX_VERTEX_NUM];
SqStack topo;
void visit(SElemType e)
{
	printf("%d ",e);
}
void DFSTopo(Graph G,int v)
{
	ArcNode *p;
	visited[v] = TRUE;
	p = G.vertices[v].firstarc;
	while(p)
	{
		if (!visited[p->data.adjvex])
		{
			DFSTopo(G,p->data.adjvex);
			Push(topo,p->data.adjvex);
		}
		p = p->nextarc;
	}
}

void DFSTopoSort(Graph G)
{
	int v;
	for (v = 0; v < G.vexnum; ++v)
	{
		visited[v] = FALSE;
	}
	for (v = 0; v < G.vexnum; ++v)
	{
		if (!visited[v])
		{
			DFSTopo(G,v);
			Push(topo,v);
		}
	};
	while (!StackEmpty(topo))
	{
		Pop(topo,v);
		printf("%s ", G.vertices[v].data.name);
	}
	printf("\n");
}

