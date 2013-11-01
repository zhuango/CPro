#include<stdio.h>
#include<stdlib.h>

typedef struct rice {
	int price;
	int heigh;
}rice;
void insert_sort(rice *Rice, int num);

int main(void)
{
	rice *Rice;
	int Case;
	int n, m, i;
	float max;
	scanf("%d", &Case);

	while(Case--) {
		scanf("%d %d\n", &n, &m);
		max = 0.0;

		Rice = malloc(sizeof(rice) * m);
		for(i = 0; i < m; i++)
			scanf("%d %d", &Rice[i].price, &Rice[i].heigh);
		insert_sort(Rice, m);

		for(i = 0; i < m; i++) {
			if(Rice[i].price * Rice[i].heigh >= n) {
				max += (float)n / Rice[i].price;
				break;
			} else {
				max += Rice[i].heigh;
				n -= Rice[i].price * Rice[i].heigh;
			}
		}
		printf("%.2f\n", max);
	}

	exit(EXIT_SUCCESS);
}

void insert_sort(rice *Rice, int num)
{
	rice cur;
	int pos;
	int i;

	for(i = 1; i < num; i++) {
		cur = Rice[i];
		pos = i - 1;

		while(pos >= 0 && Rice[pos].price > cur.price) {
			Rice[pos + 1] = Rice[pos];
			pos --;
		}
		Rice[pos + 1] = cur;
	}
}
