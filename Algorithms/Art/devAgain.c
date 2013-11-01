#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int m, n;

	scanf("%d %d", &m, &n);
	for(;;){
		m = m % n;
		if(m == 0) break;
		
		n = n % m;
		if(n == 0) {n = m; break;}
	}
	printf("%d\n", n);

	return 0;
}
