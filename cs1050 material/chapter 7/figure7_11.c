/* Fig. 7.11: figure7_11.c
   Printing a string one character at a time using
   a non-constant pointer to constant data */

#include <stdio.h>

void printCharacters( const char *sPtr );

int main (void) 
{
	/* initialize char array */
	char string[] = "print characters of a string";

	printf( "The string is:\n" );
	printCharacters( string );
	printf( "\n" );
	return 0; // indicates successful termination
} // end main 

void printCharacters( const char *sPtr )
{
	for ( ; *sPtr != '\0'; sPtr++ ) { // no initialization
		printf("%c", *sPtr );
	} // end for
} // end printCharacters function