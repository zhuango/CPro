#include<stdio.h>
#include<stdlib.h>
#include<string.h>

const int MAXD = 20;
int s[1 << 20];

int main()
{
	int D, I;

	while(scanf("%d %d", &D, &I) == 2) {
		if(D == 0 && I == 0) break;
		memset(s, 0, sizeof(s));
		int k, i, n = (1 << D) - 1;

		for(i = 0; i < I; i++) {
			k = 1;
			for(;;) {
				s[k] = !s[k];
				k = s[k] ? k * 2 : k * 2 + 1;
				if(k > n) break;
			}
		}
		printf("%d\n", k / 2);
	}

	exit(EXIT_SUCCESS);
}
