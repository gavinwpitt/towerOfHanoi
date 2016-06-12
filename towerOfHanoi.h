#ifndef TOWEROFHANOI_H
#define TOWEROFHANOI_H
/**
Gavin Pitt
towerOfHanoi.h
**/

/**
Temporary Usage Message

void usage();

void inputUsage();

/**
initTowers(numberOfBlocks, stacks[3])

function responsible for initializing the 3 polls that the blocks are stacked on.
Initializes first poll, stack[0], to have stack of blocks, accending in size, 
	until it points to NULL.
Initializes second and third poll to just be pointing at NULL.

Stacks are created using dynamic memory allocation of towerBlock structs.

@param numberOfBlocks- int that gives number of blocks to create/stack
@param stacks - array of 3 towerBlock pointers. Used to represent three polls
**/
//void initTowers(int numberOfBlocks, towerBlock* stacks[3]);

/**
moveBlock(source, desination, stacks)
Moves a block between the stacks, from source to destination stack.
Error checks for:
	Valid source and destination bounds (0-3),
	Valid source (nonNull)
	Valid move (source is less than destination in size)
Program will then move the block from the source stack to the destination stack.
Uses a temporary pointer to pop off the top source value and push it to top of 
	destination stack.

@param - source - int representing source stack (0-3)
@param - destination - int representing destination stack (0-3)
@param - stacks - array of towerBlock pointers (stacks)
return - Int representing if it was success or failure
**/
//int moveBlock(int source, int destination, towerBlock* stacks[3]);

/**
Temporary function that prints out stack to terminal.
Will create a better front end using ncurses
**/
//void displayStacks(towerBlock* stacks[3]);
/**
freeBlocks(stacks)
Function called to free dynamically allocated memory (blocks).
Takes in the array of three potential stacks and iterates though them, freeing them.

@param -stacks - array of three stacks to be freed
**/
//void freeBlocks(towerBlock* stacks[3]);

/**
Solve(disk, source, dest, spare, stacks)
Calls a recursive method to solve a given Hanoi Puzzle.
@param - disk - int, 1 number less than the total number of disks.
		This is reduced by one each recursive call until it reaches the base case
@param source - int representing starting stack
@param dest - int representing desired destination stack
@param spare - int representing spare stack for moving blocks
@param stacks - array of stacks
**/
//void solve(int disk, int source, int dest, int spare, towerBlock * stacks[3]);

//int main(int argc, char* argv[]);



#endif
