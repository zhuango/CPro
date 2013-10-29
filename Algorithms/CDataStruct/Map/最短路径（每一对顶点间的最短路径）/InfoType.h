#ifndef INFO_H
#define INFO_H
#include <stdio.h>
#include <string>

#define MAX_INFO 20
typedef char InfoType;

void InputArc(InfoType *&arc);
void InputArcFromFile(FILE *f,InfoType *&arc);
void OutputArc(InfoType *arc);

#endif