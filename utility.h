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
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MENU_LEN 1
#define MAIN_LEN 10
#define EXTRA_CHARS 2
#define DECIMAL 10
#define FAIL -1
#ifndef UTILITY_H 
#define UTILITY_H


typedef enum {
	FALSE, TRUE
} BOOLEAN;

/* clears residual data from stdin */
void read_rest_of_line(void);
int get_integer(void);
char* get_string(char prompt[], int length);
#endif
