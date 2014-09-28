/*
ID: og192li1
LANG: C
PROG: pprime
 * */
#include <stdio.h>
#include <math.h>
int primeNumber[10000];
int count = 0;

int GetMirror(int number, int *length);
int IsPrimeNumber(int number);
int InitPrimeNumber();

int main(void)
{
    freopen("pprime.in","r",stdin);
    freopen("pprime.out","w",stdout);

    int start = 5, end = 500;
    scanf("%d %d", &start, &end);
    int i;
    int printed = 0;
    int length = 0;
    count = InitPrimeNumber();
    for (i = start; i <= end; i++)
    {
        if(i == GetMirror(i, &length))
        {
            if((length % 2) == 0 && i != 11)
            {
                    int temp = length;
                    i = pow(10, length);
                    continue;
            }
            if (IsPrimeNumber(i))
            {
                printf("%d\n", i);
            }
        }
    }
    return 0;
}

int IsPrimeNumber(int number)
{
    int i;
    for (i = 0; i < count; i++)
    //for (i = 2; i <= pow((long double)number, (long double)1); i++)
    {
        if(primeNumber[i] >= number)
        {
            break;
        }
        if (0 == (number % primeNumber[i]))
        {
            return 0;
        }
    }
    return 1;
}
int GetMirror(int number, int *length)
{
    int mirror = 0;
    int len = 1;
    while (number / 10)
    {
        mirror = (mirror + (number % 10)) * 10;
        number = number / 10;
        len++;
    }
    mirror = mirror + (number % 10);
    *length = len;
    return mirror;
}

int InitPrimeNumber()
{
        int i, j;
        primeNumber[0] = 2;
        int counter = 1;
        for(i = 3; i <= 10000; i++)
        {
                for(j = 2; j <= (int)sqrt((double)i); j++)
                {
                        if((i % j) == 0)
                        {
                                continue;
                        }
                } 
                primeNumber[counter++] = i;
        }
        return counter;
}
