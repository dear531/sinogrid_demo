accurately: link shared library
zhangly@ubuntu:/mnt/data/gitstorage/sinogrid_demo/dlopen_dlsym$ ./a.out ./libmath.a 
dlopen error :./libmath.a: invalid ELF header
dlsym error :./a.out: undefined symbol: add
func :(nil)
Segmentation fault (core dumped)

invalid: link static library
zhangly@ubuntu:/mnt/data/gitstorage/sinogrid_demo/dlopen_dlsym$ ./a.out ./libmath2.so 
func :0x7f72f5784204
m[1] + n[2] = sum[3]
