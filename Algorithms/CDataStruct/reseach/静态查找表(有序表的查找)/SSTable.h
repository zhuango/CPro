#ifndef SSTABLE_H
#define SSTABLE_H

#include "SElemType.h"
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
#endif