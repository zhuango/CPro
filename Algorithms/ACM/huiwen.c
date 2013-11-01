#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

#define MAX 5000 + 10

int main(void)
{
	char buf[MAX], s[MAX];
	int i, j, k, n, m = 0, max = 0;
	fgets(buf, sizeof(s), stdin);
	n = strlen(buf);

	for(i = 0; i < n; i++)
		if(isalpha(buf[i])) s[m++] = toupper(buf[i]);

	for(i = 0; i < m; i++) {
		for(j = i; j < m; j++){
			int ok = 1;
			for(k = i; k <= j; k++)
				if(s[k] != s[j - k + i]) ok = 0;

			if(ok && j - i + 1 > max) max = j - i + 1;
		}
	}
	printf("%d\n", max);
	exit(EXIT_SUCCESS);
}

