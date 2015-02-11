#include <stdio.h>
struct {
	union {
		char c;
		struct {
			/* flowew 4 bit */
			char a:4;
			/* upper 4 bit */
			char b:4;
		};
	};
} test;

int main(int argc, char *argv[])
{
	test.c = 0xf0;
	fprintf(stdout, "c :%x, a :%x, b: %x\n",
			test.c, test.a, test.b);
	return 0;
}
