//这是一个双向冒泡排序算法，在排序过程中以交替的正反两个方向进行遍历。把最大的放在末尾最小的放在最前。  
#include<stdio.h>
#include<stdlib.h>

#define Max 20  
typedef int elemtype;  
typedef elemtype recs[Max];  
void bibubble(recs r,int n)  
{  
    int flag = 1;  
    int i = 0, j;  
    elemtype temp;  
    while (1 == flag)//这里这样写是可以避免错误的  
    {  
        flag = 0;  
        for(j = n - i - 1; j >= i + 1; j--)//反向遍历找最小值  
            if(r[j] < r[j-1])  
            {  
                flag = 1; //能交换说明没有排好序，要继续。                
                temp = r[j];  
                r[j] = r[j - 1];  
                r[j - 1] = temp;  
            }  
        for(j = i + 1; j < n - 1; j ++)//正向遍历找最大值  
            if(r[j] > r[j + 1])  
            {  
                flag = 1; //能交换说明没有排好序，要继续。  
                temp = r[j];  
                r[j] = r[j + 1];  
                r[j + 1] = temp;  
            }  
            i++;  
    } 
}  
  
void main()  
{  
    recs A={2, 8, 3, 6, 9, 5, 1, 4, 0, 7};  
    int n = 10,i;  
    for(i = 0; i < n; i++)  
        printf("%d ", A[i]); 
    printf("\n");
    
    bibubble(A,n);  
    
    for(i = 0; i < n; i++)  
        printf("%d ", A[i]); 
    printf("\n");

    exit(EXIT_SUCCESS);
}
