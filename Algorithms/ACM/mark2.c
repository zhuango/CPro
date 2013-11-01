#include<stdio.h>
void insert_sort(float array[], int num);

int main()
{
	float mark[100];
	int i, j, k, m, max = 0;
	int rep;
	int pos[100];

	for(i = 0; i < 100; i++) {
		scanf("%f", &mark[i]);
		if(mark[i] < 0) break;
	}
	m = i;
	insert_sort(mark, m);
	i = 0;
	while(i < m) {
		rep = i;/* Save the first position */
		while(mark[rep] == mark[i] && i < m)
			i++;
		pos[rep] = i - rep;
		if(pos[rep] > max ) max = pos[rep];
	}
	
	for(i = 0; i < m; i++)
		if(pos[i] == max) printf("%f ", mark[i]);
	printf("\n");

	return 0;
}

void insert_sort(float array[], int num)
{
	float cur;
	int pos;
	int i;

	for(i = 0; i < num; i++) {
		cur = array[i];
		pos = i - 1;

		while(pos >= 0 && array[pos] > cur) {
			array[pos + 1] = array[pos];
			pos --;
		}

		array[pos + 1] = cur;
	}
}
