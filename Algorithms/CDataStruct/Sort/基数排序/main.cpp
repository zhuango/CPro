#include "SLL_RadixSort.h"
#include <stdio.h>
#include <malloc.h>
 void main()
 {
   FILE *f; 
   SLList m; 
   int *adr;
   f=fopen("1.txt","r"); 
   MadeListFromFile(m,f); 
   fclose(f); 
   printf("排序前(next域还未赋值)：\n");
   Print2(m); 
   RadixSort(m); 
   adr=(int*)malloc((m.recnum+1)*sizeof(int)); 
   Sort(m,adr); 
   Rearrange(m,adr); 
   free(adr); 
   printf("\n重排记录后(next域不起作用)：\n");
   Print2(m); 
 }