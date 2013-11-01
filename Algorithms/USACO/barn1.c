/*
ID: og192li1
PROG: barn1
LANG: C
 */
#include<stdio.h>
#include<stdlib.h>

#define MAX 210

void insert_sort(int array[], int num)
{
	int cur, tmp, pos, i;

	for(i = 1; i < num; i++) {
		cur = array[i];
		pos = i - 1;

		while(pos >= 0 && cur < array[pos]) {
			array[pos + 1] = array[pos];
			pos--;
		}
		array[pos + 1] = cur;
	}
}
int main()
{
	int stalls[MAX];
	int space[MAX];
	int mark[MAX];
	int i,j, M, S, C;
	int totalstall = 0;
	int tmp;

	FILE *fin = fopen("barn1.in", "r");
	FILE *fout= fopen("barn1.out", "w");

	fscanf(fin, "%d %d %d", &M, &S, &C);

	for(i = 0; i < MAX; i++){
		space[i] = 0;
		mark[i] = 0;
	}
	for(i = 0; i < C; i++)
		fscanf(fin, "%d", &stalls[i]);
	insert_sort(stalls, C);

	for(i = 1; i < C; i++)
		space[i] = stalls[i] - stalls[i - 1];
	insert_sort(space, C);

	for(i = C - 1; C - i <= M - 1 && i > 0;) {
		j = 1;
		while(j < C && C - i <= M - 1 && i >= 0) {
			if(stalls[j] - stalls[j - 1] == space[i]) {
				mark[j - 1] = 1;
				i--;
			}
			j++;
		}
	}
	tmp = 0;
	for(i = 0; i < C; i++) {
		if(mark[i] == 1) {
			totalstall += stalls[i] - stalls[tmp] + 1;
			tmp = i + 1;
		}
	}
	totalstall += stalls[C - 1] - stalls[tmp] + 1;

	fprintf(fout, "%d\n", totalstall);
	exit(EXIT_SUCCESS);
}
