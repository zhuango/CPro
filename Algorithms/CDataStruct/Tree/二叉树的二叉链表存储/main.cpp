#include <stdio.h>
#define ET 1//只要每个源文件包含或其头文件包含QElemType.h都必须定义ET
#include "BiTree.h"
#include "LinkQueue.h"

void visit(TElemType e)
{
	printf(form" ", e);
}

int main()
{
	BiTree T;
	InitBiTree(T);
	CreatBiTree(T); 
	PreOrderTraverse(T, visit);
	printf("\n");
    InOrderTraverse(T, visit);
	printf("\n");
	InOrderTraverse1(T, visit);
	printf("\n");
	printf("%d\n",BiTreeDepth(T));
	printf("%c\n",Root(T));
	printf("%c\n",Parent(T,'e'));
	printf("%c\n",LeftChild(T,'b'));
	printf("%c\n",RightChild(T,'b'));
	printf("%c\n",LeftSibling(T,'e'));
	printf("%c\n",RightSibling(T,'d'));

	BiTree C;
	InitBiTree(C);
	CreatBiTree(C); 

	InsertChild(Point(T,'b'),1,C);
	InOrderTraverse1(T, visit);

	return 0;
}