static int Max(int a, int b)
{
	if(a > b) {
		return a;
	}
	return b;
}
static int MaxSubSum(const int array[], int left, int right)
{
	int MaxLeftSum, MaxRightSum;
	int MaxLeftBorderSum, MaxRightBorderSum;
	int LeftBorderSum, RightBorderSum;
	int Center, i;
	
	if(left == right) {
		if(array[left] > 0) {
			return array[left];
		}else {
			return 0;
		}
	}
	
	Center = (left + right) / 2;
	MaxLeftSum = MaxSubSum(array, left, Center);
	MaxRightSum = MaxSubSum(array, Center + 1, right);
	
	MaxLeftBorderSum = 0; LeftBorderSum = 0;
	for(i = Center; i >= left; i--) {
		LeftBorderSum += array[i];
		if(LeftBorderSum > MaxLeftBorderSum) {
			MaxLeftBorderSum = LeftBorderSum;
		}
	}
	
	MaxRightBorderSum = 0, RightBorderSum = 0;
	for(i = Center + 1; i <= right; i++) {
		RightBorderSum += array[i];
		if(RightBorderSum > MaxRightBorderSum) {
			MaxRightBorderSum = RightBorderSum;
		}
	}
	
	return Max(Max(MaxLeftSum, MaxRightSum), MaxLeftBorderSum + MaxRightBorderSum);
}

int MaxSequenceSumNlogN(const int array[], int N)
{
	return MaxSubSum(array, 0, N - 1);
}
