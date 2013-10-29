#ifndef __pthread_rwlock_h
#define __pthread_rwlock_h
typedef struct{
	pthread_mutex_t rw_mutex;
	pthread_cond_t rw_condreaders;
	pthread_cond_t rw_condwriters;
	int 	rw_magic;
	int 	rw_nwaitreaders;
	int 	rw_nwaitwriters;
	int 	rw_refcount;
}	pthread_rwlock_t;

#define RW_MAGIC 	0x19283746
#define PTHREAD_RWLOCK_INITIALIZER{ PTHREAD_MUTEX_INITIALIZER,\
	PTHREAD_COND_INITIALIZER, PTHREAD_COND_INITIALIZER, \
		RW_MAGIC, 0, 0, 0 }

typedef int pthread_rwlockattr_t;

int pthread_rwlock_destroy(pthread_rwlock_t *);
int pthread_rwlock_init(pthread_rwlock_t *, pthread_rwlockattr_t *);
int pthread_rwlock_rdlock(pthread_rwlock_t *);
int pthread_rwlock_tryrdlock(pthread_rwlock_t *);
int pthread_rwlock_trywrlock(pthread_rwlock_t *);
int pthread_rwlock_unlock(pthread_rwlock_t *);
int pthread_rwlock_wrlock(pthread_rwlock_t *);

void Pthread_rwlock_destroy(pthread_rwlock_t *);
void Pthread_rwlock_init(pthread_rwlock_t *, pthread_rwlockattr_t *);
void Pthread_rwlock_rdlock(pthread_rwlock_t *);
int  Pthread_rwlock_tryrdlock(pthread_rwlock_t *);
int  Pthread_rwlock_trywrlock(pthread_rwlock_t *);
void Pthread_rwlock_unlock(pthread_rwlock_t *);
void Pthread_rwlock_wrlock(pthread_rwlock_t *);

#endif
