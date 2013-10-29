#include "MGraph.h"

int LocateVex(MGraph G,VertexType u)
{//返回顶点u在图中的位置（序号）
	int i;
	for (i = 0; i < G.vexnum; ++i)
	{
		if (0 == strcmp(G.vex[i].name,u.name))
		{
			return i;
		}
	}
	return -1;
}

void CreateDG(MGraph &G)
{
	int i,j,k,IncInfo;
	VertexType v1,v2;
	printf("请输入有向图的顶点数，弧数，弧是否含有信息（是：1 否：0):");
	scanf("%d,%d,%d",&G.vexnum,&G.arcnum,&IncInfo);

	printf("请输入%d个顶点的值(名称<%d个字符)\n",G.vexnum,MAX_NAME);
	for (i = 0; i < G.vexnum; ++i)
	{
		Input(G.vex[i]);
	}

	for (i = 0;i < G.vexnum; ++i)
	{//初始化邻接矩阵（弧的信息）
		for (j = 0; j < G.vexnum; ++j)
		{
			G.arcs[i][j].adj = 0;//弧不相邻
			G.arcs[i][j].info = NULL;//弧无相关信息
		}
	}
	
	printf("输入%d条弧的弧尾和弧头\n",G.arcnum);
	for (k = 0; k < G.arcnum; ++k)
	{
		scanf("%s%s%*c",&v1.name,&v2.name);//%*c吃掉回车符
		i = LocateVex(G,v1);//弧尾的序号
		j = LocateVex(G,v2);//弧头的序号
		G.arcs[i][j].adj = 1;//
		if (IncInfo)
		{//有相关信息
			InputArc(G.arcs[i][j].info);//动态生成存储结构，输入弧的信息
		}
	}
	
	G.kind = DG;//标记为有向图
}

void CreateDN(MGraph &G)
{
	int i,j,k,IncInfo;
	VertexType v1,v2;
	VRType w;
	printf("请输入有向网的顶点数，边数，边是否含有信息（是：1 否：0):");
	scanf("%d,%d,%d",&G.vexnum,&G.arcnum,&IncInfo);

	printf("请输入%d个顶点的值(名称<%d个字符)\n",G.vexnum,MAX_NAME);
	for (i = 0; i < G.vexnum; ++i)
	{
		Input(G.vex[i]);
	}

	for (i = 0;i < G.vexnum; ++i)
	{//初始化邻接矩阵（边的信息）
		for (j = 0; j < G.vexnum; ++j)
		{
			G.arcs[i][j].adj = INFINITY;//边不相邻
			G.arcs[i][j].info = NULL;//边无相关信息
		}
	}
	
	printf("输入%d条弧，弧头，弧尾和对应的权值\n",G.arcnum);
	for (k = 0; k < G.arcnum; ++k)
	{
		scanf("%s%s%d%*c",&v1.name,&v2.name,&w);//%*c吃掉回车符
		i = LocateVex(G,v1);//顶点1序号
		j = LocateVex(G,v2);//顶点2序号
		G.arcs[i][j].adj = w;//边的权值
		if (IncInfo)
		{//有相关信息
			InputArc(G.arcs[i][j].info);//动态生成存储结构，输入边的信息
		}
	}
	G.kind = DN;//标记为有向网 	
}

