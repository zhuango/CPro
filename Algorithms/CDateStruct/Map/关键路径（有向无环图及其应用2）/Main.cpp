#include "CriticalPath.h"
int main(void)
{
	ALGraph h;
	printf("«Î—°‘Ò”–œÚÕº\n");
//	CreateGraph(h);
	CreateFromFile(h,"1.txt");
	Display(h);
	CriticalPath(h);
	return 0;
}