#include<stdio.h>
#include<stdlib.h>

typedef struct wood {
	short l;
	short w;
	short flag;
}wood;

void insert_sort(wood array[], int num);

int main(void)
{
	wood array[5000];
	int ml, mw;
	int T;
	int n;
	int mininum;
	int i, j;

	scanf("%d", &T);

	while(T--) {
		scanf("%d", &n);
		for(i = 0; i < n; i++){
			scanf("%d %d", &array[i].l, &array[i].w);
			array[i].flag = 0;
		}

		mininum = 0;
		insert_sort(array, n);

		i = 0;
		while(i < n) {
			ml = array[i].l;
			mw = array[i].w;
			array[i].flag = 1;

			for(j = i + 1; j < n; j++) {
				if(array[j].flag == 1) continue;
				if(array[j].l >= ml && array[j].w >= mw) {
					array[j].flag = 1;
					ml = array[j].l;
					mw = array[j].w;
				}
			}
			mininum ++;
			for(j = i; j < n; j++) {
				if(array[j].flag == 0) break;
			}
			i = j ;
		}
		
		printf("%d\n", mininum);
	}
	exit(EXIT_SUCCESS);
}

void insert_sort(wood array[], int num)
{
	wood cur;
	int pos;
	int i;

	for(i = 1; i < num; i++) {
		cur = array[i];
		pos = i - 1;

		while(pos >= 0 && array[pos].l >= cur.l) {
			if(array[pos].l == cur.l) { 
				if(array[pos].w <= cur.w){
					break;
				}
			}
			array[pos + 1] = array[pos];
			pos--;
		}	
		array[pos + 1] = cur;
	}
}