void CreateUDG(MGraph &G)
{
	int i,j,k,IncInfo;
	VertexType v1,v2;
	printf("请输入无向图的顶点数，顶点数，边是否含有信息（是：1 否：0）:");
	scanf("%d,%d,%d",&G.vexnum,&G.arcnum,&IncInfo);

	printf("请输入%d个顶点的值(名称<%d个字符)\n",G.vexnum,MAX_NAME);
	for (i = 0; i < G.vexnum; ++i)
	{
		Input(G.vex[i]);
	}

	for (i = 0;i < G.vexnum; ++i)
	{//初始化邻接矩阵（弧的信息）
		for (j = 0; j < G.vexnum; ++j)
		{
			G.arcs[i][j].adj = 0;//弧不相邻
			G.arcs[i][j].info = NULL;//弧无相关信息
		}
	}
	
	printf("输入%d条边的顶点1和顶点2\n",G.arcnum);
	for (k = 0; k < G.arcnum; ++k)
	{
		scanf("%s%s%*c",&v1.name,&v2.name);//%*c吃掉回车符
		i = LocateVex(G,v1);//弧尾的序号
		j = LocateVex(G,v2);//弧头的序号
		G.arcs[i][j].adj = 1;
		if (IncInfo)
		{//有相关信息
			InputArc(G.arcs[i][j].info);//动态生成存储结构，输入弧的信息
		}
		G.arcs[j][i].adj = G.arcs[i][j].adj;//无向对称
	}
	
	G.kind = UDG;//标记为有向图

}

void CreateUDN(MGraph &G)
{
	int i,j,k,IncInfo;
	VertexType v1,v2;
	VRType w;
	printf("请输入无向网的顶点数，边数，边是否含有信息（是：1 否：0):");
	scanf("%d,%d,%d",&G.vexnum,&G.arcnum,&IncInfo);

	printf("请输入%d个顶点的值(名称<%d个字符)",G.vexnum,MAX_NAME);
	for (i = 0; i < G.vexnum; ++i)
	{
		Input(G.vex[i]);
	}

	for (i = 0;i < G.vexnum; ++i)
	{//初始化邻接矩阵（边的信息）
		for (j = 0; j < G.vexnum; ++j)
		{
			G.arcs[i][j].adj = INFINITY;//边不相邻
			G.arcs[i][j].info = NULL;//边无相关信息
		}
	}
	
	printf("输入%d条边的顶点1，顶点2和对应的权值\n",G.arcnum);
	for (k = 0; k < G.arcnum; ++k)
	{
		scanf("%s%s%d%*c",&v1.name,&v2.name,&w);//%*c吃掉回车符
		i = LocateVex(G,v1);//顶点1序号
		j = LocateVex(G,v2);//顶点2序号
		G.arcs[i][j].adj = w;//边的权值
		if (IncInfo)
		{//有相关信息
			InputArc(G.arcs[i][j].info);//动态生成存储结构，输入边的信息
		}
		G.arcs[j][i].adj = G.arcs[i][j].adj;//无向对称
	}
	G.kind = UDN;//标记为有向网 	
}

void CreateGraph(MGraph &G)
{
	printf("请输入图G的类型（有向图：0 有向网：1 无向图：2 无向网：3）");
	scanf("%d",&G.kind);
	switch(G.kind)
	{//根据图G的类型，调用不同的构造图的函数
	case DG: CreateDG(G);//有向图
		break;
	case DN:CreateDN(G);//有向网
		break;
	case UDG:CreateUDG(G);//无向图
		break;
	case UDN:CreateUDN(G);//无向网
	}
}

VertexType GetVex(MGraph G,int v)
{//返回序号为v的顶点值
	if (v > G.vexnum || v < 0)
	{
		exit(OVERFLOW);
	}
	return G.vex[v];
}

Status PutVex(MGraph &G,VertexType v,VertexType value)
{//对v赋新值
	int k = LocateVex(G,v);
	if (k > G.vexnum || k < 0)
	{
		return ERROR;
	}
	G.vex[k] = value;
	return OK;
}

int FirstAdjVex(MGraph G,int v)
{//返回序号为v的顶点的第一个邻接点的序号
	int i;
	VRType j = 0;//默认为图的否相邻表示（0）
	if (v > G.vexnum || v < 0)
	{
		return ERROR;
	}
	if (G.kind % 2)//网
	{
		j = INFINITY;//改为网的否相邻表示（INFINITY）
	}

	for (i = 0; i < G.vexnum; ++i)
	{
		if (G.arcs[v][i].adj != j)//不为否相邻，即相邻
		{
			return i;
		}
	}
	return -1;
}

