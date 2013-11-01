#include "ShortestPath_FLOYD.h"
void RailwaySearch(MGraph g,PathMatrix p,DistancMatrix d);
int main(void)
{
	int i,j,k,n;
	MGraph g;
	PathMatrix p;
	DistancMatrix d;
	CreateFromFile(g,"map.txt",0);
	int order[MAX_VERTEX_NUM];//按路径上经过顶点的次序存储顶点序号
	for (i = 0; i < MAX_VERTEX_NUM; ++i)
	{
		order[i] = -1;//初始化为-1
	}
	for (i = 0; i < g.vexnum; ++i)
	{
		g.arcs[i][i].adj = 0;//对角元素值为0,因为两点相同，其距离为0
	}
	Display(g);//输出有向网g
	ShortestPath_FLOYD(g,p,d);
	printf("d矩阵：\n");
	for (i = 0; i < g.vexnum; ++i)
	{
		for (j = 0; j < g.vexnum; ++j)
		{
			printf("%6d",d[i][j]);
		}
		printf("\n");
	}
	printf("p矩阵：\n");
	for (i = 0; i < g.vexnum; ++i)
	{
		for (j = 0; j < g.vexnum; ++j)
		{
			if (i != j)
			{
				printf("由%s到%s经过：",g.vex[i].name,g.vex[j].name);
				for (k = 0; k < g.vexnum; ++k)
				{
					if (p[i][j][k] > 0)
					{
						order[p[i][j][k]] = k;
					}
				}
				for (n = 1 ; n < g.vexnum; ++n)
				{
					if (order[n] > -1)
					{
						printf("%s->",g.vex[order[n]].name);
						order[n] = -1;//恢复默认值
					}
				}
				printf("\b\b  距离为:%d\n",d[i][j]);
			}

			printf("\n");
		}
	}

	RailwaySearch(g,p,d);
	printf("\n");
	return 0;
}


/*
由A到B经过：ABDE
由A到C经过：AC
由A到D经过：AD
由A到E经过：ADE
由B到A经过：

由B到C经过：
由B到D经过：
由B到E经过：
由C到A经过：
由C到B经过：BC

由C到D经过：
由C到E经过：
由D到A经过：
由D到B经过：BDE
由D到C经过：

由D到E经过：DE
由E到A经过：
由E到B经过：BE
由E到C经过：
由E到D经过：
*/