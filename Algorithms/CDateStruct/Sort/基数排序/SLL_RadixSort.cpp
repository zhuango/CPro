#include "SLL_RadixSort.h"
#include <string.h>

void Print2(SLList L)
{//按数组序号输出静态链表
	int i = 0;
	printf("keynum = %d recnum = %d i = %d next = %d\n",L.keynum,L.recnum,i,L.r[i].next);
	for(i = 1; i <= L.recnum;i ++)
	{
		printf("i = %d keys = %s otheritems = %d next = %d \n",i,L.r[i].keys,L.r[i].otheritems,L.r[i].next);
	}
}

void PrintLL(SLList L)
{//按链表顺序输出静态链表L
	int i = L.r[0].next;
	while (i)
	{
		printf("%s ",L.r[i].keys);
		i = L.r[i].next;
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

void MadeListFromFile(SqList &L,FILE *f)
{//通过文件f建立顺序表L
	int i;
	fscanf(f,"%d",&L.recnum);//根据数据文件输入表长为L.recnum
	for (i = 1; i <= L.recnum; ++i)
	{//依次输入结点的值，除next外
		fscanf(f,"%s%d",&L.r[i].keys,&L.r[i].otheritems);
	}
	L.keynum = strlen(L.r[1].keys);//关键字长度
}

int ord(char c)
{//返回关键字c的序号
	return c - '0';
}

void Distribute(SLCell r[],int i,ArrType f,ArrType e)
{//静态链表L的r域中记录已按(keys[i-1],..,key[0])有序，本算法按第i个关键字key[i](keys[0]是最低位关键字)建立RADIX个子表
//使同一个子表中记录的key[i]相同。f[0..RADIX - 1]和e[0..RADIX-1]分别指向个子表中第一个和最后一个记录
	int j,p;
	for (j = 0; j < RADIX; ++j)
	{//各子表初始化为空表
		f[j] = 0;
	}
	for (p = r[0].next;p;p = r[p].next)
	{//p按链式结构依次指向静态链表的记录
		j = ord(r[p].keys[i]);//当前记录的第i位关键字的序号，以下将当前记录按序号插入子表
		if (!f[j])
		{//子表f[j]空
			f[j] = p;//表头指向当前记录
		}
		else
		{//子表不空
			r[e[j]].next = p;//修改原子表[j]的表尾记录的next域指向当前记录
		}
		e[j] = p;//设置表尾指针指向p所指的表尾记录
	}

	//以下输出表头指针f[]和表尾指针e[]，可删除
	printf("\nf[j] = ");
	for (j = 0; j < RADIX; ++j)
	{
		printf("%3d",f[j]);
	}
	printf("\ne[j] = ");
	for (j = 0; j < RADIX; ++j)
	{
		if (f[j])
		{
			printf("%3d",e[j]);
		}
		else
		{
			printf("%3d",0);
		}
	}
	printf("\n");
}

int succ(int i)
{//求后继函数
	return ++i;
}

void Collect(SLCell r[],ArrType f,ArrType e)
{//本算法按keys[i]自小至大地将f[0..RADIX-1]所指各子表依次连接成一个链表，e[0..RADIX-1]为各子表的尾指针
	int j,t;
	for (j = 0;!f[j]; j = succ(j));
	//找到第1个非空子表[j],succ为求后继函数
	r[0].next = f[j];//r[0]指向第一个非空子表[j]的第一个元素
	t = e[j];//t指向第1个非空子表[j]的表尾元素
	while (j < RADIX - 1)
	{//未到最后一位关键字
		for (j = succ(j); j < RADIX - 1 && !f[j]; j = succ(j));//找下一个非空子表
		if (f[j])//子表不空
		{
			r[t].next = f[j];//连接两个非空子表
			t = e[j];//t指向新的表尾元素
		}
	}
	r[t].next = 0;//表尾
}

void RadixSort(SLList &L)
{//L是采用静态链表表示的顺序表。对L作基数排序，使L成为按关键字自小至大的有序静态链表,L,r[0]为头结点
	int i,j = 1;
	ArrType f,e;//表头表尾指针
	for (i = 0; i < L.recnum; ++i)
	{//将L改造为静态链表
		L.r[i].next = i + 1;
	}
	L.r[L.recnum].next = 0;
	for  (i = L.keynum - 1;i >= 0; --i,++j)//按最低位优先（LSD）依次对个关键字进行分配和收集，修改
	{
		Distribute(L.r,i,f,e);//第i趟分配
		printf("第%d趟分配后：\n",j);
		Print2(L); 
		Collect(L.r,f,e);
		printf("第%d趟收集后：\n",j);
		Print2(L); 
		PrintLL(L); 
	}
}