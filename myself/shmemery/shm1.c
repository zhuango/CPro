#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include "shm_com.h"//include the struct: shared_use_st

int main(void){
	int running = 1;
	void *shared_memory = (void *)0;//the pointer of the memory:the newist  value is NULL
	struct shared_use_st *shared_stuff;//the struct that include the info of the text you input
	int shmid;//shared memory id

	shmid = shmget( (key_t)1234, sizeof(struct shared_use_st), 0666 | IPC_CREAT);//create sharedmemory and return shared memory id
	if(shmid == -1){//create memory failed
		fprintf(stderr,"shmget failed\n");
		exit(EXIT_FAILURE);
	}

	shared_memory = shmat(shmid,(void *)0,0);//put this shared memory at a process and return the first address of this memory

	if(shared_memory == (void*) -1){//refiect memory failed
		fprintf(stderr,"shmat failed\n");
		exit(EXIT_FAILURE);
	}
	printf("Memory attached at %X\n",(int)shared_memory);//print the address of shared memory

	shared_stuff = (struct shared_use_st *) shared_memory;//change the type of shared_memory to struct shared_use_st
								//shared_stuff include address of memory
								//this memory has a element called written_by_you(int type) and another element called some_text[TEXT_SZ](char array type)

	shared_stuff->written_by_you = 0;//the size of text is 0

	while(running){
		if(shared_stuff->written_by_you){//if the size of text is not 0 then print the text
			printf("You wrote : %s",shared_stuff->some_text);
			sleep(1);

			shared_stuff->written_by_you = 0;//print over then clear the size of the text
			if(strncmp(shared_stuff->some_text,"end",3) ==0){//if you input "end" then running = 0 ,exit the while
				running = 0;
			}
		}else{//if the text if nothing print the info
			sleep(3);
			printf("you wrote nothing,keep listening\n");
		}
	}

	if(shmdt(shared_memory) ==-1){//unlink the memory from process
		fprintf(stderr,"shmdt failed\n");
		exit(EXIT_FAILURE);
	}

	exit(EXIT_SUCCESS);
}
