#include <stdio.h>
#include "VertexType.h"
void Visit(VertexType ver)
{
	printf("%s ",ver.name);
}
void Input(VertexType &ver)
{
	scanf("%s",ver.name);
}
void Visitel(VertexType ver)
{
	printf("%3d %3d",ver.ve,ver.vl);
}
void InputFromFile(FILE *f,VertexType &ver)
{
	fscanf(f,"%s",ver.name);
}