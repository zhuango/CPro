#include<stdio.h>
#include<stdlib.h>
void sort(int array[], int num);

int main(void)
{
	int T[1000];
	int K[1000];
	int number, i, j, index = 0;
	int win = 0, fau = 0, fir = 0;
	while(1) {
		scanf("%d", &number);
		if(number == 0) break;
		for(i = 0; i < number; i++)
			scanf("%d", &T[i]);
		for(i = 0; i < number; i++)
			scanf("%d", &K[i]);
	
		sort(T, number);
		sort(K, number);
		
		win = 0;
		fir = 0;
		fau = 0;
		index = 0;
		
		for(i = number - 1, j = 0; 
			j < number && i >= 0; j++, i--) {
			if(T[j] > K[i]) win ++;
			else if(T[j] == K[i]) fir++; 
			else fau ++;
		}
		printf("%d\n", (win - fau) * 200);
	}
	return 0;
}

void sort(int array[], int num)
{
	int insert_number,position;
	int key;
	for(insert_number = 1; insert_number < num;
			insert_number ++){

		key = array[insert_number];			/* get the insert number */
		position = insert_number-1;			/* put the position that is before the current number */

		/* go throught the array ,compare each one to the insert number */
		while(position >= 0 && array[position] > key){
			array[position+1] = array[position];/* bigger than the insert number? then move the position */
			position = position-1;				/* compare next one */
		}
		array[position+1] = key;				/* insert the right position */
	}
}
