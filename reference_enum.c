#include <stdio.h>

int main(int argc, char *argv[])
{
	enum enum_value {
		ONE = 1,
		TWO = 2,
		THREE = 3,
	};
	fprintf(stdout, "enum_value.OEN:%d\n", (enum enum_value)2);
	return 0;
}
