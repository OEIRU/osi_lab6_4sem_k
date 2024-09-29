# Makefile for mainprog.c
# Standart compile mainprog.c
prog: mainprog.c
gcc -o mainprog mainprog.c
# Debugging compile mainprog.c
testprog: mainprog.c
gcc -o test_mainprog -g mainprog.c
# End Makefile