/*
ID: og192li1
ROG: skidesign
PROB: skidesign
LANG: C
 */

#include<stdio.h>
#include<math.h>

void quickSort(int arrays[], int start, int end);
int hills[1010];
const int DIFF = 17;

int main(void)
{
    freopen("skidesign.in", "r", stdin);
    freopen("skidesign.out", "w", stdout);

    int sizeOfInput = 0, i;
    int tmp = 0;
    int position = 1;
    int cost = 0;

    scanf("%d", &sizeOfInput);
    for(i = 1; i <= sizeOfInput; i++)
    {
        scanf("%d", &hills[i]);
    }
    hills[0] = -1;
    hills[sizeOfInput + 1] = -1;
    quickSort(hills, 1, sizeOfInput);
    while(hills[sizeOfInput] - hills[1] > DIFF)
    {
        hills[1] ++;
        hills[sizeOfInput] --;
        cost ++;

        position = 1;
        while(hills[position] == hills[1] && position <= sizeOfInput)
        {
            position ++;
        }
        tmp = hills[1];
        hills[1] = hills[position - 1];
        hills[position - 1] = tmp;

        position = sizeOfInput;
        while(hills[position] == hills[sizeOfInput] && position > 0)
        {
            position --;
        }
        tmp = hills[sizeOfInput];
        hills[sizeOfInput] = hills[position + 1];
        hills[position + 1] = tmp;
    }
    printf("%d\n", cost * cost * 2);

    return 0;
}

int partion(int array[], int start, int end)
{
    int mid = array[end];
    int mid_pos = start;
    int i;
    int tmp;

    for(i = start; i < end; i++)
    {
        if(array[i] < mid)
        {
            tmp = array[i];
            array[i] = array[mid_pos];
            array[mid_pos] = tmp;
            mid_pos++;
        }
    }
    tmp = array[end];
    array[end] = array[mid_pos];
    array[mid_pos] = tmp;

    return mid_pos;
}

void quickSort(int array[], int start, int end)
{
    int middle;
    if(start < end)
    {
        middle = partion(array, start, end);
        quickSort(array, start, middle - 1);
        quickSort(array, middle + 1, end);
    }
}

