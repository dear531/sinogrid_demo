#include <stdio.h>


struct b
{
	int bb;
};

struct a
{
	int aa;
};

struct c
{
	struct b b;
	struct a a;
};
int main(int argc, char *argv[])
{
	struct c c= {.b.bb=1, .a.aa=2};
	fprintf(stdout, "c.aa:%d, c.bb:%d\n", c.a.aa, c.b.bb);
	return 0;
}
