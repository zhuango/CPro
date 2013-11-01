#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

int pthread_rwlock_rdlock(pthread_rwlock_t * rw)
{
	int result;
	
	if(rw->rw_magic != RW_MAGIC)/* if the "rw" be init? */
		return(EINVAL);

	if((result = pthread_mutex_lock(&rw->rw_mutex)) != 0)/* lcok the struct pthread_rwlock */
		return (result);
	/* waiting the writers */
	while(rw->rw_refcount < 0 || rw->rw_nwaitwriters > 0){
		rw->rw_nwaitreaders ++;
		result = pthread_cond_wait(&rw->rw_condreaders, &rw->rw_mutex);/* there is another process get the lock , we must wait*/
		rw->rw_nwaitreaders --;
		if(result != 0)
			break;
	}

	if(result == 0)
		rw->rw_refcount ++;/*a reader add*/

	pthread_mutex_unlock(&rw->rw_mutex);
	return (result);
}
