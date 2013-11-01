#include "ShortestPath_FLOYD.h"

void RailwaySearch(MGraph g,PathMatrix p,DistancMatrix d)
{
	int i,j,k,n,q = 1;
	int order[MAX_VERTEX_NUM];//按路径上经过顶点的次序存储顶点序号
	for (i = 0; i < MAX_VERTEX_NUM; ++i)
	{
		order[i] = -1;//初始化为-1
	}
	while (q)
	{
		printf("请选择：1 查询  0 结束\n");
		scanf("%d",&q);
		if (q)
		{
			printf("城市代码：\n");
			for (i = 0; i < g.vexnum; i++)
			{
				printf("%2d.%-8s",i+1,g.vex[i].name);
				if (i%7 == 6)
				{
					printf("\n");
				}
			}
			printf("\n请输入要查询的起点城市代码 终点城市代码：");
			scanf("%d%d",&i,&j);
			i--;
			j--;
			if (d[i][j] < INFINITY)
			{
				printf("由%s到%s的最短距离为%d \n",g.vex[i].name,g.vex[j].name,d[i][j]);
				printf("依次经过的城市：\n");
				for (k = 0; k < g.vexnum; ++k)
				{
					if (p[i][j][k] > 0)
					{
						order[p[i][j][k]] = k;
					}
				}
				for (n = 1 ; n < MAX_VERTEX_NUM; ++n)
				{
					if (order[n] > -1)
					{
						printf("%s->",g.vex[order[n]].name);
						order[n] = -1;//恢复默认值
					}
				}
				printf("\b\b  \n");
			}
			else
			{
				printf("%s到%s没有路径可通！ \n",g.vex[i].name,g.vex[j].name,d[i][j]);
			}
		}

	}
}
