#include "RedType.h"
void InputFromFile(FILE *f,RedType &c)
{//从文件输入记录的函数
	fscanf(f,"%d%d",&c.key,&c.otherinfo);
}