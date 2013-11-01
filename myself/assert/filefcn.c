/*
 *filefcn.c - Using __LINE__ and __FILE__
 */

#include<stdio.h>
#include "filefcn.h"

int open_file(FILE **fp, char *fname, char *mode, int line, char *file)
{
	if((*fp = fopen(fname, mode) ) == NULL){
		fprintf(stderr,"[%s:%d] open_file() failed \n",file,line);
		return 1;
	}

	return 0;
}
