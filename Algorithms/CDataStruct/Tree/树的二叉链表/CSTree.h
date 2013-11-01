#include <stdio.h>
#include "Status.h"
#include "TElmeType.h"

typedef struct CSNode//树的二叉链表存储结构
{
	TElemType data;//结点的值
	CSNode *firstchild, *nextsibling;//长子和兄弟
}CSNode, *CSTree;


void InitTree(CSTree &T);
void DestroyTree(CSTree &T);
void CreateTree(CSTree &T);
Status TreeEmpty(CSTree T);
int TreeDepth(CSTree T);
TElemType Value(CSTree p);
TElemType Root(CSTree T);
CSTree Point(CSTree T, TElemType s);
Status Assign(CSTree &T, TElemType cur_e, TElemType value);
TElemType Parent(CSTree T, TElemType cur_e);
TElemType LeftChild(CSTree T, TElemType cur_e);
TElemType RightSibling(CSTree T, TElemType cur_e);
Status InsertChild(CSTree T, CSTree p, int i, CSTree c);
Status DeleteChild(CSTree T, CSTree p, int i);
void PostOrderTraverse(CSTree T, void(*visit)(TElemType));
void LevelOrderTraverse(CSTree T,void (*visit)(TElemType));
void PreOrderTraverse(CSTree T,void (*visit)(TElemType));
