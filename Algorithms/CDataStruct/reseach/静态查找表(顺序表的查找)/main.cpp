#include "SSTable.h"

int main(void)
{
	SSTable st;
	int i;
	long s;
	char filename[13];
	printf("请输入数据文件名: ");
	scanf("%s",filename);
	Creat_SeqFromFile(st,filename);
//	Creat_OrderFromFile(st,filename);
	for (i = 1; i <= st.length; i++)
	{//计算总成绩
		st.elem[i].total = st.elem[i].politics + st.elem[i].Chinese + st.elem[i].English + st.elem[i].math
			+ st.elem[i].physics + st.elem[i].chemisty + st.elem[i].biology;
	}
	printf("准考证号  姓名     政治  语文  外语  数学  物理  化学  生物   总分\n");
	Traverse(st);//输出记录表
	printf("请输入待查找人的考号:");
	InputKey(s);
	i = Search_Seq(st,s);//查找与关键字相同的记录
//	i = Search_Bin(st,s);
	if (i)
	{
		visit(st.elem[i]);
	}
	else
	{
		printf("未找到!\n");
	}
	Destroy(st);//销毁静态查找表

	return 0;
}