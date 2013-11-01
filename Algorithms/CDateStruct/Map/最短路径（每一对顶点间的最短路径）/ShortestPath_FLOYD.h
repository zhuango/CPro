#include "MGraph.h"
typedef int PathMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM][MAX_VERTEX_NUM];//三维数组，标记v到w的最短路径上的顶点，大于0为有，0为无
typedef VRType DistancMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];//二维数组，存储v到w的最短路径距离
void ShortestPath_FLOYD(MGraph G,PathMatrix P,DistancMatrix D);
