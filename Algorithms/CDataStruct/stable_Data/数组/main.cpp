#include "Status.h"
typedef int ElemType; 
#include "struct array.h"
#include "Basic_operation_functions.h"


int main()
{
	Array A;
	int i,j,k,dim = 3,bound1 = 3,bound2 = 4,bound3 = 2;
	ElemType e;
	InitArray(A,dim,bound1,bound2,bound3);
	printf("A.bounds = ");
	for (i = 0; i < dim; i++)
	{
		printf("%d ",A.bounds[i]);
	}
	printf("\nA.constants = ");
	for (i = 0; i < dim; ++i)
	{
		printf("%d ",A.constants[i]);
	}
	printf("\n%d页%d行%d列矩阵元素如下：\n",bound1,bound2,bound3);
	for (i = 0; i < bound1; i++)
	{
		for (j = 0; j < bound2; j++)
		{
			for (k = 0; k < bound3; k++)
			{
				Assign(A,i * 100 + j * 10 + k,i,j,k);
				Value(e,A,i,j,k);
				printf("A[%d][%d][%d] = %2d  ",i,j,k,e);
			}
			printf("\n");
		}
		printf("\n");
	}
	printf("A.base = \n");
	for (i = 0; i < bound1 * bound2 * bound3; i++)
	{
		printf("%4d",A.base[i]);
		if (i%(bound2 * bound3) == bound2 * bound3 - 1)
		{
			printf("\n");
		}
	}
	printf("A.dim = %d\n\n",A.dim);

	return  0;
}
/*
------------------------------------------
A.bounds = 3 4 2
A.constants = 8 2 1
3页4行2列矩阵元素如下：
A[0][0][0] =  0  A[0][0][1] =  1
A[0][1][0] = 10  A[0][1][1] = 11
A[0][2][0] = 20  A[0][2][1] = 21
A[0][3][0] = 30  A[0][3][1] = 31

A[1][0][0] = 100  A[1][0][1] = 101
A[1][1][0] = 110  A[1][1][1] = 111
A[1][2][0] = 120  A[1][2][1] = 121
A[1][3][0] = 130  A[1][3][1] = 131

A[2][0][0] = 200  A[2][0][1] = 201
A[2][1][0] = 210  A[2][1][1] = 211
A[2][2][0] = 220  A[2][2][1] = 221
A[2][3][0] = 230  A[2][3][1] = 231

A.base =
   0   1  10  11  20  21  30  31
 100 101 110 111 120 121 130 131
 200 201 210 211 220 221 230 231
A.dim = 3

请按任意键继续. . .
------------------------------------------
*/