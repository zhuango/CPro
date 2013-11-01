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
void OutputArcwel(InfoType *arc)
{//输出弧的权值、ee和el
	printf("%3d %3d %3d",arc->weight,arc->ee,arc->el);
}
void InputArcFromFile(FILE *f,InfoType *&arc)
{//从文件中输入信息
	arc = (InfoType *)malloc(sizeof(InfoType));
	fscanf(f,"%d",&arc->weight);
}