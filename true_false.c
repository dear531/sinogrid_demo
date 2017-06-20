#include <stdbool.h>
#include <stdio.h>


#define equal(a,b) (a) == (b) ? true : false
int main(void)
{

	bool bi;
	bi = false;
	bi = 2;
	printf("%d, %d, bi:%d\n", equal(1, 1), equal(1,0), bi);
	return 0;
}
