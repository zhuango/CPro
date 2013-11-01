/*
ID: og192li1
PROG: palsquare
LANG: C
 */
#include<stdio.h>
#include<stdlib.h>

int main()
{
	char number[100];
	char ora[100];
	int i,j, n, state;
	int sqn, tmp;
	int tailo = 100, tail = 100;

	FILE *fin = fopen("palsquare.in", "r");
	FILE *fout= fopen("palsquare.out", "w");

	fscanf(fin, "%d", &n);

	for(i = 1;i < 300; i++) {
		sqn =  i;
		while(sqn != 0) {
			tmp = sqn % n;
			if(tmp >= 10) {
				tailo--;
				ora[tailo] = tmp - 10 + 'A';
			}else {
				tailo--;
				ora[tailo] = tmp + '0';
			}
			sqn = sqn / n;
		}

		sqn = i * i;
		while(sqn != 0) {
			tmp = sqn % n;
			if(tmp >= 10) {
				tail--;
				number[tail] = tmp - 10 + 'A';
			}else {
				tail--;
				number[tail] = tmp + '0';
			}
			sqn = sqn / n;
		}

		state = 1;
		for(j = tail; j < 100; j++)
			if(number[j] != number[99 - j + tail]) state = 0;

		if(state == 1){
			for(j = tailo; j < 100; j++)
			       	fprintf(fout, "%c", ora[j]);
			fprintf(fout, " ");
			for(j = tail; j < 100; j++)
				fprintf(fout, "%c", number[j]);
			fprintf(fout, "\n");
		}
		tailo = 100;
		tail = 100;
	}

	exit(EXIT_SUCCESS);
}
