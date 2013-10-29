#include "SSTable.h"

void Creat_SeqFromFile(SSTable &ST,char *filename)//由数据文件构造静态顺序查找表
{//建立顺序表
	int i;
	FILE *f;
	f = fopen(filename,"r");//打开文件
	fscanf(f,"%d",&ST.length);//从文件中输入表的长度
	ST.elem = (SElemType*)malloc((ST.length + 1) * sizeof(SElemType));//动态分配长度为ST.length + 1的记录存储空间，0号单元不用
	if (!ST.elem)
	{//分配失败
		exit(OVERFLOW);
	}
	for (i = 1; i <= ST.length; ++i)
	{//从文件输入所有记录
		InputFromFile(f,ST.elem[i]);
	}
	fclose(f);//关闭文件
}

void Ascend(SSTable &ST)
{//按关键字升序排列表中的记录（此处用选择排序法完成）
	int i,j,k;//k存当前关键字最小值的序号
	for (i = 1; i < ST.length; ++i)
	{
		k = i;
		for (j = i + 1; j <= ST.length; ++j)
		{
			if (LT(ST.elem[j].number,ST.elem[k].number))
			{//有比[k]更小的值则将序号赋给k
				k = j;
			}
		}
		if (k != i)
		{//有比[i]更小的值则交换 此处0号单元用于辅助交换
			ST.elem[0] = ST.elem[i];
			ST.elem[i] = ST.elem[k];
			ST.elem[k] = ST.elem[0];
		}
	}
}

void Creat_OrderFromFile(SSTable & ST,char *filename)
{//按升序建立有序表
	Creat_SeqFromFile(ST,filename);
	Ascend(ST);
}

Status Destroy(SSTable &ST)
{//销毁静态查找表
	free(ST.elem);
	ST.elem = NULL;
	ST.length = 0;
	return OK;
}

int Search_Seq(SSTable ST,KeyType key)
{//在顺序表ST中顺序查找其关键词等于key的记录
	int i;
	ST.elem[0].key = key;//0好单元存放关键字，当做“哨兵”
	for (i = ST.length; !EQ(ST.elem[i].key,ST.elem[0].key); --i)
	{//从后往前找
		;
	}
	return i;
}

int Search_Bin(SSTable ST,KeyType key)
{//在有序表ST中折半查找其关键词等于key的记录
	int mid, low = 1, high = ST.length;//置区间初值，低值为1，高值为length
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (EQ(key,ST.elem[mid].key))
		{//中值为key,则返回中值
			return mid;
		}
		else if (LT(key,ST.elem[mid].key))
		{//key小于[mid],则key在[low,mid)区间上,高值更新为mid - 1
			high = mid - 1;
		}
		else
		{//key大于[mid],则key在(mid,high]区间上,低值更新为mid + 1
			low = mid + 1;
		}
	}
	return 0;
}

void Traverse(SSTable ST)
{
	int i;
	if (ST.length > 0)
	{
		for (i = 1; i <= ST.length; ++i)
		{
			visit(ST.elem[i]);
		}
	}
}