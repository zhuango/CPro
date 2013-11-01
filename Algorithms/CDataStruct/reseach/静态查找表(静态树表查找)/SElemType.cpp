#include "SElemType.h"

void visit(SElemType c)//访问记录
{
	printf("(%c,%.2lf) ",c.key,c.weight);
}
void InputFromFile(FILE*f,SElemType &c)//从文件中输入记录
{
	fscanf(f,"%*c%c%lf",&c.key,&c.weight); 
}
void InputKey(KeyType &k)//输入关键字
{
	scanf("%c",&k);
}