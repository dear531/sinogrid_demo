#include <stdio.h>
void f2(void)
{
	return;
}
void f1(void)
{
	f2();
	return;
}

int main(int argc, char *argv[])
{
	f1();
	return 0;
}
/*
 * $ cflow -r -T cflow_reverse_call.c 
 * +-f1() <void f1 (void) at cflow_reverse_call.c:6>
 *   \-main() <int main (int argc,char *argv[]) at cflow_reverse_call.c:12>
 * +-f2() <void f2 (void) at cflow_reverse_call.c:2>
 *   \-f1() <void f1 (void) at cflow_reverse_call.c:6>
 *     \-main() <int main (int argc,char *argv[]) at cflow_reverse_call.c:12>
 * +-main() <int main (int argc,char *argv[]) at cflow_reverse_call.c:12>
 */








