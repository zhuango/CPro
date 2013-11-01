#include<stdio.h>
#include<stdlib.h>

typedef struct wood {
	short l;
	short w;
}wood;

void insert_sort(wood array[], int num, int w);
int gettime(wood array[], int num, int w);

int main(void)
{
	wood array[5000];
	int T;
	int n;
	int time1, time2;
	int mininum;
	int i;

	scanf("%d", &T);

	while(T--) {
		scanf("%d", &n);
		time1 = 1;
		time2 = 1;
		for(i = 0; i < n; i++)
			scanf("%d %d", &array[i].l, &array[i].w);

		insert_sort(array, n, 1);
		time1 += gettime(array, n, 1);

		insert_sort(array, n, 0);
		time2 += gettime(array, n ,0);

		if(time2 >= time1)
			mininum = time1;
		else
			mininum = time2;

		printf("%d\n", mininum);
	}
	exit(EXIT_SUCCESS);
}

int gettime(wood array[], int num, int w)
{
	int i;
	int time = 0;

	if(w == 1)
		for(i = 1; i < num; i++) {
			if(array[i].w < array[i - 1].w)
				time++;
		}
	else if(w == 0)
		for(i = 1; i < num; i++) {
			if(array[i].l < array[i - 1].l)
				time++;
		}

	return time;
}
void insert_sort(wood array[], int num, int w)
{
	wood cur;
	int pos;
	int i;

	for(i = 1; i < num; i++) {
		cur = array[i];
		pos = i - 1;

		if(w == 1)
			while(pos >= 0 && array[pos].l >= cur.l) {
				if(array[pos].l == cur.l) { 
					if(array[pos].w <= cur.w){
						break;
					}
				}
				array[pos + 1] = array[pos];
				pos --;
			}
		else if(w == 0)
			while(pos >= 0 && array[pos].w >= cur.w) {
				if(array[pos].w == cur.w) { 
					if(array[pos].l <= cur.l){
						break;
					}
				}
				array[pos + 1] = array[pos];
				pos --;
			}
			
		array[pos + 1] = cur;
	}
}
