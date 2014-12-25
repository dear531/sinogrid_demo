#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
	char *saveptr;
	char *token;
	char pool[64] = "a b c d e f g";
	char *str;
	for (str = pool; ;str = NULL) {
		token = strtok_r(str, " ", &saveptr);
		if (token == NULL)
			break;
		fprintf(stdout, "token:%s\n", token);
	}
	return 0;
}
