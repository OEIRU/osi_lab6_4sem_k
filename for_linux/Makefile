#MakeFile for mainprog.c
#standart compile mainprog.c
mainprog : mainprog.c
	gcc mainprog.c -o mainprog
#debug
testprog : mainprog.c
	gcc mainprog.c -o -g testprog

mainprog_1 : mainprog.o
	gcc mainprog.o -o mainprog_1
mainprog_2 : mainprog.o
	ld -dynamic-linker /lib64/ld-linux-x86-64.so.2 -o mainprog_2 -Map=progmap mainprog.o -lc /lib64/crt1.o /lib64/crti.o /lib/gcc/x86_64-linux-gnu/10.3.1/crtbegin.o /lib/gcc/x86_64-linux-gnu/10.3.1/crtend.o /lib64/crtn.o /lib64/libstdc++.so.6
mainprog.o : mainprog.c
	gcc -c mainprog.c -o mainprog.o
