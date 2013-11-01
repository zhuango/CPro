#include <stdio.h>
#include "SString.h"
typedef char AtomType;
enum ElemTag{ATM,LIST};//ATOM == 0:原子，LIST == 1：子表
typedef struct GLNode
{
	ElemTag tag;//公共部分，用于区分原子节点和表结点
	union//共用体类型
	{
		AtomType atom;//atom是原子结点的值域，AtomType由用户定义
		struct
		{
			GLNode *hp;
			GLNode *tp;
		}ptr;//ptr是表结点的指针域，prt.hp和prt.tp分别指向表头和表尾（广义表中表头之外的其余元素）
	};
} *GList,GLNode;//广义表类型

void Divide(SString str,SString hstr); 

void InitGList(GList &L);

void CreateGList(GList &L,SString S);

void DestroyGList(GList &L);

void CopyGList(GList &T,GList L);

int GListLength(GList L);
;
int GListDepth(GList L);

Status GListEmpty(GList L);

GList GetHead(GList L);

GList GetTail(GList L);

void InsertFirst_GL(GList &L,GList e);

void DeleteFirst_GL(GList &L,GList &e);

void Traverse_GL(GList L,void (*visit)(AtomType));
