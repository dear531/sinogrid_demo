#include <stdio.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>

void sig_alarm(int signum)
{
	write(STDOUT_FILENO, ".", strlen("."));
	alarm(2);
}
int main(void)
{
#if 0
	typedef void (*sighandler_t)(int);
	sighandler_t signal(int signum, sighandler_t handler);
#endif
	signal(SIGALRM, sig_alarm);
	alarm(2);
	while (1)
		sleep(10);
	fprintf(stdout, "here is appear ?\n");
	return 0;
}
