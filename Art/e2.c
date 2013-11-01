#include<stdio.h>
#include<stdlib.h>
int getshare(int , int);
int count = 0;

int main(void)
{
	int num1 = 2, num2 = 4;
	int i;
	int result;
	for(num2 = 1; num2 < num1 + 1; num2++)
		result = getshare(num1, num2);

	printf("%d\n", count/num1);

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
		count ++;
		if(rest == 0)
			return num2;
		num1 = num2;
		num2 = rest;
	}
}

