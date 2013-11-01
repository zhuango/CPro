#include<stdio.h>
#include<stdlib.h>

typedef struct Table {
	int start;
	int end;
}Table;

void sort(Table array[], int num);
int TanXin(Table *T, int c);
int getcorr(int a)
{
	if(a % 2)
		return (a + 1) / 2;
	else
		return a / 2;
}
int main(void)
{
	Table *T;
	int i, j, n, c, s, e, time;
	
	scanf("%d", &n);

	while(n--) {
		scanf("%d", &c);
		T = malloc(sizeof(Table) * c);
		for(i = 0; i < c; i++){
			scanf("%d %d", &s, &e);
			if(s > e){
				s = s ^ e;
				e = s ^ e;
				s = s ^ e;
			}
			T[i].start = getcorr(s);
			T[i].end = getcorr(e);
		}
		sort(T, c);	
		time = TanXin(T, c);
		printf("%d\n", time);
		free(T);
	}
}

//Sort
void sort(Table array[], int num)
{
	int insert_number,position;
	Table key;
	for(insert_number = 1; insert_number < num;
			insert_number ++){

		key = array[insert_number];			/* get the insert number */
		position = insert_number-1;			/* put the position that is before the current number */

		while(position >= 0 && array[position].end > key.end){
			array[position+1] = array[position];/* bigger than the insert number? then move the position */
			position = position-1;				/* compare next one */
		}
		array[position+1] = key;				/* insert the right position */
	}
}

int TanXin(Table *T, int c)
{
	int i, best = 0;
	int tmp, sum = 0;

	for(i = 0; i < c; i++) {
		if(T[i].end != 0 && T[i].start != 0){
			break;
		}
	}
	if(i == c) { return 0; }
	for(i = 0; i < c; i++) {
		if(T[i].start == 0 && T[i].end == 0)
			continue;
		tmp = T[best].end;
		if(tmp < T[i].start) {
			T[best].start = 0;
			T[best].end = 0;
			best = i;
		}
	}
	T[best].start = 0;
	T[best].end = 0;

	sum = sum + 10 + TanXin(T, c);
	return sum;
}
