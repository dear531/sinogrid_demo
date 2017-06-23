#ifndef __EXTERN_H__
#define __EXTERN_H__
#if 0
extern int add(int a, int b);
#else
typedef int func (int, int);
extern func add;
typedef int (*funcp) (int a, int b);
extern funcp addp;
#endif
#endif
