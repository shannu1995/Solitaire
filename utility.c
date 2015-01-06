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

/* Tidy up residual data in stdin when encountering an error. You will 
 * need to use this when there is a possibility that there will be 
 * leftover characters in the input buffer. */
void read_rest_of_line(void)
{
        int ch;
        /* remove all characters from the buffer */
        while (ch = getc(stdin), ch != '\n' && ch != EOF)
                ;
        /* clear the error status of the input pointer */
        clearerr(stdin);
}

int get_integer(void)
{
	char prompt[MENU_LEN + EXTRA_CHARS];
	char *endPtr;
	int choice;
	fgets(prompt, MENU_LEN + EXTRA_CHARS, stdin);
	if(prompt[strlen(prompt) - 1] != '\n')
	{
		fprintf(stderr, "Error: Input too long\n");
		return FAIL;
	}
	prompt[strlen(prompt) - 1] = '\0';
	choice = strtol(prompt,&endPtr,DECIMAL);
	if(*endPtr)
	{
		fprintf(stderr, "Error: Input not numeric\n");
		return FAIL;
	}
	if(choice < 1 || choice > 3)
	{
		fprintf(stderr, "Error: Input should be between 1 and 3\n");
		return FAIL;
	}
	return choice;
}
