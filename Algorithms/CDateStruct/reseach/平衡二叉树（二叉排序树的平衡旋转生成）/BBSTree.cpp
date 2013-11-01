#include "BBSTree.h"

void R_Rotate(BBSTree &p)
{//对以*p为根的平衡二叉树的LL型失衡，作单向右旋处理，使二叉树的重心右移，但此处不修改平衡因子
	BBSTree lc;
	lc = p->lchild;//lc指向p的左孩子结点，lc的左子树不变
	p->lchild = lc->rchild;//lc的右子树挂接为p的左子树
	lc->rchild = p;//原根结点为lc的右子树
	p = lc;//原根结点更新为lc
}

void L_Rotate(BBSTree &p)
{//对以*p为根的平衡二叉树的RR型失衡，作单向左旋处理，使二叉树的重心左移，但此处不修改平衡因子
	BBSTree rc;
	rc = p->rchild;//rc指向p的右孩子结点，rc的右子树不变
	p->rchild = rc->lchild;//rc的左子树挂接为p的右子树
	rc->lchild = p;//原根结点为rc的左子树
	p = rc;//原根结点更新为rc
}

void LR_Rotate(BBSTree &p)
{//对以*p为根的平衡二叉树的LR型失衡，直接进行平衡旋转处理（不是双向旋转）,但此处不修改平衡因子
	BBSTree lc;
	lc = p->lchild;//lc指向p的左孩子结点，lc的左子树不变
	p->lchild = lc->rchild->rchild;//lc的右子树根结点的右子树挂接为结尾p的左子树
	lc->rchild->rchild = p;//原根结点是lc的右子树根结点的右子树
	p = lc->rchild;//原根结点更新为lc的右子树
	lc ->rchild = p->lchild;//更新后的根结点左子树挂接为lc的右子树
	p->lchild = lc;//lc是更新后的根结点的左子树
}

void RL_Rotate(BBSTree &p)
{//对以*p为根的平衡二叉树的RL型失衡，直接进行平衡旋转处理（不是双向旋转）,但此处不修改平衡因子
	BBSTree rc;
	rc = p->rchild;//rc指向p的右孩子结点，rc的右子树不变
	p->rchild = rc->lchild->lchild;//rc的右子树根结点的左子树挂接为结尾p的右子树
	rc->lchild->lchild = p;//原根结点是rc的右子树根结点的右子树
	p = rc->lchild;//原根结点更新为rc的左子树
	rc ->lchild = p->rchild;//更新后的根结点右子树挂接为rc的左子树
	p->rchild = rc;//rc是更新后的根结点的右子树
}

#define LH 1//平衡因子为1,左高 
#define EH 0//平衡因子为0,等高
#define RH -1//平衡因子为-1,右高

void LeftBalance(BBSTree &T)
{//初始条件：原本平衡二叉树T的左子树比右子树高（T->bf = 1）,又在左子树中插入了结点，并导致左子树更高，破坏了树T的平衡性
//操作结果：对不平衡树T（LL型失衡和LR型失衡）作左平衡旋转处理，使树T的重心向右移，实现新的的平衡。结束时，T指向新的平衡二叉树根结点。
	BBSTree lc,rd;
	lc = T->lchild;
	switch (lc->BF)
	{//检查*T的左子树平衡度，并做相应的平衡处理
	case LH://新结点插入在*T的左孩子的左子树上，导致左子树的平衡因子为左高，形成LL(/)型失衡，要作单向右旋处理
		T->BF = lc->BF = EH;//旋转后，原根结点和左孩子（新根结点）的平衡因子为0
		R_Rotate(T);//作单向右旋处理
		break;
	case RH://新结点插入在*T的左孩子的右子树上，导致左子树的平衡因子为右高，形成LR(<)型失衡，要作双旋处理或直接平衡旋转处理。
		rd = lc->rchild;
		switch (rd->BF)
		{//检查*T的左孩子的右子树的平衡度，修改*T及其左孩子的平衡因子
		case LH://新结点插入在*T的左孩子的右孩子的左子树上
			T->BF = RH;//旋转后，原根结点的平衡因子为右高
			lc ->BF = EH;//旋转后，原根结点的左孩子的平衡因子为等高
			break;
		case EH://新结点是*T的左孩子的右孩子（即*rd为叶子结点）
			T->BF = lc->BF = EH;//旋转后，原根结点和左孩子结点的平衡因子都为等高
			break;
		case RH://新结点插在*T的左孩子的右孩子的左子树上
			T->BF = EH;//旋转后，原根结点的平衡因子为等高
			lc->BF = LH;//旋转后，原根结点的左孩子的平衡因子为左高
		}
		rd->BF = EH;
#ifndef FLAG//没定义FLAG,使用2个函数实现双旋处理
		L_Rotate(T->lchild);//对以*T的左孩子为根结点的右子树（包括根结点*(T->lchild)）进行左旋处理，使*T成为LL(/)型失衡
		R_Rotate(T);//对以更新后的*T的左子树（包括根结点*T）进行右旋处理，使T平衡
#else//定义了FLAG，用一个函数直接处理LR型失衡
		LR_Rotate(T);//对*T直接进行平衡旋转处理
#endif
	}
}

