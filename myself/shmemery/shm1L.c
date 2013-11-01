#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/ipc.h>
#include "shm_comL.h"
#include<string.h>
int main(void){
	int sharedMemory;
	void *address = (void *)0;
	struct memoryInfo  *memoryinfo = (struct memoryInfo *)0;
	int running = 1;
	sharedMemory = shmget( (key_t)1234, sizeof(struct memoryInfo),0666 | IPC_PRIVATE);

	if(sharedMemory == -1){
		printf("create shared memory failed\n");
		exit(EXIT_FAILURE);
	}

	address = shmat(sharedMemory,(void *)0,0);

	if(address == (void *)-1){
		printf("link to proces failed\n");
		exit(EXIT_FAILURE);
	}
	printf("memory attached %X\n",(int)address);

	memoryinfo = (struct memoryInfo *) address;
	memoryinfo->writtenOrNot = 0;
	while(running){

		if(memoryinfo->writtenOrNot){
			printf("you wrote: %s\n",memoryinfo->text);
			memoryinfo->writtenOrNot = 0;
			sleep(1);

			if(strncmp(memoryinfo->text,"end",3) == 0){
				running = 0;
			}
		}else{
			sleep(2);
			printf("you wrote nothing ,keep listenning\n");
		}
	}

	if(shmdt(address) == -1 ){
		printf("unlink frim process failed\n");
		exit(EXIT_FAILURE);
	}

	exit(EXIT_SUCCESS);
}
