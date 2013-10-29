#include "ShortestPath_DIJ.h"
int main(void)
{
	int i,j,k;
	MGraph g;
	PathMatrix p;
	ShortestPathTable d;
	int order[MAX_VERTEX_NUM];//辅助数组，按最短路径上的顶点次序依次存储顶点序号
	for (i = 0; i < MAX_VERTEX_NUM;++i)
	{//初始化顶点序号为-1
		order[i] = -1;
	}
	CreateFromFile(g,"2.txt",0);
	Display(g);
	ShortestPath_DIJ(g,0,p,d);
	printf("最短路径数组p[i][j]如下：\n");
	for (i = 0; i < g.vexnum; ++i)
	{
		for (j = 0; j < g.vexnum; ++j)
		{
			printf("%2d",p[i][j]);
		}
		printf("\n");
	}
	
	for (i = 1; i < g.vexnum; ++i)
	{
		printf("%s->%s的最短路径为:  ",g.vex[0].name,g.vex[i].name);
		for (j = 0; j < g.vexnum; ++j)
		{
			if (p[i][j] > 0)
			{
				order[p[i][j]] = j;//按路径次序依次存储顶点序号
			}
		}
		for (k = 1;order[k] > -1;++k)
		{
			printf("%s->",g.vex[order[k]].name);//按序输出已排好的顶点序号
			order[k] = -1;                      //恢复默认值，以便存储下一条最短路径的定点序号
		}
		printf("\b\b  距离为：%d",d[i]);
		printf("\n");
	}
	return 0;
}

