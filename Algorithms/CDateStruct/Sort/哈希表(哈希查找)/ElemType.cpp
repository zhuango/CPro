/***************************ElemType.cpp***************************/
#include "ElemType.h"
#include <stdio.h>
void Visit(int p,ElemType r)
{
	printf("address = %d(%d,%d)\n",p,r.key,r.order);
}