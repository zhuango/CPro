int main()
{
	TSMatrix A,B,C;
	printf("创建稀疏矩阵A:");
	CreateSMatrix(A);
	PrintSMatrix(A);
	
	printf("由矩阵A复制矩阵B:\n");
	CopySMatrix(A,B);
	PrintSMatrix(B);

	printf("销毁矩阵B后：\n");
	DestroySMatrix(B);
	PrintSMatrix(B);

	printf("创建矩阵B2:(与矩阵A的行、列数相同，行、列分别为3,3)\n");
	CreateSMatrix(B);
	PrintSMatrix(B);

	printf("矩阵C1(A + B):\n");
	AddSMatrix(A,B,C);
	PrintSMatrix(C);

	printf("矩阵C2(A - B):\n");
	SubtSMatrix(A,B,C);
	PrintSMatrix(C);

	printf("矩阵C3(A的转置矩阵):\n");
	TransposeSMatrix(A,C);
	PrintSMatrix(C);

	printf("创建稀疏矩阵A2:");
	CreateSMatrix(A);
	PrintSMatrix(A);
	printf("创建稀疏矩阵B3(行数和矩阵A2的列数相同 = 3):");
	CreateSMatrix(B);
	PrintSMatrix(B);

	printf("矩阵C5(A * B):\n");
#ifndef FLAG
	MultSMatrix(A,B,C);
#else
	MultSMatrix1(A,B,C);
#endif
	PrintSMatrix(C);
	return 0;
}