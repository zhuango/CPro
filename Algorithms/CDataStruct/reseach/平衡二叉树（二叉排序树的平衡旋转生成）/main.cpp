#include "DSTable.h"
int main(void)
{
	BiTree dt,p;
	int i,n;
	Boolean flag;
	KeyType j;
	DElemType r;
	Status k;
	FILE *f;
	f = fopen("1.txt","r");
	fscanf(f,"%d",&n);
	InitDSTable(dt);
	for (i = 0; i < n; ++i)
	{
		InputFromFile(f,r);
		k = InsertAVL(dt,r,flag);//采用平衡二叉树（属于二叉查找树）构建动态查找表
//		k = InsertBST(dt,r);//采用二叉查找树构建动态查找表
		if (k) 
		{
			printf("插入关键字为%d的记录后，按关键字顺序（中序）遍历平衡二叉树dt:\n",r.key);
			TraverseDSTable(dt,Visit);
			printf("\n先序遍历平衡二叉树dt:\n");
			PreOrderTraverse(dt,Visit);
			printf("\n");
		}
		else
		{
			printf("二叉排序树中dt已存在关键字为%d的数据,故(%d,%d)无法插入到dt中。\n",r.key,r.key,r.others);
		}
	}
	fclose(f);
	printf("\n请输入待查找的关键字的值:");
	InputKey(j);
	k = SearchBST(dt,j,NULL,p);
	if (k)
	{
		printf("dt中存在关键字为%d的结点。\n",j);
	}
	else
	{
		printf("dt中不存在关键字为%d的结点\n",j);
	}
	DestroyDSTable(dt);
	return 0;
}