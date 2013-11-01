#include "ShortestPath_FLOYD.h"

void ShortestPath_FLOYD(MGraph G,PathMatrix P,DistancMatrix D)
{
	int v,w,u,i;
	int ordercount[MAX_VERTEX_NUM][MAX_VERTEX_NUM];//辅助数组，用于给最短路径上的顶点编号
	for (v = 0; v < G.vexnum; ++v)
	{
		for (w = 0; w < G.vexnum; ++w)
		{
			D[v][w] = G.arcs[v][w].adj;//初始化v到w的最短路径距离为顶点v到w的直接距离；
			ordercount[v][w] = 1;
			for (u = 0; u < G.vexnum; ++u)
			{
				P[v][w][u] = FALSE;//初始化各顶点的最短路径标记为0
			}
			if (D[v][w] < INFINITY)
			{
				P[v][w][v] = ordercount[v][w];//v到w的最短路径经过顶点v,给其编号
				if (v != w)
				{
					P[v][w][w] = ++ordercount[v][w];//v到w的最短路径经过顶点w，给其编号
				}
			}		
		}
	}

	for (u = 0; u < G.vexnum; ++u)
	{
		for (v = 0; v < G.vexnum; ++v)
		{
			for (w = 0; w < G.vexnum; ++w)
			{
				if (D[v][u] < INFINITY && D[u][w] < INFINITY && D[v][u] + D[u][w] < D[v][w])
				{//从v经u到w的一条路径更短
					D[v][w] = D[v][u] + D[u][w];//更新最短距离
					ordercount[v][w] = ordercount[v][u];//更新编号
					for (i = 0; i < G.vexnum; ++i)
					{
						P[v][w][i] = P[v][u][i];//从v到w的路径经过从v到u所有路径，复制路径
						if (!P[v][w][i] && (P[v][u][i] || P[u][w][i]))
					    {
							P[v][w][i] = P[u][w][i] + ordercount[v][u] - 1;//从v到w的路径经过从u到w的所有路径，复制路径，编号更新
							ordercount[v][w]++;//编号加1
						}
					} 

				}
			}
		}
	}
}
