#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXSIZE 1024

void fail(char *p, int f[])
{
	int m = strlen(p);
	int i, j;
	f[0] = -1;

	for(j = 1; j < m - 1; j++) {
		i = f[j - 1];

		while(p[j] != p[i - 1] && i > 0)
			i = f[i];

		if(p[j] == p[i + 1]) 
			f[i] = i + 1;
		else
			f[j] = -1;
	}
}

char *fastfind(char *s, char *p)
{
	int length1 = strlen(s);
	int length2 = strlen(p);
	int f[MAXSIZE];
	int n = 0, m = 0;

	fail(p, f);
	while(n < length1 && m < length2) {
		printf("%c %c\n", s[n], p[m]);
		if(s[n] == p[m]) {n++; m++;}
		else if(m == 0) n++;
		else m = f[m] + 1;
	}
	//not match, then return '\0'
	if(m < length2) {return &s[n];}

	return &s[n - m];
}

int main()
{
	//char *s = "abcabcbcaabcdabcd";
	//char *s =  "weeeeabcee";
	//char *s = "abcdsfewfeadgdg";
	//char *s = "abcddsfgsdgfabcd";
	char *s = "sdfadfabcddgfsabcdfdggdg";
	char *p = "abcd";
	char *result = s;
	int time = 0;
	int plength = strlen(p);
	int slength = strlen(s);
	int i;

	while( (result + plength) <= s + slength) {
		result = fastfind(result, p);
		if(*result != '\0') time++;
		printf("%s\n", result);
		 result = result + plength;
	}

	printf("%d\n", time);

	exit(EXIT_SUCCESS);
}
