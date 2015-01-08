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
	while(!is_game_over(board))
	{
		player_move(board);
		display_board(board);
	}
}

/* Requirement 6 - tests to see whether a move is valid or not */
BOOLEAN is_valid_move(struct move curr_move,enum cell_contents board[][BOARD_HEIGHT])
{
	enum cell_contents start = board[curr_move.start.x][curr_move.start.y];
	enum cell_contents end = board[curr_move.end.x][curr_move.end.y];
	if(start == INVALID || start == EMPTY || start == HOLE)
	{
		fprintf(stderr, "Error: Cannot move an empty block\n");
		return FALSE;
	}
	if(end == INVALID || end == PEG)
	{
		fprintf(stderr, "Error: Cannot move into an occupied block\n");
		return FALSE;
	}
	if(abs(curr_move.start.x - curr_move.end.x) != 2)
	{
		if(abs(curr_move.start.y - curr_move.end.y) != 2)
		{
			fprintf(stderr, "Error: Can only move orthagonally\n");
			return FALSE;
		}
	}
	else
	{
		if(curr_move.end.x > curr_move.start.x)
		{
			if(board[curr_move.start.x + 1][curr_move.end.y] == EMPTY)
			{
				fprintf(stderr, "Error: Must jump over something\n");
				return FALSE;
			}
		}
		else
		{
			if(board[curr_move.start.x - 1][curr_move.end.y] == EMPTY)
			{
				fprintf(stderr, "Error: Must jump over something\n");
				return FALSE;
			}
		}
	}
	return TRUE;
}

/* Requirement 7 - tests to see whether it is the end of the game */
BOOLEAN is_game_over(enum cell_contents board[][BOARD_HEIGHT])
{
	unsigned pegs = 0;
	unsigned validPegs = 0;
	int height, width;
	printf("Valid pegs:");
	for(height = 0; height < BOARD_HEIGHT; height++)
	{
		for(width = 0; width < BOARD_WIDTH; width++)
		{
			if(board[height][width] == PEG)
			{
				if(moves_exist(height, width, board))
				{
					validPegs++;
				}
				pegs++;
			}
		}
	}
	printf("\n");
	if(pegs == 1)
	{
		return TRUE;
	}
	if(validPegs == 0)
	{
		return TRUE;
	}
	printf("%d\n",pegs);
	printf("%d\n",validPegs);
	return FALSE;
}

BOOLEAN moves_exist(int height, int width, enum cell_contents board[][BOARD_HEIGHT])
{
	char x;
	x = width  + 'A';
	if(board[height + 2][width] == PEG && board[height - 2][width] == PEG && board[height][width + 2] == PEG && board[height][width - 2] == PEG)
	{
		return FALSE;
	}
	if(height == 0)
	{
		if(board[height][width - 2] == INVALID && board[height][width + 2] == INVALID)
		{
			if((board[height + 2][width] != EMPTY) || (board[height + 1][width] != PEG))
				return FALSE;
		}
		else
		{
			if(board[height][width - 1] == INVALID)
			{
				if((board[height][width + 2] == EMPTY || board[height][width + 1] == PEG)
				&& (board[height + 2][width] == EMPTY || board[height + 2][width] == PEG))
					return FALSE;
			}
			else
			{
				if((board[height][width - 2] == EMPTY || board[height][width - 1] == PEG)
				&& (board[height + 2][width] == EMPTY || board[height + 2][width] == PEG))
					return FALSE;
			}
		}
	}
	if(height == 6)
	{
		if(board[height][width - 2] == INVALID && board[height][width + 2] == INVALID)
		{
			if((board[height - 2][width] != EMPTY) || (board[height - 1][width] != PEG))
				return FALSE;
		}
		else
		{
			if(board[height - 2][width] != EMPTY || board[height - 1][width] != PEG)
			{
				if(board[height][width - 1] == INVALID)
				{
					if((board[height][width + 2] == EMPTY || board[height][width + 1] == PEG)
					&& (board[height - 2][width] == EMPTY || board[height - 1][width] == PEG))
						return FALSE;
				}
				else
				{
					if((board[height][width - 2] == EMPTY || board[height][width - 1] == PEG)
					&& (board[height - 2][width] == EMPTY || board[height - 1][width] == PEG))
						return FALSE;
				}
			}
		}
	}
	printf("%c%d ",x,height+1);
	return TRUE;
}

/* Requirement 5 - handle the logic for each individual move */
enum move_result player_move(enum cell_contents board[][BOARD_HEIGHT])
{
	char prompt[MAIN_LEN + EXTRA_CHARS];
	char width1, width2;
	int initialWidth, initialHeight, finalWidth, finalHeight;
	struct move mover;
	while(1 > 0)
	{
		if(strcmp(get_string(prompt, MAIN_LEN + EXTRA_CHARS),"FAIL") == 0)
			fprintf(stderr,"Error: Invalid Input, please try again\n");
		else
			break;
	}
	width1 = prompt[0];
	width2 = prompt[strlen(prompt) - 2];
	initialWidth = width1 - 'A';
	finalWidth = width2 - 'A';
	initialHeight = prompt[1] - '0' - 1;
	finalHeight = prompt[strlen(prompt) - 1] - '0' - 1;
	mover.start.x = initialWidth;
	mover.start.y = initialHeight;
	mover.end.x = finalWidth;
	mover.end.y = finalHeight;
	if(is_valid_move(mover,board) == TRUE)
	{
		board[mover.end.x][mover.end.y] = board[mover.start.x][mover.start.y];
		board[mover.start.x][mover.start.y] = EMPTY;
		if(abs(mover.end.x - mover.start.x) == 2)
		{
			if(mover.end.x > mover.start.x)
				board[mover.start.x + 1][mover.start.y] = EMPTY;
			else
				board[mover.start.x - 1][mover.start.y] = EMPTY;
		}
		else
		{
			if(mover.end.y > mover.start.y)
				board[mover.start.x][mover.start.y + 1] = EMPTY;
			else
				board[mover.start.x][mover.start.y - 1] = EMPTY;
		}
	}
	else
		fprintf(stderr, "Error: Invalid move, please try again\n");
	return SUCCESSFUL_MOVE;
}
