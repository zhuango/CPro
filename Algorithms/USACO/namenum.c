/*
ID: og192li1
LANG: C
PROG: namenum
 * */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	char cha[9][3] = {'0', '0', '0',
		'A', 'B', 'C',
	       	'D', 'E', 'F', 
		'G', 'H', 'I',
		'J', 'K', 'L',
		'M', 'N', 'O',
		'P', 'R', 'S',
		'T', 'U', 'V',
		'W', 'X', 'Y'
	};
	char names[5000][14];
	char number[14];
	char *ch;
	int i, j, n, nname, state = 0;

	FILE *fin = fopen("namenum.in", "r");
	FILE *fout = fopen("namenum.out", "w");
	FILE *fin2 = fopen("dict.txt", "r");
	memset(names, 0, sizeof(names));
	memset(number, 0, sizeof(number));
	i = 0;
	while(1) {
		if(fgets(names[i], 14, fin2) == NULL) break;
		n = strlen(names[i]);
		names[i][n - 1] = '\0';
		i++;
	}

	fgets(number, 14, fin);
	n = strlen(number);
	number[n - 1] = '\0';
	nname = i - 1;
	for(i = 0; i < nname; i++) {
		if(strlen(names[i]) != n - 1) continue;
		j = 0;
		while(j < n - 1) {
			ch = cha[number[j] - '1'];
			if(names[i][j] != ch[0] && names[i][j] != ch[1] && names[i][j] != ch[2]){
				break;
			}
			j++;
		}
		if(j == n - 1){ fprintf(fout, "%s\n", names[i]); state = 1;}
	}

	if(state == 0) fprintf(fout, "NONE\n");

	exit(EXIT_SUCCESS);
}
