//用普里姆算法求最小生成树
#include "MGraph.h"

typedef struct
{
	int adjvex;//顶点集U中到该点（一维数组的序号对应相应的顶点）为最小权值的那个顶点的序号
	VRType lowcost;//那个顶点到该点的权值（是最小的）
}minside[MAX_VERTEX_NUM];//记录从顶点集U到顶点集V-U的代价最小的边的辅助数组定义

//基本函数声明
void MiniSpanTree_PRIM(MGraph G,VertexType u);