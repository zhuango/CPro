//用克鲁斯卡尔算法求最小生成树

#include "MGraph.h"

typedef struct
{//图的边信息存储结构
	int a,b;//边的两顶点的序号
	VRType weight;//边的权值
}side;

void MiniSpanTree_Kruskal(MGraph G);
