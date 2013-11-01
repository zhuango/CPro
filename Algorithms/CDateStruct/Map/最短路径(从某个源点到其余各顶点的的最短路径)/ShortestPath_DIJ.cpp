#include "ShortestPath_DIJ.h"

void ShortestPath_DIJ(MGraph G,int v0,PathMatrix P,ShortestPathTable D)
{//用迪杰斯特拉算法（Dijkstra algorithm）求最短路径 
	int v,w,i,j;
	VRType min;
	Status Final[MAX_VERTEX_NUM];//辅助矩阵S集，标记最短路径是否已经求得，为真表示v0到该顶点的最短距离已求出，初值为假
	int OrderCount[MAX_VERTEX_NUM];//辅助数组，记录v0到v最短路径上的顶点数，用于给路径上顶点按序编号
	for(v = 0; v < G.vexnum; ++v)
	{
		Final[v] = FALSE;//初始化为假
		OrderCount[v] = 1;//初始化编号为1
		D[v] = G.arcs[v0][v].adj;//最短距离初始化为v0
		for (w = 0; w < G.vexnum; ++w)
		{
			P[v][w] = 0;//路径顶点初始化为无
		}
		if(D[v] < INFINITY)//v0到v存在路径
		{
			P[v][v0] = OrderCount[v];//路径经过顶点v 给其编号
			P[v][v] = ++OrderCount[v];//路径经过顶点v0 给其编号
		}
	}
	D[v0] = 0;//v0到v0的最短路径为0
	Final[v0] = TRUE;//已求得v0到v0的最短路径
	for (i = 0; i < G.vexnum - 1; ++i)//对除v0外的顶点求最短路径
	{
		min = INFINITY;//初始化最小值为无穷值
		for (w = 0; w < G.vexnum; ++w)//对所有顶点进行比较
		{
			if (!Final[w] && D[w] < min)//在S集外的顶点（FInal[] = FALSE）中
			{//找离v0最近的w,并赋值给v,距离赋值给min
				v = w;//最小值
				min = D[w];
			}
		}
		Final[v] = TRUE;//v0到v的最短距离已求得,将v并入S集
		for (w = 0; w < G.vexnum; ++w)
		{
			if (!Final[w] && min < INFINITY && G.arcs[v][w].adj < INFINITY && min + G.arcs[v][w].adj < D[w])
			{//w不属于S集，并且v0-v-w的距离小于v0-w的距离
				D[w] = min + G.arcs[v][w].adj;//更新v到w的最短距离D[w]，最短距离为v0-v-w
				for (j = 0; j < G.vexnum; ++j)
				{
					P[w][j] = P[v][j];//将v0-v路径复制到p[w]中
				}
				OrderCount[w] = OrderCount[v];//p[w]延续p[v]的编号
				P[w][w] = ++OrderCount[w];//路径经过w 给其编号
			}

		}

	}
}