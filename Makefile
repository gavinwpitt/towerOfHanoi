CC=gcc
CFLAGS= 

test: towerOfHanoi.c
	gcc -std=c99 -Wall -Wextra -pedantic -o towerOfHanoi towerOfHanoi.c