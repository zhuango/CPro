#include<stdio.h>
#include<stdlib.h>

int queueInRow[10];
int n = 4;

int place(int k, int i) {
	int j = 1;
	int result = 1;

	while(j < k) {
		if(queueInRow[j] == i ||
				abs(queueInRow[j] - i) == abs(j - k)) {
			result = 0; 
			return result;
		}
		else
			result = 1;
		j++;
	}
	return result;
}
void print(int queue[]) {
	int i;
	for(i = 1; i <= n; i++)
		printf("%d ", queueInRow[i]);
	printf("\n");
}
void queue(int k) {
	int i;
	int result;

	for(i = 1; i <= n; i++) {
		result = place(k, i);
		if(result == 1) {
			queueInRow[k] = i;
			if(k == n) print(queueInRow);
			queue(k + 1);
		}
	}
}
int main(void)
{
	int i;
	for(i = 0; i <= n; i++)
		queueInRow[i] = 0;
	queue(1);
	exit(EXIT_SUCCESS);
}
