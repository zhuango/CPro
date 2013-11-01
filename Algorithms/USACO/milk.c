/*
ID: og192li1
LANG: C
PROG: milk
*/
#include<stdio.h>
#include<stdlib.h>

typedef struct famer {
	int pi;
	int ai;
}famer;

void insert_sort(famer famers[], int num)
{
	int pos;
	famer cur, tmp;
	int i;

	for(i = 1; i < num; i++) {
		cur = famers[i];
		pos = i - 1;

		while(pos >= 0 && cur.pi < famers[pos].pi) {
			famers[pos + 1] = famers[pos];
			pos --;
		}
		famers[pos + 1] = cur;
	}
}
int main()
{
	int N, M;
	int i;
	int mon = 0;
	famer famers[5100];

	FILE *fin = fopen("milk.in", "r");
	FILE *fout= fopen("milk.out", "w");

	fscanf(fin, "%d %d", &N, &M);

	for(i = 0; i < M; i++) {
		fscanf(fin, "%d %d\n", &famers[i].pi, &famers[i].ai);
	}

	insert_sort(famers, M);

	for(i = 0; i < M; i++) {
		if(N <= famers[i].ai) {
			mon += N * famers[i].pi;
			break;
		}else {
			N -= famers[i].ai;
			mon += famers[i].ai * famers[i].pi;
		}
	}
	
	fprintf(fout, "%d\n", mon);
	exit(EXIT_SUCCESS);
}
