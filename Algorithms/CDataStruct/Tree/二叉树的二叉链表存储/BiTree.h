#ifndef BITREE_H
#define BITREE_H

#include "Status.h"
#include "TElmeType.h" 
//定义二叉链表的节点
typedef struct BiTNode
{
	TElemType date;//数据域
	BiTNode *lchild, *rchild;//指针域，分别指向左子树和右子树
} *BiTree;//定义指向节点的头指针

//函数声明（一组操作）
void InitBiTree(BiTree &);
void DestroyBiTree(BiTree &);
void PreOrderTraverse(BiTree , void (*visit)(TElemType));
void InOrderTraverse(BiTree , void (*visit)(TElemType));
void PostOrderTraverse(BiTree , void (*visit)(TElemType));
Status BiTreeEmpty(BiTree &);
int BiTreeDepth(BiTree &);
TElemType Root(BiTree &);
TElemType value(BiTree );
void Assign(BiTree , TElemType );
BiTree Point(BiTree , TElemType );
TElemType LeftChild(BiTree , TElemType );
TElemType RightChild(BiTree , TElemType );
Status DeleteChild(BiTree , int );
void CreatBiTree(BiTree &);
TElemType Parent(BiTree , TElemType );
void LevelOrderTraverse(BiTree , void (*visit)(TElemType));
TElemType LeftSibling(BiTree , TElemType );
TElemType RightSibling(BiTree , TElemType );
Status InsertChild(BiTree , int , BiTree );
void InOrderTraverse1(BiTree , void(*visit)(TElemType));
#endif