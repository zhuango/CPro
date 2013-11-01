#include "Status.h"
#include "HString.h"
#include "Basic_operation_functions.h"
#include "Line_List.h"
int main()
{
	int i;
	char c,*p = "God bye!",*q = "God luck!";
	char ps[100];
	HString s,t,r;
	InitString(s);
	InitString(t);
	InitString(r);
	StrAssign(s,p);
	printf("串s为：");
	StrPrint(s);
	printf("串长为%d,串空否？%d(1:空 0：否)\n",StrLength(s),StrEmpty(s));
	StrAssign(t,q);
	printf("串t为：");
	StrPrint(t);
    
	i = StrCompare(s,t);
	if (i < 0)
	{
		c = '<';
	}
	else if (0 == i)
	{
		c = '=';
	}
	else
	{
		c = '>';
	}
	printf("串s%c串t\n",c);

	Concat(r,s,t);
	printf("连接串s和串t得串r为");
	StrPrint(r);

	StrAssign(t,"oo");
	printf("串t为：");
	StrPrint(t);
	StrAssign(s,"o");
	printf("串s为：");
	StrPrint(s);
	Replace(r,s,t);
	printf("把串r中所有和串s相同的串用串t替换后，串r为");
	StrPrint(r);

	ClearString(t);
	printf("清空串t后,串长为%d,串空否？%d(1:空 0：否)\n",StrLength(t),StrEmpty(t));
	SubString(t,r,6,4);
	printf("串t为从串r的第6个字符起的4个字符，长度为%d,串t为",StrLength(t));
	StrPrint(t);

	StrCopy(s,r);
	printf("将r复制到s中，串s为");
	StrPrint(s);

	StrInsert(s,6,t);
	printf("在串s的第6个字符前插入t后，串s为");
	StrPrint(s);

	StrDelete(s,1,5);
	printf("从串s的第1个字符起删除5个字符后，串s为");
	StrPrint(s);

	printf("%d是串s的第1个字符起，和串t相同的第一个子串位置\n",Index1(s,t,1));
	printf("%d是串s的第2个字符起，和串t相同的第一个子串位置\n",Index1(s,t,2));

	return 0;
}
/*
------------------------------------------
串s为：God bye!
串长为8,串空否？0(1:空 0：否)
串t为：God luck!
串s<串t
连接串s和串t得串r为God bye!God luck!
串t为：oo
串s为：o
把串r中所有和串s相同的串用串t替换后，串r为Good bye!Good luck!
清空串t后,串长为0,串空否？1(1:空 0：否)
串t为从串r的第6个字符起的4个字符，长度为4,串t为bye!
将r复制到s中，串s为Good bye!Good luck!
在串s的第6个字符前插入t后，串s为Good bye!bye!Good luck!
从串s的第1个字符起删除5个字符后，串s为bye!bye!Good luck!
是串s的第1个字符起，和串t相同的第一个子串位置
是串s的第2个字符起，和串t相同的第一个子串位置
请按任意键继续. . .
------------------------------------------
*/