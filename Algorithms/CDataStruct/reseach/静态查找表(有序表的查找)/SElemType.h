#ifndef SELEMTYPE_H
#define SELEMTYPE_H

#include "Status.h"
typedef long KeyType; //定义关键字类型为长整型
#define key number//准考证为关键字
struct SElemType//记录的数据类型（数据元素类型）
{
	long number;//准考证号
	char name[9];//姓名
	int politics;//政治成绩
	int Chinese;//语文成绩
	int English;//英语成绩
	int math;//数学成绩
	int physics;//物理成绩
	int chemisty;//化学成绩
	int biology;//生物成绩
	int total;//总分
};
//对两个数值型关键字的比较约定为如下的宏定义。
#define EQ(a,b) ((a) == (b))
#define LT(a,b) ((a) < (b))
#define LE(a,b) ((a) <= (b))

void visit(SElemType c);
void InputFromFile(FILE*f,SElemType &c);
void InputKey(KeyType &c);
#endif