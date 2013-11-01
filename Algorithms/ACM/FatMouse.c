#include<stdio.h>
#include<stdlib.h>
typedef struct Room {
	float Javabean;
	float CatFood;
	float per;
}Room;
void insertion_sort(Room array[], int num);

int main(void)
{
	Room *rooms;
	int i, m, n;
	float Sum;

	while(1) {
		scanf("%d %d", &m, &n);
		if(m == -1 && n == -1) break;
		rooms = malloc(sizeof(Room) * n);
		for(i = 0; i < n; i++) {
			scanf("%f %f", &rooms[i].Javabean, &rooms[i].CatFood);
			if(rooms[i].CatFood == 0)
				rooms[i].per = 1000.0;
			else if(rooms[i].Javabean == 0)
				rooms[i].per = 0;
			else rooms[i].per = rooms[i].Javabean / rooms[i].CatFood ;
		}
		insertion_sort(rooms, n);
		i = n - 1;
		while(m > 0 && i >= 0) {
			if(m >= rooms[i].CatFood) {
				Sum += rooms[i].Javabean;
				m = m - rooms[i].CatFood;
				i--;
			}else {

				Sum += rooms[i].Javabean * m / rooms[i].CatFood ;
				break;
			}
		}
		printf("%.3f\n", Sum);
		Sum = 0;
		free(rooms);
	}
}


void insertion_sort(Room array[], int num)
{
	int insert_number,position;
	Room key;
	for(insert_number = 1; insert_number < num;
			insert_number ++){

		key = array[insert_number];			/* get the insert number */
		position = insert_number-1;			/* put the position that is before the current number */

		/* go throught the array ,compare each one to the insert number */
		while(position >= 0 && array[position].per > key.per){
			array[position+1] = array[position];/* bigger than the insert number? then move the position */
			position = position-1;				/* compare next one */
		}
		array[position+1] = key;				/* insert the right position */
	}
}
