#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <execinfo.h>
#include <string.h>

void sig_segv(int signum)
{
#if 0
	int backtrace(void **buffer, int size);
	char **backtrace_symbols(void *const *buffer, int size);
	void backtrace_symbols_fd(void *const *buffer, int size, int fd);
#endif
#define BUFF_NUM 32
	void *buff[BUFF_NUM] = {NULL};
	int n = 0;
	n = backtrace(buff, sizeof(buff) / sizeof(*buff));
	if (0 == n) {
		fprintf(stderr, "stack is not retured\n");
		exit(EXIT_FAILURE);
	}
	char ** strings = NULL;
	strings = backtrace_symbols(buff, n);
	int i = 0;
	for (i = 0; n > i; i++)
		fprintf(stdout, "strings[%d] : %s\n", i, strings[i]);
	if (NULL != strings) {
		free(strings);
		strings = NULL;
	}
	exit(EXIT_FAILURE);
}
int main(int argc, char *argv[])
{
#if 0
       typedef void (*sighandler_t)(int);
      sighandler_t signal(int signum, sighandler_t handler);
#endif
	signal(SIGSEGV, sig_segv);
	char *p = NULL;
	memcpy(p, "1", sizeof("1"));
	return 0;
}
