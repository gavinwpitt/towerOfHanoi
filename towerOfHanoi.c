/**
Gavin Pitt
towerOfHanoi.c
**/

#include <stdlib.h>
#include <stdio.h>
#include "display.h"
#include "stack.h"
#include <unistd.h>

int moveBlock(int source, int destination, towerBlock* stacks[3]);
void initTowers(int numberOfBlocks, towerBlock* stacks[3]);
void freeBlocks(towerBlock* stacks[3]);
void solve(int disk, int source, int dest, int spare, towerBlock * stacks[3]);
static int waitTime = 500000;

/**
Temporary Usage Message
**/
void usage(){
	printf("\nTower of Hanoi Usage: \n");
	printf("'./towerOfHanoi NumberOfBlocks'\n");
	printf("NumberOfBlocks must be integer greater than or equal to 0\n\n");
}

void inputUsage(){
	printf("\nTower of Hanoi Input Loop:\n");
	printf("Enter valid integers [0-2] to move blocks from source to destination stacks\n");
	printf("enter '9' '9' to quit\n");
	printf("enter '8' '8' to display board without moving\n");
}

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
void initTowers(int numberOfBlocks, towerBlock* stacks[3]){
	//Create bottom of stack and set it equal to Null
	towerBlock* permaRoot = NULL;
	
	//set second and third stacks index to NULL
	stacks[1] = permaRoot; stacks[2] = permaRoot;
	
	int i;
	towerBlock* root = NULL;
	//Iteratively create blocks, with the next pointer always pointing to root
	//Change root with each iteration to the current block.
	for(i = numberOfBlocks; i > 0; i--){
		push(&root, i);
		/**
		towerBlock* block = malloc(sizeof(towerBlock));
		block->size = i;
		block->next = root;
		root = block;
		*/
	}

	//set first stacks index (stack A) to the top of the stack of blocks
	stacks[0] = root;

}

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
int moveBlock(int source, int destination, towerBlock* stacks[3]){
	if(source < 0 || source > 2 || destination < 0 || destination > 2){
		printErrorMessage("\nInvalid Range! Source or Destination must be in range [0..2]\n");
		//usage();
		return EXIT_FAILURE;
	}

	if(stacks[source]){
		//check if destination is null
		if(stacks[destination]){
			//Check if is valid move (source block is smaller than destination block)
			if(stacks[source]->size  < stacks[destination]->size ){
				//move block
				//push value from source stack onto destiantion stack
				push( &(stacks[destination]), stacks[source]->size );

				//pop value off of old stack. This frees the memory.
				pop(&(stacks[source]));
				return EXIT_SUCCESS;
			}else{
				printErrorMessage("Invalid Move! Source block cannot be larger than destination!");
				return EXIT_FAILURE;
				//usage();
			}
		}else{
			//move block
			//push value from source stack onto destiantion stack
			push( &(stacks[destination]), stacks[source]->size );

			//pop value off of old stack. This frees the memory.
			pop(&(stacks[source]));
			return EXIT_SUCCESS;
		}
	}else{
		printErrorMessage("Invalid Move! Empty Source Stack");
		usleep(waitTime);
		return EXIT_FAILURE;
		//usage();
	}
}

/**
Temporary function that prints out stack to terminal.
Will create a better front end using ncurses
**/
void displayStacks(towerBlock* stacks[3]){
	int i = 0;
	//printf("---------DisplayingStacks\n");
	towerBlock* block;
	towerBlock* reverseBlock = NULL;
	towerBlock* temp;
	for(i = 0; i < 3; i++){
		//printf("Stack %d\n", i);
		if((stacks[i])){
			block = (stacks[i]);
			//This first while loop reverses the stack
			while(block){
				push(&reverseBlock, block->size);
				block = block->next;
			}
			//printf("REVERSED\n");
			int j = 1;
			while(reverseBlock){
				printBlock(reverseBlock->size, i, j);
				reverseBlock = reverseBlock->next;
				j++;
			}
		}
	}
	while(reverseBlock){
		pop(&reverseBlock);
	}
	//printf("--------StacksDisplayed\n");
}

/**
freeBlocks(stacks)
Function called to free dynamically allocated memory (blocks).
Takes in the array of three potential stacks and iterates though them, freeing them.

@param -stacks - array of three stacks to be freed
**/
void freeBlocks(towerBlock* stacks[3]){
	//towerBlock* block;
	//towerBlock* temp;
	int i;
	for(i = 0; i < 3; i++){
		while(stacks[i]){
			pop(&(stacks[i]));
		}
	}
}

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
void solve(int disk, int source, int dest, int spare, towerBlock * stacks[3]){
	if(disk == 0){
		updateDisplay();
		displayStacks(stacks);
		usleep(waitTime);
		moveBlock(source, dest, stacks);
		updateDisplay();
		displayStacks(stacks);
		usleep(waitTime);

	}
	else{
		solve(disk - 1, source, spare, dest, stacks);
		updateDisplay();
		displayStacks(stacks);
		usleep(waitTime);
		moveBlock(source, dest, stacks);
		updateDisplay();
		displayStacks(stacks);
		usleep(waitTime);
		solve(disk - 1, spare, dest, source, stacks);
	}
}

int main(int argc, char* argv[]){
	//HardCoded array: Stacks.
	//Stacks is an array of three pointers, which represent the three rods.
	//Stacks will hold towerBlock stacks, and the bottom of all of them will be NULL
	towerBlock* stacks[3];// = malloc(sizeof(towerBlock) * 3);

	//error check user input
	if( !(argc == 2 || argc == 3) ){
		usage();
		return EXIT_FAILURE;
	}

	int solveBoolean = 0;
	int numberOfBlocks = 0;
	//get user input for number of blocks
	if(argc == 2){
		numberOfBlocks = atoi(argv[1]);
	}else{
		solveBoolean = 1;
		numberOfBlocks = atoi(argv[1]);
	}

	//error check user input
	if(numberOfBlocks < 0){
		usage();
		return EXIT_FAILURE;
	}


	//initialize three 'poles' with the number of blocks.
	initTowers(numberOfBlocks, stacks);
	//init display
	initDisplay();

	//enter input loop
	int source, destination;
	//displayStacks(stacks);
	//printf("Move block from [source] to [destination]: ");
	//printBlock(0, 0);
	//scanf("%d %d", &source, &destination);
	if(solveBoolean){
		printf(" :( \n");
		solve(numberOfBlocks - 1, 0, 2, 1, stacks);
		printSuccessMessage();
		printErrorMessage("Press Any Key to Quit");
		getchar();
	}else{
		updateDisplay();
		displayStacks(stacks);
		while(1){
			//printMessage("Move block from [source] to [destination]: ");
			source = getUserInput(0);
			destination = getUserInput(1);
			getchar();
			getchar();
			if(source == 9)
				break;
			if(source == 8){
				//displayStacks(stacks);
			}
			else{
				if(moveBlock(source, destination, stacks) == EXIT_SUCCESS){
					updateDisplay();
					displayStacks(stacks);
				}else{
					getchar();
					updateDisplay();
					displayStacks(stacks);
				}
			}
		}
	}


	/**
	displayStacks(stacks);
	solve(numberOfBlocks - 1, 0,1,2, stacks);
	displayStacks(stacks);
	**/
	
	//printf("=======CLEANING=======\n");
	//endDisplay();
	endDisplay();
	freeBlocks(stacks);
	return EXIT_SUCCESS;
}
