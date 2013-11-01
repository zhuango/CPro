/*
ID: og192li1
PROG: milk2
LANG: C
 */

#include<stdio.h>
#include<stdlib.h>

typedef struct node {
	int start;
	int end;
}node;

void insert_sort(node famers[], int sum)
{
	int i, tmp;
	int pos;
	node cur;

	for(i = 1; i < sum; i++) {
		cur = famers[i];
		pos = i - 1;

		while(pos >= 0 && famers[pos].start > cur.start) {
			famers[pos + 1] = famers[pos];
			pos --;
		}
		famers[pos + 1] = cur;
	}
}
int main()
{
	int n, i, start, end;
	node famers[5000];
	int lm = 0, ld = 0;
	
	FILE *fin = fopen("milk2.in", "r");
	FILE *fout = fopen("milk2.out", "w");
	
	fscanf(fin, "%d", &n);

	for(i = 0; i < n; i++)
		fscanf(fin, "%d %d", &famers[i].start, &famers[i].end);
	insert_sort(famers, n);

	start = famers[0].start;
	end = famers[0].end;
	for(i = 1; i < n; i++) {
		if(end < famers[i].start) {
			if(ld < famers[i].start - end)
				ld = famers[i].start - end;
			if(end - start > lm)
				lm = end - start;
			start = famers[i].start;
			end = famers[i].end;
		}else if(end < famers[i].end)
			end = famers[i].end;
	}
	if(end - start > lm) lm = end - start;

	fprintf(fout, "%d %d\n", lm, ld);

	exit(EXIT_SUCCESS);
}

