#include <stdio.h>

typedef enum {
	normal,
	except
} result;

result subfunc(void)
{
	return normal;
}

int main(void)
{
	printf("nolmal :%d\n", subfunc());
	return 0;
}
