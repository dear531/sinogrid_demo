#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <pthread.h>
#include <stdlib.h>

static pthread_key_t key;
static pthread_once_t key_once = PTHREAD_ONCE_INIT;

#define PTHRED_NUM	10
static void make_key()
{
	(void) pthread_key_create(&key, NULL);
}


void *thread_func (void *arg)
{
#if 0
       int pthread_once(pthread_once_t *once_control,
		                     void (*init_routine)(void));
              pthread_once_t once_control = PTHREAD_ONCE_INIT;
#endif
	(void) pthread_once(&key_once, make_key);
#if 0
int pthread_key_create(pthread_key_t *key, void (*destructor)(void*));
#endif
	int *ptr = NULL;
	if ((ptr = pthread_getspecific(key)) == NULL) {
		ptr = malloc(sizeof(*ptr));
		(void) pthread_setspecific(key, ptr);
		fprintf(stdout, "setspecific\n");
	}
	fprintf(stdout, "ptr :%p\n", ptr);
}
int main(void)
{
	int i = 0;
	pthread_t  thread_id[PTHRED_NUM];
	for (i = 0; PTHRED_NUM > i; i++)
	{
#if 0
       int pthread_create(pthread_t *thread, const pthread_attr_t *attr,
                          void *(*start_routine) (void *), void *arg);
#endif
		/* pthread_create */
		if(0 != pthread_create(thread_id + i, NULL, thread_func, NULL))
		{
			fprintf(stderr, "pthread_create error :%s\n", strerror(errno));
		}
		if (0 != pthread_detach(thread_id[i]))
		{
			fprintf(stderr, "pthread_detach error :%s\n", strerror(errno));
		}
	}
	pthread_exit(NULL);
	/* ptread_detach */
	return 0;
}
