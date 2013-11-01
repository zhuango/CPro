#define MAX_SIZE  100//三元组元素的最大存储量

typedef struct
{
	int i,j;   //存储下标（行和列）
	ElemType e;//矩阵元素
}Triple;

typedef struct
{
	Triple date[MAX_SIZE + 1];//分配稀疏矩阵的静态顺序存储空间
	int mu,nu,tu;//矩阵的行、列和非零元素个数
}TSMatrix;