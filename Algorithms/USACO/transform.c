/*
ID: og192li1
PROG: transform
LANG: C
 */
#include<stdio.h>
#include<stdlib.h>

int main()
{
	char cha[7][7];
	char cha1[7][7];
	int i, j, n;
	int pos1, pos2, tmp;
	int number;

	FILE *fin = fopen("transform.in", "r");
	FILE *fout = fopen("transform.out", "w");

	fscanf(fin, "%d", &n);
	fgetc(fin);
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			fscanf(fin, "%c", &cha[i][j]);
		}
		fgetc(fin);
	}
	for(i = 0; i < n; i++) {
		for(j = 0; j < n; j++){
			fscanf(fin, "%c", &cha1[i][j]);
		}
		fgetc(fin);
	}
	/* #1 */
	number = 1;
	for(i = 0; i < n; i++)
		for(j = 0; j < n; j++)
			if(cha[i][j] != cha1[j][n - 1 - i]) number = 0;
	if(number != 0) goto result;

	/* #2 */
	number = 2;
	for(i = 0; i < n; i++)
		for(j = 0; j < n; j++)
			if(cha[i][j] != cha1[n - 1 - i][n - 1 - j]) number = 0;
	if(number != 0) goto result;
	
	/* #3 */
	number = 3;
	for(i = 0; i < n; i++)
		for(j = 0; j < n; j++)
			if(cha[i][j] != cha1[n - 1 - j][i]) number = 0;
	if(number != 0) goto result;
	
	/* #4 */
	number = 4;
	for(i = 0; i < n; i++)
		for(j = 0; j < n; j++)
			if(cha[i][j] != cha1[i][n - 1 -j]) number = 0;
	if(number != 0) goto result;

	/* #5 */
	number = 5;
	for(i = 0; i < n; i++)
		for(j = 0; j < n; j++) {
			pos1 = i;
			pos2 = n - 1 - j;
			tmp = pos1;
			pos1 = pos2;
			pos2 = n - 1 - tmp;

			if(cha[i][j] != cha1[pos1][pos2]) number = 0;
		}
	if(number != 0) goto result;

	number = 5;
	for(i = 0; i < n; i++)
		for(j = 0; j < n; j++) {
			pos1 = i;
			pos2 = n - 1 - j;
			tmp = pos1;
			pos1 = n - 1 - pos1;
			pos2 = n - 1 - pos2;
			if(cha[i][j] != cha1[pos1][pos2]) number = 0;
		}
	if(number != 0) goto result;
	
	number = 5;
	for(i = 0; i < n; i++)
		for(j = 0; j < n; j++) {
			pos1 = i;
			pos2 = n - 1 - j;
			tmp = pos1;
			pos1 = n - 1 - pos2;
			pos2 = tmp;
			if(cha[i][j] != cha1[pos1][pos2]) number = 0;
		}
	if(number != 0) goto result;
	/* #6 */
	number = 6;
	for(i = 0; i < n; i++)
		for(j = 0; j < n; j++)
			if(cha[i][j] != cha1[i][j]) number = 0;
	if(number != 0) goto result;



	number = 7;
result:
	fprintf(fout, "%d\n", number);
	exit(EXIT_SUCCESS);
}