int NextAdjVex(MGraph G,int v,int w)
{//返回序号为v的顶点的下一个邻接点（相对于w）
	int i;
	VRType j = 0;
	if (v > G.vexnum || v < 0)
	{
		return ERROR;
	}
	if (G.kind % 2)//网
	{
		j = INFINITY;//改为网的否相邻表示（INFINITY）
	}

	for (i = w + 1; i < G.vexnum; ++i)
	{
		if (G.arcs[v][i].adj != j)//不为否相邻，即相邻
		{
			return i;
		}
	}
	return -1;
}

void InsertVex(MGraph &G, VertexType v)
{//在图中增添新顶点v(不增添与顶点相关的弧或边，留待InsertArc()去做)
	int i;
	VRType j = 0;
	G.vex[G.vexnum] = v;
	if (G.kind % 2)//网
	{
		j = INFINITY;
	}
	for (i = 0; i <= G.vexnum; ++i)
	{//初始化邻接矩阵
		G.arcs[G.vexnum][i].adj = G.arcs[i][G.vexnum].adj = j;
		G.arcs[G.vexnum][i].info = G.arcs[i][G.vexnum].info = NULL;
	}
	G.vexnum++;//顶点数加1
}
Status InsertArc(MGraph &G, VertexType v,VertexType w)
{//在图中增添弧<v,w>,若是无向图，则还增添对称弧<w,v>
	int i,v1,w1;
	v1 = LocateVex(G,v);
	w1 = LocateVex(G,w);
	if (v1 < 0 || w1 < 0)
	{
		return ERROR;
	}
	if (G.kind % 2)//网
	{
		printf("请输入此弧（或边）的权值：");
		scanf("%d",&G.arcs[v1][w1].adj);
	}
	else
	{
		G.arcs[v1][w1].adj = 1;
	}
	printf("是否有该弧或边的相关信息（0：无  1：有）");
	scanf("%d%*c",&i);
	if (i)
	{//输入弧的信息
		InputArc(G.arcs[v1][w1].info);
	}
	if (G.kind > 1)
	{//无向
		G.arcs[w1][v1] = G.arcs[v1][w1];
	}
	G.arcnum++;
	return OK;
} 

Status DeleteArc(MGraph &G,VertexType v,VertexType w)
{//在图中删除弧<v,w>,若是无向，则好删除弧<w,v>
	int v1,w1;
	VRType j = 0;
	v1 = LocateVex(G,v);
	w1 = LocateVex(G,w);
	if (v1 < 0 || w1 < 0)
	{
		return ERROR;
	}
	if (G.kind % 2)//网
	{
		j = INFINITY;
	}
	if (G.arcs[v1][w1].adj != j)
	{
		G.arcs[v1][w1].adj = j;
		if (G.arcs[v1][w1].info)
		{
			free(G.arcs[v1][w1].info);
			G.arcs[v1][w1].info = NULL;
		}
		if (G.kind > 1)//无向
		{
			G.arcs[w1][v1] = G.arcs[v1][w1];
		}
		G.arcnum--;
	}
	return OK;	
}

Status DeleteVex(MGraph &G, VertexType v)
{//删除图中的顶点v
	int i,j,k;
	k = LocateVex(G,v);
	if (k < 0)
	{
		return ERROR;
	}
	for (i = 0; i < G.vexnum; ++i)
	{//删除由顶点v出发的所有弧
		DeleteArc(G,v,GetVex(G,i));
	}
	if (G.kind < 2)//有向
	{//删除发向顶点v的所有弧
		for (i = 0; i < G.vexnum; ++i)
		{
			DeleteArc(G,GetVex(G,i),v);
		}
	}
	for (i = k + 1; i < G.vexnum; ++i)
	{//删除顶点v的序号
		G.vex[i - 1] = G.vex[i]; 
	}
	for (i = k + 1; i < G.vexnum; ++i)
	{//移动待删除顶点之右的矩阵元素
		for (j = 0; j < G.vexnum; ++j)
		{
			G.arcs[j][i - 1] = G.arcs[j][i];
		}
	}
	for (i = k + 1; i < G.vexnum; ++i)
	{//移动待删除顶点之下的矩阵元素
		for (j = 0; j < G.vexnum; ++j)
		{
			G.arcs[i - 1][j] = G.arcs[i][j];
		}
	}
	G.vexnum--;
	return OK;
}
void DestroyGraph(MGraph &G)
{
	int i;
	for (i = G.vexnum - 1; i >= 0; --i)
	{
		DeleteVex(G,G.vex[i]);
	}
}	

