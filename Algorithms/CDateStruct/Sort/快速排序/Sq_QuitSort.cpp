/*****************Sq_QuitSort.cpp*****************/
#include "Sq_QuitSort.h"
#include <stdio.h>
typedef int Status;//状态类型
#define TRUE 1
#define FALSE 0
void PrintL(SqList &L)
{//输出顺序表L
	int i;
	for (i = 1; i <= L.length; ++i)
	{
		printf("(%d,%d) ",L.r[i].key,L.r[i].otherinfo);
	}
	printf("\n");
}

int Parition1(SqList &L,int low,int high)
{//交换顺序表L中子表L.r[low...high]的记录，使枢轴记录到位
//函数返回交换后枢轴的位置，其前的记录小于枢轴关键字，其后则大于
	KeyType pivotkey;//枢轴关键字
	pivotkey = L.r[low].key;//用子表的第一个关键字作枢轴的关键字
	while (low < high)
	{//从表的两端交替地向中间扫描
		while (low < high && L.r[high].key >= pivotkey)
		{//高端关键字大于等于枢轴关键字
			--high;//高端向低移，继续比较
		}
		L.r[0]	= L.r[low];//将比枢轴小的关键词记录交换到低端，枢轴到高端
		L.r[low] = L.r[high];
		L.r[high] = L.r[0];
		while (low < high && L.r[low].key <= pivotkey)
		{//低端关键词小于等于枢轴关键字
			++low;//低端向高移，继续比较
		}
		L.r[0]	= L.r[low];//将比枢轴大的关键词记录交换到高端，枢轴到低端
		L.r[low] = L.r[high];
		L.r[high] = L.r[0];
	}
	return low;//返回枢轴位置
}

int Parition2(SqList &L,int low,int high)
{//【改进算法1】交换顺序表L中子表L.r[low...high]的记录，使枢轴记录到位
//函数返回交换后枢轴的位置，其前的记录小于枢轴关键字，其后则大于
	KeyType pivotkey;//枢轴关键字
	pivotkey = L.r[low].key;//用子表的第一个关键字作枢轴的关键字
	L.r[0] = L.r[low];//将枢轴记录保存到[0]，改进处
	while (low < high)
	{//从表的两端交替地向中间扫描
		while (low < high && L.r[high].key >= pivotkey)
		{//高端关键字大于等于枢轴关键字
			--high;//高端向低移，继续比较
		}
		L.r[low] = L.r[high];//将比枢轴关键字小的记录移动到低端，枢轴在[0]处不动，改进处
		while (low < high && L.r[low].key <= pivotkey)
		{//低端关键词小于等于枢轴关键字
			++low;//低端向高移，继续比较
		}
		L.r[high] = L.r[low];//将比枢轴关键字大的记录移动到高端，枢轴在[0]处不动，改进处
	}
	L.r[low] = L.r[0];//将枢轴记录移动到位，改进处
	return low;//返回枢轴位置
}

