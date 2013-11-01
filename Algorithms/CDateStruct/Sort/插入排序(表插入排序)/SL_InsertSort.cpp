#include "SL_InsertSort.h"

#include <stdio.h>
#include <stdlib.h>
void PrintL(SLinkListType L)
{//按顺序结构输出静态链表
	int i;
	for (i = 1;i <= L.length; ++i)
	{
		printf("i = %d key = %d ord = %d next = %d\n",i,L.r[i].rc.key,
			    L.r[i].rc.otherinfo,L.r[i].next);
	}
}

void CreatTableFromFile(SLinkListType &SL,FILE*f)
{//由数据文件f建立为排序的顺序表SL(next域不起作用)
	int i;
	fscanf(f,"%d",&SL.length);//由文件输入表长
	for (i = 1; i <= SL.length; ++i)
	{
		InputFromFile(f,SL.r[i].rc);//依次由文件输入记录到SL.r[i].rc
	}
}

void MakeTableSorted(SLinkListType &SL)
{//使无序的顺序表SL成为有序的静态循环链表
	int i,p,q;
	SL.r[0].rc.key = INT_MAX;//表头结点记录的关键字取最大整数（非降序循环链表的表尾）
	SL.r[0].next = 0;//next域为0形成空循环链表，初始化
	for (i = 1; i <= SL.length; ++i)
	{
		q = 0;//q指向静态链表的表头元素
		p = SL.r[0].next;//p指向静态链表的第1个元素
		while (SL.r[p].rc.key <= SL.r[i].rc.key)
		{//p所指记录的关键字不大于待插入记录的关键字（上行的“=”使排序方法是稳定的）
			q = p;//q指向所指元素
			p = SL.r[p].next;//p指向下一个元素
		}
		SL.r[q].next = i;//将当前记录插到静态链表中（q前p后）
		SL.r[i].next = p;//当前记录的下一个记录序号
	}
}

void Arrange(SLinkListType &SL)
{//根据静态链表SL中个结点的指针值调整记录位置，使得SL成为非递减有序的顺序表
	int i,p,q;
	SLNode t;
	p = SL.r[0].next;//p指示第一个记录的当前位置
	for (i = 1; i < SL.length; ++i)
	{//SL.r[1..i-1]中记录议案关键字有序排列，第i个记录在SL中的当前位置应不小于i
		while (p<i)//p所指的记录已排好
		{
			p = SL.r[p].next;//继续向后找，跳出已排序好的部分
		}
		q = SL.r[p].next;//q指示尚未调整的表尾部分
		if (p != i)//第i个记录不在p所指的位置，需移动
		{
			t = SL.r[p];
			SL.r[p] = SL.r[i];
			SL.r[i] = t;
			SL.r[i].next = p;//指向被移走的记录，[i]已排好序，使得以后可由while循环找回p所指记录
		}
		p = q;//指示尚未调整的表尾部分，为找第i+1个记录作准备
	}
}

void Sort(SqList L,int adr[])
{//求得adr[1..L.length],adr[i]为静态链表L的第i个最小记录的序号
	int i = 1, p = L.r[0].next;//p指向第一个记录
	while (p)
	{//未到表尾
		adr[i++] = p;//将p赋值给adr[i],i+1
		p = L.r[p].next;//p指向下一个记录
	}
}

void Rearrange(SqList &L,int adr[])
{//adr给出给出静态链表L的有序次序，即L.r[adr[i]]是第i小记录
	int i,j,k;
	for (i = 1; i <= L.length; ++i)
	{
		if (adr[i] != i)
		{
			j = i;
			L.r[0] = L.r[i];//暂存记录[i]到[0](空出[i]或[j]来)
			while (adr[j]!=i)//记录不在正确的位置
			{//调整L.r[adr[j]]的记录到位，知道adr[j] = i为止;
				k = adr[j];
				L.r[j] = L.r[k];//将[j]中应放的记录移来（因[j]空）
				adr[j] = j;//记录处于正确位置的标志
				j = k;//新空出的位置赋值给j，以便继续循环使用
			}
			L.r[j] = L.r[0];//循环调整完毕，将暂存在[0]中的记录赋值给L.r[j]
			adr[j] = j;
		}
	}
}