void Display(MGraph G)
{
	int i,j;
	char s[10] = "无向网", s1[4] = "边";
	switch(G.kind)
	{
	case DG:strcpy(s,"有向图");
			strcpy(s1,"弧");
			break;
	case DN:strcpy(s,"有向网");
			strcpy(s1,"弧");
			break;
	case UDG:strcpy(s,"无向图");
			break;
	case UDN:;
	}
	printf("%d个顶点%d条%s的%s。顶点依次是：",G.vexnum,G.arcnum,s1,s);
	for (i = 0; i < G.vexnum; ++i)
	{
		Visit(GetVex(G,i));
	}
	printf("\nG.arcs.adj:\n");
	for (i = 0; i < G.vexnum; ++i)
	{
		for (j = 0; j < G.vexnum; ++j)
		{
			printf("%11d",G.arcs[i][j].adj);
		}
		printf("\n");
	}
	printf("G.arcs.info:\n");
	if (G.kind < 2)//有向
	{
		printf("弧尾 弧头 该%s的信息\n",s1);
	}
	else
	{
		printf("顶点1 顶点2 该%s的信息:\n",s1);
	}
	for (i = 0; i < G.vexnum; ++i)
	{
		if (G.kind < 2)
		{
			for (j = 0; j < G.vexnum; ++j)
			{
				if (G.arcs[i][j].info)
				{
					printf("%5s%5s  ",G.vex[i].name,G.vex[j].name);
					OutputArc(G.arcs[i][j].info);
				}
			}
		}
		else
		{
			for (j = i + 1; j < G.vexnum; ++j)
			{
				if (G.arcs[i][j].info)
				{
					printf("%5s%5s ",G.vex[i].name,G.vex[j].name);
					OutputArc(G.arcs[i][j].info);
				}
			}
		}
	}
}

void CreateFromFile(MGraph &G,char *filename,int IncInfo)
{
	int i,j,k;
	VRType w = 0;
	VertexType v1,v2;
	FILE *f;
	f = fopen(filename,"r");
	fscanf(f,"%d",&G.kind);
	if (G.kind%2)
	{ 
		w = INFINITY;
	}
	fscanf(f,"%d",&G.vexnum);
	for (i = 0; i < G.vexnum; ++i)
	{
		InputFromFile(f,G.vex[i]);
	}
	fscanf(f,"%d",&G.arcnum);
	for (i = 0; i < G.vexnum; ++i)
	{//初始化邻接矩形
		for (j = 0; j < G.vexnum; ++j)
		{
			G.arcs[i][j].adj = w;
			G.arcs[i][j].info = NULL;
		}
	}
	if (!(G.kind%2))
	{
		w = 1;
	}
	for (k = 0; k < G.arcnum; ++k)
	{
		fscanf(f,"%s%s",v1.name,v2.name);
		if (G.kind%2)
		{
			fscanf(f,"%d",&w);
		}
		i = LocateVex(G,v1);
		j = LocateVex(G,v2);
		G.arcs[i][j].adj = w;
		if (IncInfo)
		{
			InputArcFromFile(f,G.arcs[i][j].info);
		}
		if (G.kind > 1)
		{
			G.arcs[j][i] = G.arcs[i][j];
		}
	}
	fclose(f);
}

