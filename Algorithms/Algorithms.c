#include<stdio.h>
#include<stdlib.h>
#define N 5
int main(void){
	int a[N] = {5,4,3,2,1};
	int i = 2,j;
	int key;
	
	for(i = 1 ; i < N ; i++){
		
		//keep the current value into 'key'
		key = a[i];
		j = i-1;
		
		//if the value was bigger than 'key' value,then exchange the positio
		while(j >= 0 && key < a[j]){
			a[j+1] = a[j];
			j = j-1;
		}
		//insert the 'key'value
		a[j+1] = key;
	}
	//output the array
	for(i = 0 ; i < N ; i++){
		printf("%d ",a[i]);
	}
	printf("\n");

	return 0;
}
