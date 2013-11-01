#include "MiniSpanTree_PRIM.h"
#include "MiniSpanTree_Kruskal.h"
int main(void)
{
	MGraph g;
	char filename[13];
	printf("请输入文件名:");
	scanf("%s",&filename);
	CreateFromFile(g,filename,0);
	Display(g);
	printf("【普里姆算法】\n");
	MiniSpanTree_PRIM(g,g.vex[0]);
	printf("【克鲁斯卡尔算法】\n");
	MiniSpanTree_Kruskal(g);
	return 0;
}