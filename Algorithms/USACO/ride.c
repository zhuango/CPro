/*
ID: og192li1
LANG: C
PROG: ride
*/
#include<stdio.h>
#include<stdlib.h>

int main()
{
	FILE *fin = fopen("ride.in", "r");
	FILE *fout = fopen("ride.out", "w");
	
	int sum1 = 1, sum2 = 1;
	char ch1, ch2;
	while(1) {
		fscanf(fin, "%c", &ch1);
		if(ch1 == '\n') break;
		else
			sum1 *= (ch1 - 'A' + 1);
	}
	while(1) {
		fscanf(fin, "%c", &ch2);
		if(ch2 == '\n') break;
		else
			sum2 *= (ch2 - 'A' + 1);
	}

	if(sum1 % 47 == sum2 % 47) {
		fprintf(fout, "GO\n");
	}else
		fprintf(fout, "STAY\n");

	exit(0);
}
