#include<stdio.h>

int heap_size = 10;

PARENT(int i){
	if( i%2 == 0) return i/2-1;
	else return i/2;
}

LEFT(int i){
	return 2*i+1;
}

RIGHT(int i){
	return 2*i + 2;
}

void MAX_HEAPIFY(int a[],int n, int i){
	int l = LEFT(i);
	int r = RIGHT(i);
	int large = 0;
	int tmp;
	int e;
	
	for(e=0;e<10;e++){
		printf("%d ",a[e]);
	}
	printf("\n");

	if (l <= heap_size && a[l] > a[i])
		large = l;
	else 
		large = i;

	if (r <= heap_size && a[r] > a[large])
		large = r;

	if(large != i){
		tmp = a[i];
		a[i] = a[large];
		a[large] = tmp;
		MAX_HEAPIFY(a,n,large);
	}

}

//build max heap
BUILD_MAX_HEAP(int a[] , int n){
	 int i;
	 for(i=heap_size/2 ; i >= 0 ; i--){
	 	MAX_HEAPIFY(a,n,i);
	 }
	
}
HEAPSORT(int a[] , int n){
	int i;
	int tmp;
	heap_size = heap_size-1;
	BUILD_MAX_HEAP(a,n);
	for(i = heap_size;i >= 1;i--){
		tmp = a[0];
		a[0] = a[i];
		a[i] = tmp;
		heap_size = heap_size - 1;
		MAX_HEAPIFY(a,n,0);
	}
}
int main(void){
	int a[10]={4,1,3,2,16,9,10,14,8,7};
	int i;
	HEAPSORT(a,10);
	for(i=0;i<10;i++){
		printf("%d ",a[i]);
	}
	printf("\n");

	return 0;
	
}
