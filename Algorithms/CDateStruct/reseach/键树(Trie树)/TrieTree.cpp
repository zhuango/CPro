#include "TrieTree.h"
static int count = 1;//内部链接的静态变量
int ord(char c)
{//英文字母返回其在字母表中的序号（此处不分大小写）
	if (c == Nil)
	{
		return 0;
	}
	else
	{
		return toupper(c) - 'A' + 1;
	}
}

void Visit(Record *r)
{//访问结点上关键字的记录
	printf("(%s,%d)",r->key.ch,r->others.order);
}

void InputKey(char *k)
{//输入关键字
	scanf("%s",k);
}

void InitDSTable(TrieTree &T)
{//初始化Trie树为空树
	T = NULL;
}

void DestroyDSTable(TrieTree &T)
{//销毁Trie树T
	int i,j = 0;
	if (!T)
	{
		for (i = 0; i < LENGTH && j < T->bh.num; ++i)
		{
			if (T->kind == BRANCH && T->bh.ptr[i])
			{
				DestroyDSTable(T->bh.ptr[i]);
			}
			else
			{
				free(T->bh.ptr[i]);
			}
			j++;
		}
		free(T);
		T = NULL;
	}
}

Record *SearchTrie(TrieTree T,KeyType k)
{//在Trie树中查找关键词等于k的记录。
	TrieTree p = T;
	int i;
	for (i = 0; p && p->kind == BRANCH && i <= k.num; p = p->bh.ptr[ord(k.ch[i++])]);
	//对k的每个字符逐个查找，*p为分支结点，ord[]求字符在字母中的序号
	if (p && p->kind == LEAF && EQ(p->lf.k.ch,k.ch))
	{
		return p->lf.infoptr;
	}
	else
	{
		return NULL;
	}
}

 void InsertTrie(TrieTree &T,Record* r)
 { //在Trie树中插入记录r
   TrieTree p=T,q,ap;
   int i,j,k,n;
   if(!T) 
   { T=(TrieTree)malloc(sizeof(TrieNode)); 
     T->kind=BRANCH; 
     for(i=0;i<LENGTH;i++) 
       T->bh.ptr[i]=NULL;
     T->bh.num=1; 
     p=T->bh.ptr[ord(r->key.ch[0])]=(TrieTree)malloc(sizeof(TrieNode));
     
     p->kind=LEAF; 
     p->lf.k=r->key; 
     p->lf.infoptr=r; 
   }
   else 
   { for(i=0;p&&p->kind==BRANCH&&i<=r->key.num;++i) 
     { q=p; 
       p=p->bh.ptr[ord(r->key.ch[i])]; 
     }
     if(!p) 
     { p=q->bh.ptr[ord(r->key.ch[i-1])]=(TrieTree)malloc(sizeof(TrieNode));
       
       q->bh.num++; 
       p->kind=LEAF; 
       p->lf.k=r->key; 
       p->lf.infoptr=r; 
     }
     else 
     { if(EQ(p->lf.k.ch,r->key.ch)) 
         return; 
       else 
       { for(n=0;r->key.ch[n]==p->lf.k.ch[n];n++); 
         n=n-i;
         for(k=0;k<=n;k++)
         { ap=q=q->bh.ptr[ord(r->key.ch[i++-1])]=(TrieTree)malloc(sizeof
           (TrieNode)); 
           ap->kind=BRANCH; 
           for(j=0;j<LENGTH;j++)
             ap->bh.ptr[j]=NULL; 
           ap->bh.num=1; 
         }
         ap->bh.num++; 
         ap->bh.ptr[ord(p->lf.k.ch[i-1])]=p; 
         q=ap->bh.ptr[ord(r->key.ch[i-1])]=(TrieTree)malloc(sizeof(TrieNode));
         
         q->kind=LEAF; 
         q->lf.k=r->key; 
         q->lf.infoptr=r; 
       }
     }
   }
 }

 void TraverseDSTable(TrieTree T,void(*Visit)(Record*))
 { //遍历Trie树
   TrieTree p;
   int i,n=9; 
   if(T) 
     for(i=0;i<LENGTH;i++) 
     { p=T->bh.ptr[i]; 
       if(p&&p->kind==LEAF) 
       { Visit(p->lf.infoptr); 
         count++;
         if(count%n==0)
           printf("\n"); 
       }
       else if(p&&p->kind==BRANCH) 
         TraverseDSTable(p,Visit); 
     }
 }
