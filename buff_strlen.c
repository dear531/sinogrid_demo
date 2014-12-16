#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
	char buff[10] = "\n";
	fprintf(stdout, "%ld\n", (long)strlen(buff));
	return 0;
}
