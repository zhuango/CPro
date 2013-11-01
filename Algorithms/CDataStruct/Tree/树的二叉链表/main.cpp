#define ET 1
#include "CSTree.h"

void visit(TElemType e)
{
	printf(form" ",e);
}

int main()
{ 
	int i;
	CSTree T,p,q;
	TElemType e,e1;
	InitTree(T);
	printf("构造空树后，树空否？%d(1:是 0:否)。树根为%c,树的深度为%d。\n",TreeEmpty(T),Root(T),TreeDepth(T));
	CreateTree(T);
	printf("构造树T后，树空否？%d(1:是 0:否)。树根为%c,树的深度为%d。\n",TreeEmpty(T),Root(T),TreeDepth(T));
	printf("层序遍历数T:\n");
	LevelOrderTraverse(T,visit);
	printf("请输入待修改的结点的值和新值：");
	scanf("%c%*c%c%*c",&e,&e1);
	Assign(T,e,e1);
	printf("层序遍历修改后的树：\n");
	LevelOrderTraverse(T,visit);
	printf("\n");	
	printf("%c的双亲是%c,长子是%c，下一个兄弟是%c。\n",e1,Parent(T,e1),LeftChild(T,e1),RightSibling(T,e1));
	printf("建立树P：\n");
	CreateTree(p);
	printf("层序遍历树p:");
	LevelOrderTraverse(p,visit);
	printf("\n");
	printf("将树p插到T中，请输入T中的双亲的结点和子树序号：");
	scanf("%c%d%*c",&e,&i);
	q = Point(T,e);
	InsertChild(T,q,i,p);
	printf("层序遍历修改后的树T:");
	LevelOrderTraverse(T,visit);
	printf("\n");
	printf("先根遍历树T:");
	PreOrderTraverse(T,visit);
	printf("\n");
	printf("后根遍历树T:");
	PostOrderTraverse(T,visit);
	printf("\n");
	printf("删除树T中结点e的第i棵子树，输入e i:");
	scanf("%c%d",&e,&i);
	q = Point(T,e);
	DeleteChild(T,q,i);
	printf("层序遍历修改后的树T:\n");
	LevelOrderTraverse(T,visit);
	printf("\n");
	DestroyTree(T);
	return 0;
}