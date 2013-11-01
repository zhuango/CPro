#include "Sq_InsertSort.h"
#include <malloc.h>
#define N 10//记录数组长度
#define T 3//增量序列数组长度
int main(void)
{
   RedType d[N] = {{49,1},{38,2},{65,3},{97,4},{76,5},{13,6},{27,7},{49,8},
   {55,9},{4,10}};//记录数组
   SqList m;//顺序表
   //int i,dt[T] = {5,3,1};//增量序列数组（由大到小，最后一项的值比为1）
   int i;
   for (i = 0; i < N; ++i)
   {//将数组d赋给顺序表m
	   m.r[i + 1] = d[i];
   }
   m.length = N;
   printf("希尔排序前：");
   Print(m);//输出排序前的顺序表m
   ShellSort(m);//按增量序列dt[0..T-1]对顺序表m作希尔排序
   printf("希尔排序后：");
   Print(m);
   return 0;
}

