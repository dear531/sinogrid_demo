#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


int main(void)
{
	int fd = -1;
	if (-1 == (fd = open("readonly.txt", O_RDONLY))) {
		printf("%m\n");
	}
	if (-1 != fd) {
		close(fd);
		fd = -1;
	}
	return 0;
}
