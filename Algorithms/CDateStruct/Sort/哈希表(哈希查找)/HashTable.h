/***************************HashTable.h***************************/
/*本算法中采用的构造哈希表的方法有：
1.构造哈希函数的方法：【除留余数法】
   H(key) = key MOD p (p ≤ m),其中m为表长，本算法中取p＝m;(一般情况下，可选p为质数或不包含小于20的质因数的合数)
2.处理冲突的方法：【开放定址法】
   Hi = (H(key) + di) MOD m, i=1,2,3,...,k(k <= m - 1),其中di为增量序列,可有下列三种取法：
   (1) 线性探索再散列：di = 1,2,3,...,m-1
   (2) 二次探索再散列：di = 1,-1^2,2,-2^2,...,±k^2(k <= m - 1)
   (3) 伪随机探索再散列：di = 伪随机数序列
*/
#ifndef HASHTABLE_H//头文件保护符
#define HASHTABLE_H

#include "ElemType.h"
static int hashsize[] = {11,19,29,37};//内部链接静态变量，哈希表容量（表长m）递增表，一个合适的素数序列。
typedef struct HashTable
{//哈希表的存储结构
	ElemType *elem;//记录存储基址变量，动态分配数组
	int count;//当前记录个数
	int sizeindex;//hashsize[sizeindex]为当前表长
}HashTable;

//宏定义
typedef int Status; // Status是函数的类型,其值是函数结果状态代码，如下边三个宏定义
#define SUCCESS 1 //查找成功
#define UNSUCCESS 0//查找失败
#define DUPLICATE -1//记录重复

//基本操作函数声明
void InitHashTable(HashTable &H);

void DestroyHashTable(HashTable &H);

unsigned Hash(KeyType k);

int d(int i);

void collision(KeyType &k,int &p,int i);

Status SearchHash(HashTable H,KeyType k,int &p,int &c);

Status InsertHash(HashTable &H,ElemType e);

void RecreateHashTable(HashTable &H);

void TraverseHash(HashTable H,void (*Visit)(int,ElemType));

#endif
