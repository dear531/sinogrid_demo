#include <stdio.h>
#include "extern.h"

int sub(int a, int b)
{
	return a - b;
}

int main(void)
{
	int a = 1, b = 2;
	addp = add;
	fprintf(stdout, "%d + %d = %d\n", a, b, add(a, b));
	fprintf(stdout, "%d + %d = %d\n",
			a,
			b,
			addp(a, b));
	return 0;
}
