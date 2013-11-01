#include "SSTable.h"

int main(void)
{
	SSTable st;
	SOSTree t;
	KeyType s;
	Status i;
	Creat_OrderFromFile(st,"1.txt");
	Traverse(st);
	CreateSOSTree(t,st);
	printf("请输入待查找的字符");
	InputKey(s);
	i = Search_SOSTree(t,s);
	if (i)
	{
		printf("%c的权值是%.2lf\n",s,t->date.weight);
	}
	else
	{
		printf("表中不存在此字符!\n");
	}
	Destroy(st);//销毁静态查找表
	return 0;
}