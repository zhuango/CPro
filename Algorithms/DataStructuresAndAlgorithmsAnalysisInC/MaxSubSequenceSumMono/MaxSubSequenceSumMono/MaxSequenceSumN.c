int MaxSequenceSumN(int array[], int N)
{
	int ThisSum, result;
	int i;
	ThisSum = 0;
	result = 0;
	for(i = 0; i < N; i++) {
		ThisSum += array[i];
		if(ThisSum > result) {
			result = ThisSum;
		}else {
			ThisSum = 0;
		}
	}
}
