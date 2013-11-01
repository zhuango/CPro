void Pthread_rwlock_destroy(pthread_rwlock_t *rwlock)
{
	if(pthread_rwlock_destroy(rwlock) < 0){
		perror("pthread_rwlock_destroy");
		exit(EXIT_FAILURE);
	}
}

void Pthread_rwlock_init(pthread_rwlock_t * rwlock ,
		pthread_rwlockattr_t *lock_attr)
{
	if(pthread_rwlock_init(rwlock, lock_attr) < 0){
		perror("pthread_rwlock_init");
		exit(EXIT_FAILURE);
	}
}

void Pthread_rwlock_rdlock(pthread_rwlock *rwlock)
{
	if(pthread_rwlock_rdlock(rwlock) < 0){
		perror("ptrhead_rwlock_rdlock");
		exit(EXIT_FAILURE);
	}
}

int Pthread_rwlock_tryrdlock(pthread_rwlock_t *rwlock)
{
	int ret;
	if((ret = pthread_rwlock_tryrdlock(rwlock)) < 0){
		perror("pthread_rwlock_tryrdlock");
		exit(EXIT_FAILURE);
	}

	return (ret);
}

int Pthread_rwlock_trywrlock(pthread_rwlock_t *rwlock)
{
	int ret;
	if((ret = pthread_rwlock_trywrlock(rwlock) ) < 0){
		perror("pthread_rwlock_trywrlock");
		exit(EXIT_FAILURE);
	}
	return (ret);
}

void Pthread_rwlock_unlock(pthread_rwlock_t *rwlock)
{
	if(pthread_rwlock_unoock(rwlock) < 0){
		perror("pthread_rwlock_unlock");
		exit(EXIT_FAILURE);
	}
}

void Pthread_rwlock_wrlock(pthread_rwlock_t *rwlock)
{
	if(pthread_rwlock_wrlock(rwlock) < 0){
		perror("pthread_rwlock_wrlock");
		exit(EXIT_FAILURE);
	}
}
