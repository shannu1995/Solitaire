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

#include "solitaire.h"
#include "utility.h"
#include "game.h"

void display_menu(void)
{
	char  name_of_game[] = "\nPEG SOLITAIRE\n\n";
	char  option1[] = "1. Play Game\n";
	char  option2[] = "2. How to Play\n";
	char  option3[] = "3. Quit\n"; 
	printf("%s%s%s%s",name_of_game,option1,option2,option3);
}

int main(int argc, char *argv[])
{
	int choice;
	display_menu();
	while((choice = get_integer()) == FAIL)
	{
		fprintf(stderr, "Invalid Input, please try again\n");
	}
	switch(choice)
	{
		case 1:
			play_game();
			break;
		default:
			printf("Not yet ready\n");
			break;
	}
	return EXIT_SUCCESS;
}

