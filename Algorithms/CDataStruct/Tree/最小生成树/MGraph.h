#ifndef MGR_H
#define MGR_H
#include "Status.h"
#include "InfoType.h"
#include "VertexType.h"
#include <stdio.h>
#include <string>

#define INFINITY INT_MAX
typedef int VRType;//定义定点类型为整型，与INFINITY的类型一致
#define MAX_VERTEX_NUM 26
enum GraphKind{DG,DN,UDG,UDN};

typedef struct //边（或弧）的信息结构
{
	VRType adj; //顶点关系类型。对无权图，用1（是）或2（否）表示相邻否；对带权值，则为权值
	InfoType *info;//该弧的相关信息的指针（可无）
}ArcCell,AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];//二维数组，行列序号对应相应的顶点序号，数组值表示两顶点关系

struct MGraph//图的信息结构
{
	VertexType vex[MAX_VERTEX_NUM];//顶点向量 一维数组存储顶点信息
	AdjMatrix arcs;//邻接矩阵,存储边（或弧）的关系
	int vexnum, arcnum;//图的当前顶点数和边（或弧）数
	GraphKind kind;//图的类型标志
};

int LocateVex(MGraph G,VertexType u);
void CreateDG(MGraph &G);
void CreateDN(MGraph &G);
void CreateUDG(MGraph &G);
void CreateUDN(MGraph &G);
void CreateGraph(MGraph &G);
VertexType GetVex(MGraph G,int v);
Status PutVex(MGraph &G,VertexType v,VertexType value);
int FirstAdjVex(MGraph G,int v);
int NextAdjVex(MGraph G,int v,int w);
void InsertVex(MGraph &G, VertexType v);
Status InsertArc(MGraph &G, VertexType v,VertexType w);
Status DeleteArc(MGraph &G,VertexType v,VertexType w);
Status DeleteVex(MGraph &G, VertexType v);
void DestroyGraph(MGraph &G);
void Display(MGraph G);
void CreateFromFile(MGraph &G,char *filename,int IncInfo);
#endif

