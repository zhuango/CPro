#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/mman.h>
#include<string.h>
int main(int argc, char *argv[])
{
	int fdin, fdout;/* fdin: File you want to copy
						fdout:File you want to create*/
	void *src, *dst;/* src: Old file's address 
						dst: New file's address*/
	struct stat statbuf;/* Get the file info */

	if(argc != 3){/* Info you give is correct? */
		printf("Usage: %s <fromfile> <tofile>\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	/* Open old file */
	if((fdin = open(argv[1], O_RDONLY)) < 0){
		perror("open");/* Error? */
		exit(EXIT_FAILURE);
	}
	/* Open(Or craete) new file */
	if((fdout = open(argv[2], O_RDWR | O_CREAT | O_TRUNC, 0644)) < 0){
		perror("open 2");/* Error? */
		exit(EXIT_FAILURE);
	}
	/* Get the old file info */
	if(fstat(fdin, &statbuf) < 0){
		perror("stat");/* Error? */
		exit(EXIT_FAILURE);
	}
	/* Set the new file's size same as old file */
	if(lseek(fdout, statbuf.st_size - 1, SEEK_SET) < 0){
		perror("lseek");/* Error? */
		exit(EXIT_FAILURE);
	}
	/* Get the end position of new file */
	if(write(fdout, " ", 1) != 1){
		perror("write");/* Error? */
		exit(EXIT_FAILURE);
	}

	/* mmap old file, read only, and shared (has no copy) */
	if((src = mmap(0, statbuf.st_size, PROT_READ, MAP_SHARED,
					fdin, 0)) == MAP_FAILED){
		perror("mmap");/* Error? */
		exit(EXIT_FAILURE);
	}
	/* mmap new file, read and write and shared */
	if((dst = mmap(0, statbuf.st_size, PROT_READ | PROT_WRITE,
					MAP_SHARED, fdout, 0)) == MAP_FAILED){
		perror("mmap2");/* Error? */
		exit(EXIT_FAILURE);
	}
	/* copy old file to new file */
	memcpy(dst, src, statbuf.st_size);

	exit(EXIT_SUCCESS);/* exit */
}
