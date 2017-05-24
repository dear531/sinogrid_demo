CFLAGS	:=-g -Wall
all:test
test:libtest.so main.o
	$(CC) -g main.o -L. -ltest -o test
libtest.so:
	$(CC) test.c -fPIC -g -shared -o libtest.so
echo:
	echo $(CC)
clean:
	-rm -rf *.so *.o test
.PHONY:
	echo clean all libtest
