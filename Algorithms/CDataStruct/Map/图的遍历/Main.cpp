#include "MTraverse.h"
int main(void)
{
	Graph g;
	char filename[13];
	printf("请输入数据文件名：");
	scanf("%s", filename);
#ifdef MG
	CreateFromFile(g,filename,0);
	Display(g);
#else
	CreateFromFile(g,filename);
	Display(g);
#endif
	printf("深度优先搜索的结果：\n");
	DFSTraverse(g,Visit);
	printf("广度优先搜索的结果：\n");
	BFSTraverse(g,Visit);
	return 0;
}