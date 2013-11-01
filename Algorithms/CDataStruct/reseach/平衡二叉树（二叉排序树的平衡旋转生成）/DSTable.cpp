#include "DSTable.h"

Status SearchBST(BiTree &T,KeyType key,BiTree f,BiTree &p)
{//在二叉排序树中查找关键字等于key的记录，查找成功，则返回True,且p指针指向该记录的结点，查找失败，则返回FALSE,p指针指向查找路径上的最后一个结点
	if (!T)
	{
		p = f;
		return FALSE;
	}
	else if (EQ(key,T->data.key))
	{//找到等于key的记录
		p = T;
		return TRUE;
	}
	else if(LT(key,T->data.key))
	{//在左子树中查找
		return SearchBST(T->lchild,key,T,p);
	}
	else
	{//在右子树中查找
		return  SearchBST(T->rchild,key,T,p);
	}
}

Status InsertBST(BiTree &T,DElemType e)
{//在二叉排序表T中插入记录e
	BiTree p,s;
	if (!SearchBST(T,e.key,NULL,p))
	{//查找失败，返回FALSE,p指针指向查找路径上的最后一个结点
		s = (BiTree)malloc(sizeof(BiTNode));//生成新结点
		s->data.key = e.key;
		s->data.others = e.others;
		s->lchild = s->rchild = NULL;
		if (!T)
		{//T为空，则插入e为二叉查找树的根结点
			T = s;
		}
		else if (LT(e.key,p->data.key))
		{//e.key小于最后结点T的key，则将e作为T的左孩子
			p->lchild = s;
		}
		else
		{//e.key大于最后结点T的key，则将e作为T的右孩子
			p->rchild = s;
		}
		return TRUE;
	}
	return FALSE;
}

void Delete(BiTree &p)
{//从二叉排序树中删除p所指向的结点（p是该节点的双亲的其中一个指针域，而非独立的指针变量），并重接它的左右子树
	BiTree s,q = p;//q指向待删除结点
	if (!p->lchild)
	{//p的右子树为空，则重接它的左子树子树
		p = p->rchild;
		free(q);
	}
	else if (!p->rchild)
	{//p的左子树为空，则重接它的右子树子树
		p = p->lchild;
		free(q);
	}
	else
	{//p的左右子树都不空
		s = p->lchild;//s指向待删除结点的左孩子
		while (s->rchild)
		{//s向右到尽头
			q = s;
			s = s->rchild;
		}
		p->data = s->data;//将待删结点的前驱（关键字排序）的值取代待删结点
		if (q != p)
		{//新待删结点*s的左孩子重接到其双亲结点q的右子树
			q->rchild = s->lchild;
		}
		else
		{//新待删结点*s的左子树重接到其双亲结点q的左子树
			q->lchild = s->lchild;
		}
		free(s);
	}
}

Status DeleteBST(BiTree &T,KeyType key)
{//若二叉排序树T中存在关键字等于Key的数据元素时，则删除之
	if (!T)//树空
	{
		return FALSE;
	}
	else
	{
		if (EQ(key,T->data.key))
		{//找到待删记录
			Delete(T);
		}
		else if (LT(key,T->data.key))
		{//向左查找待删结点
			DeleteBST(T->lchild,key);
		}
		else
		{//向右查找待删结点
			DeleteBST(T->rchild,key);
		}
		return TRUE;
	}
}







