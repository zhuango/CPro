#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void get_next(const char *s, int *next)
{
	int i = 1, j = 0;
	next[0] = 0;
	next[1] = 1;
	printf("%s\n", s);
	while(i < strlen(s)){/* The ist element's next is ??? */
		if(j == 0 || s[j] == s[i]){
			j++;
			i++;
			next[i] = j;
		}else j = next[j];
	}

}


int main(void)
{
	const char a[] = "abaabcac";
	int next[8];
	int i;
	for(i = 0; i < 8; i++)
		next[i] = 0;

	get_next(a, next);

	for(i = 0; i < 8; i++)
		printf("%d ", next[i]);
	printf("\n");
	
	return 0;
}
