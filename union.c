#include <stdio.h>

int main(void)
{
	union file {
		struct {
			char * local;
			char * remote;
		};
		struct {
			char *dest;
			char *source;
		};
	};

	union file file = {.local = "1.txt", .remote = "2.txt", };
	union file file2 = {.dest = "3.txt", .source = "4.txt", };
	return 0;
}
