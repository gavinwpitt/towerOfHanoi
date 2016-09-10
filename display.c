/**
Gavin Pitt
display.c
A source file used by towerOfHanoi.c.
Display will have a lot of ncurses functions that will display the 'backend' tower in the main file.
**/

#include <ncurses.h>
#include <math.h>
#include <string.h>

static int max_y = 30;
static int max_x = 90;
static int poles_y;
static int poles_x[3];

int getUserInput(int i){
	int input;
	mvprintw(max_y - 1, 1, "Move Block From: ");
	refresh();
	scanf("%d", &input);
	mvprintw(max_y - 1, 18 + (2*i), "%d", input);
	refresh();
	return input;
}

void printErrorMessage(char message[]){
	int length = strlen(message);
	mvprintw(max_y - 7, (max_x / 2) - (length / 2), message);
	refresh();
}

void initDisplay(){
	//Initialization
	//int max_y = 0, max_x = 0;

	initscr(); //initialize curses mode
	noecho(); //turn off echoing
	cbreak();
	nodelay(stdscr, TRUE);
	curs_set(FALSE); //leave cursor visible
	//Set poles and borders
	//getmaxyx(stdscr, max_y, max_x);
	poles_y = max_y - 10;
	poles_x[0] = max_x / 5;
	poles_x[1] = poles_x[0] + 20;
	poles_x[2] = poles_x[1] + 20;
	for(int i = 0; i <= max_x; i++){
		mvprintw(max_y, i, "=");
		mvprintw(0, i, "=");
	}
	for(int i = 0; i <=max_y; i++){
		mvprintw(i, max_x, "|");
		mvprintw(i, 0, "|");
	}

	if(has_colors() == FALSE){
		endwin();
		printf("Your terminal does not support colors\n");
		//exit(1);
		return;
	}
	start_color();
	//CREATE COLOR PAIRS
	init_pair(3, COLOR_BLACK, COLOR_RED);
	init_pair(1, COLOR_BLACK, COLOR_BLUE);
	init_pair(2, COLOR_BLACK, COLOR_GREEN);
	init_pair(4, COLOR_WHITE, COLOR_BLACK);
}

void clearDisplay(int max_y, int max_x){
	int y, x;

	for(y = 1; y < max_y; y++)
		for(x = 1; x < max_x; x++)
			mvprintw(y, x, " ");
}

void updateDisplay(){
	clearDisplay(max_y,max_x);
	for(int i = 1; i < max_x; i++){
		mvprintw(max_y, i, "=");
		mvprintw(0, i, "=");
	}
	for(int i = 0; i <=max_y; i++){
		mvprintw(i, max_x, "|");
		mvprintw(i, 0, "|");
	}
	mvprintw(poles_y, poles_x[0], "==A==");
	mvprintw(poles_y, poles_x[1], "==B==");
	mvprintw(poles_y, poles_x[2], "==C==");
	mvwprintw(stdscr, 0, 0, "Tower of Hanoi");
	move(max_y + 1, 2);
	refresh();
}

void printBlock(int blockNumber, int stackNumber, int height){
	int boxScalar = 2*blockNumber - 1;
	int colorPair = (blockNumber % 3) + 1;
	attron( COLOR_PAIR( colorPair ) );
	
	mvprintw(1,1, "%d", height);
	int i;
	for(i = 0; i <= boxScalar /2; i++){
		mvprintw(poles_y - height, poles_x[stackNumber] - i, " ");
	}
	for(i = 0; i <= boxScalar /2; i++ ){
		mvprintw(poles_y - height, poles_x[stackNumber] + i, " ");
	}
	mvprintw(poles_y - height, poles_x[stackNumber], "%d", blockNumber);
	attroff(COLOR_PAIR( colorPair ) );
	refresh();
}

void printSuccessMessage(){
	mvprintw(max_y - 4, poles_x[1] - 3,"'Righteous!'");
	mvprintw(max_y - 3, poles_x[1] - 1,"   _    ");
	mvprintw(max_y - 2, poles_x[1] - 1," \\( )/");
	mvprintw(max_y - 1, poles_x[1] - 1,"  | |  ");
	refresh();
}

void endDisplay(){
	endwin();
}