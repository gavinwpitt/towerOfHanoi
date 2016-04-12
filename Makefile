CC=gcc
CFLAGS= -lncurses -l -L

test: towerOfHanoi.c stack.c stack.h
	gcc -std=c99 -Wall -Wextra -pedantic -o towerOfHanoi towerOfHanoi.c stack.c -lncurses
