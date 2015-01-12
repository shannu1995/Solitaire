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
	if(curr_move.end.x < WIDTH_LEFT_BOUND || curr_move.end.y < HEIGHT_LOWER_BOUND || curr_move.end.x > WIDTH_RIGHT_BOUND || curr_move.end.y > HEIGHT_UPPER_BOUND)
	{
		fprintf(stderr, "Error: Cannot move out of bounds\n");
		return FALSE;
	}
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
		else
		{
			if(curr_move.end.y > curr_move.start.y)
			{
				if(board[curr_move.start.x][curr_move.start.y + 1] == EMPTY || board[curr_move.start.x][curr_move.start.y + 1] == HOLE)
				{
					fprintf(stderr, "Error: Must jump over something\n");
					return FALSE;
				}
			}
			else
			{
				if(board[curr_move.start.x][curr_move.start.y - 1] == EMPTY || board[curr_move.start.x][curr_move.start.y - 1] == HOLE)
				{
					fprintf(stderr, "Error: Must Jump over something\n");
					return FALSE;
				}
			}
		}
	}
	else
	{
		if(curr_move.end.x > curr_move.start.x)
		{
			if(board[curr_move.start.x + 1][curr_move.start.y] == EMPTY || board[curr_move.start.x + 1][curr_move.end.y] == HOLE)
			{
				fprintf(stderr, "Error: Must jump over something\n");
				return FALSE;
			}
		}
		else
		{
			if(board[curr_move.start.x - 1][curr_move.start.y] == EMPTY || board[curr_move.start.x - 1][curr_move.end.y] == HOLE)
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
	printf("Suggested moves:");
	for(height = 0; height < BOARD_HEIGHT; height++)
	{
		for(width = 0; width < BOARD_WIDTH; width++)
		{
			
			if(moves_exist(height, width, board))
			{
				validPegs++;
			}
			if(board[height][width] == PEG)
				pegs++;
		}
	}
	printf("\n");
	if(validPegs == 0)
	{
		printf("Game has ended!\n%d pegs remaining\n",pegs);
		if(pegs == 1)
		{
			printf("Congratulations! You have only one peg remaining\n");
		}
		return TRUE;
	}
	return FALSE;
}

BOOLEAN moves_exist(int height, int width, enum cell_contents board[][BOARD_HEIGHT])
{
	struct move possible_move;
	struct position vertical1, vertical2, horizontal1, horizontal2;
	possible_move.start.x = width;
	possible_move.start.y = height;
	vertical1.x = width;
	vertical1.y = height + 2;
	vertical2.x = width;
	vertical2.y = height - 2;
	horizontal1.x = width + 2;
	horizontal1.y = height;
	horizontal2.x = width - 2;
	horizontal2.y = height;
	if(possible_move.end = vertical1, check_validity(possible_move, board))
	{
		printf("%c%d-%c%d ", width + 'A',height + 1, vertical1.x + 'A', vertical1.y + 1);
		return TRUE;
	}
	if(possible_move.end = vertical2, check_validity(possible_move, board))
	{
		printf("%c%d-%c%d ", width + 'A',height + 1,vertical2.x + 'A', vertical2.y + 1);
		return TRUE;
	}
	if(possible_move.end = horizontal1, check_validity(possible_move, board))
	{
		printf("%c%d-%c%d ", width + 'A',height + 1,horizontal1.x + 'A', horizontal1.y + 1);
		return TRUE;
	}
	if(possible_move.end = horizontal2, check_validity(possible_move, board))
	{
		printf("%c%d-%c%d ", width + 'A',height + 1,horizontal2.x + 'A', horizontal2.y + 1);
		return TRUE;
	}
	return FALSE;
}

/* Requirement 5 - handle the logic for each individual move */
enum move_result player_move(enum cell_contents board[][BOARD_HEIGHT])
{
	char prompt[MAIN_LEN + EXTRA_CHARS];
	char width1, width2;
	int initialWidth, initialHeight, finalWidth, finalHeight;
	struct move mover;
	printf("Please enter input in the format: A1-B1:\n");
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
	if(width1 >= 'a' && width1 <= 'z')
		width1 = toupper(width1);
	if(width2 >= 'a' && width2 <= 'z')
		width2 = toupper(width2);
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

BOOLEAN check_validity(struct move curr_move,enum cell_contents board[][BOARD_HEIGHT])
{
	enum cell_contents start = board[curr_move.start.x][curr_move.start.y];
	enum cell_contents end = board[curr_move.end.x][curr_move.end.y];
	if(curr_move.end.x < 0 || curr_move.end.y < 0 || curr_move.end.x > 6 || curr_move.end.y > 6)
	{
		return FALSE;
	}
	if(start == INVALID || start == EMPTY || start == HOLE)
	{
		return FALSE;
	}
	if(end == INVALID || end == PEG)
	{
		return FALSE;
	}
	if(abs(curr_move.start.x - curr_move.end.x) != 2)
	{
		if(abs(curr_move.start.y - curr_move.end.y) != 2)
		{
			return FALSE;
		}
		else
		{
			if(curr_move.end.y > curr_move.start.y)
			{
				if(board[curr_move.start.x][curr_move.start.y + 1] == EMPTY || board[curr_move.start.x][curr_move.start.y + 1] == HOLE)
				{
					return FALSE;
				}
			}
			else
			{
				if(board[curr_move.start.x][curr_move.start.y - 1] == EMPTY || board[curr_move.start.x][curr_move.start.y - 1] == HOLE)
				{
					return FALSE;
				}
			}
		}
	}
	else
	{
		if(curr_move.end.x > curr_move.start.x)
		{
			if(board[curr_move.start.x + 1][curr_move.start.y] == EMPTY || board[curr_move.start.x + 1][curr_move.start.y] == HOLE)
			{
				return FALSE;
			}
		}
		else
		{
			if(board[curr_move.start.x - 1][curr_move.start.y] == EMPTY || board[curr_move.start.x - 1][curr_move.start.y] == HOLE)
			{
				return FALSE;
			}
		}
	}
	return TRUE;
}
