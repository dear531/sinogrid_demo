#include <stdio.h>
#include <mcheck.h>
#include <stdlib.h>

int main(void)
{
	mtrace();
	int *p;
	p = malloc(sizeof(*p));
	//free(p);

	return 0;
}
