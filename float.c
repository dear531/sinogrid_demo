#include <stdio.h>

int
main(int argc, char *argv[])
{
	float num;
	scanf("%f", &num);
	fprintf(stdout, "num:%lf\n", num);

	return 0;
}
