#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

struct foo{
	int a, b, c, d;
};

/* print the struct foo value */
void printfoo(const char *s, const struct foo *fp)
{
	printf(s);
	printf("struct at 0x%x\n", (unsigned)fp);
	printf("foo.a = %d\n", fp->a);
	printf("foo.b = %d\n", fp->b);
	printf("foo.c = %d\n", fp->c);
	printf("foo.d = %d\n", fp->d);
}
/* pthread 1 foo = {1, 2, 3, 4} */
void *thr_fn1(void *arg)
{
	struct foo foo = {1, 2, 3, 4};
	printfoo("thread 1:\n", &foo);
	pthread_exit((void*)&foo);
}
/* pthread 2 print self ID */
void *thr_fn2(void *arg)
{
	printf("thread 2: ID is %u\n", (unsigned)pthread_self());
	pthread_exit((void*)0);
}

int main(void)
{
	int err;/* check the error */
	pthread_t 	tid1, tid2;/* use to create the new pthread */
	struct foo *fp;/* a pointer to struct foo */

	/* create new pthread */
	err = pthread_create(&tid1, NULL, thr_fn1, NULL);
	if(err != 0){/* error? */
		perror("pthread_create1 ");
		exit(EXIT_FAILURE);
	}
	/* join it, and wait the pthread go over */
	err = pthread_join(tid1, (void*)&fp);
	if(err != 0){/* error? */
		perror("pthread_create 2");
		exit(EXIT_FAILURE);
	}

	sleep(1);/* sleep for 1 seconds and wait the pthread 1 go over */

	printf("parent starting second thread\n");
	/* create another pthread */
	err = pthread_create(&tid2, NULL, thr_fn2, NULL);
	if(err != 0){/* error? */
		perror("pthread 2");
		exit(EXIT_FAILURE);
	}
	sleep(1);/* sleep 1 seconds */

	printfoo("parent :\n", fp);/* print the fp */

	exit(EXIT_SUCCESS);
}
