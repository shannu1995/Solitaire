/***********************************************************************
 * COSC1076 - Advanced Programming Techniques
 * Summer 2015 Assignment #1 
 * Full Name        : EDIT HERE
 * Student Number   : EDIT HERE
 * Course Code      : EDIT HERE
 * Program Code     : EDIT HERE
 * Start up code provided by David Shaw
 * Based on 2014 code by Paul Miller and Virginia King
 **********************************************************************/

#include "board.h"
void init_board(enum cell_contents board[][BOARD_HEIGHT])
{
	int height, width;
	for(height = 0; height < BOARD_HEIGHT; height++)
	{
		for(width = 0; width < BOARD_WIDTH; width++)
		{
			board[height][width] = master_board[height][width];
		}
	}
}

void display_board(enum cell_contents board[][BOARD_HEIGHT])
{
	int width,height;
	printf("\n");
	for(height = 0; height < BOARD_HEIGHT; height++)
	{
		printf("   ");
		if(height > 1 && height <= 5)
		{
			for(width = 0; width < BOARD_WIDTH; width++)
			{
				printf("%s+---%s",COLOR_LINES,COLOR_RESET);
			}
			printf("%s+%s",COLOR_LINES,COLOR_RESET);
			printf("\n%d",height+1);
		}
		else
		{
			for(width = 0; width < BOARD_WIDTH; width++)
				printf(" ");
			printf(" ");
			for(width = 0; width < 3; width++)
				printf("%s+---%s",COLOR_LINES,COLOR_RESET);
			printf("%s+%s",COLOR_LINES,COLOR_RESET);
			printf("\n%d",height+1);
		}
		if(height > 1 && height < 5)
			printf("  ");
		for(width = 0; width < BOARD_WIDTH; width++)
		{
			switch(board[width][height])
			{
				
				case INVALID:
					if(width >= 5)
					{
					}
					else
						printf("     ");
					break;
				case PEG:
					printf("%s|%s %sO%s ",COLOR_LINES,COLOR_RESET,COLOR_PEG,COLOR_RESET);
					break;
				case HOLE:
					printf("%s|%s %s.%s ",COLOR_LINES,COLOR_RESET,COLOR_LINES,COLOR_RESET);
					break;
			}
		}
		printf("%s|%s\n",COLOR_LINES,COLOR_RESET);
	}
	for(width = 0; width <= 10; width++)
	{
		printf(" ");
	}
	for(width = 1; width <= 3; width++)
	{
		printf("%s+---%s",COLOR_LINES,COLOR_RESET);
	}
	printf("%s+%s",COLOR_LINES,COLOR_RESET);
	printf("\n");
	printf("    ");
	for(width = 0; width < BOARD_WIDTH; width++)
	{
		printf(" %c  ",'A'+width);
	}
	printf("\n");
}
