#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

int pthread_rwlock_wrlock(pthread_rwlock_t *rw)
{
	int result;

	if(rw->rw_MAGIC != RW_MAGIC)/* rwlock struct init? */
		return (EINVAL);
	if((result = pthread_mutex_lock(&rw->rw_mutex)) != 0)/* lock rwlock struct */
		return result;

	if(rw->rw_refcount != 0)/* busy? then return right now */
		return EBUSY;
	else
		rw->refcount = -1;/* get lock */

	pthread_mutex_unlock(&rw->mutex);/* unlock rwlock struct */
	return (result);
}
