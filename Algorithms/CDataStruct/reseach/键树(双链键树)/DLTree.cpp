#include "DLTree.h"

void Visit(Record *r)
{//访问结点上关键字的记录
	printf("(%s,%d)",r->key.ch,r->others.order);
}

void InputKey(char *k)
{//输入关键字
	scanf("%s",k);
}

void InitDSTable(DLTree &DT)
{//初始化双链表DT
	DT=(DLTree)malloc(sizeof(DLTNode)); 
	DT->first=DT->next=NULL;
	DT->kind=BRANCH; 
}

void DestroyDSTable(DLTree &DT)
{ //销毁双链表DT
	if(DT) 
	{ 
		if(DT->kind==BRANCH)
		{
			DestroyDSTable(DT->first); 
		}
		DestroyDSTable(DT->next); 
		free(DT); 
		DT=NULL; 
	}
}

Record* SearchDLTree(DLTree T,KeyType K)
{ //在双链表DT中查找关键词等于K的记录,若查找成功，则返回指向关键词记录的指针，查找失败，则返回空指针
	DLTree p=T->first; 
	int i=0;
	while(p&&i<K.num) 
	{ 
		while(p&&p->symbol<K.ch[i])
		{
			p=p->next;
		}
		if(p&&p->symbol==K.ch[i])
		{
			p=p->first; 
			++i; 
		}
		else
		{
			p=NULL;
		}
	} 
	if(p&&p->kind==LEAF) 
		return p->infoptr; 
	else 
		return NULL;
}

Status InsertDSTable(DLTree &DT,Record* r)
{ //在双链表中插入记录*r，插入成功则返回TRUE，否则返回FALSE 
	DLTree q=DT,p=DT->first,ap; 
	int i=0;
	KeyType K=r->key;
	while(p&&i<K.num) 
	{ while(p&&p->symbol<K.ch[i]) 
	  { q=p; 
	    p=p->next; 
	  }
	if(p&&p->symbol==K.ch[i]) 
	{ q=p; 
	p=p->first; 
	++i; 
	}
	else
		break;
	}
	if(p&&p->kind==LEAF) 
		return FALSE;
	else
	{
		ap=(DLTree)malloc(sizeof(DLTNode)); 
		if(q->first==p)
			q->first=ap; 
		else 
			q->next=ap; 
		if(i==K.num) 
		{
			ap->next=p;
			ap->symbol=Nil;
			ap->kind=LEAF;
			ap->infoptr=r;
			return true;
		}
		else 
		{
			ap->next=p; 
			ap->symbol=K.ch[i]; 
			ap->kind=BRANCH; 
			p=ap; 
			ap=(DLTree)malloc(sizeof(DLTNode)); 
			i++; 
			for(;i<K.num;i++) 
			{ 
				p->first=ap; 
				ap->next=NULL; 
				ap->symbol=K.ch[i]; 
				ap->kind=BRANCH; 
				p=ap; 
				ap=(DLTree)malloc(sizeof(DLTNode)); 
			}
			p->first=ap; 
			ap->next=NULL; 
			ap->symbol=Nil;
			ap->kind=LEAF; 
			ap->infoptr=r; 
			return TRUE;
		}
	}
}

void TraverseDSTable(DLTree p,void(*Visit)(Record*))
{ //遍历双链表DT

	if(p) 
	{
		if(p->kind==BRANCH) 
			TraverseDSTable(p->first,Visit);
		else
			Visit(p->infoptr); 
		TraverseDSTable(p->next,Visit);
	}
}


