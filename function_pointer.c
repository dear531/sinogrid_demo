#include <stdio.h>

int f1(int b)
{
	fprintf(stdout, "%d\n", b);
	return 0;
}

void call(int a, int (*f)(int b))
{
	f(a);
	return;
}

int
main(void)
{
	call(1, f1);

	return 0;
}
