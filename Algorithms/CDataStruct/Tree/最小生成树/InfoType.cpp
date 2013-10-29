#include "InfoType.h"

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