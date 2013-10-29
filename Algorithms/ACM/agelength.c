#include<stdio.h>
#include<ctype.h>
#include<string.h>

int main()
{
	char ch;
	int length[100];
	int i, sum = 0,  count = 0;
	float age;

	memset(length, 0, sizeof(length));

	while((ch = getchar()) != '\n') {
		i = 0;
		while( isalpha(ch) ) {
			ch = getchar();
			i ++;
		}
		length[count] = i;
		if(i != 0) count ++;
		if(ch == '\n') break;
	}
	for(i = 0; i < count; i++){
		sum += length[i];
	}
	printf("%.2f\n", (float) sum / (count));
	return 0;
}