void SwapMid(SqList &L,int low,int high)
{//将顺序表L中记录L.r[low],L.r[(low + high)/2],L.r[high]的关键字为中值的记录和第一个记录L.r[low]互换
	int i,j,mid,m = (low + high)/2;
	SqList t;//存储以上三个记录的临时顺序表，用来对三个记录排序以便找出中值
	t.length = 3;
	t.r[1] = L.r[low];
	t.r[2] = L.r[m];
	t.r[3] = L.r[high];
	Status change = TRUE;//调整的标志,初值为TRUE
	for (i = t.length - 1; i >= 1 && change; --i)
	{
		change = FALSE;//本次循环未调整的标志
		for (j = 1; j <= t.length - 1; ++j)
		{
			if (LT(t.r[j + 1].key,t.r[j].key))//前面记录的关键字大于后面记录的关键字
			{//两记录互换
				t.r[0] = t.r[j];
				t.r[j] = t.r[j + 1];
				t.r[j + 1] = t.r[0];
				change = TRUE;//已调整的标志
			}
		}
	}

	if (EQ(t.r[2].key,L.r[high].key))
	{//中值为L.r[high].key
		mid = high;
	}
	else if (EQ(t.r[2].key,L.r[m].key))
	{//中值为L.r[m].key
		mid = m;
	}
	else
	{//中值为L.r[low].key
		mid = low;
	}
	if (mid != low)
	{//中值记录和第一个记录互换
		L.r[0] = L.r[mid];
		L.r[mid] = L.r[low];
		L.r[low] = L.r[0];
	}
}
int Parition3(SqList &L,int low,int high)
{//【改进算法2】交换顺序表L中子表L.r[low...high]的记录，使枢轴记录到位
//函数返回交换后枢轴的位置，其前的记录小于枢轴关键字，其后则大于
	KeyType pivotkey;//枢轴关键字
	SwapMid(L,low,high);//记录L.r[low],L.r[(low + high)/2],L.r[high]的关键字为中值的记录和L.r[low]互换,改进处
	pivotkey = L.r[low].key;//用子表的第一个关键字作枢轴的关键字
	L.r[0] = L.r[low];//将枢轴记录保存到[0]
	while (low < high)
	{//从表的两端交替地向中间扫描
		while (low < high && L.r[high].key >= pivotkey)
		{//高端关键字大于等于枢轴关键字
			--high;//高端向低移，继续比较
		}
		L.r[low] = L.r[high];//将比枢轴关键字小的记录移动到低端，枢轴在[0]处不动
		while (low < high && L.r[low].key <= pivotkey)
		{//低端关键词小于等于枢轴关键字
			++low;//低端向高移，继续比较
		}
		L.r[high] = L.r[low];//将比枢轴关键字大的记录移动到高端，枢轴在[0]处不动
	}
	L.r[low] = L.r[0];//将枢轴记录移动到位
	return low;//返回枢轴位置
}
int Parition4(SqList &L,int low,int high)
{//【改进算法2】交换顺序表L中子表L.r[low...high]的记录，使枢轴记录到位
//函数返回交换后枢轴的位置，其前的记录小于枢轴关键字，其后则大于
	KeyType pivotkey;//枢轴关键字
	RedType t;
	SwapMid(L,low,high);//记录L.r[low],L.r[(low + high)/2],L.r[high]的关键字为中值的记录和L.r[low]互换
	pivotkey = L.r[low].key;//用子表的第一个关键字作枢轴的关键字
	L.r[0] = L.r[low];//将枢轴记录保存到[0]
	while (low < high)
	{//从表的两端交替地向中间扫描
		while (low < high && L.r[high].key >= pivotkey)
		{//高端关键字大于等于枢轴关键字
			if (LT(L.r[high].key,L.r[high - 1].key))
			{//在相邻两记录处于“逆序时”进行互换，改进处
				t = L.r[high];
				L.r[high] = L.r[high - 1];
				L.r[high - 1] = t;
			}
			--high;
		}
		L.r[low] = L.r[high];//将比枢轴关键字小的记录移动到低端，枢轴在[0]处不动
		while (low < high && L.r[low].key <= pivotkey)
		{//低端关键词小于等于枢轴关键字
			if (LT(L.r[low + 1].key,L.r[low].key))
			{//在相邻两记录处于“逆序时”进行互换，改进处
				t = L.r[low];
				L.r[low] = L.r[low + 1];
				L.r[low + 1] = t;
			}
			++low;//低端向高移，继续比较
		}
		L.r[high] = L.r[low];//将比枢轴关键字大的记录移动到高端，枢轴在[0]处不动
	}
	L.r[low] = L.r[0];//将枢轴记录移动到位
	return low;//返回枢轴位置
}

void Qsort(SqList &L,int low ,int high)
{//对顺序表L中的子序列L.r[low..high]作快速排序
	static int c = 1;//统计趟数
	int pivotloc;//枢轴位置
	if (low < high)
	{//子序列长度大于1
		pivotloc = Parition4(L,low,high);//将L.r[low..high]按关键字一分为二，pivotlc是枢轴位置
		printf("第%d趟排序后 顺序表L:\n",c++);
		PrintL(L);
		Qsort(L,low,pivotloc - 1);//对关键字小于枢轴关键字的低子表递归快速排序
		Qsort(L,pivotloc + 1,high);//对关键字大于枢轴关键字的高子表递归快速排序
	}
}

void QuikSort(SqList &L)
{//对整个顺序表L作快速排序
	Qsort(L,1,L.length);
}
//


