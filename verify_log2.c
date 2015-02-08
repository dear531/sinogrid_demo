#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <limits.h>

int main(int argc, char *argv[])
{
	/* check command-line */
	if (2 != argc) {
		fprintf(stderr, "usage : check_log2 number\n");
		exit(EXIT_FAILURE);
	}
	/* convert command-line argv to numeric */
	int ret;
	ret = strtol(argv[1], NULL, 10);
	if (ERANGE == errno) {
	       if (LONG_MIN == ret ) {
		       fprintf(stderr, "%s underflow\n",
				       argv[1]);
	       } else if (LONG_MAX == ret) {
		       fprintf(stderr, "%s overflow\n",
				       argv[1]);
	       }
		exit(EXIT_FAILURE);
	}
	/* verify multiple two */
	if (0 < ret && 0 == (ret & (ret - 1))) {
		int num = ret, count;
		for (num = ret, count = 0; 1 < num; num >>= 1) {
			count++;
		}
		fprintf(stdout, "%d is two %d multiple\n",
				ret, count);
	} else {
		fprintf(stdout, "%d is not multiple two\n",
				ret);
	}
	return 0;
}
