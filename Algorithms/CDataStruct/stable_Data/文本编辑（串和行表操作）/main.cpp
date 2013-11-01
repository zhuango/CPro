#include "Status.h"
#include "HString.h"
#include "Basic_operation_functions.h"
#include "Line_List.h"
int main()
{
	int i,num;
	char ch,str[100];
	HString s,t,r;
	LineList l;

	InitString(s);
	InitList(l,&s);
	InitString(t);
	InitString(r);

	printf("请输入文本串s（按ctrl + Z结束）\n");
	for(i = 0; (ch = getchar()) != EOF; i++)
	{
		str[i] = ch;
	}
	str[i] = '\0';
	StrAssign(s,str);
	printf("文本串s如下：\n");
	StrPrint(s);
	UpdateList(l);
	printf("文本串s的行表如下：\n\n");
	ListPrint(l);

	printf("\n请输入将要插入到文本串s中的文本t\n");
	for(i = 0; (ch = getchar()) != EOF; i++)
	{
		str[i] = ch;
	}
	str[i] = '\0';
	StrAssign(t,str);
	printf("将要插入到文本串s中的文本t如下：\n");
	StrPrint(t);
	printf("请输入s中t的插入位置（t插在该位置前）:");
	scanf("%d",&num);
	ListInsert(l,num,t);
	printf("\n插入t后的s为\n");
	StrPrint(s);
	printf("插入t后，文本串s的行表如下：\n\n");
	ListPrint(l);

	printf("\n请输入s中要删除行的行号:");
	scanf("%d",&num);
	ListDelete(l,num);
	printf("\n删除%d后的s为\n",num);
	StrPrint(s);
	printf("此时文本串s的行表如下：\n\n");
	ListPrint(l);

	
	ClearList(l);
	printf("清空l后,行表l的记录数为%d,是否为空？%d（1：空 0：否）\n\n",ListLength(l),ListEmpty(l));
	DestroyList(l);

	return 0;
}
/*
------------------------------------------
请输入文本串s（按ctrl + Z结束）
int main()
{
  abcdefg;
  return 0;
}
^Z
文本串s如下：
int main()
{
  abcdefg;
  return 0;
}

文本串s的行表如下：

 行号  起始地址  长度
 100     201      11
 101     212      2
 102     214      11
 103     225      12
 104     237      2

请输入将要插入到文本串s中的文本t
  printf("Hello World!");
^Z
将要插入到文本串s中的文本t如下：
  printf("Hello World!");

请输入s中t的插入位置（t插在该位置前）:102

插入t后的s为
int main()
{
  printf("Hello World!");
  abcdefg;
  return 0;
}

插入t后，文本串s的行表如下：

 行号  起始地址  长度
 100     201      11
 101     212      2
 102     214      26
 103     240      11
 104     251      12
 105     263      2

请输入s中要删除行的行号:103

删除103后的s为
int main()
{
  printf("Hello World!");
  return 0;
}

此时文本串s的行表如下：

 行号  起始地址  长度
 100     201      11
 101     212      2
 102     214      26
 103     240      12
 104     252      2
清空l后,行表l的记录数为0,是否为空？1（1：空 0：否）

请按任意键继续. . .
------------------------------------------
*/