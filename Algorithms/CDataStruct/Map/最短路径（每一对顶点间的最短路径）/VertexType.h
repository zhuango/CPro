#ifndef VERTEXTYPE_H
#define VERTEXTYPE_H

#include <stdio.h>
#define MAX_NAME 9
struct VertexType
{
	char name[MAX_NAME];
};
void Visit(VertexType ver);
void Input(VertexType &ver);
void InputFromFile(FILE *f,VertexType &ver);

#endif
