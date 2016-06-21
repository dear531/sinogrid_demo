#include <stdio.h>
#include <string.h>
#include <errno.h>

int main(int argc,char *argv[])
{
	FILE *fp = NULL;
	char input[80 * 6] = {0};
	fp = fopen("customerinfo.data", "r");
	if (NULL == fp)
	{
		fprintf(stderr, "fopen error -- %s\n", strerror(errno));
		goto failure;
	}
	while (NULL != fgets(input, 80 * 6, fp))
	{
		fprintf(stdout, "%s\n", strtok(input, "\t"));
		fprintf(stdout, "%s\n", strtok(NULL, "\t"));
		fprintf(stdout, "%s\n", strtok(NULL, "\t"));
		fprintf(stdout, "%s\n", strtok(NULL, "\t"));
		fprintf(stdout, "%s\n", strtok(NULL, "\t"));
		fprintf(stdout, "%s\n", strtok(NULL, "\n"));
	}
failure:
	if (NULL != fp)
		fclose(fp);
	return 0;
}
