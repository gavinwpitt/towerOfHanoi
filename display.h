#ifndef DISPLAY_H
#define DISPLAY_H

int getUserInput(int i);

void printErrorMessage(char message[]);

void initDisplay();

void updateDisplay();

void printBlock(int blockNumber, int stackNumber, int height);

void endDisplay();

void displayStacks();

void printSuccessMessage();

#endif