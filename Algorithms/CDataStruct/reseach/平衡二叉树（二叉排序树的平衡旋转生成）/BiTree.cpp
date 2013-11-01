#include "Status.h"
#define ET 1//只要每个源文件包含或其头文件包含QElemType.h都必须定义ET
#include "BiTree.h"
#include "LinkQueue.h"//其包含的"QElemType.h"中有包含"BiTree.h",所以"BiTree.h"中应有头文件保护符，否则会重复定义
//C++
#include <stack>
#include <vector>
#include <list>
#define ClearBiTree DestroyBiTree //清空二叉链表同销毁二叉链表

using namespace std;

void InitBiTree(BiTree &T)
{//初始化二叉树为空二叉树
	T = NULL;
}

void DestroyBiTree(BiTree &T)
{//后序销毁二叉链表（因为这种遍历顺序的操作定义为：后序遍历左子树--后序遍历右子树--访问根节点，先访问根节点的话就无法访问其子树了）
	if (T)
	{
		DestroyBiTree(T->lchild);//递归调用,T指向左子树
		DestroyBiTree(T->rchild);//递归调用,T指向右子树
		free(T);//释放结点
		T = NULL;
	}
}

void PreOrderTraverse(BiTree T, void (*visit)(TElemType))
{//先序遍历二叉链表
	if (T)
	{
		visit(T->data);//先访问根节点
		PreOrderTraverse(T->lchild,visit);//再先序遍历左子树
		PreOrderTraverse(T->rchild,visit);//最后先序遍历右子树
	}
}

void InOrderTraverse(BiTree T, void (*visit)(TElemType))
{
	if (T)
	{
		InOrderTraverse(T->lchild, visit);//先中序遍历左子树
		visit(T->data);                   //再访问根节点
		InOrderTraverse(T->rchild, visit);//最后中序遍历右子树
	}
}

void PostOrderTraverse(BiTree T, void (*visit)(TElemType))
{
	if (T)
	{
		PostOrderTraverse(T->lchild,visit);//先后序遍历左子树
		PostOrderTraverse(T->rchild,visit);//再后序遍历右子树
		visit(T->data);//最后访问根节点
	}
}

Status BiTreeEmpty(BiTree &T)
{//二叉链表判空
	if (!T)
	{//二叉链表为空
		return TRUE;
	}
	else
	{//二叉链表不为空
		return FALSE;
	}
}

int BiTreeDepth(BiTree &T)
{//返回二叉树深度
	int i,j;
	if (!T)
	{//若子树为空则返回0
		return 0;
	}
	i = BiTreeDepth(T->lchild);//i为左子树的深度，如左子树为空，则i为0；
	j = BiTreeDepth(T->rchild);//j为右子树的深度，如右子树为空，则j为0；
	return i > j ? i + 1: j + 1;//T的深度为子树中的大者加1；
}

TElemType Root(BiTree &T)
{//返回二叉树T的根
	if (T)
	{
		return T->data;
	}
	else
	{
		return Nil;
	}
}

TElemType value(BiTree p)
{//返回p所指结点的数据元素
	return p->data;
}

void Assign(BiTree p, TElemType value)
{//给p所指结点的数据元素赋值为value
	p->data = value;
}

Status DeleteChild(BiTree p, int LR)
{//删除p的左子树或用子树
	if (p)
	{
		if (0 == LR)
		{//清除左子树
			ClearBiTree(p->lchild);
		}
		else
		{//清除右子树
			ClearBiTree(p->rchild);
		}
		return OK;
	}
	return ERROR;
}

void LevelOrderTraverse(BiTree T, void(*visit)(TElemType))
{//层序遍历二叉树
	LinkQueue q;
	BiTree p;
	if (T)
	{
		InitQueue(q);
		EnQueue(q,T);
		while (!IsQueueEmpty(q))
		{
			DelQueue(q,p);
			visit(p->data);//访问元素
			if (p->lchild != NULL)
			{
				EnQueue(q, p->lchild);
			}
			if (p->rchild != NULL)
			{
				EnQueue(q, p->rchild);
			}
		}
		printf("\n"); 
	}
}

Status InsertChild(BiTree p, int LR, BiTree c)
{//插入插入子树e为左子树或右子树
	if (p)
	{
		if (LR = 0)
		{
			c->rchild = p->lchild;
			p->lchild = c;
		}
		else
		{
			c->rchild = p->rchild;
			p->rchild = c;
		}
		return OK;
	}
	return ERROR;
}

void InOrderTraverse1(BiTree T, void(*visit)(TElemType))
{//中序遍历二叉树
	stack<BiTree,vector<BiTree>> S;//栈，C++中的容器适配器stack
	while (T || !S.empty())
	{
		if (T)
		{
			S.push(T);
			T = T->lchild;
		}
		else
		{
			T = S.top();
			S.pop();
			visit(T->data);
			T = T->rchild;
		}

	}
	printf("\n");

}