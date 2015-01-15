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

void menu_choose(void)
{
	int choice;
	while((choice = get_integer()) == FAIL)
	{
		fprintf(stderr, "Invalid Input, please try again\n");
	}
	switch(choice)
	{
		case 1:
			play_game();
			display_menu();
			menu_choose();
			break;
		case 3:
			exit(0);
			break;
		default:
			display_rules();
			display_menu();
			menu_choose();
			break;
	}
	
}

int main(int argc, char *argv[])
{
	display_menu();
	menu_choose();
	return EXIT_SUCCESS;
}

void display_rules(void)
{
	char objective[] = "\nOBJECTIVE: To remove as many pegs as possible\n";
	char rule1[] = "Must jump over a peg for it to be deleted\n";
	char rule2[] = "Cannot move diagonally\n";
	char rule3[] = "Cannot move out of bounds\n";
	printf("%s%s%s%s",objective,rule1,rule2,rule3);
}
