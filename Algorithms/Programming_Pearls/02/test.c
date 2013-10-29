#include<stdio.h>
#include<stdlib.h>

int mask = 0x80000000;
int main(void)
{
	FILE *t;
	int n;
	char buf[1024];
	if((t = fopen("a1", "w+")) == NULL){
		printf("dfasdfgad\n");
		exit(EXIT_FAILURE);
	}

	fprintf(t, "1\n");
	//rewind(t);
	fseek(t, 0l, SEEK_SET);
	if(fscanf(t, "%d\n", &n) == 0){
		printf("NiMaBi\n");
	}
	printf("%d %d\n", n, n & mask);
	exit(EXIT_SUCCESS);
}
