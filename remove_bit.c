#include <stdio.h>
int remo_bit()
{
	return ((1 - sizeof(int)) >> 32);
}

int
main(int argc, char *argv[])
{
	fprintf(stdout, "remo_bit :%d\n", remo_bit());
	return 0;
}
