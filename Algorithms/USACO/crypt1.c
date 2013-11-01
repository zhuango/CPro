/**
ID: og192li1
PROG: crypt1
LANG: C
 */

#include<stdio.h>
#include<stdlib.h>

int main()
{
	int array[10];
	int mark[10];
	int i, j, k, l, m, n, tmp, m1, m2;
	int number = 0;

	FILE *fin = fopen("crypt1.in", "r");
	FILE *fout = fopen("crypt1.out", "w");

	fscanf(fin, "%d", &n);
	for(i = 0; i < 10; i++)
		mark[i] = 0;
	for(i = 0; i < n; i++){
		fscanf(fin, "%d", &array[i]);
		mark[array[i]] = 1;
	}
	for(i = 0; i < n; i++)
		for(j = 0; j < n; j++)
			for(k = 0; k < n; k++){
				for(l = 0; l < n; l++)
					for(m = 0; m < n; m++) {
						m1 = array[i] * 100 + array[j] * 10 + array[k];
						m2 = array[l] * 10 + array[m];
						if(m1 * array[m] >= 1000 || m1 * array[m] < 100) continue;
						if(m1 * array[l] >= 1000 || m1 * array[l] < 100) continue;
						if(m1 * m2 >= 10000 || m1 * m2 < 1000) continue;

						tmp = m1 * array[m];
						while(mark[tmp % 10] == 1)
							tmp = tmp / 10;
						if(tmp != 0) continue;
						
						tmp = m1 * array[l];
						while(mark[tmp % 10] == 1)
							tmp = tmp / 10;
						if(tmp != 0) continue;
						
						tmp = m1 * m2;
						while(mark[tmp % 10] == 1)
							tmp = tmp / 10;
						if(tmp != 0) continue;

						number ++;
					}
			}

	fprintf(fout, "%d\n", number);
	exit(EXIT_SUCCESS);
}
