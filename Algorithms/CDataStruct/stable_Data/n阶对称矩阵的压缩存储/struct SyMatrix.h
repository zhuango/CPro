#define MAX_SYM_DEGREE 10//对称矩阵的最大阶数

typedef struct
{
	ElemType *base;//存储对称矩阵的一维数组基址
	int degree;    //对称矩阵阶数
	int comspace;//压缩空间大小
}SyMatrix;