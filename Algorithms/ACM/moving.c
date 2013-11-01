#include<stdio.h>
#include<stdlib.h>

typedef struct Table {
	int start;
	int end;
}Table;

int getcorr(int a)
{
	if(a % 2)
		return (a + 1) / 2;
	else
		return a / 2;
}
int main(void)
{
	int T[201];
	int i, j, n, c, s, e, time, max;
	
	scanf("%d", &n);

	while(n--) {
		scanf("%d", &c);
		for(i = 0; i < 201; i++)
			T[i] = 0;
		for(i = 0; i < c; i++){
			scanf("%d %d", &s, &e);
			if(s > e){
				s = s ^ e;
				e = s ^ e;
				s = s ^ e;
			}
			for(j = getcorr(s); j <= getcorr(e); j++)
				T[j]++;
		}
		time = T[0];
		for(i = 0; i < 201; i++)
			if(time < T[i]) time = T[i];
		printf("%d\n", time * 10);
	}
}

