/**
stack.c
Author: Gavin Pitt

Source file that holds functionality for a stack
Functions:
push()
top()
pop()
*/

#include "stack.h"
#include <stdlib.h>
#include <stdio.h>

/// Add an element to the top of the stack (stack is changed).
/// This routine should dynamically allocate a new node.
/// @param stack Points to the top of the stack
/// @param data The token (C String)
void push(towerBlock** stack, int size){
	towerBlock* block = malloc(sizeof(towerBlock));
	block->size = size;
	block->next = *stack;
	*stack = block;
}

/// Return the top element from the stack (stack is unchanged)
/// @param stack Points to the top of the stack
/// @return the top element on the stack
/// @exception If the stack is empty, the program should 
///	exit with EXIT_FAILURE
int top(towerBlock* stack){
	if(stack){
		return stack->size;
	}else{
		return -1;
	}
}

/// Removes the top element from the stack (stack is changed).
/// This routine should free the memory associated with the top node.
/// @param stack Points to the top of the stack
/// @exception If the stack is empty, the program should 
///	exit with EXIT_FAILURE
void pop(towerBlock** stack){
	if(*stack){
		towerBlock* old = (*stack);
		*stack = (*stack)->next;
		free(old);
	}else{
		fprintf(stderr, "Tried to pop empty stack\n");
	}
}