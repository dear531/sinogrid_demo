#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <syslog.h>
#include <string.h>
#include <errno.h>
#include <sys/epoll.h>
#include <fcntl.h>


int setnonblocking(int fd)
{
	int opt;
	int ret;
	if ((opt = fcntl(fd, F_GETFL)) < 0) {
		fprintf(stdout, "get fd status error :%s\n",
				strerror(errno));
		ret = opt;
	}
	if ((ret = fcntl(fd, F_SETFL, opt | O_NONBLOCK)) < 0) {
		fprintf(stdout, "set nonbloking error :%s\n",
				strerror(errno));
	}
err:
	return ret;
}

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
	int epfd;
	epfd = epoll_create(1024);
	struct epoll_event tmpevt = {.events = EPOLLIN};
	if (epfd < 0)
		fprintf(stdout, "epoll_create error :%s\n",
				strerror(errno));
	int i;
	int pfd[10][2];
	pid_t pid;
	int maxfd;
	for (i = 0; i < 10; i++) {
		if (pipe(pfd[i]) < 0)
			fprintf(stdout, "pipe %s", strerror(errno));
		if ((pid = fork()) < 0) {
			fprintf(stdout, "create proccess failure %s %s %d\n",
					__FILE__, __func__, __LINE__);
		} else if (pid == 0) {
			close(pfd[i][0]);
			sleep(10);
			write(pfd[i][1], "123", sizeof("123"));
			close(pfd[i][1]);
			fprintf(stdout, "here child proccess pfd[%d]:%d\n", i, pfd[i][1]);
			exit(EXIT_SUCCESS);
		} else {
			close(pfd[i][1]);
			setnonblocking(pfd[i][0]);
			tmpevt.data.fd = maxfd = pfd[i][0];
			epoll_ctl(epfd, EPOLL_CTL_ADD, pfd[i][0], &tmpevt);
		}
	}
	int fdn;
	struct epoll_event fdes[maxfd];
	int n;
	for ( ; maxfd; ) {
		fdn = epoll_wait(epfd, fdes, maxfd, 1000 * 10);
		for (i = 0; i < fdn; i++) {
			char buf[10];
			sleep(1);
			if ((n = read(fdes[i].data.fd, buf, sizeof(buf))) < 0) {
				fprintf(stdout, "read error :%s\n",
						strerror(errno));
			} else if (n == 0) {
				close(fdes[i].data.fd);
				epoll_ctl(epfd, EPOLL_CTL_DEL,fdes[i].data.fd, &fdes[i]);
				while (maxfd == fdes[i].data.fd) {
					maxfd--;
				}
			} else {
			write(STDOUT_FILENO, buf, strlen(buf));
			fprintf(stdout, "fdes[%d].data.fd:%d\n",
					i, fdes[i].data.fd);
			}
		}
	}
#if 0
	for (i = 0; i < 10; i++) {
		char buf[10];
		int n;
again:
		n = read(pfd[i][0], buf, sizeof(buf));
		if (n < 0 && errno == EAGAIN) {
			fprintf(stdout, "try again \n");
			sleep(1);
			goto again;
		} else if (n < 0) {
			fprintf(stdout, "read error :%s\n", strerror(errno));
		}
		write(STDOUT_FILENO, buf, strlen(buf));
		fprintf(stdout, "here perent proccess pfd[%d]:%d\n", i, pfd[i][0]);
	}
#endif
	for (i = 0; i < 10; i++)
		if (pfd[i][0] != -1)
			close(pfd[i][0]);
	if (signal(SIGCHLD, sigbackup) == SIG_ERR) {
		syslog(LOG_INFO, "set child signal error %s %s %d\n",
				__FILE__, __func__, __LINE__);
		return -1;
	}

	return 0;
}
