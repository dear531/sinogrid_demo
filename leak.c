#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *mystrcpy(char *src, char *dest)
{
	int i;
	for (i = 0; src[i];i++)
		dest[i] = src[i];
	dest[i - 1] = '\0';
	return dest;
}

int
main(int argc, char *argv[])
{
	char *p;
	char dest[5];
	int i;
	p = malloc(5);
#include <strings.h>
	bcopy("123", p, strlen("123"));	
	for (i = 0; i < 3; i++)
		mystrcpy(p, dest);
	free(p);

	return 0;
}
