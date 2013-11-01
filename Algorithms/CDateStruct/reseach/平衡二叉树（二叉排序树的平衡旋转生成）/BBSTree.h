#ifndef BBSTREE_H
#define BBSTREE_H
#include "Status.h"
#include "DElemType.h"
//平衡二叉树的存储结构
typedef struct BBSTNode
{
	DElemType data;//数据元素类型的结点值
	int BF;//结点的平衡因子，比二叉树结构多此项
	BBSTNode *lchild,*rchild;//左右孩子指针
}BBSTNode, *BBSTree;
//基本操作函数声明
void R_Rotate(BBSTree &p);

void L_Rotate(BBSTree &p);

void LR_Rotate(BBSTree &p);

void RL_Rotate(BBSTree &p);

void LeftBalance(BBSTree &T);

void RightBalance(BBSTree &T);

Status InsertAVL(BBSTree &T,DElemType e,Boolean &taller);
#endif