void RightBalance(BBSTree &T)
{//初始条件：原本平衡二叉树T的右子树比左子树高（T->bf = -1）,又在右子树中插入了结点，并导致右子树更高，破坏了树T的平衡性
//操作结果：对不平衡树T（RR型失衡和RL型失衡）作左平衡旋转处理，使树T的重心向左移，实现新的的平衡。结束时，T指向新的平衡二叉树根结点。
	BBSTree rc,ld;
	rc = T->rchild;
	switch (rc->BF)
	{//检查*T的右子树平衡度，并做相应的平衡处理
	case RH://新结点插入在*T的右孩子的右子树上，导致右子树的平衡因子为右高，形成RR(\)型失衡，要作单向左旋处理
		T->BF = rc->BF = EH;//旋转后，原根结点和右孩子（新根结点）的平衡因子为0
		L_Rotate(T);//作单向左旋处理
		break;
	case LH://新结点插入在*T的右孩子的左子树上，导致右子树的平衡因子为左高，形成RL(>)型失衡，要作双旋处理或直接平衡旋转处理。
		ld = rc->lchild;
		switch (ld->BF)
		{//检查*T的右孩子的左子树的平衡度，修改*T及其右孩子的平衡因子
		case RH://新结点插入在*T的右孩子的左孩子的右子树上
			T->BF = LH;//旋转后，原根结点的平衡因子为左高
			rc ->BF = EH;//旋转后，原根结点的右孩子的平衡因子为等高
			break;
		case EH://新结点是*T的右孩子的左孩子（即*ld为叶子结点）
			T->BF = rc->BF = EH;//旋转后，原根结点和右孩子结点的平衡因子都为等高
			break;
		case LH://新结点插在*T的右孩子的左孩子的左子树上
			T->BF = EH;//旋转后，原根结点的平衡因子为等高
			rc->BF = RH;//旋转后，原根结点的右孩子的平衡因子为右高
		}
		ld->BF = EH;
#ifndef FLAG//没定义FLAG,使用2个函数实现双旋处理
		R_Rotate(T->rchild);//对以*T的右孩子为根结点的左子树（包括根结点*(T->rchild)）进行右旋处理，使*T成为RR(\)型失衡
		L_Rotate(T);//对以更新后的*T的右子树（包括根结点*T）进行左旋处理，使T平衡
#else//定义了FLAG，用一个函数直接处理RL型失衡
		RL_Rotate(T);//对*T直接进行平衡旋转处理
#endif
	}
}

Status InsertAVL(BBSTree &T,DElemType e,Boolean &taller)
{//若在平衡的二叉排序树T中不存在和e有相同关键字的结点，则插入一个数据元素为e的新结点，不返回TRUE;否则返回FALSE
 //若因插入而使平衡二叉树失衡，则做平衡旋转处理,布尔型变量taller反映在调用InserAVL()前后，T是否长高。
	if (!T)
	{//树或子树为空
		T = (BBSTree)malloc(sizeof(BBSTNode));//插入新结点
		T->data = e;
		T->lchild = T->rchild = NULL;
		T->BF = EH;//叶子结点的平衡因子为等高
		taller = TRUE;//以T为根结点的数长高了（深度由0变为1）,此信息返回该T的双亲结点
	}
	else
	{//树或子树不空
		if (EQ(e.key,T->data.key))
		{//T所指的结点的关键字与插入结点的关键字相同
			taller = FALSE;//未插入结点，没有长高
			return FALSE;//没有在树中插入结点的标志
		}
		else if (LT(e.key,T->data.key))
		{//T所指的结点的关键字小于插入结点的关键字。
			if (!InsertAVL(T->lchild,e,taller))//继续在*T的左子树中递归调用InsertAVL()
			{//已存在e,未能插入
				return FALSE;//返回没有在树中插入结点的标志
			}
			if (taller)
			{//已插入到*T的左子树中且左子树长高
				switch (T->BF)//检查T的平衡因子
				{
				case LH://原本树T的左子树比右子树高，现在T的左子树又长高了
					LeftBalance(T);//对树T作左平衡处理，使T重心右移
					taller = FALSE;//对T作左平衡处理后，树T的深度与插入结点e前相同，未长高，此信息返回给T的双亲结点
					break;
				case EH://原本树T的左子树与右子树等高，现在T的左子树长高了
					T->BF = LH;//T的左子树高于右子树
					taller = TRUE;//树T比插入结点e前长高了，此信息返回给T的双亲结点
					break;
				case RH://原本树T的右子树比左子树高，现在T的左子树长高了，左右子树变平衡了
					T->BF = EH;//左右子树等高
					taller = FALSE;//左右子树等高，T的深度未增加，此信息返回给T的双亲结点
				}
			}
		}
		else
		{
			if (!InsertAVL(T->rchild,e,taller))//继续在*T的右子树中递归调用InsertAVL()
			{//已存在e,未能插入
				return FALSE;//返回没有在树中插入结点的标志
			}
			if (taller)
			{//已插入到*T的右子树中且右子树长高
				switch (T->BF)//检查T的平衡因子
				{
				case RH://原本树T的右子树比左子树高，现在T的右子树又长高了
					RightBalance(T);//对树T作右平衡处理，使T重心左移
					taller = FALSE;//对T作右平衡处理后，树T的深度与插入结点e前相同，未长高，此信息返回给T的双亲结点
					break;
				case EH://原本树T的左子树与右子树等高，现在T的右子树长高了
					T->BF = RH;//T的右子树高于左子树
					taller = TRUE;//树T比插入结点e前长高了，此信息返回给T的双亲结点
					break;
				case LH://原本树T的左子树比右子树高，现在T的右子树长高了，左右子树变平衡了
					T->BF = EH;//左右子树等高
					taller = FALSE;//左右子树等高，T的深度未增加，此信息返回给T的双亲结点
				}
			}
		}
	}
	return TRUE;
}