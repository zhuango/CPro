#include "FindArticul.h"
int count,lowcount = 1;//全局变量count对顶点访问顺序计数，lowcount对求得low值的顺序计数
int visited[MAX_VERTEX_NUM];//访问标志数组
int low[MAX_VERTEX_NUM],lowOrder[MAX_VERTEX_NUM];//low数组存顶点的low值,lowOrder存顶点求得low值的顺序（后根）
void DFSArticul(ALGraph G, int v0)
{
	int min,w;
	ArcNode *p;
	visited[v0] = min = ++count;//v0是第count个访问顶点,min的初值为v0的访问顺序
	for (p = G.vertices[v0].firstarc;p;p = p->nextarc)
	{
		w = p->data.adjvex;//w为v0的邻接点的位置
		if (0 == visited[w])//w未曾访问,是v0的孩子
		{
			DFSArticul(G,w);//从第w个顶点出发深度遍历图G,查找并输出关节点。返回前求得low[w]
			if (low[w] < min)//如果v0的孩子结点的low值小，这说明孩子结点还与其他节点（祖先）相邻
			{
				min = low[w];//取min值为孩子结点的low值，则v0不是关节点
			}
			else if (low[w] >= visited[v0])//v0的孩子结点w只与v0连接,则v0是关节点
			{
				printf("%d %s\n",v0,G.vertices[v0].data.name);//输出关节点v0
			}
		}
		else
		{
			if (visited[w] < min)//w已访问,则w是v0在生成树上的祖先,它的访问顺序必小于min
			{
				min = visited[w];//故取min为visited[w]
			}
		}
	}
	low[v0] = min;//v0的low值为三者中的最小值
	lowOrder[v0] = lowcount++;//记录v0求得low值上网顺序，总是在返回主调函数之前求得low[].
}

void FindArticul(ALGraph G)
{
	int i,v;
	ArcNode *p;
	count = 1;//访问顺序
	visited[0] = count;//设定邻接表上的0号顶点为生成树的根，第i个被访问的结点；
	for (i = 1; i < G.vexnum; ++i)//对其余顶点初始化
	{
		visited[i] = 0;
	}
	p = G.vertices[0].firstarc;
	v = p->data.adjvex;
	DFSArticul(G,v);
	if (count < G.vexnum)//说明生成树的根至少两棵子树，则根是关节点
	{
		printf("%d %s\n",0,G.vertices[0].data.name);//根是关节点，则输出根
		while (p->nextarc)//根有下一个邻接点
		{
			p = p->nextarc;//p指向下一个邻接点
			v = p->data.adjvex;
			if (visited[v] == 0)//此邻接点未被访问
			{
				DFSArticul(G,v);
			}
		}
	}
}