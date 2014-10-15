#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h> 
#include <arpa/inet.h>

	int
main(int argc, char *argv[])
{
	int tcpfd;
	/* socket */
	tcpfd = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
	/* bind */
#if 0
	struct sockaddr_in {
		sa_family_t    sin_family;
		u_int16_t      sin_port;
		struct in_addr sin_addr;
	};
#endif
	struct sockaddr_in saddr;
	saddr.sin_family;
	saddr.sin_port = htons(65536);
	saddr.sin_addr;
	bind(tcpfd, (struct sockaddr*)&saddr, sizeof(saddr));

	fprintf(stdout, "%d\n", saddr.sin_port);

	/* listen */
	/* accept */
	/* close */
	return 0;
}
