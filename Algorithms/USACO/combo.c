/*
ID: og192li1
ROG: combo
PROB: combo
LANG: C
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NumberOfLock (3)
#define Tolerance (2)
char table[NumberOfLock][100];

int main(void)
{
    int SizeOfLock = 50;
    int i, j;
    int farmer[NumberOfLock];
    int master[NumberOfLock];
    freopen("combo.in","r",stdin);
    freopen("combo.out","w",stdout);

    scanf("%d", &SizeOfLock);
    if(SizeOfLock <= (Tolerance * 2 + 1))
    {
        int total = pow(SizeOfLock, NumberOfLock);
        printf("%d\n", total);
        return 0;
    }
    for(i = 0; i < NumberOfLock; i++)
    {
        scanf("%d", &farmer[i]);
    }
    for(i = 0; i < NumberOfLock; i++)
    {
        scanf("%d", &master[i]);
    }
    for(i = 0; i < NumberOfLock; i++)
    {
        for(j = 0; j < 100; j++)
        {
            table[i][j] = 0;
        }
    }
    for(i = 0; i < NumberOfLock; i++)
    {
        int start;
        if(farmer[i] - Tolerance <= 0)
        {
            start = SizeOfLock + farmer[i] - Tolerance;
        }
        else
        {
            start = farmer[i] - Tolerance;
        }
        j = start;
        int k;
        for(k = 0, j = start; k < (Tolerance * 2 + 1); k++)
        {
            table[i][j] = 1;
            if(j + 1 > SizeOfLock)
            {
                j = 1;
            }
            else
            {
                j++;
            }
        }
    }
    int total = pow((Tolerance * 2 + 1), NumberOfLock);
    int masterTotal = 1;
    for(i = 0; i < NumberOfLock; i++)
    {
        int counter = 0;
        int start;
        if(master[i] - Tolerance <= 0)
        {
            start = SizeOfLock + master[i] - Tolerance;
        }
        else
        {
            start = master[i] - Tolerance;
        }
        j = start;
        int k;
        for(k = 0, j = start; k < (Tolerance * 2 + 1); k++)
        {
            if(table[i][j] == 1)
            {
                counter ++;
            }
            if(j + 1 > SizeOfLock)
            {
                j = 1;
            }
            else
            {
                j++;
            }
        }
        masterTotal *= counter;
    }
    total = total + total - masterTotal;

    printf("%d\n", total);
    return 0;
}

