/*
ID: og192li1
LANG: C
PROG: sprime
 * */
#include <stdio.h>
#include <math.h>
int primeNumber[10000];
int count = 0;

int IsPrimeNumber(int number);
int InitPrimeNumber();
void FindsPrime(int base, int number);

int main(void)
{
    freopen("sprime.in","r",stdin);
    freopen("sprime.out","w",stdout);

    int start;
    scanf("%d", &start);
    count = InitPrimeNumber();
    FindsPrime(0, start);
    return 0;
}

void FindsPrime(int base, int number)
{
        int currentNumber = base * 10;
        int i;
        for(i = 0; i < 10; i++)
        {
                if(number == 1)
                {
                        if(IsPrimeNumber(currentNumber + i))
                        {
                                printf("%d\n", currentNumber  + i);
                        }
                        else
                        {
                                continue;
                        }
                }
                else if(IsPrimeNumber(currentNumber + i))
                {
                        FindsPrime(currentNumber + i, number - 1);
                }
        }
}

int IsPrimeNumber(int number)
{
    int i;
    if(number == 0 || number == 1)
    {
            return 0;
    }
    for (i = 0; i < count; i++)
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

