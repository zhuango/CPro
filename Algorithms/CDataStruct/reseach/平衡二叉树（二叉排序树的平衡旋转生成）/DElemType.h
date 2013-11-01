#ifndef DELEMTYPE_H
#define DELEMTYPE_H
#include <stdio.h>
typedef int KeyType;
struct DElemType
{
	KeyType key;
	int others;
};

void Visit(DElemType c);
void InputFromFile(FILE * f,DElemType &c);
void InputKey(KeyType &k);

//对两个数值型关键字的比较约定为如下的宏定义。
#define EQ(a,b) ((a) == (b))
#define LT(a,b) ((a) < (b))
#define LE(a,b) ((a) <= (b))

#endif