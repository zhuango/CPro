#ifndef TRIETREE_H
#define TRIETREE_H

#include "Record.h"
#define LENGTH 27//结点的最大度（0+大写英文字母）
#define Nil 0 //定义串结束符为0
enum NodeKind{BRANCH,LEAF};
typedef struct TrieNode
{//Trie树的存储结构
	NodeKind kind;
	union 
	{//共用体类型
		
		struct 
		{
			KeyType k;//关键字
			Record *infoptr;//记录指针
		}lf;//叶子节点
		struct 
		{
			TrieNode *ptr[LENGTH];//指向Tire树下一结点的指针
			int  num; //分支结点的孩子个数
		}bh;//分支结点
	};
}TrieNode,*TrieTree;//定义指向Trie树结点的指针TrieTree

//基本操作函数
void Visit(Record *r);
void InputKey(char *k);
int ord(char c);
void InitDSTable(TrieTree &T);
void DestroyDSTable(TrieTree &T);
Record *SearchTrie(TrieTree T,KeyType k);
void InsertTrie(TrieTree &T,Record* r);
void TraverseDSTable(TrieTree T,void(*Visit)(Record*));

#endif