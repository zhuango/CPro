#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include "shm_com.h"

int main(void){
	int running =1;
	void *shared_memory = (void*) 0;//the address of the memory 
	struct shared_use_st *shared_stuff;//the memory info
	char buffer[BUFSIZ];//buffer
	int shmid;//the memory id

	shmid = shmget( (key_t)1232,sizeof(struct shared_use_st),0666 | IPC_CREAT);//create shared memory
	if(shmid == -1){//create shared memory failed
		fprintf(stderr,"shmget failed\n");
		exit(EXIT_FAILURE);
	}

	shared_memory = shmat(shmid,(void*) 0,0);//link the shared memory to the process
	if(shared_memory == (void*) -1){//link failed
		fprintf(stderr,"shmat failed\n");
		exit(EXIT_FAILURE);
	}
	printf("Memory attached at %X\n",(int) shared_memory);//print address of the shared memory in this process

	shared_stuff = (struct shared_use_st *) shared_memory;//change the type of shared_memory to gave the value to that struct that include info of shared memory

	while(running){
		while(shared_stuff->written_by_you == 1){//if
			sleep(1);
			printf("waiting for client...\n");
		}
		printf("Enter come text:");
		fgets(buffer,BUFSIZ,stdin);
		strncpy(shared_stuff->some_text,buffer,TEXT_SZ);
		shared_stuff->written_by_you = 1;

		if(strncmp(buffer,"end",3) == 0){
			running = 0;
		}
	}

	if(shmdt(shared_memory) ==-1){
		fprintf(stderr,"shmdt failed\n");
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
}
