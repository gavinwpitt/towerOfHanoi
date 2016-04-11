/**
stack.h
*/

#ifndef STACK_H
#define STACK_H

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
Add an element to the top of the stack (stack is changed).
This routine should dynamically allocate a new node.
@param stack Points to the top of the stack
@param data The token (C String)
*/
void push(towerBlock** stack, int size);

/*8
Removes the top element from the stack (stack is changed).
This routine should free the memory associated with the top node.
@param stack Points to the top of the stack
@exception If the stack is empty, the program should not segfault.
	Because that is bad
*/
void pop(towerBlock** stack);

#endif

