#define MAX_ARRAY_DIM 8//最大维度

typedef struct
{
	ElemType *base;//指向存储数组的空间的基址
	int dim;       //数组维度
	int * bounds;  //指向存储各维度边界的空间的基址
	int * constants;//指向存储各维度数组映像函数常量的空间的基址
}Array;