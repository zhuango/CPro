#include "DisjSet.h"

void InitializeDisjSet(DisjSet disjSet, unsigned int disjSetSize)
{
    for(unsigned int i = 0; i < disjSetSize; i++)
    {
        disjSet[i] = 0;
    }
}

SetType FindInDisjSet(SetType setType, DisjSet disjSet)
{
    SetType index = setType;
    while(disjSet[index] != 0)
    {
        index = disjSet[index];
    }
    return index;
}

void SetUnion(DisjSet disjSet, SetType root1, SetType root2)
{
    disjSet[root1] = root2;
}
