/* Fig. 7.10: figure7_10.c
	Converting a string to uppercase using a
	non-constant pointer to non-constant data */


#include <stdio.h>
#include <ctype.h>

void convertToUppercase( char *sPtr ); // prototype

int main( void )
{
	char string[] = "characters and $32.98"; // initialize char array

	printf("The string before conversion is: %s", string );
	convertToUppercase( string );
	printf("\nThe string after conversion is: %s\n", string );
	return 0; // Indicates successful terimination
} // end main

void convertToUppercase( char *sPtr )
{ // current character isn't '\0'
	while ( *sPtr != '\0' ) 
	{
		if ( islower( *sPtr ) ) { // if character is lower case
			*sPtr = toupper( *sPtr );
		} // end if

		++sPtr; // move sPtr to the next character
	} // end while
} // End function convertToUppercase