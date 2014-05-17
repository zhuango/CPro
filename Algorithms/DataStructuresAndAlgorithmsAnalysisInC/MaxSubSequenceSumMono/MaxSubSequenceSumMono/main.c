#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "MaxSequenceSumAlg.h"
int main(void)
{
    int array[11] = {1, 2, 3, -1, 3, -10, 2, 4, 2, -2222, 12};
    int result = MaxSubSequenceSumN2(array, 11);
    printf("%d\n", result);
    result = MaxSubSequenceSumN3(array, 11);
    printf("%d\n", result);
    exit(EXIT_SUCCESS);
}