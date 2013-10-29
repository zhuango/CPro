#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/ipc.h>
#include<string.h>
#include"shm_comL.h"


int main(void){
	int running = 1;
	int sharedMemory;
	struct memoryInfo *memoryinfo = (struct memoryInfo*)0;
	void *address = (void*) 0;
	char buffer[TEXT_SIZE];

	sharedMemory = shmget((key_t)1234,sizeof(struct memoryInfo),0666 | IPC_PRIVATE);

	if(sharedMemory == -1){
		printf("create memory failed\n");
		exit(EXIT_FAILURE);
	}

	address = shmat(sharedMemory,(void *)0 , 0);
	if(address == (void*)-1){
		printf("link memory to process filed\n");
		exit(EXIT_FAILURE);
	}
	printf("attached memory : %X\n",(int)address);

	memoryinfo = (struct memoryInfo*) address;

	while(running){
		while(memoryinfo->writtenOrNot == 1){
			sleep(1);
			printf("wait for client...\n");
		}
		printf("enter something : ");
		fgets(buffer,TEXT_SIZE,stdin);
		strncpy(memoryinfo->text,buffer,TEXT_SIZE);
		memoryinfo->writtenOrNot = 1;

		if(strncmp(buffer,"end",3) == 0){
			running = 0;
		}
	}

	if( shmdt(address) == -1){
		printf("unlink error\n");
		exit(EXIT_FAILURE);
	}

	exit(EXIT_SUCCESS);
}
