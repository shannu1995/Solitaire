/***********************************************************************
 * COSC1076 - Advanced Programming Techniques
 * Summer 2015 Assignment #1 
 * Full Name        : Shanmukha Prasad Sivapurapu
 * Student Number   : s3453738
 * Course Code      : BP 096
 * Program Code     : COSC 1076
 * Start up code provided by David Shaw
 * Based on 2014 code by Paul Miller and Virginia King
 **********************************************************************/
#include "utility.h"
#ifndef BOARD_H 
#define BOARD_H

#define BOARD_WIDTH	7
#define BOARD_HEIGHT	7
#define WIDTH_RIGHT_BOUND	6
#define WIDTH_LEFT_BOUND	0
#define HEIGHT_UPPER_BOUND	6
#define HEIGHT_LOWER_BOUND	0

/* colour codes for displaying the board */
#define COLOR_RESET     "\x1b[0m"
#define COLOR_LINES     "\x1b[2;34m"    /* blue */
#define COLOR_HOLE      "\x1b[2;34m"    /* blue */
#define COLOR_PEG       "\x1b[1;37m"    /* white */

struct position {
        int x, y; 
};

enum cell_contents {
	INVALID, HOLE, PEG, EMPTY /*Added this*/
};

/* The initial game board - this is an example of the occasional
 * exception to the rule against global variables. Be aware that
 * this should be the only global variable in your program */
static const enum cell_contents master_board[BOARD_HEIGHT][BOARD_WIDTH] = {
	{ INVALID, INVALID, PEG, PEG, PEG, INVALID, INVALID },
	{ INVALID, INVALID, PEG, PEG, PEG, INVALID, INVALID },
	{ PEG, PEG, PEG, PEG, PEG, PEG, PEG },
	{ PEG, PEG, PEG, HOLE, PEG, PEG, PEG },
	{ PEG, PEG, PEG, PEG, PEG, PEG, PEG },
	{ INVALID, INVALID, PEG, PEG, PEG, INVALID, INVALID },
	{ INVALID, INVALID, PEG, PEG, PEG, INVALID, INVALID }
};

/* Requirement 2 - copies the contents of master_board to a local
 * board for each game */
void init_board(enum cell_contents board[][BOARD_WIDTH]);

/* Requirement 4 - displays the puzzle game board to the screen */
void display_board(enum cell_contents board[][BOARD_WIDTH]);


#endif
