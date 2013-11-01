#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "SL_InsertSort.h"

int main(void)
{
	FILE *f;
	int *adr,i;
	SLinkListType m1,m2;
	if (!(f = fopen("1.txt","r")))
	{//打开文件失败
		fprintf(stderr,"Cannot open 1.txt!\n");
		exit (EXIT_FAILURE);
	}
	CreatTableFromFile(m1,f);//有数据文件建立未排序的顺序表
	if (fclose(f))
	{//关闭文件失败
		fprintf(stderr,"Close file failed!\n");
		exit (EXIT_FAILURE);
	}
	printf("m1排序前\n");
	PrintL(m1);
	MakeTableSorted(m1);
	m2 = m1;
	printf("m1,m2链式有序后:\n");
	PrintL(m1);
	Arrange(m1);
	printf("m1排序后:\n");
	PrintL(m1);
	adr = (int *)malloc((m2.length + 1)*sizeof(int));
	Sort(m2,adr);
	for (i = 1; i <= m2.length; ++i)
	{
		printf("adr[%d] = %d  ",i,adr[i]);
		if (i % 4 == 0)
		{
			printf("\n");
		}
	}
	Rearrange(m2,adr);
	printf("m2排序后：\n");
	PrintL(m2);
	free(adr);
	return 0;
}