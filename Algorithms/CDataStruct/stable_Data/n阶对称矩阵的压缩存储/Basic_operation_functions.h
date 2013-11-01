Status InitMatrix(SyMatrix &M,int n)
{
	int space;//对称矩阵的压缩存储空间大小
	if (n < 1 || n > MAX_SYM_DEGREE)
	{
		return ERROR;
	}
	M.degree = n;//阶数
	M.comspace = (n * (n + 1))/2; //压缩存储空间

	if (!(M.base = (ElemType*)malloc(M.comspace * sizeof(ElemType))))//动态分配矩阵压缩存储空间
	{
		exit (OVERFLOW);
	}
	return OK;
}

void DestroyMaxtrix(SyMatrix &M)//销毁对称矩阵
{
	if (M.base)
	{
		free(M.base);
	}
	M.base = NULL;
    M.degree = 0;
	M.comspace = 0;
}

Status Locate(SyMatrix M,int i,int j,int &off)//通过下标返回对称矩阵在压缩空间中的相对位置
{
	int m,n;
	if (i < 1 || i > M.degree || j < 1 || j > M.degree)
	{
		return ERROR;
	}
	if (i >= j)
	{
		m = i;
		n = j;
	}
	else
	{
		m = j;
		n = i;
	}

	off = ( m*( m - 1 ) )/2 + n - 1;//通过下标计算对称矩阵在压缩空间中的相对位置

	return OK;
}

Status Value(SyMatrix M,ElemType &e,int i,int j)//将对称矩阵中相应下标的元素赋给e
{
	int off = 0;
	if (Locate(M,i,j,off) == ERROR)
	{
		return ERROR;
	}
	e = M.base[off];
	return OK;
}

Status Assign(SyMatrix &M,ElemType e,int i,int j)//将e赋值给对称矩阵中相应下标的元素
{
	int off = 0;
	if (Locate(M,i,j,off) == ERROR)
	{
		return ERROR;
	}
	M.base[off] = e;
	return OK;	
}

void SymPrint(SyMatrix M)
{
	int i,j,off;
	for (i = 1; i <= M.degree; i++)
	{
		for (j = 1; j <= M.degree; j++)
		{
			Locate(M,i,j,off);
			printf("%d ",M.base[off]);
		}
		printf("\n");
	}
}