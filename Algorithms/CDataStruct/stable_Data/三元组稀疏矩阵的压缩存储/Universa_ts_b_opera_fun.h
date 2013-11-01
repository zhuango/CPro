void DestroySMatrix(TSMatrix &M)//销毁稀疏矩阵
{
	M.mu = M.nu = M.tu = 0;
}

void PrintSMatrix(TSMatrix M)//打印稀疏矩阵
{
	int i,j,k = 1;
	Triple * tp = &M.date[1];//tp指向三元组首元素的地址
	for (i = 1; i <= M.mu; i++)
	{
		for (j = 1; j <= M.nu; j++)
		{
			if (k <= M.tu && tp->i == i && tp->j == j)//稀疏矩阵元素为非零
			{
				printf("%3d",tp->e);
				tp++;
				k++;
			}
			else //稀疏矩阵元素值为为零
			{
				printf("%3d",0);
			}
		}
		printf("\n");
	}
}

void CopySMatrix(TSMatrix M, TSMatrix &T)//复制稀疏矩阵
{
	T = M;
}

Status SubtSMatrix(TSMatrix M,TSMatrix N, TSMatrix &Q)//稀疏矩阵相减
{
	int p;
	if (M.mu != N.mu && M.nu != N.nu)
	{
		return ERROR;
	}

	for (p = 1; p <= N.tu; p++)
	{
		N.date[p].e *= -1;
	}
	AddSMatrix(M,N,Q);
	return OK;
}