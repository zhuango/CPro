#include <stdio.h>
#include <stdlib.h>

int MaxSubSequenceSumN2(const int A[], int N)
{
	int ThisSum, result = 0, i, j;
	
	for(i = 0; i < N; i++) {
		ThisSum = 0;
		for(j = i; j < N; j++) {
			ThisSum += A[j];
			if(ThisSum > result)
				result = ThisSum;
		}
	}

	return result;
}
