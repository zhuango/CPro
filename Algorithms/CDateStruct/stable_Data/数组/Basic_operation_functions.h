//初始化数组
Status InitArray(Array &A, int dim,...)//变长参数代表各维度长度
{
	int elemtotal = 1, i;//elemtotal用于记录数组元素总数
	va_list ap;//定义用于指向变长参数表参数的指针ap   va_lis、va_start、va_arg和va_end包含在头文件stdarg.h中

	if (dim < 1 || dim > MAX_ARRAY_DIM)
	{
		return ERROR;
	}
	A.dim = dim;//维度赋值

	if (!(A.bounds = (int *)malloc(dim * sizeof(int))))//为存储各维度边界分配地址
	{
		exit (OVERFLOW);
	}

	va_start(ap,dim); //初始化指针，变长参数“...”从参数dim后开始
	for (i = 0; i < dim; ++i)
	{
		if ((A.bounds[i] = va_arg(ap,int)) < 0)//提取代表各维度长度的变长参数赋值给数组维界基址
		{
			return (UNDERFLOW);//下溢
		}
		elemtotal *= A.bounds[i];//累计数组元素以计算总数
	}
	va_end(ap);//结束提取变长参数
	
	if (!(A.base = (ElemType*)malloc(elemtotal * sizeof(ElemType))))//动态分配数组存储空间
	{
		exit (OVERFLOW);
	}

	if (!(A.constants = (int *)malloc(dim * sizeof(int))))//动态分配映像函数常数存储空间
	{
		exit (OVERFLOW);
	}

	A.constants[dim - 1] = 1;//最后一维的偏移量为一
	for (i = dim - 2; i >= 0; --i)
	{
		A.constants[i] = A.bounds[i + 1] * A.constants[i + 1];//每一维的偏移量
	}
	return OK;
}

void DestroyArray(Array &A)//销毁数组
{
	if (A.base)
	{
		free(A.base);
	}
	if (A.bounds)
	{
		free(A.bounds);
	}
	if (A.constants)
	{
		free(A.constants);
	}
	A.base = A.bounds = A.constants = NULL;
	A.dim = 0;
}

Status Locate(Array A,va_list ap,int &off)//定位数组下标对应的相对地址
{
	int i,ind;
    off = 0;//相对地址

	for (i = 0; i < A.dim; ++i)
	{
		ind = va_arg(ap,int);
		if (ind < 0 || ind >= A.bounds[i])
		{
			return OVERFLOW;
		}
		off += ind * A.constants[i];
	}
	return OK;
}

Status Value(ElemType &e ,Array A,...)//将数组元素赋值给e
{
	va_list ap;
	int off;
	va_start(ap,A);
	if (Locate(A,ap,off) == OVERFLOW)
	{
		return ERROR;
	}
	e = *(A.base + off);
	return OK;
}

Status Assign(Array &A, ElemType e,...)
{
	va_list ap;
	int off;
	va_start(ap,e);
	if (Locate(A,ap,off) == OVERFLOW)
	{
		return ERROR;
	}
	*(A.base + off) = e;
	return OK;
}