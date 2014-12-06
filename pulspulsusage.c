#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	int j = 100;
	for ( ; ; ) {
		if (100 < j--)
			break;
			usleep(5000);
			fprintf(stdout, "j :%d\n", j);
	}
	return 0;
}
