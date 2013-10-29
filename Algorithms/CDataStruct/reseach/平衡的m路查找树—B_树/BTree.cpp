#include "BTree.h"

void Visit(BTNode c,int i)
{//访问结点上第i个关键字的记录
	printf("(%d,%d)",c.recptr[i]->key,c.recptr[i]->others);
}

void InputKey(KeyType &k)
{//输入关键字
	scanf("%d",&k);
}

void InitDSTable(BTree &DT)
{//构造一个空的B_树DT
	DT = NULL;
}

void DestroyDSTable(BTree &DT)
{//销毁一个B_树
	int i;
	if (DT)
	{
	  for (i = 0; i <= DT->keynum; ++i)
	  {
		 DestroyDSTable(DT->ptr[i]);//依次递归销毁第i棵子树
	  }
	  free(DT);
	  DT = NULL;
	}
}

void TraverseDSTable(BTree &DT,void (*Visit)(BTNode,int))
{//遍历B_树DT
	int i;
	if (DT)
	{
		for (i = 0; i <= DT->keynum;++i)
		{
			if (i > 0)
			{
				Visit(*DT,i);
			}
			TraverseDSTable(DT->ptr[i],Visit);
		}
	}
}

int Search(BTNode *p,KeyType k)
{//采用折半查找法在结点*p中查找满足k∈[p->key[i],p->key[i + 1])的序号i
	int mid,low = 1,high = p->keynum;
	if LT(k,p->key[low])
	{
		return 0;
	}
	while (low < high)
	{
		mid = (low + high + 1)/2;//中值去较大的
		if (EQ(k,p->key[mid]))
		{
			return mid;//找到满足k = p->key[i]的序号mid返回mid
		}
		else if (LT(k,p->key[mid]))
		{
			high = mid - 1;//在[low,mid)区间中进行查找
		}
		else
		{
			low = mid;//在[mid,high]区间中进行查找
		}
	}
	return low;//找到满足p->key[i] < i < p->key[i + 1]的序号low返回low
}

Result SearchBTree(BTree T,KeyType k)
{//在B_树DT中查找关键字等于k的记录，返回结果(pt,i,tag);若查找成功，则特征值tag=1,pt所指结点中第i个结点等于k;否则特征值tag=0,
 //等于k的关键词应插到指针pt所指结点的第i和第i+1个关键字之间
	BTree p = T,q = NULL;
	Status found = FALSE;
	int i = 0;
	Result r;
	while(p && !found)
	{//p不空且未找到k
		i = Search(p,k);//在*p结点中查找k
		if (i > 0 && p->key[i] == k)
		{//查找到k所在结点，退出循环
			found = TRUE;
		}
		else
		{
			q = p;//继续寻找，当前节点成为双亲结点
			p = p->ptr[i];//p指向继续查找的结点
		}
	}

	if (found)
	{//查找成功
		r.pt = p;//pt指向关键字k所指向的结点
		r.tag = 1;//查找成功
	}
	else
	{
		r.pt = q;//pt指向关键字k应插入的结点
		r.tag = 0;//查找失败
	}
	r.i = i;
	return r;
}

void Split(BTree q,BTree &ap)
{//将q分裂为两个结点,前一半将保留在*q,后一半移入新生结点*ap
	int i;
	ap = (BTree)malloc(sizeof(BTNode));//生成新的结点
	ap->ptr[0] = q->ptr[s];//将关键字大于q->key[s]的结点指针赋给ap->ptr[0]
	if (ap->ptr[0])
	{//存在关键字大于q->key[s]非空结点
		ap->ptr[0]->parent = ap;//修改该结点的双亲指针，使其指向ap
	}
	for (i = s + 1; i <= m; ++i)
	{//移动3个成员的到*ap
		ap->key[i - s] = q->key[i];//关键字
		ap->recptr[i - s] = q->recptr[i];//记录指针
		ap->ptr[i - s] = q->ptr[i];//结点指针
		if (ap->ptr[i - s])
		{//修改孩子的双亲
			ap->ptr[i - s]->parent = ap;
		}
	}
	ap->keynum = m - s;//ap关键字数
	q->keynum = s - 1;//更新q的关键字数
}

void Insert(BTree q,int i,Record *r, BTree ap)
{//将记录地址r和r->key分别赋给q->recptr[i + 1]和q->key[i + 1],q->ptr[i + 1]指向结点*ap
	int j;
	for (j = q->keynum;j > i;j--)
	{//由后向前，空出（*q）[i + 1]
		q->key[j + 1] = q->key[j];//3个成员均向后移
		q->recptr[j + 1] = q->recptr[j];
		q->ptr[j + 1] = q->ptr[j];
	}
	q->key[i+1] = r->key;
	q->recptr[i+1] = r;
	q->ptr[i + 1] = ap;
	if (ap)
	{
		ap->parent = q;
	}
	q->keynum++;
}

void NewRoot(BTree &T,Record *r,BTree ap)
{//生成含信息(T,r,ap)的新的根结点*T,原根结点T和ap为其子树指针
	BTree p = (BTree)malloc(sizeof(BTNode));//生成新的根结点
	p->parent = NULL;//根结点无双亲
	p->keynum = 1;//根结点的关键点个数为1
	p->key[1] = r->key;//
	p->recptr[1] = r;
	p->ptr[0] = T;
	p->ptr[1] = ap;
	if (T)
	{
		T->parent = p;
	}
	if (ap)
	{
		ap->parent = p;
	}
	T = p;
}

void InsertBTree(BTree &T,Record *r,BTree q, int i)
{//在B_树的q节点中插入
	BTree ap = NULL;
	Status finished = FALSE;//插入完成标志，初始为位完成
	while (q && !finished)
	{//q不空且为完成插入
		Insert(q,i,r,ap);
		if (q->keynum < m)
		{//关键字超出结点容量
			finished = TRUE;//插入完成
		}
		else
		{
			r = q->recptr[s];//分裂点的地址赋给r
			Split(q,ap);//分裂结点q
			q = q->parent;//当前节点为被分裂结点的双亲结点
			if (q)//被分裂结点的双亲结点存在
			{
				i = Search(q,r->key);//在被分裂结点的双亲结点*q中查找r->key的插入位置
			}
		}
	}
	if (!finished)
	{//T是空树
		NewRoot(T,r,ap);//生成新的根结点
	}
}
