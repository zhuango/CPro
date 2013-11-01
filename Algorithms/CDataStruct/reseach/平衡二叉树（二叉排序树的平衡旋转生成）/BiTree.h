#ifndef BITREE_H
#define BITREE_H

#include "Status.h"
#include "BBSTree.h"
#include "TElmeType.h" 
//定义二叉链表的节点
//typedef struct BiTNode
//{
//	TElemType data;//数据域
//	BiTNode *lchild, *rchild;//指针域，分别指向左子树和右子树
//} *BiTree;//定义指向节点的头指针

typedef BBSTree BiTree;//将二叉树的存储类型重定义为平衡二叉树类型
typedef BBSTNode BiTNode;
//函数声明（一组操作）

void InitBiTree(BiTree &T);

void DestroyBiTree(BiTree &T);

void PreOrderTraverse(BiTree T, void (*visit)(TElemType));

void InOrderTraverse(BiTree T, void (*visit)(TElemType));

void PostOrderTraverse(BiTree T, void (*visit)(TElemType));

Status BiTreeEmpty(BiTree &T);

int BiTreeDepth(BiTree &T);

TElemType Root(BiTree &T);

TElemType value(BiTree p);

void Assign(BiTree p, TElemType value);

Status DeleteChild(BiTree p, int LR);

void LevelOrderTraverse(BiTree T, void(*visit)(TElemType));

Status InsertChild(BiTree p, int LR, BiTree c);

void InOrderTraverse1(BiTree T, void(*visit)(TElemType));
#endif