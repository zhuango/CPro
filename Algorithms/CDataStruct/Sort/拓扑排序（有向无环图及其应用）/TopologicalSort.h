#include "ALGraph.h"
#include "SqStack.h"

//基本操作函数声明
void FindIndegree(ALGraph G,int indegree[]);
Status TopologicalSort(ALGraph G);
void DFSTopo(Graph G,int v);
void DFSTopoSort(Graph G);