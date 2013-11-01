#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(void)
{
	int Astart, Bstart;
	int Astep, Bstep;
	int Length;
	int times;

	printf("Please inout your numbers: \n");
	scanf("%d %d %d %d %d", &Astart, &Bstart, &Astep, &Bstep, &Length);

	times = OuJiLiDeEx(Astart, Bstart, Astep, Bstep, Length);


