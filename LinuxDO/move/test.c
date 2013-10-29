#include<stdio.h>

int main(void)
{
	int c = 0;
	int k = 1;

	switch(k){
		default: c += k;
		case 2: c++;break;
		case 4: c+=2;break;
	}

	printf("c = %d k = %d\n",c,k);
	return 0;
}
