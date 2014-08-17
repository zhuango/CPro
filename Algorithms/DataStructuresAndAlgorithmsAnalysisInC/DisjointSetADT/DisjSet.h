#ifndef _DisjSet_H
#define NumSet 10

typedef int DisjSet[NumSet + 1];
typedef int SetType;
typedef int ElementType;

void Initilialize(DisjSet s);
void SetUnion(DisjSet S, SetType Root1, SetType Root2);
SetType Find(ElementType X, DisjSet S);

#endif _DisjSet_H
