#include<stdio.h>
#include<stdlib.h>
int getshare(int , int);

int main(void)
{
	int num1 = 2166, num2 = 6099;
	int i;
	int result;
	result = getshare(num1, num2);

	printf("%d\n", result);

	return 0;
}

int getshare(num1, num2)
{
	int rest;
	if(num2 > num1){/* be sure that num1 > num2 */
		num2 = num1 + num2;
		num1 = num2 - num1;
		num2 = num2 - num1;
	}
	while(1){
		rest = num1 % num2;
		if(rest == 0)
			return num2;
		num1 = num2;
		num2 = rest;
	}
}

