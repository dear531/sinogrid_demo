#include <stdio.h>

int main(int argc, char *argv[])
{
	enum enum_value {
		ONE = 0,
		TWO,
		THREE,
		MAX,
	};
	int value[MAX] = {1, 0, 1024};
	int i;
	for (i = 0; MAX > i; i++) {
		fprintf(stdout, "enum_value.OEN:%d\n", (enum enum_value)i);
		fprintf(stdout, "value :%d\n", value[(enum enum_value)i]);
	}
	return 0;
}
