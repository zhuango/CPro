#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

int pthread_rwlock_unlock(pthread_rwlock_t *rw)
{
	int result;
	if(rw->rw_magic != RW_MAGIC)
		return (EINVAL);

	if((result = pthread_mutex_lock(&rw->rw_mutex)) < 0)
		return (result);

	if(rw->rw_refcount > 0)
		rw->rw_refcount --;
	else if(rw->refcount == -1)
		rw->rw_refcount == 0;
	else{
		printf("error: rw_refcount = %d\n", rw->rw_refcount);
		exit(EXIT_FAILURE);
	}

	if(rw->rw_nwaitwriters > 0){
		if(rw->refcount == 0)
			result = pthread_cond_signal(&rw->rw_condwriters);
	}else if(rw->nwaitreaders > 0)
		result = pthread_cond_broadcast(&rw->rw_condreaders);

	pthread_mutex_unlock(&rw->rw_mutex);
	return (result);
}
