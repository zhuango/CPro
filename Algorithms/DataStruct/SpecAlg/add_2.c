/*******************************************
 * Book			: Introduction to Algorithms
 * Page			: 12
 * Algorithms	: add as 0 or 1
 * ......(Fuck ! My English is pool)
 *******************************************/
#include<stdio.h>

#define NUM 5

/*the function use to add*/
void add(int add1[], int add1_num, int add2[], int add2_num, int result[], int result_num);

int main(void)
{
	int i;								/* use to print */
	int add1[NUM] = {1,1,1,1,1};		/* first add element */
	int add2[NUM] = {1,1,1,1,1};		/* second add element */
	int result[NUM+1] = {0,0,0,0,0,0};	/* the result */

	/* do the add */
	add(add1, NUM, add2, NUM, result, NUM);

	/* print the result */
	for(i = 0; i < NUM+1; i++)
		printf("%d ",result[i]);
	printf("\n");

	return 0;
}

/*****************************************************************
 * add		 : add two element witch are 2 JinZhi
 * add1		 : the first element
 * add1_num  : length of add1
 * add2		 : the second element
 * add2_num  : length of add2
 * result	 : the result
 * result_num: the length of result, but here equa to the add2_num
 * ***************************************************************/
void add(int add1[], int add1_num, int add2[], int add2_num, int result[], int result_num)
{
	int bit_count;		/* count the bit for the adding */
	int CF = 0;			/* Jin Wei Wei */
	int result_tmp = 0; /* result */

	/* do the add */
	for(bit_count = add1_num - 1; bit_count >= 0; bit_count--,result_num--){
		
		if((result_tmp = add1[bit_count] + add2[bit_count] + CF) < 2){/* less than 2, then CF = 0, result get the add */
			result[result_num] = result_tmp;
			CF = 0;
		}else if(result_tmp == 2){	/* has the CF, and the result = 0 */
			result[result_num] = 0;
			CF = 1;
		}else if(result_tmp == 3){	/* has the CF, and the result = 1 */
			result[result_num] = 1;
			CF = 1;
		}
	}
	result[0] = CF;/* hightist bit = CF */
}
