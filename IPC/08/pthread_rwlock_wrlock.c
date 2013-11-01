#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

int pthread_rwlock_wrlock(pthread_rwlock_t *rw)
{
	int result;

	if(rw->magic != RW_MAGIC)/* rwlock struct init? */
		return (EINVAL);
	if((result = pthread_mutex_lock(&rw->rw_mutex)) < 0){/*get the lock*/
		return (result);
	}

	while(rw->refcount != 0){/* can not get write lock, busy, then loop */
		rw->rw_nwaitwriters ++;
		result = pthread_cond_wait(&rw->rw_condwriters, &rw->rw_mutex);/* waiting... */
		rw->rw_nwaitwriters --;
		if(result != 0)
			break;
	}

	if(result == 0)
		rw->refcount = -1;/* get write lock */

	pthread_mutex_unlock(&rw->rw_mutex);/* unlock rwlock struct */
	return (result);
}
