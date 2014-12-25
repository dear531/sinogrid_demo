#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
	char buff[1024] = {0};
	char *str = "\n1\n2\n3\n1\n2\n3\n";
	sprintf(buff, "echo \"%s\" | sort | uniq ", str);
	fprintf(stdout, "buff:%s", buff);
	FILE *uniq_fp;
	uniq_fp = popen(buff, "r");
	while (memset(buff, 0x00, sizeof(buff)), NULL != fgets(buff, sizeof(buff), uniq_fp)) {
		fprintf(stdout, "%s", buff);
	}
	return 0;
}
