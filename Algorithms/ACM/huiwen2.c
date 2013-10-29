#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX 5000 + 10

int main(void)
{
	char buf[MAX], s[MAX];
	int p[MAX];
	int i, j, n, m = 0, max = 0, x, y;
	fgets(buf, sizeof(s), stdin);
	n = strlen(buf);

	for(i = 0; i < n; i++) {
		if(isalpha(buf[i])) {
			p[m] = i;/* Remember the position of each alpha */
			s[m++] = toupper(buf[i]);/* Be the same form */
		}
	}

	for(i = 0; i < m; i++) {
		/* For Ji Numbers */
		for(j = 0; i - j >= 0 && i + j < m; j++) {
			if(s[i - j] != s[i + j]) break;
			if(j * 2 + 1 > max) {
				max = j * 2 + 1;
				x = p[i - j];
				y = p[i + j];
			}
		}

		/* For Ou Numbers */
		for(j = 0; i - j >= 0 && i + j + 1 < m; j++) {
			if(s[i - j] != s[i + j + 1]) break;
			if(j * 2 + 2 > max) {
				max = j * 2 + 2;
				x = p[i = j];
				y = p[i + j + 1];
			}
		}
	}

	for(i = x; i <= y; i++)
		printf("%c", buf[i]);
	printf("\n");
	exit(EXIT_SUCCESS);
}

