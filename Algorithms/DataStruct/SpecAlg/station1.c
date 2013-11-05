#include<stdio.h>
#include<stdlib.h>
#define N 6
/* Come in station time */
int start[2] = {2, 4};
/* Go out the station */
int finsh[2] = {3, 2};
/* Time on one station */
int timeOnStation[2][N] = {
	7, 9, 3, 4, 8, 4,
	8, 5, 6, 4, 5, 7};
/* Move to other line time */
int timeToMove[2][N - 1] = {
	2, 3, 1, 3, 4,
	2, 1, 2, 2, 1};
/* The fast time*/
int route[2][N];
/* Line record */
int whitchLine[2][N + 1];

int main(void)
{
	int i, j;
	int Fast, Maxl;
	/* The first station of each lines*/	
	route[0][0] = start[0] + timeOnStation[0][0];
	route[1][0] = start[1] + timeOnStation[1][0];
	printf("route[0][0] = %d, route[1][0] = %d\n",route[0][0], route[1][0]);
	/* The Fastest time of each stations of each lines */
	for(j = 1; j < N; j++){
		if(route[0][j - 1] + timeOnStation[0][j] <=
				route[1][j - 1] + timeOnStation[0][j] + timeToMove[1][j - 1]){
			/* Come from first line */
			route[0][j] = route[0][j - 1] + timeOnStation[0][j];
			whitchLine[0][j] = 1;
		}else{
			/* Come from second line */
			route[0][j] = route[1][j - 1] + timeOnStation[0][j] + timeToMove[1][j - 1];
			whitchLine[0][j] = 2;
		}
		if(route[1][j - 1] + timeOnStation[1][j] <= 
				route[0][j - 1] + timeOnStation[1][j] + timeToMove[0][j - 1]){
			/* Come from second line */
			route[1][j] = route[1][j - 1] + timeOnStation[1][j];
			whitchLine[1][j] = 2;
		}else{
			/* Come from first line */
			route[1][j] = route[0][j - 1] + timeOnStation[1][j] + timeToMove[0][j - 1];
			whitchLine[1][j] = 1;
		}
		printf("route[0][%d] = %d, route[1][%d] = %d\n", j, route[0][j], j, route[1][j]);
	}
	/* Go out lines */
	if(route[0][N - 1] + finsh[0] <= route[1][N - 1] + finsh[1]){
		/* Go out from first line */
		Fast = route[0][N - 1] + finsh[0];
		Maxl = 1;
	}else{
		/* Go out from second line */
		Fast = route[1][N - 1] + finsh[1];
		Maxl = 2;
	}

	for(j = 1; j < N; j++)
		printf("l[1][%d] = %d, l[0][%d] = %d\n", j, whitchLine[1][j], j, whitchLine[0][j]);
	printf("Fastest: %d\n", Fast);
	/* Print thr map */
	void print(int, int);
	print(Maxl-1, N - 1);
	printf("Station %d on line %d\n", N ,Maxl);
	exit(EXIT_SUCCESS);
}
void print(int Maxl, int i)
{
	Maxl = whitchLine[Maxl][i] - 1;
	if(i > 1)
		print(Maxl, i - 1);
	printf("Station %d on line %d\n", i, Maxl + 1);
}
