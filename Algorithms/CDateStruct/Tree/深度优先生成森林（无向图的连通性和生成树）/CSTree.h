#include <stdio.h>
#include "Status.h"
//#include "TElmeType.h"
#include "VertexType.h"
typedef VertexType TElemType;
typedef struct CSNode//树的二叉链表存储结构
{
	TElemType data;//结点的值
	CSNode *firstchild, *nextsibling;//长子和兄弟
}CSNode, *CSTree;


void InitTree(CSTree &T);
void DestroyTree(CSTree &T);
void PostOrderTraverse(CSTree T, void(*visit)(TElemType));
void LevelOrderTraverse(CSTree T,void (*visit)(TElemType));
void PreOrderTraverse(CSTree T,void (*visit)(TElemType));
