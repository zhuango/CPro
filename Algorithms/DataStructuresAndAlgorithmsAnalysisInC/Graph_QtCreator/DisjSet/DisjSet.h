#ifndef DISJSET_H
#define DISJSET_H

typedef int SetType;
typedef SetType* DisjSet;

void InitializeDisjSet(DisjSet disjSet, unsigned int disjSetSize);
SetType FindInDisjSet(SetType setType, DisjSet disjSet);
void SetUnion(DisjSet disjSet, SetType root1, SetType root2);

#endif // DISJSET_H
