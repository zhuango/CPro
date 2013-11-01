#include "TrieTree.h"
#define N 20//数组可
int main(void)
{
	TrieTree t;
	int i,j=0; 
	KeyType k;
	Record *p,r[N]; 
	FILE *f; 
	InitDSTable(t); 
	f=fopen("1.txt","r"); 
	do 
	{ i=fscanf(f,"%s%d",&r[j].key.ch,&r[j].others.order); 
	if(i!=-1) 
	{ r[j].key.num=strlen(r[j].key.ch); 
	p=SearchTrie(t,r[j].key); 
	if(!p) 
		InsertTrie(t,&r[j++]);

	else 
		printf("树t中已存在关键字为%s的记录，故(%s,%d)无法插入。\n",
		r[j].key.ch,r[j].key.ch,r[j].others.order);
	}
	}while(!feof(f)&&j<N); 
	fclose(f); 
	printf("按关键字符串的顺序遍历树t：\n");
	TraverseDSTable(t,Visit); 
	printf("\n请输入待查找记录的关键字符串：");
	InputKey(k.ch); 
	k.num=strlen(k.ch); 
	p=SearchTrie(t,k); 
	if(p) 
		Visit(p); 
	else 
		printf("未找到"); 
	printf("\n");
	DestroyDSTable(t); 
	return 0;
}