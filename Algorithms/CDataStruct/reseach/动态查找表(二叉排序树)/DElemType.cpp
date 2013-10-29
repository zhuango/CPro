#include "DElemType.h"

void Visit(DElemType c)
{
	printf("(%d,%d)",c.key,c.others);
}
void InputFromFile(FILE * f,DElemType &c)
{
	fscanf(f,"%*c%d%d",&c.key,&c.others);
}
void InputKey(KeyType &k)
{
	scanf("%d",&k);
}