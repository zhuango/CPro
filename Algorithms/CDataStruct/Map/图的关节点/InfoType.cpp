#include "InfoType.h"
#include <stdio.h>
#include <malloc.h>

void InputArc(InfoType *&arc)
{//输入弧（边）的信息
	arc = (InfoType *)malloc(sizeof(InfoType));
	scanf("%d",&arc->weight);
}
void OutputArc(InfoType *arc)
{//输出信息
	printf(":%d ",arc->weight);
}
void InputArcFromFile(FILE *f,InfoType *&arc)
{//从文件中输入信息
	arc = (InfoType *)malloc(sizeof(InfoType));
	fscanf(f,"%d",&arc->weight);
}