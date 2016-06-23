#include <time.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
	time_t currtime;
	char tradetime[15] = {0};
#if 0
	time_t time(time_t *t);
#endif
	currtime = time(NULL);
	strftime(tradetime, sizeof(tradetime), "%I:%M:%S %p", localtime(&currtime));
	fprintf(stdout, "%s\n", tradetime);
	memset(tradetime, 0x00, sizeof(tradetime));
	strftime(tradetime, sizeof(tradetime), "%I%M%S %p", localtime(&currtime));
	fprintf(stdout, "%s\n", tradetime);
	memset(tradetime, 0x00, sizeof(tradetime));
	strftime(tradetime, sizeof(tradetime), "%I%M%S", localtime(&currtime));
	fprintf(stdout, "%s\n", tradetime);
	memset(tradetime, 0x00, sizeof(tradetime));
	return 0;
}
