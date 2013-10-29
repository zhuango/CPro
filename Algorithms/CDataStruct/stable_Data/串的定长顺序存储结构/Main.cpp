#include "Status.h"
#include "def_SString.h"
#include "Basic_operation_functions.h"

int main(void)
{
	int i,j;
	Status k;
	char s,c[MAX_STR_LEN];
	SString t,s1,s2;

	printf("请输入串s1:");
	gets(c);
	StrAssign(s1,c);
	printf("串长为%d,串是否为空？%d（1:是 0：否）\n",StrLength(s1),StrEmpty(s1));

	StrCopy(s2,s1);
	printf("复制s1生成的串为：");
	StrPrint(s1);
	printf("请输入串s2：");
	gets(c);
	StrAssign(s2,c);

	i = StrCompare(s1,s2);
	if (i<0)
	{
		s = '<';
	}
	else if (0 == i)
	{
		s = '=';
	}
	else
	{
		s = '>';
	}
	printf("串s1%c串s2\n",s);

	k = Concat(t,s1,s2);
	printf("串s1连接串s2得到的串t为：");
	StrPrint(t);
	if (k == FALSE)
	{
		printf("串t有截断\n");
	}
	ClearString(s1);
	printf("清空串s1后，串是s1为:");
	StrPrint(s1);
	printf("串长为%d,串是否为空？%d（1:是 0：否）\n",StrLength(s1),StrEmpty(s1));
    
	printf("求串t的子串，请输入子串的起始位置和子串长度：");
	scanf("%d,%d",&i,&j);
		k = SubString(s2,t,i,j);
	if (k)
	{
		printf("子串s2为：");
		StrPrint(s2);
	}
	printf("从串t的第pos个字符起，删除len个字符，请输入pos，len：");
	scanf("%d,%d",&i,&j);
	StrDelete(t,i,j);
	printf("删除后的t为：");
	StrPrint(t);

	i = StrLength(s2)/2;
	StrInsert(s2,i,t);
	printf("在串s2的第%d个字符之前插入串t后，串s2为：",i);
	StrPrint(s2);

	i = Index(s2,t,1);
	printf("s2的第%d字符起和t的第一次匹配\n",i);
	i = Index1(s2,t,1);
	printf("s2的第%d字符起和t的第一次匹配\n",i);

}
/*
------------------------------------------
请输入串s1:ABCD
串长为4,串是否为空？0（1:是 0：否）
复制s1生成的串为：ABCD
请输入串s2：123456
串s1<串s2
串s1连接串s2得到的串t为：ABCD123456
清空串s1后，串是s1为:
串长为0,串是否为空？1（1:是 0：否）
求串t的子串，请输入子串的起始位置和子串长度：3,7
子串s2为：CD12345
从串t的第pos个字符起，删除len个字符，请输入pos，len：4,4
删除后的t为：ABC456
在串s2的第3个字符之前插入串t后，串s2为：CDABC45612345
s2的第3字符起和t的第一次匹配
请按任意键继续. . .
------------------------------------------
*/