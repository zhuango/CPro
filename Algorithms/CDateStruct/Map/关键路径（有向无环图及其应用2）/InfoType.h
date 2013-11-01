#include <stdio.h>
typedef int VRType;//权值类型
struct InfoType
{//仅有权值项的弧（边）信息结构体类型（可以按需增加项目）
	VRType weight;
	int ee,el;
};

void InputArc(InfoType *&arc);
void OutputArc(InfoType *arc);
void OutputArcwel(InfoType *arc);
void InputArcFromFile(FILE *f,InfoType *&arc);

