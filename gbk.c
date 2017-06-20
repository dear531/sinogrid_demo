#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	if (2 != argc) {
		fprintf(stdout, "usage : a.out gbk\n");
		exit(EXIT_FAILURE);
	}
	unsigned char *p = argv[1];
	int i = 0, len = strlen(argv[1]);
	for (i = 0; len > i; i++) {
		if (0x81 <= p[i] && 0xfe >= p[i]) {
			i++;
		} else if ('|' == p[i]) {
			p[i] = ',';
		}
	}
	for (i = 0; len > i; i++)
		fprintf(stdout, "p[%d] :%x\n", i, p[i]);
	fprintf(stdout, "p :%s\n", p);
	return 0;
}
