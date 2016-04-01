/**
Gavin Pitt
towerOfHanoi.c
**/

#include <stdlib.h>
#include <stdio.h>

/**
Definition for the towerBlocks.
Will function like a stack
Will have an int attribute, size, for diameter of block.
Will have a pointer to another block struct, which will be the block that is 'under' this one.

@param size - size of block struct. Used to compare to other blocks and see if move is legal
				(Blocks cannot be placed ontop of blocks of a smaller size).
@param next - pointer to another towerBlock struct. The thing it points to will be 'under' this
				towerBlock. This will allow towerBlocks to be used as a stack.
**/
typedef struct towerBlock {
    int size;                  // the data stored in the node
    struct towerBlock * next;     // node's left child
} towerBlock;

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
	
	if(permaRoot == NULL)
		printf("root==NULL\n");
	//set second and third stacks index to NULL
	stacks[1] = permaRoot; stacks[2] = permaRoot;
	if(stacks[1] == NULL)
		printf("stacks==NULL\n");
	
	int i;
	towerBlock* root = NULL;
	//Iteratively create blocks, with the next pointer always pointing to root
	//Change root with each iteration to the current block.
	for(i = numberOfBlocks; i > 0; i--){
		towerBlock* block = malloc(sizeof(towerBlock));
		block->size = i;
		block->next = root;
		printf("block size: %d\n", block->size);
		root = block;
		//printf("new root size: %d\n", root->size);
	}

	//set first stacks index (stack A) to the top of the stack of blocks
	printf("set root\n");
	stacks[0] = root;
	printf("root set\n");
	//set second and third stacks index to NULL
	//stacks[1] = NULL; stacks[2] = NULL;

}

void moveBlock(int source, int destination, towerBlock* stacks[3]){
	if((stacks[source]) != NULL){
		
		//check if destination is null
		//if(stacks[destination]){
			//check if source is < destination
			//if( *(stacks[source])->size  < *(stacks[destination])->size ){
				//move block
				//stacks[source]->next = stacks[destination];
			//}
		//}else{
			//if null just move it
			//stacks[source]->next = stacks[destination];
		//}

	}else{
		printf("Invalid Move: Empty Stack\n");
	}
}

void displayStacks(towerBlock* stacks[3]){
	int i = 0;
	printf("---------DisplayingStacks\n");
	towerBlock* block;
	for(i = 0; i < 3; i++){
		printf("Stack %d\n", i);
		block = NULL;
		if((stacks[i])){
			printf("Here?\n");
			block = (stacks[i]);
			printf("Here?\n");
			while(block){
				printf("Here, stack: %d!\n", i);
				printf("%d\n", block->size);
				block = block->next;
			}
			//set back to null
			//block = NULL;
		}
	}
	printf("--------StacksDisplayed\n");
}

int main(int argc, char* argv[]){
	//HardCoded array: Stacks.
	//Stacks is an array of three pointers, which represent the three rods.
	//Stacks will hold towerBlock stacks, and the bottom of all of them will be NULL
	towerBlock* stacks[3];// = malloc(sizeof(towerBlock) * 3);
	int numberOfBlocks = 3;

	//initialize three polls with the number of blocks.
	//stacks[0] point to accending stack towerBlocks,
	//stacks[1] and stacks[2] will just point to NULL
	initTowers(numberOfBlocks, stacks);
	displayStacks(stacks);
	moveBlock(1,2,stacks);
	displayStacks(stacks);
	//moveBlock(0,1,stacks);
	displayStacks(stacks);	
	return 0;
}