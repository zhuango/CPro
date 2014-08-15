#include <stdio.h>
#include <stdlib.h>

int MaxSubSequenceSumN3(const int A[], int N)
{
	int ThisSum, result = 0, i, j, k;
	
	for(i = 0; i < N; i++) {
		for(j = i; j < N; j++) {
			ThisSum = 0;
			for(k = i; k <= j; k++) {
				ThisSum += A[k];
			}

			if(ThisSum > result)
				result = ThisSum;
		}
	}

	return result;
}
