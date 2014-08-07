#include <stdio.h>

int main(void)
{
	char str[10] = "a b c";
	char a[10] = {0}, b[10] = {0}, c[10] = {0};
	sscanf(str, "%*s %s %s", b, c); 
	printf("b:%s, c:%s\n", b, c);
	return 0;
}
