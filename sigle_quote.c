#include <stdio.h>

int main(void)
{
	char str[10] = {0};
	sprintf(str, "a'b'c");
	printf("%s\n", str);
	return 0;
}
