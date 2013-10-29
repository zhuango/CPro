#include "SSTable.h"
#include <math.h>
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
			if (LT(ST.elem[j].key,ST.elem[k].key))
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

void FindSW(double sw[],SSTable ST)
{//按照有序表ST中记录的权值求累计权值数组sw,CreateSOSTree()调用
	int i;
	sw[0] = 0;//置为0
	printf("\nsw = 0");
	for (i = 1; i <= ST.length; ++i)
	{//按序由小到大累加权值
		sw[i] = sw[i - 1] + ST.elem[i].weight;
		printf("%-6.2f",sw[i]);
	}
	printf("\n");
}

Status SecondOptimal(BiTree &T,SElemType R[],double sw[],int low,int high)
{
	int j,i = low;//i是△Pi为最小值时的序号，初值设为当low == high (有序表仅一个元素)时的值
	double dw = sw[high] + sw[low - 1];//△Pi = |sw[high] + sw[low - 1] - sw[j] - sw[j -1]|,若当j = i时△Pi取得最小值,求i的值。
	double min = fabs(sw[high] - sw[low]);//△Pi的最小值,初值设为当low == high 时的值
	for (j = low + 1; j <= high; ++j)
	{
		if (fabs(dw - sw[j] - sw[j - 1]) < min)
		{
			min = fabs(dw - sw[j] - sw[j - 1]);//更新最小值
			i = j;//更新最小值序号
		}
	}
	if (!(T = (BiTree)malloc(sizeof(BiTNode))))
	{//生成结点失败
		exit (OVERFLOW);
	}
	T ->date = R[i];//将有最小△Pi值的记录元素赋给结点的数据域
	if (i == low)//有最小△Pi值的序号是最小序号
	{
		T->lchild = NULL;//设左子树空
	}
	else
	{
		SecondOptimal(T->lchild,R,sw,low,i - 1);//递归构造次优查找左子树
	}
	if (i == high)//有最小△Pi值的序号是最大序号
	{
		T->rchild = NULL;//设右子树空
	}
	else
	{
		SecondOptimal(T->rchild,R,sw,i + 1,high);//递归构造次优查找右子树
	}
}

void CreateSOSTree(SOSTree &T,SSTable ST)
{//由有序表ST构造一棵次优查找树T
	double sw[N + 1];
	if (ST.length == 0)
	{
		T = NULL;
	}
	else
	{
		FindSW(sw,ST);
		SecondOptimal(T,ST.elem,sw,1,ST.length);
	}
}

Status Search_SOSTree(SOSTree &T,KeyType key)
{//在次优查找树T中查找主关键字等于key的元素,找到则返回OK,T指向该元素;否则返回FALSE
	while (T)
	{
		if (EQ(key,T->date.key))
		{
			return OK;
		}
		else if (LT(key,T->date.key))
		{
			T = T->lchild;
		}
		else
		{
			T = T->rchild;
		}
	}
	return FALSE;
}

