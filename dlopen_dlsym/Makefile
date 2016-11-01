a.out:libmath.a libmath2.so dlopen.c
	gcc -o a.out dlopen.c -L. -lmath -lmath2 -ldl
libmath.a:math.o
	ar cr libmath.a math.o 
libmath2.so:math.o
	ld -shared -fPIC -o libmath2.so math.o 
math.o:math.c
	gcc -c math.c -o math.o 
clean:
	-rm -rf a.out* *.o *.a *.so
.PHONY:
	clean

