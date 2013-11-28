/* Figure 7.12: figure7_12.c
   Attempting to modify data through a 
   non-constant pointer to constant data. */

#include <stdio.h>

void f( const int *xPtr ); // Prototype

int main ( void )
{
	int y; //define y

	f( &y );
	printf("The value of y is %d\n", y); // f attempts illegal modification
	return 0; // Indicates successful termination
} // end main

// xPtr cannot be used to modify the value of the variable to which it points

void f( const int *xPtr ) 
{
	*xPtr = 100; // error: cannot modify a constant object
} // end function f