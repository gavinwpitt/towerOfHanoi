# towerOfHanoi
Terminal Based Tower of Hanoi Game, with Recursive Solver

This program is written in C and comes with a make file. If you have gcc version 4.8.4 and make downloaded then you can
compile/link the code using the given makefile.

The program is an interactive terminal based Tower of Hanoi game that uses dynamically allocated memory.
It utilizes a three index array of pointers create dynamically allocated stacks from the three pointers.

It can be run in the terminal, after it is compiled using the MakeFile, by running:
  ./towerOfHanoi [number of desired blocks]
  
##this will bring you into an input loop where you can enter a source stack (0, 1, or 2) and a destintation stack (0,1, or 2)
##The program will then move the block (if it is a valid move), and display the current stacks.
