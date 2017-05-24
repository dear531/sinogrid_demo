#ifndef __TEST_H__
#define __TEST_H__
typedef int (*meth_func) (int, int);
struct meth {
	meth_func tmp;
	meth_func add;
	meth_func sub;
	meth_func mul;
	meth_func div;
};
extern struct meth meth;
extern int add(int a, int b);
extern int sub(int a, int b);
extern int mul(int a, int b);
extern int div(int a, int b);
extern int test(int a, int b);
#endif
