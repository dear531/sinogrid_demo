#include <stdio.h>
#include <string.h>

int
main(int argc, char *argv[])
{
	char buf[10] = {0};
	memset(buf, 0x00, sizeof(buf));
	int ret;
	ret = strcmp(buf, "0");
	fprintf(stdout, "ret:%d\n", ret);
	fprintf(stdout, "buf[0]:%c, %c\n", buf[0], '0');
	return 0;
}
