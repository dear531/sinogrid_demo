#include <stdio.h>
#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <string.h>
#include <errno.h>
#include <signal.h>
#include <stdlib.h>

void sig_alarm(int signum)
{
	fprintf(stdout, "this is signal %d function\n", signum);
}
int main(void)
{
	int sockfd = -1;
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (-1 == sockfd) {
		fprintf(stderr, "socket error :%s\n", strerror(errno));
		exit(EXIT_FAILURE);
	}
	struct sockaddr_in src_add;
	memset(&src_add, 0x00, sizeof(src_add));
	src_add.sin_family	= AF_INET;
	src_add.sin_port	= htons(8001);   
	inet_pton(AF_INET, "127.0.0.1", &src_add.sin_addr);
	int ret = -1;
	ret = connect(sockfd, (const struct sockaddr *)&src_add, sizeof(src_add));
	if (-1 == ret) {
		fprintf(stderr, "connect error :%s\n", strerror(errno));	
		exit(EXIT_FAILURE);
	}
	int len = 0;
	char recvbuff[1024] = {0};
	struct sigaction newact, oldact;
	newact.sa_handler = sig_alarm;
	newact.sa_flags = 0;

	sigaction(SIGALRM, &newact, &oldact);
	alarm(10);
	while (1) {
		len = recv(sockfd, recvbuff, sizeof(recvbuff), 0);
		if (-1 == len && errno == EINTR) {
			fprintf(stdout, "timetou, sigalarm signal finish\n");
			break;
		} else if (-1 == len) {
			fprintf(stderr, "recv error :%s\n", strerror(errno));
			exit(EXIT_FAILURE);
		} else if (NULL != strstr(recvbuff, "@")) {
			fprintf(stdout, "recv finish\n");
			alarm(0);
			usleep(1000);
			break;
		} else if (0 < len) {
			fprintf(stdout, "recvbuff :%s\n", recvbuff);
			memset(recvbuff, 0x00, len);
		} else {
			fprintf(stdout, "peer close\n");
			break;
		}
	}
	fprintf(stdout, "end\n");
	return 0;
}
