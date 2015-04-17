#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>


int main(int argc, char *argv[])
{
	int a = 0x01020304;
	char *p = (char *)&a;
	int fd = -1;
	fprintf(stdout, "a address :%p, p value :%p, a:%d, *p:%d\n",
			&a, p, a, *p);
	fd = open("tmp.txt", O_CREAT | O_RDWR, S_IRUSR | S_IWUSR);
	if (-1 == fd) {
		fprintf(stderr, "open error :%s\n",
				strerror(errno));
		goto finish;
	}
	if (-1 == write(fd, &a, sizeof(a))) {
		fprintf(stderr, "write error :%s\n",
				strerror(errno));
		goto finish;
	}
finish:
	if (-1 != fd) {
		close(fd);
		fd = -1;
	}
	return 0;
}
