#include <stdio.h>

int main(int argc, char *argv[])
{
	struct {
		int a;
		char *p;
		char b;
	} z;
	fprintf(stdout, "sizeof(z):%ld\n", sizeof(z));
	return 0;
}
