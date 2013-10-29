#include "DSTable.h"
int main(void)
{
	BiTree dt,p;
	int i,n;
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
		k = InsertBST(dt,r);
		if (!k)
		{
			printf("二叉排序树中dt已存在关键字为%d的数据,故(%d,%d)无法插入到dt中。\n",r.key,r.key,r.others);
		}
	}
	fclose(f);
	printf("\n中序遍历二叉排序树dt:\n");
	TraverseDSTable(dt,Visit);
	printf("\n先序遍历二叉排序树dt:\n");
	PreOrderTraverse(dt,Visit);
	printf("\n请输入待查找的关键字的值:");
	InputKey(j);
	k = SearchBST(dt,j,NULL,p);
	if (k)
	{
		printf("dt中存在关键字为%d的结点。",j);
		DeleteBST(dt,j);
		printf("删除此结点后,中序遍历二叉排序树dt:\n");
		TraverseDSTable(dt,Visit);
		printf("\n先序遍历二叉排序树\n");
		PreOrderTraverse(dt,Visit);
		printf("\n");
	}
	else
	{
		printf("dt中不存在关键字为%d的结点\n",j);
	}
	DestroyDSTable(dt);
	return 0;
}