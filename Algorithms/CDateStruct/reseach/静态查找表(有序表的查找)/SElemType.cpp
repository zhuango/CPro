#include "SElemType.h"

void visit(SElemType c)//访问记录
{
	printf("%-8ld %-8s %4d %5d %5d %5d %5d %5d %5d  %5d \n",c.number,c.name,c.politics,c.Chinese,c.English,c.math,c.physics,
		c.chemisty,c.biology,c.total);
}
void InputFromFile(FILE*f,SElemType &c)//从文件中输入记录
{
	fscanf(f,"%ld%s%d%d%d%d%d%d%d",&c.number,&c.name,&c.politics,&c.Chinese,&c.English,&c.math,&c.physics,
		&c.chemisty,&c.biology);
}
void InputKey(KeyType &k)//输入关键字
{
	scanf("%ld",&k);
}