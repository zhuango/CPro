#include "ALGraph.h"
#include "SqStack.h"

void FindIndegree(ALGraph G,int indegree[]);
Status TopologicalOrder(ALGraph &G,SqStack &T);
Status CriticalPath(ALGraph &G);