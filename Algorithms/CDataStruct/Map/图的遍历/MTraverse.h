//#define MG
#ifdef MG//图的存储结构为邻接矩阵
#include "MGraph.h"
typedef MGraph Graph; 
#else//图的存储结构为邻接表
#include "ALGraph.h"
typedef ALGraph Graph;
#endif

//声明与遍历有关的基本操作函数
void DFS(Graph G,int v);
void DFSTraverse(Graph G,void(*Visit)(VertexType));
void BFSTraverse(Graph G,void (* Visit)(VertexType));
