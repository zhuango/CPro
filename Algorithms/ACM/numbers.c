#include<stdio.h>

void insert_sort(int array[], int num);

int main(void)
{
	int i, j, k, m;
	int array[4];
	int Array[24], count = 0;

	while(1) {
		for(i = 0; i < 4; i++)
			scanf("%d", &array[i]);
		if(array[0] == 0 &&
			array[1] == 0 &&
			array[2] == 0 &&
			array[3] == 0) break;

		count = 0;

		for(i = 0; i < 24; i++) 
			Array[i] = 0;

		for(i = 0; i < 4; i++) {

			if(array[i] == 0) continue;

			for(j = 0; j < 4; j++) {
				if(j == i) continue;

				for(k = 0; k < 4; k++) {
					if(k == i || k == j) continue;

					for(m = 0; m < 4; m++) {
						if(m == i || m == j || m == k) continue;
						Array[count] = array[i] * 1000 + array[j] * 100 + array[k] * 10 + array[m];
						count++;
					}
				}
			}
		}
		insert_sort(Array, 24);

		for(i = 0; i < 24; i++){
			if(Array[i] / 1000 == 0) continue;
			if(i != 0 && Array[i] == Array[i - 1]) continue;
			
			if(i != 23 && Array[i] / 1000 != Array[i + 1] / 1000) {printf("%d\n", Array[i]); continue;}
			printf("%d ",  Array[i]);

		}

	}

	return 0;
}
void insert_sort(int array[], int num)
{
	int cur;
	int pos;
	int i;

	for(i = 1; i < num; i++) {
		cur = array[i];
		pos = i - 1;

		while(pos >= 0 && array[pos] > cur) {
			array[pos + 1] = array[pos];
			pos --;
		}
		array[pos + 1] = cur;
	}
}
