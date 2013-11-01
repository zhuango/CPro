#include <stdio.h>
#include <string>

#ifdef MG

#define MAX_INFO 20
typedef char InfoType;

#else

typedef int VRType;//权值类型
struct InfoType
{//仅有权值项的弧（边）信息结构体类型（可以按需增加项目）
	VRType weight;
};

#endif

void InputArc(InfoType *&arc);
void InputArcFromFile(FILE *f,InfoType *&arc);
void OutputArc(InfoType *arc);