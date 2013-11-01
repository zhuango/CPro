#include "MiniSpanTree_PRIM.h"

int minimun(minside sz,MGraph G)
{
	int i = 0,j,k,min;
	while (!sz[i].lowcost)
	{//寻找第一个代价不为0的顶点序号
		i++;
	}
	min = sz[i].lowcost;//初始化最小值为第一个不为0的代价
	k = i;//初始化序号为第一个代价不为0的顶点序号
	for (j = i + 1; j < G.vexnum; ++j)
	{//继续找最小值
		if (sz[j].lowcost != 0 && sz[j].lowcost < min)//存在比前一个最小值还小的代价并且不为零，则更新最小值，并用k标记序号
		{
			min = sz[j].lowcost;
			k = j;
		}
	}
	return k;
}

void MiniSpanTree_PRIM(MGraph G,VertexType u)
{
	int i,j,k;
	minside closedge;//辅助数组
	k = LocateVex(G,u);//顶点序号
	for (j = 0; j < G.vexnum; ++j)
	{//初始化辅助数组
		closedge[j].adjvex = k;//此时U中只有顶点u,其序号为k
		closedge[j].lowcost = G.arcs[k][j].adj;//u到其他顶点的代价。不相邻则赋值为INT_MAX
	}
	closedge[k].lowcost = 0;//u到u初始为0
	printf("最小生成树的各条边为：\n");
	for (i = 1; i < G.vexnum; ++i)
	{
		k = minimun(closedge,G);//求最小生成树的T的下一个结点:序号为k
		printf("(%s-%s)\n",G.vex[closedge[k].adjvex].name,G.vex[k].name);//输出最小生成树的边
		closedge[k].lowcost = 0;//第k个顶点并入U集
		for (j = 0; j < G.vexnum; ++j)
		{
			if (G.arcs[k][j].adj < closedge[j].lowcost)
			{//新顶点并入U集后重新选择最小边
				closedge[j].adjvex = k;
				closedge[j].lowcost = G.arcs[k][j].adj;
			}
		}
	}
}

//void MiniSpanTree_Kruskal()