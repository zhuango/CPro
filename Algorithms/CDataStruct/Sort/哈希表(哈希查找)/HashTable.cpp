/***************************HashTable.cpp***************************/
#include <stdio.h>//NULL等
#include <stdlib.h>//exit()、 rand()
#include <malloc.h>//malloc
#include <math.h>//OVERFLOW、pow()
#include "HashTable.h"

static int m;//内部链接静态变量，m为哈希表表长

void InitHashTable(HashTable &H)
{//初始化哈希表，构造一个记录为空的哈希表
	int i;
	H.sizeindex = 0;//初始化表长数组索引为0
	m = hashsize[H.sizeindex];//初始化表长为hashsize[0]
	H.count = 0;//初始化记录数为0
	H.elem = (ElemType *)malloc(m * sizeof(ElemType));//动态分配记录数组
	if (!H.elem)
	{//分配失败
		exit(OVERFLOW);
	}
	for (i = 0; i < m; ++i)
	{//初始化记录数组关键字为空
		H.elem[i].key = NULL_KEY;//未填记录的标志
	}
}

void DestroyHashTable(HashTable &H)
{//销毁哈希表
	free(H.elem);//释放动态记录数组
	H.elem = NULL;//指针置为空
	H.count = 0;//记录数置为为0
	H.sizeindex = 0;//表长索引项置为0
}

unsigned Hash(KeyType k)
{//返回哈希函数求得的哈希地址（用除留余数法构造的一个简单的哈希函数）
	return k % m;// H(key) = key MOD p (p ≤ m),取p=m
}

int d(int i)
{//增量序列函数，其中i为冲突次数。根据需要在3种方法选取一种，其他两种注释掉
	return i;//线性探索再散列：di = 1,2,3,...,m-1
//	return ((i + 1)/2) * ((i + 1)/2) * (int)pow(double(-1),i - 1);//二次探索再散列：di = 1,-1^2,2,-2^2,...,±k^2(k <= m - 1)
//	return rand();//伪随机探索再散列：di = 伪随机数序列
}

void collision(KeyType &k,int &p,int i)
{//用开放定址法处理冲突,其中p为处理后所得的哈希地址,i为冲突次数。
	p = (Hash(k) + d(i)) % m;
}

Status SearchHash(HashTable H,KeyType k,int &p,int &c)
{//在开放地址哈希表中查找关键字为K的记录，若查找成功，以p指示记录在表中的位置，并返回SUCCESS；
 //否则以p指示插入位置，并返回UNSUCCESS。c以计冲突次数，其初值为0,供建表插入时参考
	p = Hash(k);//用哈希函数计算哈希地址
	while (H.elem[p].key != NULL_KEY && !EQ(H.elem[p].key,k))
	{//该位置中填有记录，并且与待查记录不相等
		c++;
		if (c < m)
		{//处理冲突次数未超出m - 1，则继续处理冲突
			collision(k,p,c);
		}
		else
		{//超出最大处理次数，H中位找到记录
			break;
		}
	}
	if (EQ(H.elem[p].key,k))
	{//查找成功
		return SUCCESS;
	}
	else
	{//查找失败
		return UNSUCCESS;
	}
}

void RecreateHashTable(HashTable &);//对函数RecreateHashTable()的声明

Status InsertHash(HashTable &H,ElemType e)
{
	int p,c = 0;//冲突次数初始为0
	if (SearchHash(H,e.key,p,c))
	{//查找成功
		return DUPLICATE;//H中已有与e有相同关键字的记录,不插入
	}
	else if (c < hashsize[H.sizeindex]/2)
	{//未找到，冲突次数c也未达到上限（c的阀值可调,但最大不超过hashsize[H.sizeindex] - 1）
		H.elem[p] = e;//在H中插入数据元素e
		++H.count;
		return SUCCESS;//插入成功
	}
	else
	{//未找到，但冲突次数c已达到上限
		RecreateHashTable(H);//重建哈希表
		return UNSUCCESS;//插入不成功
	}
}

void RecreateHashTable(HashTable &H)
{
	int i,count = H.count;//H中原有记录个数
	ElemType *p,*elem = (ElemType *)malloc(count *sizeof(ElemType));//动态生成存放哈希表H原有数据的空间
	p =elem;
	for (i = 0; i < m; ++i)
	{//将原有的所有记录，保存到elem中
		if (!EQ(H.elem[i].key,NULL_KEY))
		{//H在该单元有记录
			*p++ = H.elem[i];//将记录依次存入elem
		}
	}
	H.count = 0;//将原有记录数置为0，为下面调用InserHash做准备
	H.sizeindex++;//表长数组索引加1
	m = hashsize[H.sizeindex];//新的存储容量（表长）
	H.elem = (ElemType *)realloc(H.elem,m*sizeof(ElemType));//以新的存储容量重新生成空哈希表H
	for (i = 0; i < m; ++i)
	{//初始化新的哈希表
		H.elem[i].key = NULL_KEY;//未填记录
	}
	for (p = elem; p < elem + count; ++p)
	{//将原表中的记录重新存储到新的哈希表中
		InsertHash(H,*p);
	}
	free(elem);//释放elem的存储空间
}

void TraverseHash(HashTable H,void (*Visit)(int,ElemType))
{//按哈希地址的顺序遍历哈希表H
	int i;
	printf("哈希地址 0 ~ %d\n",m - 1);
	for (i = 0; i < m; ++i)
	{//对于整个哈希表H
		if (!EQ(H.elem[i].key,NULL_KEY))
		{//H在第i个单元有记录
			Visit(i,H.elem[i]);//访问第i个数据
		}
	}
}

