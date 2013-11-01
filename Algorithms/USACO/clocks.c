#include<stdio.h>
#include<stdlib.h>

int opern[18];
int top = 0;
void openum(int move[9][10], int clock[9])
{
	int i, j;
	int pos = 0, time = 0, tmp = 0;
	for(i = 0; i < 9; i++) {
		for(j = 0; j < 9; j++)
			if(clock[j] == 12 && move[i][j] == 3)
				move[i][9] = 1;
	}
	for(i = 0; i < 9; i++)
		printf("%d ", clock[i]);
	printf("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
	pos = -1;
	for(i = 0; i < 9; i++) {
		if(move[i][9] == 1) continue;
		tmp = 0;
		for(j = 0; j < 9; j++) {
			if(move[i][j] == 3)
				tmp += clock[j];
		}
		printf("%d####%d############\n", tmp, i);
		if(tmp > time) {
			time = tmp;
			pos = i;
		}
	}
	printf("%d@@@@@%d@@@@@@@@@@@@@\n", pos, i);
	if(pos != -1) {
		for(j = 0; j < 9; j++)
			clock[j] += move[pos][j];
		opern[top] = pos;
		top++;
	}
	tmp = 0;
	for(j = 0; j < 9; j++)
		if(clock[j] != 12) tmp = 1;
	if(tmp == 1) openum(move, clock);
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

	for(i = 0; i < 9; i++)
		fscanf(fin, "%d", &clock[i]);
	for(i = 0; i < 9; i++)
		printf("%d ", clock[i]);
	printf("\n");

	openum(move, clock);

	for(i = 0; i < top; i++)
		printf("%d ", opern[i]);
	printf("\n");
	exit(EXIT_SUCCESS);
}
