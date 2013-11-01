#include<stdio.h>
#include<stdlib.h>

int the_one = 0x00000000;
int mask = 0x40000000;
int bit = 32;
int main(void)
{
	int n, num1 = 0, num2 = 0, count;
	FILE *a1, *a2, *file, *a3;
	a3 = stdin;
	
	for(count = 0; count < bit; count++){
		/* Open first file to save the smaller number*/
		if((a1 = fopen("a1", "w+")) == NULL){
			printf("open error\n");
			exit(EXIT_FAILURE);
		}
		/* Open second file to save the bigger number */
		if((a2 = fopen("a2", "w+")) == NULL){
			printf("open error\n");
			exit(EXIT_FAILURE);
		}
		if(count != 0){/* First time the "a3" equal stdin */
			if((a3 = fopen("a3", "r")) == NULL){/* Open the third file to save the result group */
				printf("open error\n");
				exit(EXIT_FAILURE);
			}
		}
		/* Cut */
		while(fscanf(a3, "%d", &n) == 1){
			if(n & mask){/* This bit is 1? */
				num1 ++;/* Counting */
				fprintf(a1, "%d\n", n);/* Write to "a1" */
			}else{/* This bit is 0 ? */
				num2 ++;/* Counting */
				fprintf(a2, "%d\n", n);/* Write to "a2" */
			}
		}

		/* Get the group that number in , set "file" */
		if(num1 == 0 && num2 == 0)
			break;
		else if(num1 > num2){/* The number is in a2 */
			file = a2;
		}else {/* In a1 */
			file = a1;
			the_one |= mask;/* In "a1", and this bit is 1 */
		}
//			printf("__________________%d %d %d\n",num1, num2, the_one);
		/* Reset the position */
		rewind(file);
		fclose(a3);/* Close file for read */
		/* Open "a3" for write */
		if((a3 = fopen("a3", "w")) == NULL){
			printf("fopen a3\n");
			exit(EXIT_FAILURE);
		}
		/* Write the file that number in it */
		while(fscanf(file, "%d\n", &n) == 1){
			fprintf(a3, "%d\n", n);
		}
		rewind(a3);
		while(fscanf(a3, "%d\n", &n) == 1){
			printf("%d\n", n);
		}
//		printf("+++++++++++++++++++++\n");
		
		mask = mask >> 1;/* Next bit to Cut */
		/* Clear the counter */
		num1 = 0;
		num2 = 0;
		/* Close the files */
		fclose(a1);
		fclose(a2);
		fclose(a3);
	}
	printf("%d\n", the_one);/* Print the result */

	return 0;
}

