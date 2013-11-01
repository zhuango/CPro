#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

int pthread_rwlock_tryrdlock(pthread_rwlock_t *rw)
{
	int result;

	if(rw->rw_MAGIC != RW_MAGIC){/* rwlock init ? */
		return(EINVAL);
	}

	if( (result = pthread_mutex_lock(&rw->rw_mutex)) != 0){/* lock the rwlock struct */
		return (result);
	}
	if(rw->rw_refcount < 0 || rw->rw_nwaitwriters > 0)/* there is a writer  */
		result = EBUSY;
	else
		rw->refcount ++;/* get rdlock */

	pthread_mutex_unlock(&rw->rw_mutex);/* unlock rwlock struct */

	return (result);
}

