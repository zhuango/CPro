#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include"pthread_rwlock.h"

int pthread_rwlock_init(pthread_rwlock_t *rw, pthread_rwlockattr_t *attr)
{
	int result;
	if(attr != NULL)
		return(EIVAL);

	if((result = pthread_mutex_init(&rw->rw_mutex, NULL)) != 0)
		goto 	err1;
	if((result = pthread_cond_init(&rw->rw_condreaders, NULL)) != 0)
		goto 	err2;
	if((result = pthread_cond_init(&rw->rw_condwriters, NULL)) != 0)
		goto 	err3;

	rw->rw_nwaitreaders = 0;
	rw->rw_nwaitwriters = 0;
	rw->refcount = 0;
	rw->magic = RW_MAGIC;

	return (0);

	err 3: 
		pthread_cond_destroy(&rw->rw_condreaders);
	err 2:
		pthread_mutex_destroy(&rw->rw_mutex);
	err 1:
		return(result);
}
