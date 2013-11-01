#ifndef SELEMTYPE_H
#define SELEMTYPE_H

#include "Status.h"
typedef char KeyType; //定义关键字类型为字符型

struct SElemType//记录的数据类型（数据元素类型）
{
	KeyType key;
	double weight;
};
//对两个数值型关键字的比较约定为如下的宏定义。
#define EQ(a,b) ((a) == (b))
#define LT(a,b) ((a) < (b))
#define LE(a,b) ((a) <= (b))

void visit(SElemType c);
void InputFromFile(FILE*f,SElemType &c);
void InputKey(KeyType &c);
#endif