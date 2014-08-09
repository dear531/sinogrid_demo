#include <stdio.h>

int printf_sharp(char *s)
{
#define p(s) fprintf(stdout, "%s\n", #s)
	p(s);
	return 0;
}

int main(int argc, char *argv[])
{
	char *str = "helloc world";
	printf_sharp(str);
	return 0;
}
