/*
 * testmacs.c - Exercise the function defined in filefcn.c
 */
#include<stdio.h>
#include<stdlib.h>
#include "filefcn.h"

int main(void)
{
	FILE *fp;

	if(open_file(&fp, "foo_bar", "w", __LINE__, __FILE__))	{
		exit(EXIT_FAILURE);
	}else{
		fputs("This text proves we scribbled in the dile.\n",fp);
		fclose(fp);
	}
	/*thie call will fail*/

	if(open_file(&fp, "bar_baz", "r", __LINE__,__FILE__)){
		exit(EXIT_FAILURE);
	}else{
		fclose(fp);
	}

	return 0;
}
