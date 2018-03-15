#include <stdio.h>
#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h> /* superset of previous */
#include <unistd.h>
#include <stdlib.h>
#include <arpa/inet.h>
int main(int argc, char *argv[])
{
	pid_t pid = 0;
	fprintf(stdout, "fork start\n");
	pid = fork();
	if (-1 == pid)
	{
		fprintf(stderr, "fork error :%m\n");
		exit(EXIT_FAILURE);
	}
	else if (0 == pid)
	{
		fprintf(stdout, "start child\n");
		int fd = -1;
		fd = socket(AF_INET, SOCK_STREAM, 0);
		if (-1 == fd)
		{
			fprintf(stdout, "socket error :%m\n");
			exit(EXIT_FAILURE);
		}
		struct sockaddr_in addr;
		addr.sin_family		= AF_INET;
		addr.sin_port 		= htons(8000);
		addr.sin_addr.s_addr	= inet_addr("127.0.0.1");
		if (-1 == bind(fd, (struct sockaddr *)&addr, sizeof(addr)))
		{
			fprintf(stdout, "bind error :%m\n");
			exit(EXIT_FAILURE);
		}
		if (-1 == listen(fd, 10))
		{
			fprintf(stdout, "listen error :%m\n");
			exit(EXIT_FAILURE);
		}
		int confd = -1;
		confd = accept(fd, NULL, NULL);
		close(confd);
		close(fd);
		fprintf(stdout, "child finished\n");
	}
	else if (0 < pid) 
	{
		sleep(100);
		fprintf(stdout, "prent finished\n");
		return 0;
	}
}
