#include <stdio.h>
#if 0
int main(void)
#else
int main(int argc, char *argv[])
#endif
{
	fprintf(stdout, "argc:%d\n", argc);
	int i;
	for (i = 0; i < argc; i++)
		fprintf(stdout, "argv[%d]:%s\n", i, argv[i]);
	return 0;
}
