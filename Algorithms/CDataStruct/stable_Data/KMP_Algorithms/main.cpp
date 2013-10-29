#include "Status.h"
#include "def_SString.h"
#include "Basic_operation_functions.h"
#include "KMP.h"

int main(void)
{
	int i,*p;
	SString s1,s2;
	StrAssign(s1,"acabaabcacaabc");
	printf("主串为:");
	StrPrint(s1);
	StrAssign(s2,"abaabcac");
	printf("子串为:");
	StrPrint(s2);
	p = (int *)malloc((StrLength(s2) + 1)*sizeof(int));
	get_next(s2,p);
	printf("子串的next数组为：");
	for(i = 1; i <= StrLength(s2); i++)
	{
		printf("%d  ",p[i]);
	}
	printf("\n");
	i = Index_KMP(s1,s2,1,p);
	if(i)
	{
		printf("主串和子串在地%d个字符处首次匹配\n",i);
	}
	else
	{
		printf("主串和子串匹配不成功\n");
	}
	get_nextval(s2,p);
	printf("修改算法后，子串的next数组为：");
	for(i = 1; i <= StrLength(s2); i++)
	{
		printf("%d  ",p[i]);
	}
	printf("\n");
	i = Index_KMP(s1,s2,1,p);
	if(i)
	{
		printf("主串和子串在地%d个字符处首次匹配\n",i);
	}
	else
	{
		printf("主串和子串匹配不成功\n");
	}

}