#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <limits.h>

int main(int argc, char *argv[])
{
	/* check command-lien argv */
	if (3 != argc) {
		fprintf(stderr, "usage : a.out number1 number2\n");
		exit(EXIT_FAILURE);
	}
	/* convert from argv to numeric */
	int num1, num2;
	num1 = strtol(argv[1], NULL, 10);
	if (LONG_MIN == num1 || LONG_MAX == num1) {
		fprintf(stderr, "conver num1 error :%s\n",
				strerror(errno));
	}
	num2 = strtol(argv[2], NULL, 10);
	if (LONG_MIN == num2 || LONG_MAX == num2) {
		fprintf(stderr, "conver num2 error :%s\n",
				strerror(errno));
	}
	/* count */
	int compare, count;
	for (compare = num1 ^ num2, count = 0; 0 != compare;
			compare = compare & (compare - 1)) {
		count++;
	}
	fprintf(stdout, "%d and %d bitwise copare %d\n",
			num1, num2, count);
	return 0;
}
