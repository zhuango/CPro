#include "Status.h"
typedef int ElemType; 
#include "struct SyMatrix.h"
#include "Basic_operation_functions.h"

int main()
{
	int i,j,e,e1,degree = 4;
	SyMatrix M;


	InitMatrix(M,degree);
	printf("M.degree =%d  M.comspace = %d\n\n",M.degree,M.comspace);

	printf("给下三角的赋值（包括对角线）如下：\n");
	for (i = 1; i <= degree; i++)
	{
		for (j = 1; j <= i; j++)
		{
			Assign(M,i*10 + j,i,j);
			Value(M,e,i,j);
			printf("%d ",e);
		}
		printf("\n");
	}
	printf("\n得到的对称矩阵如下：\n");
	SymPrint(M);

	Assign(M,90,3,2);
	Assign(M,80,4,3);
	printf("将M[3][2]的值改为90,M[4][3]的值改为80后，矩阵如下：\n");
	SymPrint(M);

	Value(M,e,2,1);
	Value(M,e1,2,4);
	printf("将M[2][1]的值赋给e为%d,M[2][4]的值赋给e1为%d\n",e,e1);

	return 0;
}