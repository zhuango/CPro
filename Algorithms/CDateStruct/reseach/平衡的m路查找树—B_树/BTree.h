#ifndef BTREE_H
#define BTREE_H

#include "Status.h"
#define m 3//设B_树的阶为3
const int s = (m + 1)/2;//s为分裂结点的中值
#include "Record.h"
typedef struct BTNode
{//B_树结点类型
	int keynum;//结点中的关键字数
	BTNode *parent;//指向双亲结点
	KeyType key[m + 1];//关键字向量，0号单元未用
	Record *recptr[m + 1];//记录指针向量，0号单元未用
	BTNode *ptr[m + 1];//子树指针向量,0好单元指向比key[1]小的关键字所在结点
}BTNode,*BTree;//B_树结点类型和B_树的类型

typedef struct Result
{//查找结果类型
	BTree pt;//指向关键字所在结点
	int i;//关键词所在序号
	int tag;//特征值 1：查找成功 0：查找失败
}Result;

void Visit(BTNode c,int i);

void InputKey(KeyType &k);

void InitDSTable(BTree &DT);

void DestroyDSTable(BTree &DT);

void TraverseDSTable(BTree &DT,void (*Visit)(BTNode,int));

int Search(BTNode *p,KeyType k);

Result SearchBTree(BTree T,KeyType k);

void Split(BTree q,BTree &ap);

void Insert(BTree q,int i,Record *r, BTree ap);

void NewRoot(BTree &T,Record *r,BTree ap);

void InsertBTree(BTree &T,Record *r,BTree q, int i);

#endif