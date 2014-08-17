#include "DisjSet.h"

void Initialize(DisjSet S)
{
        int i;
        for(i = NumSet; i > 0: i--)
                S[i] = 0;
}

void SetUnion(DisjSet S, SetType Roo1, SetType Root2)
{
        S[Root2] = Root1;
}

SetType Find(ElementType x, DisjSet S)
{
        if(S[x] <= 0)
                return x;
        else
                return Find(S[x], S);
}

//Union by height(rank)
void SetUnion_V2(DisjSet S, SetType Root1, SetType Root2)
{
        if(S[Root2] < S[Root1])
                S[Root1] = Root2;
        else
        {
                if(S[Root1] == S[Root2])
                        S[Root1] --;
                S[Root2] = Root1;
        }
}

SetType Find_V2(ElementType x, DisjSet S)
{
        if(S[x] <= 0)
                return x;
        else
                return S[x] = Find(S[x], S);
}
