#include <stdio.h>
#include <pthread.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

pthread_once_t once_control = PTHREAD_ONCE_INIT;
void init_routine(void)
{
#if 0
       ssize_t write(int fd, const void *buf, size_t count);
#endif
	write(STDOUT_FILENO, "this is pthread_once\n", sizeof("this is pthread_once\n"));
       fprintf(stdout, "thread_id %d\n", pthread_self());
}
void *pthread_func(void* arg)
{
#if 0
       int pthread_once(pthread_once_t *once_control,
              void (*init_routine)(void));
#endif
       if (0 != pthread_once(&once_control, init_routine))
       {
	       fprintf(stderr, "pthread_once error :%s\n", strerror(errno));
       }
       fprintf(stdout, "thread_id %d\n", pthread_self());
#if 0
void pthread_exit(void *value_ptr);
#endif
	pthread_exit(NULL);
}
int main(void)
{
	int i = 0;
#if 0
       int pthread_create(pthread_t *restrict thread,
              const pthread_attr_t *restrict attr,
              void *(*start_routine)(void*), void *restrict arg);
#endif
	pthread_t thread_id[5];
	for (i = 0; sizeof(thread_id) / sizeof(*thread_id) > i; i++)
	{
		if (0 != pthread_create(thread_id + i, NULL, pthread_func, (void*)NULL))
		{
			fprintf(stderr, "pthread_create error :%s\n", strerror(errno));
		}
		fprintf(stdout, "main thread_id[%d]:%d\n", i, thread_id[i]);
	}
	for (i = 0; sizeof(thread_id) / sizeof(*thread_id) > i; i++)
	{
#if 0
int pthread_join(pthread_t thread, void **value_ptr);
#endif
		pthread_join(thread_id[i], NULL);
	}
}
