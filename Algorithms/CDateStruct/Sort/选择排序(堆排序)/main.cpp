#include "Sq_HeapSort.h"
#include <stdio.h>

int main(void)
{
	FILE *f; 
	SqList m; 
	int i;
    f=fopen("1.txt","r"); 
    fscanf(f,"%d",&m.length); 
    for(i=1;i<=m.length;i++) 
    {  
	    InputFromFile(f,m.r[i]); 
	}
	fclose(f);  
    printf("排序前：\n");
    PrintL(m); 
    HeapSort(m); 
    printf("简单选择排序后：\n");
    PrintL(m); 
	return 0;
}