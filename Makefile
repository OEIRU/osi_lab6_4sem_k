all: prog1 prog2

prog1: prog1.c
    gcc -o prog1 prog1.c

prog2: prog2.c
    gcc -o prog2 prog2.c