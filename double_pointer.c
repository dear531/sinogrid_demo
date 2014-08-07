#include <stdio.h>
#include <stdlib.h>

char *mystrcpy(char *src, char *dest)
{
	int i;
	for (i = 0; src[i];i++)
		dest[i] = src[i];
	dest[i - 1] = '\0';
	return dest;
}

int main(int argc, char *argv[])
{
	char **p = NULL;
	char tmp[10] = "123456789";
	int i;

	p = malloc(sizeof(*p) * 10);
	for (i = 0; i < 10; i++)
		p[i] = malloc(sizeof(**p) * 10);
	int j;
	for (j = 0; j < 2; j++)
		for (i = 0; i < 10; i++)
			mystrcpy(tmp, p[i]);
#if 1
	for (i = 0; i < 10; i++)
		free(p[i]);
	free(p);
#endif
	return 0;
}
