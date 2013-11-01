/*
ID: og192li1
PROG: dualpal
LANG: C
*/
#include<stdio.h>
#include<stdlib.h>

int main()
{
	char number[100];
	int i, j, k;
	int tail = 100;
	int n, s;
	int time = 0, num, state, tmp, count = 0;

	FILE *fin = fopen("dualpal.in", "r");
	FILE *fout = fopen("dualpal.out", "w");

	fscanf(fin, "%d %d", &n, &s);
	for(i = s + 1, time = 0; time < n; i++) {
		count = 0;
		for(j = 2; j < 11; j++) {
			num = i;
			while(num != 0) {
				tmp = num % j;
				tail--;
				number[tail] = tmp + '0';
				num = num / j;
			}
			state = 1;
			for(k = tail; k < 100; k++)
				if(number[k] != number[99 - k + tail]){ state = 0;break;}
			if(state == 1) {
				count ++;
				if(count >= 2){
					count = 0;
					time++;
					tail = 100;
					fprintf(fout, "%d\n", i);
					break;
				}
			}
			tail = 100;
		}
	}

	exit(EXIT_SUCCESS);
}
