#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	union{
		short s;
		char c[sizeof(short)];
	}un;

	un.s = 0x0102;
<<<<<<< HEAD
	printf("%s: ", CPU_VENDOR_SO);
=======
//	printf("%s: ", CPU_VENDOR_SO);
>>>>>>> b377d5b6d37e1e0791c3b0af7035f3dc99c42dd4
	if(sizeof(short) == 2){
		if(un.c[0] == 1 && un.c[1] == 2){
			printf("big end!\n");
		}else if(un.c[0] == 2 && un.c[1] == 1){
			printf("lettle end\n");
		}else 
			printf("unknow\n");
	}else{
		printf("sizeof(short) == %d\n", sizeof(short));
	}

	exit(EXIT_SUCCESS);
}
