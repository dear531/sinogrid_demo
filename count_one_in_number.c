#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <limits.h>

int main(int argc, char *argv[])
{
	/* check command-line argv */
	if (2 != argc) {
		fprintf(stderr, "usage : a.out number\n");
		exit(EXIT_FAILURE);
	}
	/* convert argv to numeric */
	int ret;
	ret = strtol(argv[1], NULL, 10);
	if (LONG_MIN == ret || LONG_MAX == ret) {
		fprintf(stderr, "strtol error :%s\n",
				strerror(errno));
		exit(EXIT_FAILURE);
	}
	/* count number count in numeric */
	int num, count;
	for (num = ret, count = 0; 0 != num; num = num & (num - 1)) {
		count++;
	}
	fprintf(stdout, "%d contianed %d bit one\n",
			ret, count);
	return 0;
}
