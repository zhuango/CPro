#define ET 1
#include "BiThrTree.h"
#include <malloc.h>

void CreatBiThrTree (BiThrTree &T)//构造线索二叉树T
{
	TElemType ch;
	scanf(form, &ch);
	if (ch == Nil)
	{
		T = NULL;
	}
	else
	{
		T = (BiThrTree)malloc(sizeof(BiThrNode));//构造结点
		if (!T)
		{
			exit (OVERFLOW);		
		}
		T->data = ch;
		CreatBiThrTree (T->lchild);//构造左子树
		if (T->lchild)
		{//T所指的结点有左孩子，则左标志为Link
			T->LTag = Link;
		}
		CreatBiThrTree(T->rchild);//构造右子树
		if (T->rchild)
		{//T所指的结点有右孩子，则右标志为Link
			T->RTag = Link;
		}
	}
}

BiThrTree pre;
void InThreading (BiThrTree p)//中序遍历线索化
{
	if (p)
	{
		InThreading (p->lchild);//左子树线索化
		if (!p->lchild)
		{//p的前驱线索
			p->LTag = Thread;
			p->lchild = pre;
		}
		if (!pre->rchild)
		{//pre的后继线索
			pre->RTag = Thread;
			pre->rchild = p;
		}
		pre = p;//保持pre指向p的前驱
		InThreading (p->rchild);//右子树线索化
	}
}
void InOrderThreading(BiThrTree &Thrt, BiThrTree T)//中序线索化
{
	if (!(Thrt = (BiThrTree)malloc(sizeof(BiThrNode))))
	{
		exit (OVERFLOW);
	}
	Thrt->LTag = Link;
	Thrt->RTag = Thread;
	Thrt->rchild = Thrt;
	if (!T)
	{
		Thrt->lchild = Thrt;
	}
	else
	{		
		Thrt->lchild = T;
		pre = Thrt;
		InThreading (T);
		pre->RTag = Thread;
		pre->rchild = Thrt;
		Thrt->rchild = pre;
	}
}
void InOrderTraverse_Thr (BiThrTree T, void (*visit)(TElemType))//中序遍历线索二叉树
{//T为头结点
	BiThrTree p = T->lchild;
	while (p != T)
	{
		while (p->LTag == Link)
		{
			p = p->lchild;
		}
		visit(p->data);
		while (p->RTag == Thread && p->rchild != T)
		{
			p = p->rchild;
			visit (p->data);
		}
		p = p->rchild;
	}

}