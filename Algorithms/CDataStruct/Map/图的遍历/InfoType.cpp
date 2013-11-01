#include "InfoType.h"
#include <stdio.h>
#include <malloc.h>

#ifdef MG

void InputArc(InfoType *&arc)
{
	int m;
	char s[MAX_INFO];
	printf("请输入边（弧）的信息");
	gets(s);
	m = strlen(s);

	if (m > 0)
	{
		arc = (char *)malloc((m + 1) * sizeof(char));
		strcpy(arc,s);
	}
}
void InputArcFromFile(FILE *f,InfoType *&arc)
{
	char s[MAX_INFO];
	fgets(s,MAX_INFO,f);
	arc = (char *)malloc((strlen(s) + 1) * sizeof(char));
	strcpy(arc,s);
}
void OutputArc(InfoType *arc)
{
	printf("%s\n",arc);
}

#else

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

#endif