#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

int
main(int argc, char *argv[])
{
	signal(SIGCHLD, SIG_IGN);
	char *file = "1.txt";
	char procfile[sizeof("/proc/4294967295/status")];
	pid_t pid;
	
	if ((pid = fork()) < 0) {
		/* error */
	} else if (pid == 0) {
		/* child */
		sleep(5);
		exit(EXIT_SUCCESS);
	} else {
		/* perent */
		int i;
		sprintf(procfile, "/proc/%d/status", pid);
		for (i = 0; i < 10; i++) {
			if (access(procfile, F_OK) == 0)
				fprintf(stdout, "child exists\n");
			else
				fprintf(stdout, "child not exists\n");
			sleep(1);
		}
	}

	if (!access(file, R_OK))
		fprintf(stdout, "readable\n");
	if (!access(file, X_OK))
		fprintf(stdout, "excution\n");
	else
		fprintf(stdout, "not excution\n");
	if (!access(file, F_OK))
		fprintf(stdout, "file exists\n");
	return 0;
}
