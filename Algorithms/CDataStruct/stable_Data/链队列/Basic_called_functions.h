#ifndef BASIC_CALLED_FUN_H//预处理保护符
#define BASIC_CALLED_FUN_H

//一些通用函数的声明
#include "QElemType.h"
#define ElemType QElemType
Status equal(ElemType c1,ElemType c2);
int comp(ElemType ,ElemType );
void print(ElemType );
void print1(ElemType &);
void print2(ElemType );

#endif
