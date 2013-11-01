#include "DFSForest.h"

int main(void)
{
	Graph g;
	CSTree t;
	printf("请选择无向图");
	CreateGraph(g);
	Display(g);
	DFSForest(g,t);
	printf("先序遍历生成森林：");
	PreOrderTraverse(t,Visit);
	printf("\n");
	return 0;
}