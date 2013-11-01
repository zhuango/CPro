/* 
ID: og192li1
PROG: beads
LANG: C
 */
#include<stdio.h>
#include<stdlib.h>

int main()
{
	char necklace[400];
	int *sum;
	int NP, i;
	int max = 0;
	char color;
	int head, tail, count = 0;

	FILE *fin = fopen("beads.in", "r");
	FILE *fout = fopen("beads.out", "w");
	


	fscanf(fin, "%d %s", &NP, necklace);
	color = necklace[0];

	i = 0;	
	while(necklace[i] == 'w') {i++;}
		color = necklace[i];
	for(i = 0; i < NP - 1; i++){
		if(necklace[i] != 'w' && necklace[i] != color) max = 1;
	}
	if(max == 0){ 
		max = NP; 
		fprintf(fout, "%d\n", max);
		exit(0);
	}
	for(i = 0; i < NP; i++) {
		if(necklace[i] != necklace[ (i + 1) % NP]) {
			head = i;
			tail = (i + 1) % NP;
			while(necklace[head] == 'w'){
				head --;
				if(head == -1) head = NP - 1;
				count++;
				if(head == tail) break;
			}
			color = necklace[head];
			while(necklace[head] == 'w' || necklace[head] == color) {
				head --;
				if(head == -1) head = NP - 1;
				count ++;
				if(head == tail) break;
			}
		//	head = i;

			while(necklace[tail] == 'w') {
				tail = (tail + 1) % NP;
				count++;
				if(head == tail) break;
			}
			color = necklace[tail];
			while(necklace[tail] == 'w' || necklace[tail] == color) {
				count++;
				if(head == tail) break;
				tail = (tail + 1) % NP;
			}
			if(max < count) max = count;
			count = 0;
		}
	}
	fprintf(fout, "%d\n", max);
	exit(0);
}
