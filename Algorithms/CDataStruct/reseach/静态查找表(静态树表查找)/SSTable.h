#ifndef SSTABLE_H
#define SSTABLE_H

#include "SElemType.h"
#include "BiTree.h"
struct SSTable//静态查找表类型
{
	SElemType *elem;//数据元素（记录）存储空间基址,建表时按实际记录数分配，0号单元留空（可设置哨兵）
	int length;//表长度
};

//函数声明

void Creat_SeqFromFile(SSTable &ST,char *filename);

void Ascend(SSTable &ST);

void Creat_OrderFromFile(SSTable & ST,char *filename);

Status Destroy(SSTable &ST);

int Search_Seq(SSTable ST,KeyType key);

int Search_Bin(SSTable ST,KeyType key);

void Traverse(SSTable ST);

//静态查找树的操作
void FindSW(double sw[],SSTable ST);

Status SecondOptimal(BiTree &T,SElemType R[],double sw[],int low,int high);

typedef BiTree SOSTree;//次优查找树采用二叉链表的存储结构
#define N 100 //静态查找表的最大表长

void CreateSOSTree(SOSTree &T,SSTable ST);

Status Search_SOSTree(SOSTree &T,KeyType key);



#endif