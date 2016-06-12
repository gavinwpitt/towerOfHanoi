CC=gcc
CFLAGS= -lncurses -l -L

test: towerOfHanoi.c stack.c stack.h display.c display.h
	gcc -std=c99 -Wall -Wextra -pedantic -o towerOfHanoi towerOfHanoi.c stack.c display.c -lncurses -lm
