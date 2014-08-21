#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <syslog.h>
#include <string.h>
#include <errno.h>


int
main(int argc, char *argv[])
{
	typedef void (*sighandler_t)(int);
	sighandler_t sigbackup;
	if ((sigbackup = signal(SIGCHLD, SIG_IGN)) == SIG_ERR) {
		syslog(LOG_INFO, "set child signal error %s %s %d\n",
				__FILE__, __func__, __LINE__);
		return -1;
	}
	int i;
	int pfd[10][2];
	pid_t pid;
	for (i = 0; i < 10; i++) {
		if (pipe(pfd[i]) < 0)
			fprintf(stdout, "pipe %s", strerror(errno));
		if ((pid = fork()) < 0) {
			fprintf(stdout, "create proccess failure %s %s %d\n",
					__FILE__, __func__, __LINE__);
		} else if (pid == 0) {
			//close(pfd[i][1]);
			fprintf(stdout, "here child process pfd[%d][0]:%d, pfd[%d][1]:%d\n", i, pfd[i][0], i, pfd[i][1]);
			exit(EXIT_SUCCESS);
		} else {
			close(pfd[i][0]);
			fprintf(stdout, "here perent proccess pfd[%d]:%d\n", i, pfd[i][1]);
		}
	}

	if (signal(SIGCHLD, sigbackup) == SIG_ERR) {
		syslog(LOG_INFO, "set child signal error %s %s %d\n",
				__FILE__, __func__, __LINE__);
		return -1;
	}

	return 0;
}
