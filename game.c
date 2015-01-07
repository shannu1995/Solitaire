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

#include "game.h"

/* Requirement 3 - controls the flow of play in the game */
void play_game(void)
{
	enum cell_contents board[BOARD_WIDTH][BOARD_HEIGHT];
	init_board(board);
	display_board(board);
	player_move(board);
	display_board(board);
}

/* Requirement 6 - tests to see whether a move is valid or not */
BOOLEAN is_valid_move(struct move curr_move,
        enum cell_contents board[][BOARD_HEIGHT])
{
	/* delete this and write your own comments and code here */
	return FALSE;
}

/* Requirement 7 - tests to see whether it is the end of the game */
BOOLEAN is_game_over(enum cell_contents board[][BOARD_HEIGHT])
{
	/* delete this and write your own comments and code here */
	return FALSE;
}

/* Requirement 5 - handle the logic for each individual move */
enum move_result player_move(enum cell_contents board[][BOARD_HEIGHT])
{
	char prompt[MAIN_LEN + EXTRA_CHARS];
	char width1, width2;
	int initialWidth, initialHeight, finalWidth, finalHeight;
	while(1 > 0)
	{
		if(strcmp(get_string(prompt, MAIN_LEN + EXTRA_CHARS),"FAIL") == 0)
			fprintf(stderr,"Error: Invalid Input, please try again\n");
		else
			break;
	}
	width1 = prompt[0];
	width2 = prompt[strlen(prompt) - 2];
	initialWidth = width1 - 'A' - 1;
	finalWidth = width2 - 'A' - 1;
	initialHeight = prompt[1] - '0' - 1;
	finalHeight = prompt[strlen(prompt) - 1] - '0' - 1;
	printf("Coordinates are: %d,%d-%d,%d",initialHeight, initialWidth, finalHeight, finalWidth);
	board[finalWidth][finalHeight] = board[initialWidth][initialHeight];
	board[initialWidth][initialHeight] = EMPTY;
	return SUCCESSFUL_MOVE;
}


