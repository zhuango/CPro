#ifndef DLTREE_H
#define DLTREE_H

#include "Status.h"
#include "Record.h"

enum NodeKind{LEAF,BRANCH};//结点种类：{叶子，分支}
#define Nil '&' //定义结束符类型为$
typedef struct DLTNode
{//双链键树结点类型的存储结构
	char symbol;//关键字字符
	NodeKind kind;//结点的类型
	DLTNode *next;//指向兄弟结点的指针
	union
	{//共用体类型
		DLTNode *first;//对于分支结点，有指向其长子的指针
		Record *infoptr;//对于叶子结点，有指向记录的指针
	};
}DLTNode,*DLTree;//定义双链树的头指针

void Visit(Record *r);

void InputKey(char *k);

void InitDSTable(DLTree &DT);

 void DestroyDSTable(DLTree &DT);

 Record* SearchDLTree(DLTree T,KeyType K);

 Status InsertDSTable(DLTree &DT,Record* r);

 void TraverseDSTable(DLTree p,void(*Visit)(Record*));

#endif