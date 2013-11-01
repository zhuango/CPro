#include "Status.h"
#include "InfoType.h"//弧（边）的相关信息类型
#include "VertexType.h"//顶点类型

#define MAX_VERTEX_NUM 20//最大顶点数
enum GraphKind{DG,DN,UDG,UDN};//枚举常量GraphKind为图的类型

struct ElemType
{//存储弧（边）的信息
	int adjvex;//该弧（边）所指向的顶点的位置
	InfoType * info;//该弧的相关信息（包括网的权值）的指针
};

struct ArcNode
{//表结点，存储弧（边）的相关信息
	ElemType data;//数据域
	ArcNode *nextarc;//指向下一条弧（边）
};

typedef struct
{//头结点，存储顶点信息
	VertexType data;//顶点信息
	ArcNode *firstarc;//第一个表结点的地址，指向第一条依附于该顶点的弧的指针
}VNode, AdjList[MAX_VERTEX_NUM];

struct ALGraph
{//邻接表结构
	AdjList vertices;//头结点（顶点）数组
	int vexnum,arcnum;//顶点数，弧（边）数
	GraphKind kind;//图的类型标志
};

/****引入单链表的基本操作****/
#define LNode ArcNode//用邻接表的表结点替换单链表操作中的结点
#define next nextarc//替换结点的指针域
typedef ArcNode *LinkList ;//链表的头指针指向表结点
//单链表基本操作函数声明

Status Equal(ElemType e1,ElemType e2);//新增
void InitList(LinkList &L);
void ClearList(LinkList &L);
Status ListEmpity(LinkList L);
int ListLength(LinkList L);
Status GetElem(LinkList L,int i,ElemType &e);
int LocateElem(LinkList L,ElemType e,Status(*compare)(ElemType,ElemType));
Status ListInsert(LinkList &L,int i,ElemType e);
Status ListDelete(LinkList &L,int i,ElemType &e);
void ListTraverse(LinkList L, void (*vi)(ElemType));
Status PriorElem(LinkList L,ElemType cur_e,ElemType &pre_e);//有修改 
Status NextElem(LinkList L,ElemType cur_e,ElemType &next_e);//有修改
LinkList Point(LinkList L,ElemType e,Status(*equal)(ElemType ,ElemType),LinkList &pre);//新增
//邻接表基本操作函数声明

int LocateVex(ALGraph G,VertexType u);
void CreateGraph(ALGraph &G);
void CreateFromFile(ALGraph &G,char *filename);
VertexType GetVex(ALGraph &G,int v);
Status PutVex(ALGraph &G,VertexType v,VertexType value);
int FirstAdjVex(ALGraph G,int v);
Status EqualVex(ElemType a,ElemType b);
int NextAdjVex(ALGraph G,int v,int w);
void InsertVex(ALGraph &G,VertexType v);
Status InsertArc(ALGraph &G,VertexType v,VertexType w);
Status DeleteArc(ALGraph &G,VertexType v,VertexType w);
Status DeleteVex(ALGraph &G,VertexType v);
void DestroyGraph(ALGraph &G);
void Display(ALGraph G);