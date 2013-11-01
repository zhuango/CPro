/*
ID: og192li1
PROG: friday
LANG: C
 */

#include<stdio.h>
#include<stdlib.h>

int main()
{
	int monthtable[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int res[8] = {0, 0, 0, 0, 0, 0, 0, 0};
	int sumdays = 0;
	int NY;
	int i, j;

    	FILE *fin  = fopen ("friday.in", "r");
	FILE *fout = fopen ("friday.out", "w");

	fscanf(fin, "%d", &NY);

	for(i = 0; i < NY; i++) {
		if((1900 + i) % 100 != 0 && (1900 + i) % 4 == 0)
			monthtable[2] = 29;
		if((1900 + i) % 400 == 0) 
			monthtable[2] = 29;

		for(j = 1; j < 13; j++) {
			res[ (sumdays + 13) % 7 ] += 1;
			sumdays += monthtable[j];
		}
		monthtable[2] = 28;
	}

	fprintf(fout, "%d ", res[6]);
	fprintf(fout, "%d ", res[0]);
	fprintf(fout, "%d ", res[1]);
	fprintf(fout, "%d ", res[2]);
	fprintf(fout, "%d ", res[3]);
	fprintf(fout, "%d ", res[4]);
	fprintf(fout, "%d\n", res[5]);

	exit(0);
}
