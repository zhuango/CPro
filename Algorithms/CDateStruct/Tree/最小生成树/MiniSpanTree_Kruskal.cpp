#include "MiniSpanTree_Kruskal.h"

void MiniSpanTree_Kruskal(MGraph G)
{
	int set[MAX_VERTEX_NUM];//标记连通分量
	int senumber = 0,sb,i,j,k;
	side se[MAX_VERTEX_NUM * (MAX_VERTEX_NUM - 1) / 2];//一维数组,存储边的信息
	for (i = 0; i < G.vexnum; ++i)
	{//查找所有边并按照权值升序插到se中
		for (j = i + 1; j < G.vexnum; ++j)
		{
			if (G.arcs[i][j].adj < INFINITY)
			{
				k = senumber - 1;
				while (k >= 0)
				{
					if (se[k].weight > G.arcs[i][j].adj)
					{//K所指的值大于刚才找到边的权值
						se[k + 1] = se[k];//k的边向后移
						k--;//指向前一条边
					}
					else
					{
						break;
					}
				}
				se[k + 1].a = i;
				se[k + 1].b = j;
				se[k + 1].weight = G.arcs[i][j].adj;
				senumber++;
			}
		}
	}
	printf("i   se[i].a  se[i].b   se[i].weight\n");
	for (i = 0; i < senumber; ++i)
	{//输出数组se中按升序排列的各边
		printf("%d %4d %7d %9d \n",i,se[i].a,se[i].b,se[i].weight);
	}

	for (i = 0; i < G.vexnum; ++i)
	{
		set[i] = i;//设初值，各顶点都是一个连通分量
	}	
	printf("最小代价生成树各边为：\n");
	j = 0;//j指示se要当前要并入最小生成树边的边的序号，初值为0
	k = 0;//k指示当前构成最小生成树的边数
	while (k < G.vexnum - 1)//最小生成树应有G.vexnum - 1 条边
	{
		if (set[se[j].a] != set[se[j].b])
		{//j所指边的两顶点不在同一个连通分量中（不属于同一个集合）
			printf("(%s-%s)\n",G.vex[se[j].a].name,G.vex[se[j].b].name);
			sb = set[se[j].b];//将该边的顶点se[j].b所在的来连通分量标志赋给sb
			for (i = 0; i < G.vexnum; ++i)
			{//与se[j].b在同一个连通分量中的顶点都标记到se[j].a所在连通分量中；
				if (sb == set[i])
				{
					set[i] = set[se[j].a];
				}
			}
			k++;//边数+1
		}
		j++;//j指示下一条要并入最小生成树中的边的序号
	}
}