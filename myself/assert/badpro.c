#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

int main(void){

	FILE *fp;

	printf("%d\n",sizeof(fp));
	printf("%d\n",sizeof(int));
	fp = fopen("foo_bar","w");
	assert(fp);
	fclose(fp);

	fp = fopen("bar_baz","r");
	assert(fp);
	fclose(fp);

	exit(EXIT_FAILURE);

	return 0;
}
