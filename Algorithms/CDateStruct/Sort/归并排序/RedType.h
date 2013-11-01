/*****************RedType.h*****************/
#ifndef RED_TYPE
#define RED_TYPE
#include <stdio.h>
typedef int KeyType;//定义关键字类型为整型
typedef int infoType;//定义定义其他数据项的类型为整型

typedef struct RedType
{//记录的类型
	KeyType key;//关键字
	infoType otherinfo;//其他数据项

}RedType;

//对两个数值型关键字的比较约定为如下的宏定义。
#define EQ(a,b) ((a) == (b))
#define LT(a,b) ((a) < (b))
#define LQ(a,b) ((a) <= (b))

//基本操作函数
void InputFromFile(FILE *f,RedType &c);

#endif