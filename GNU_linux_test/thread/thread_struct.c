#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>


struct member{
	int a;
	char *s;
};

void *create(void *arg){
	struct member *temp;
	temp = (struct member *)arg;
	printf("member->a = %d\n",temp->a);
	printf("member->s = %s\n",temp->s);

	return (void*)0;
}

int main(int argc, char **argv){
	pthread_t tidp;
	int error;
	struct member *b;

	b = (struct member *) malloc(sizeof(struct member));
	b->a = 4;
	b->s = "LiuZhuang";

	error = pthread_create(&tidp,NULL,create,(void*)b);

	if(error){
		printf("pthread is not created...\n");
		return -1;
	}

	sleep(1);
	printf("pthread is created ...\n");
	return 0;
}
