/***************************main.cpp***************************/
#include <stdio.h>
#include "HashTable.h"

#define N 15//数组可容纳的记录个数
int main(void)
{
	ElemType r[N];//记录数组
	HashTable h;
	int i,n = 0,p = 0;
	Status s;
	KeyType k;
	FILE *f;//文件指针类型
	f = fopen("Records.txt","r");//打开记录文件Record.txt
	do
	{
		i = fscanf(f,"%d%d",&r[p].key,&r[p].order);//先将记录暂存入记录数组r[p]
		if (i != -1)
		{//输入数据成功
			p++;
		}
	} while (!feof(f) && p < N);//未到达数据文件结尾且记录数组未满
	fclose(f);//关闭数据文件
	InitHashTable(h);
	for (i = 0; i < p - 1; ++i)
	{//在h中插入前p-1个记录(最后一个记录不插入,插入最后一个记录会重建哈希表)
		s = InsertHash(h,r[i]);
		if (DUPLICATE == s)
		{
			printf("表中已有关键字为%d的记录，无法再插入记录（%d,%d）\n",r[i].key,r[i].key,r[i].order);
		}
	}
	printf("按哈希地址的顺序遍历哈希表:\n");
	TraverseHash(h,Visit);
	printf("请输入待查找记录的关键字：");
	scanf("%d",&k);
	s = SearchHash(h,k,p,n);
	if (SUCCESS == s)
	{//查找成功
		Visit(p,h.elem[p]);//输出该记录
	}
	else
	{//查找失败
		printf("未找到\n");
	}
	s = InsertHash(h,r[i]);//插入最后一个记录（需重建哈希表）
	if (UNSUCCESS == s)
	{//插入不成功
		s = InsertHash(h,r[i]);//重建哈希表后重新插入
	}
	printf("按哈希表地址的顺序遍历重建后的哈希表:\n");
	TraverseHash(h,Visit);

	printf("请输入待查找记录的关键字：");
	scanf("%d",&k);
	s = SearchHash(h,k,p,n);
	if (SUCCESS == s)
	{//查找成功
		Visit(p,h.elem[p]);//输出该记录
	}
	else
	{//查找失败
		printf("未找到\n");
	}
	DestroyHashTable(h);
	return 0;
}


/*******************************运行结果*******************************/
/*

表中已有关键字为60的记录，无法再插入记录（60,9）
按哈希地址的顺序遍历哈希表:
哈希地址 0 ~ 10
address = 1(1,5)
address = 2(2,6)
address = 3(3,7)
address = 4(4,8)
address = 5(60,2)
address = 6(17,1)
address = 7(29,3)
address = 8(38,4)
请输入待查找记录的关键字：13
未找到
按哈希表地址的顺序遍历重建后的哈希表:
哈希地址 0 ~ 18
address = 0(38,4)
address = 1(1,5)
address = 2(2,6)
address = 3(3,7)
address = 4(4,8)
address = 5(60,2)
address = 10(29,3)
address = 13(13,10)
address = 17(17,1)
请输入待查找记录的关键字：13
address = 13(13,10)
请按任意键继续. . .

*/

