#include "BTree.h"

#define N 12//定义数据元素个数
int main(void)
{
	Record r[N]={{24,1},{45,2},{53,3},{12,4},{37,5},{50,6},{61,7},{90,8},
                {100,9},{70,10},{3,11},{37,12}}; 
	BTree t;
	Result u;
	KeyType j;
	int i;
	InitDSTable(t);
	for (i = 0; i < N; i++)
	{
		u = SearchBTree(t,r[i].key);
		if (u.tag)
		{
			printf("树中已存在关键字为%d的记录,故(%d,%d)无法插入。\n",r[i].key,r[i].key,r[i].others.order);
		}
		else
		{
			InsertBTree(t,&r[i],u.pt,u.i);
		}
	}
	printf("按关键词的顺序遍历B_树t:\n");
	TraverseDSTable(t,Visit);
	for (i = 1;i <= 4; ++i)
	{
		printf("\n请输入待查找记录的关键字：");
		InputKey(j);
		u = SearchBTree(t,j);
		if (u.tag)
		{
			Visit(*(u.pt),u.i);
		}
		else
		{
			printf("未找到！");
		}
	}
	printf("\n");
	DestroyDSTable(t);
	return 0;
}