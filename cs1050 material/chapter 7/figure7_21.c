/* Figure 7.21: figure7_21.c
   Copying a string using array notation and pointer notation */

#include <stdio.h>

void copy1 ( char * const s1, const char * s2 );
void copy2 ( char *s1, const char *s2 );

int main (void) 
{
	char string1[ 10 ]; // Create array string1
	const char *string2 = "Hello"; // Create a pointer to a string
	char string3[ 10 ]; // Create array string3
	char string4[] = "Good Bye"; // Create a pointer to a string

	copy1( string1, string2 );
	printf("string1 = %s\n", string1 );

	copy2( string3, string4);
	printf("string3 = %s\n", string3 );

	return 0; // indicates successful termination
} // ends main

void copy1 ( char * const s1, const char * s2 )
{
	int i;

	// loop through strings
	for ( i = 0; (s1[ i ] = s2[i]) != '\0'; i++ ) {
		; // does nothing in the body
	} // end for
}

void copy2 ( char *s1, const char *s2 )
{
	int i;

	// loop through strings
	for ( ; ( *s1 = *s2 ) != '\0'; s1++, s2++ ){
		;
	} // end for
} // end function copy2