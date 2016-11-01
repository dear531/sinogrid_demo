#include <stdio.h>
#include <dlfcn.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>

#include "head.h"

int main(int argc, char *argv[])
{
	int m = 1, n = 2;
	typedef int (*F)(int, int);
#if 0
	fprintf(stdout, "m[%d] + n[%d] = sum[%d]\n", m, n, add(m ,n));
#else
#if 0
void *dlopen(const char *filename, int flag);
#endif
	void *math_dl = NULL;
	if (2 != argc)
	{
		fprintf(stderr, "usage : a.out <./libmath.a|./libmath2.so>\n");
		exit(EXIT_FAILURE);
	}
	math_dl = dlopen(argv[1], RTLD_LAZY);
	if (NULL == math_dl)
		fprintf(stderr, "dlopen error :%s\n", dlerror());
#if 0
	void *dlsym(void *handle, const char *symbol);
#endif
	F func = NULL;
	func = dlsym(math_dl, "add");
	if (NULL == func)
		fprintf(stderr, "dlsym error :%s\n", dlerror());
	fprintf(stdout, "func :%p\n", func);
	fprintf(stdout, "m[%d] + n[%d] = sum[%d]\n", m, n, func(m, n));

#if 0
	int dlclose(void *handle);
#endif
	dlclose(math_dl);
#endif
	return 0;
}
