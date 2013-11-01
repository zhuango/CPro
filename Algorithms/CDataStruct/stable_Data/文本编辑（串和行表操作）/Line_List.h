#define MAX_LINE_LIST 100//最大行表记录
#define ADD_NUM 10//增量
#define INIT_ADR 201//第一个起始地址
#define	INIT_NUM 100//第一个行号

//定义行表（顺序存储）
//定义行表元素
typedef struct LineList_Elem
{
	int num; //行号
	int address; //起始地址
	int length; //长度
} *P_LineList_Elem;//指向行表元素的指针

//定义行表指针
struct LineList
{
	P_LineList_Elem list;//指向行表的指针
	HString * string; //指向串的指针
};

void InitList(LineList &L, HString *S)//初始化行表
{
	int i;
	//为行表分配存储空间
	if (!(L.list = (P_LineList_Elem)malloc( (MAX_LINE_LIST + 1) * sizeof(LineList_Elem))))//最后一个记录用于标记结束
	{
		exit (OVERFLOW);
	}
	L.string = S; //指向空
	L.list[0].num= 0;//标记行表结束
}

void ClearList(LineList &L)//清空行表
{
	L.list[0].num= 0;//标记行表结束
}

void DestroyList(LineList &L)//销毁行表
{
	free(L.list);
	L.list = NULL;
	L.string = NULL;
}

int ListLength(LineList L)//行表长度
{
	int i = 0;
	while (L.list[i].num)
	{
		i++;
	}
	return i;
}

Status ListEmpty(LineList L)
{
	if (L.list[0].num)
	{
		return FALSE;
	}
	else
	{
		return TRUE;
	}
}
void UpdateList(LineList &L)//更新行表
{
	int i,j,max = MAX_LINE_LIST;
	L.list[0].num = INIT_NUM;
	L.list[0].address = INIT_ADR;
	for (i = 0,j = 1; i < (*L.string).length; i++)
	{
		if (L.list[j].num == max + 1)//当记录数超过最大记录数时增加记录
		{
			if (!(L.list = (P_LineList_Elem)realloc( L.list,(max + ADD_NUM + 1) * sizeof(LineList_Elem))))
			{
				exit (OVERFLOW);
			}
			max += ADD_NUM;
		}
		if ((*L.string).ch[i] == '\n')
		{
			L.list[j].num = j + INIT_NUM ;
			L.list[j].address = i + INIT_ADR + 1;
			L.list[j - 1].length = L.list[j].address - L.list[j - 1].address;
			j++;
		}
	}
	if ((*L.string).ch[(*L.string).length - 1] != '\n')//
	{
		L.list[j - 1].length = (*L.string).length - ( L.list[j - 1].address - INIT_ADR);//最后一个字符不是换行符，计算最后一个记录的长度
		L.list[j].num = 0;//标记行表结束
	}
	else
	{
		L.list[j - 1].num = 0;//最后一个字符是换行符，则舍弃最后一个记录，并标记为结束
	}
}

Status ListInsert(LineList &L,int num,HString S)//在第num行号前插入记录
{
	int i = num - INIT_NUM, pos;
	if (i < 0 || i > ListLength(L))
	{
		return ERROR;
	}
	pos = L.list[i].address - INIT_ADR  + 1;
	StrInsert((*L.string),pos,S);
	UpdateList(L);
	return OK;
}

Status ListDelete(LineList &L,int num)//删除行号为num的记录
{
	int i = num - INIT_NUM, pos,len;
	if (i < 0 || i > ListLength(L) - 1)
	{
		return ERROR;
	}
	pos = L.list[i].address - INIT_ADR  + 1;
	len = L.list[i].length;
	StrDelete((*L.string),pos,len);
	UpdateList(L);
	return OK;
}

void ListPrint(LineList L)//打印行表
{
	int i;
	printf(" 行号  起始地址  长度\n");
	for (i = 0; i < ListLength(L); i++)
	{
		printf(" %d     %d      %d",L.list[i].num,L.list[i].address,L.list[i].length);
		printf("\n");
	}
}