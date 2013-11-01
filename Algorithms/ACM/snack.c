#include<stdio.h>
#include<string.h>
#include<stdlib.h>


int main(void)
{
	int a[8][8];
	int n, index = 0;
	int x, y;

	scanf("%d", &n);
	
	memset(a, 0, sizeof(a));
	index = a[x = 0][y = n - 1] = 1;

	while(index < n * n) {
		while(x + 1 < n && !a[x + 1][y]) a[++x][y] = ++index;
		while(y - 1 >= 0 && !a[x][y - 1]) a[x][--y] = ++index;
		while(x - 1 >= 0 && !a[x - 1][y]) a[--x][y] = ++index;
		while(y + 1 < n && !a[x][y + 1]) a[x][++y] = ++index;
	}
	for(x = 0; x < n; x++) {
		for(y = 0; y < n; y++) {
			printf("%d ", a[x][y]);
		}
		printf("\n");
	}

	return 0;
}
