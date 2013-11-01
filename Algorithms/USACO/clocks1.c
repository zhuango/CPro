/*
ID: og192li1
PROG: clocks
LANG: C
 */
#include<stdio.h>
#include<stdlib.h>

int opern[18];
int sum[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
int res[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
int restop = 0;
int top = 0;
int state = 0;
void openum(int move[9][10], int clock[9], int n)
{
	int i, j;
	int pos = 0, time = 0, tmp = 0;

	for(i = n; i < 9; i++) {
		for(j = 0; j < 9; j++) {
			sum[j] = sum[j] + move[i][j];
			if(sum[j] >= 12) sum[j] = sum[j] % 12;
			printf("%d ", sum[j]);
		}
		printf("$$$$$$$$$$$$$$%d$$$$%d$$$$\n", i, move[i][9]);

		opern[top] = i + 1;
		top++;
////////////////////////////////////////////////////////////////////
		tmp = 0;
		for(j = 0; j < 9; j++)
			if(sum[j] != clock[j]) tmp = 1;
		if(tmp == 0) {
			for(j = 0; j < top; j++)
				res[j] = opern[j];
			restop = top;
			state = 1;
			return ;
		}
///////////////////////////////////////////////////////////////////
//		tmp = 0;
//		for(j = 0; j < 9; j++)
//			if(sum[j] > clock[j]) tmp = 1;
//		if(tmp == 0)
		move[i][9] ++;
		if(move[i][9] >= 3) {
			for(j = 0; j < 9; j++) {
				sum[j] -= move[i][j];
				if(sum[j] < 0)
					sum[j] = 12 + sum[j];
				printf("%d ", sum[j]);
			}
			printf("#################%d###%d###\n", i, move[i][9]);
			top --;
			opern[top] = 0;
			return ;
		}
		openum(move, clock, i);
		move[i][9] --;
		top --;
		opern[top] = 0;
		for(j = 0; j < 9; j++) {
			sum[j] -= move[i][j];
			if(sum[j] < 0)
				sum[j] = 12 + sum[j];
			printf("%d ", sum[j]);
		}
			printf("#################%d###%d###\n", i, move[i][9]);
	}
}
int main()
{
	int clock[9];
	int move[9][10] =  {3, 3, 0, 3, 3, 0, 0, 0, 0,0,
			   3, 3, 3, 0, 0, 0, 0, 0, 0,0,
			   0, 3, 3, 0, 3, 3, 0, 0, 0,0,
			   3, 0, 0, 3, 0, 0, 3, 0, 0,0,
			   0, 3, 0, 3, 3, 3, 0, 3, 0,0,
			   0, 0, 3, 0, 0, 3, 0, 0, 3,0,
			   0, 0, 0, 3, 3, 0, 3, 3, 0,0,
			   0, 0, 0, 0, 0, 0, 3, 3, 3,0,
			   0, 0, 0, 0, 3, 3, 0, 3, 3,0};
	int i;
	FILE *fin = fopen("clocks.in", "r");
	FILE *fout = fopen("clocks.out", "w");

	for(i = 0; i < 9; i++){
		fscanf(fin, "%d", &clock[i]);
		clock[i] = 12 - clock[i];
		printf("%d ", clock[i]);
	}
	printf("\n");

	openum(move, clock, 0);

	for(i = 0; i < restop - 1; i++){
		fprintf(fout, "%d ", res[i]);
		printf("%d ", res[i]);
	}
	fprintf(fout, "%d\n", res[restop - 1]);
	printf("%d\n", res[restop - 1]);
	exit(EXIT_SUCCESS);
}
