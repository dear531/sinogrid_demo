#include <stdio.h>
#include "test.h"

int main(void)
{
	int a = 2, b = 1, c;
	/* flag src2 main.c */
	c = meth.sub(a, b);
	printf("c = %d\n", c);
	return 0;
}
