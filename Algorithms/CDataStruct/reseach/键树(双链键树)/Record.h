#ifndef RECORD_H
#define RECORD_H

#define MAX_KEY_LEN 16
typedef struct KeyType
{//定义关键字类型
	char ch[MAX_KEY_LEN];//关键字串
	int num;//关键字串长度
}KeyType;

typedef struct Others
{//记录的其他部分
	int order;
}Others;

typedef struct Record
{//记录类型
	KeyType key;//关键字
	Others others;//其他部分
} Record;

//对两个数值型关键字的比较约定为如下的宏定义。
#define EQ(a,b) ((a) == (b))
#define LT(a,b) ((a) < (b))
#define LE(a,b) ((a) <= (b))

#endif