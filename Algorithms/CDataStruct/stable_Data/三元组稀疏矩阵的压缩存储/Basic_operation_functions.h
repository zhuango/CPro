Status CreateSMatrix(TSMatrix &M)
{
	int i;
	Status k;
	Triple T;
	
	printf("请输入稀疏矩阵的行数、列数和非零元素个数（小于%d）:",MAX_SIZE);
	scanf("%d,%d,%d",&M.mu, &M.nu, &M.tu);
	if (M.tu > MAX_SIZE)
	{
		return ERROR;
	}
	M.date[0].i = M.date[0].j = 0;//第一个存为空
	for (i = 1; i <= M.tu; i++)
	{
		do 
		{
			printf("请输入第%d个非零元素的行（1~%d）、列(1~%d)和元素值:",i,M.mu,M.nu);
			scanf("%d,%d,%d",&T.i, &T.j, &T.e);
			k = 0;//标记输入正确
			if (T.i < 1 || T.i > M.mu || T.j < 1 || T.j > M.nu)
			{
				k = 1;//输入范围错误，标记输入错误
			}
			if (T.i < M.date[i - 1].i || T.i == M.date[i - 1].i && T.j <= M.date[i - 1].j)
			{
				k = 1;//输入顺序有误，标记输入错误
			}

		}while(k);

		M.date[i] = T;//存入三元组
	}
	return OK;
}

Status AddSMatrix(TSMatrix M,TSMatrix N,TSMatrix &Q)
{
	int m = 1,n = 1,q = 0;
	if (M.mu != N.mu || M.nu != N.nu)//两矩阵的行列不同
	{
		return ERROR;
	}
	Q.mu = M.mu;//设置稀疏矩阵Q的行和列
	Q.nu = M.nu;
	while (m <= M.tu && n <= N.tu)
	{
		switch (comp(M.date[m].i,N.date[n].i))
		{//比较当前元素的行关系
		case -1 :Q.date[++q] = M.date[m++];
			break;
		case 0:
			switch (comp(M.date[m].j,N.date[n].j))
			{//比较当前元素的列关系
			case -1:Q.date[++q] = M.date[m++];
				break;
			case 0:Q.date[++q] = M.date[m++];
					Q.date[q].e +=N.date[n++].e; 
					if (0 == Q.date[q].e)//元素和为0，不存入
					{
						q--;
					}
					break;
			case 1:Q.date[++q] = N.date[n++];
			}
			break;
		case 1:Q.date[++q] = N.date[n++];
		}
	}

	while (m <= M.tu)//M元素未处理完
	{
		Q.date[++q] = M.date[m++];
	}
	while (n <= N.tu)//N元素未处理完
	{
		Q.date[++q] = N.date[n++];
	}
	if (q > MAX_SIZE)//Q的非零元素超过最大值
	{
		return ERROR;
	}
	Q.tu = q;
	return OK;
}

void TransposeSMatrix(TSMatrix M,TSMatrix &T)//求稀疏矩阵M的转置矩阵T
{
	int col,p,q = 0;

	T.mu = M.nu;
	T.nu = M.mu;
	T.tu = M.tu;
	if (T.tu)//T.tu非空
	{
		for (col = 1; col <= M.nu; col++)
		{
			for (p = 1; p <= M.tu; p++)
			{
				if (col == M.date[p].j)
				{
					T.date[++q].i = M.date[p].j;
					T.date[q].j = M.date[p].i;
					T.date[q].e = M.date[p].e;
				}
			}
		}
	}
}

Status MultSMatrix(TSMatrix M,TSMatrix N,TSMatrix &Q)
{
	int i,j,p,q;
	ElemType Qs;//存储临时数据
	TSMatrix T;//矩阵N的转置矩阵

	if (M.nu != N.mu)
	{//不符合矩阵相乘的条件6
		return ERROR;
	}
	Q.mu = M.mu;//Q的行数
	Q.nu = N.nu;//Q的列数
	Q.tu = 0;	
	TransposeSMatrix(N,T);//将N的转置矩阵存到T

	for (i = 1; i <= Q.mu; i++)
	{
		q = 1;//指向T
		for (j = 1; j <= Q.nu; j++)
		{	
			Qs = 0;
			p = 1;//指向M
			while (M.date[p].i < i)
			{
				p++;
			}
			while (T.date[q].i < j)
			{
				q++;
			}
			while (p <= M.tu && q <= T.tu && M.date[p].i == i && M.date[q].i == j)
			{
				switch(comp(M.date[p].j, T.date[q].j))
				{
				case -1:p++;
						break;
				case 0:Qs += M.date[p++].e * T.date[q++].e;
						break;
				case 1:q++;
				}
			}

			if (Qs)
			{
				if (++Q.tu > MAX_SIZE)
				{
					return ERROR;
				}
				Q.date[Q.tu].i = i;
				Q.date[Q.tu].j = j;
				Q.date[Q.tu].e = Qs;
			}
		}
	}
	return OK;
}
