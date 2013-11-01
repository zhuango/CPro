#include "Status.h"
//数据类型定义部分
#define MAX_STR_LEN 40//用户可在255（1个字节所能表示的最大整数）以内定义最大串长
typedef unsigned char SString[MAX_STR_LEN + 1];//0号单元存储串长
//函数声明部分

#define DestroyString ClearString
#define InitString ClearString
Status StrAssign(SString T,char *chars);
void StrCopy(SString T, SString S);
Status StrEmpty(SString S);
int StrCompare(SString S,SString T);
int StrLength(SString S);
void ClearString(SString S);
Status Concat(SString T,SString S1,SString S2);
Status SubString(SString Sub,SString S,int pos,int len);
int Index(SString S,SString T,int pos);
int Index1(SString S,SString T,int pos);
Status StrInsert(SString S,int pos,SString T);
Status StrDelete(SString S,int pos,int len);
void StrPrint(SString S);
int next(SString S, int j);