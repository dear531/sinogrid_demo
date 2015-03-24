#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	fprintf(stdout, "getpagesize :%d\n",
			getpagesize());
	fprintf(stdout, "sysconf(PAGESIZE):%ld\n",
			sysconf(_SC_PAGESIZE));
	return 0;
}
