#include "MGraph.h"
typedef int PathMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];//Â·¾¶¾ØÕó
typedef VRType ShortestPathTable[MAX_VERTEX_NUM]; //×î¶Ì¾àÀë±í
void ShortestPath_DIJ(MGraph G,int v0,PathMatrix P,ShortestPathTable D);