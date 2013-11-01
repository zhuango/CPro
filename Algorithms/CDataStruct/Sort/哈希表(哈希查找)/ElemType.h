/***************************ElemType.h***************************/
#ifndef ELEMTYPE_H//头文件保护符
#define ELEMTYPE_H

#define NULL_KEY 0//0为无记录标志
typedef int KeyType;//关键字类型
typedef struct ElemType
{//数据元素（记录）类型
	KeyType key;
	int order;
}ElemType;

//对两个数值型关键字的比较约定为如下的宏定义。
#define EQ(a,b) ((a) == (b))
#define LT(a,b) ((a) < (b))
#define LE(a,b) ((a) <= (b))

//基本操作函数声明
void Visit(int p,ElemType r);

#endif