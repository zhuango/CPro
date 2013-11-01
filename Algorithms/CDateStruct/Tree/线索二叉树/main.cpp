#define ET 1
#include "BiThrTree.h"
void visit(TElemType e)
{
	printf(form" ",e);
}
int main()
{
	BiThrTree T,H;
	CreatBiThrTree(T);
	InOrderThreading(H,T);
	printf("\n÷––Ú ‰≥ˆ£∫\n");
	InOrderTraverse_Thr(H,visit);

	return 0;
}