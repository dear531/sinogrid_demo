#include <stdio.h>

int main(int argc, char *argv[])
{
	setbuf(stdout, NULL);
	fprintf(stdout, "a");
	sleep(1);
	fprintf(stdout, "b");
	sleep(1);
	fprintf(stdout, "c");
	sleep(1);
	fflush(stdout);
	return 0;
}
