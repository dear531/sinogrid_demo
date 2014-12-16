#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	fprintf(stdout, "access 1.txt ret :%d\n",
			access("1.txt", F_OK));
	return 0;
}
