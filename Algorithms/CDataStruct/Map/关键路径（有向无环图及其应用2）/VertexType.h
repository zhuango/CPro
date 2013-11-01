#define MAX_NAME 9
struct VertexType
{
	char name[MAX_NAME];
	int ve,vl;
};
void Visit(VertexType ver);
void Input(VertexType &ver);
void Visitel(VertexType ver);
void InputFromFile(FILE *f,VertexType &ver);
