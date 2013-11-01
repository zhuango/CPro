#include "ALGraph.h"
//全局变量声明
extern int count,lowcount;//全局变量count对顶点访问顺序计数，lowcount对求得low值的顺序计数
extern int visited[MAX_VERTEX_NUM];//访问标志数组
extern int low[MAX_VERTEX_NUM],lowOrder[MAX_VERTEX_NUM];//low数组存顶点的low值,lowOrder存顶点求得low值的顺序（后根）
//函数声明
void DFSArticul(ALGraph G, int v0);
void FindArticul(ALGraph G);	

