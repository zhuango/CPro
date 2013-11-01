#include "CriticalPath.h"

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

Status TopologicalOrder(ALGraph &G,SqStack &T)
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
	InitStack(T);
	for (i = 0; i < G.vexnum; ++i)//初始化ve为0
	{
		G.vertices[i].data.ve = 0;
	}
	while (!StackEmpty(S))//当栈不空时
	{
		Pop(S,i);//出栈一个零入度顶点的序号,并将其赋值给i
		Visit(G.vertices[i].data);
		Push(T,i);//i号顶点入逆拓扑排序栈T(栈底元素为拓扑排序的第1个元素)
		++count;//已输出顶点数+1
		for (p = G.vertices[i].firstarc; p; p = p->nextarc)//对i号的顶点的每个邻接顶点
		{
			k = p->data.adjvex;//其序号为K
			if (!(--indegree[k]))//k的入度减1,若减为0,则将k入栈S
			{
				Push(S,k);
			}
			if ((G.vertices[i].data.ve + p->data.info->weight) > G.vertices[k].data.ve)
			{//顶点i事件的最早发生时间 + <i,k>的权值  > 顶点j事件的最早发生时间
				G.vertices[k].data.ve = G.vertices[i].data.ve + p->data.info->weight;
				//顶点j事件的最早发生时间 = 顶点i事件的最早发生时间 + <i,k>的权值
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
		return OK;
	}
}

Status CriticalPath(ALGraph &G)
{
	SqStack T;
	int i,j,k;
	ArcNode *p;
	if (!TopologicalOrder(G,T))
	{
		return ERROR;
	}
	j = G.vertices[0].data.ve;//j的初值
	for (i = 1; i < G.vexnum;++i)
	{
		if (G.vertices[i].data.ve > j)
		{
			j = G.vertices[i].data.ve;//j = MAX(ve)完成点的最早发生时间
		}
	}
	for (i = 0; i < G.vexnum; ++i)//初始化顶点事件的最迟发生时间
	{
		G.vertices[i].data.vl = j;
	}
	while (!StackEmpty(T))//按逆拓扑序求各顶点的vl值
	{
		Pop(T,j);
		p = G.vertices[j].firstarc;
		while (p)
		{
			k = p->data.adjvex;//后序顶点的值
			if (G.vertices[k].data.vl - p->data.info->weight < G.vertices[j].data.vl)
			{//事件j的最迟发生时间 > 其直接后继事件的最迟发生时间 - <j,k>的权值
				G.vertices[j].data.vl = G.vertices[k].data.vl - p->data.info->weight;
			 //事件j的最迟发生时间 = 其直接后继事件的最迟发生时间 - <j,k>的权值
			}
			 p = p->nextarc;
		}
	}
	printf("\ni  ve  vl\n");
	for (i = 0; i < G.vexnum; ++i)
	{
		printf("%d  ",i);//输出序号
		Visitel(G.vertices[i].data);//输出ve、vl的值
		if (G.vertices[i].data.ve == G.vertices[i].data.vl)
		{//事件（顶点）的最早发生时间 = 最迟发生时间
			printf("  关键路径经过的顶点");
		}
		printf("\n");
	}
	printf("j  k  权值  ee  el\n");
	for (j = 0; j < G.vexnum; ++j)
	{
		for (p = G.vertices[j].firstarc;p;p = p->nextarc)
		{
			k = p->data.adjvex;//邻接顶点（直接后继事件）的序号
			p->data.info->ee = G.vertices[j].data.ve;//ee(活动<i,j>的最早开始时间 = （顶点j）事件最早发生时间)
			p->data.info->el = G.vertices[k].data.vl - p->data.info->weight;
			////el(活动<j,k>的最迟开始时间)=（顶点k）事件最迟发生时间-<j,k>的权值
			printf("%s->%s",G.vertices[j].data.name,G.vertices[k].data.name);
			OutputArcwel(p->data.info);
			if (p->data.info->ee == p->data.info->el)
			{//活动最早开始时间 = 活动最迟开始时间 
				printf("  关键活动");
			}
			printf("\n");
		}
	}
	return OK;
}


