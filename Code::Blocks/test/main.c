#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *thr_fn(void *arg)
{
    printf("=+++++++++++++++++++\n");
}


int main()
{
    printf("Hello world!\n");
    pthread_t tid;
    if(pthread_create(&tid, NULL, thr_fn, NULL) < 0){
        perror("pthread_create");
        exit(EXIT_FAILURE);
    };
    if(pthread_join(tid, NULL) < 0){
        perror("pthread_join");
        exit(EXIT_FAILURE);
    }
    return 0;
}
