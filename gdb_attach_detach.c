#include <stdio.h>

int
main(int argc, char *argv[])
{
	int i;
	for (i = 0; i < 100000; i++) {
		sleep(1);
		fprintf(stdout, "i:%d\n", i);
	}
	return 0;
}
