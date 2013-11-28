/* Figure 7.13: figure7_13.c
   Attempting to modify a constant pointer to non-constant data */

#include <stdio.h>

int main( void )
{
	int x; // define x
	int y; // define y

	/* ptr is a constant pointer to an integer that can be modified
	   through ptr, but ptr always points to the same memory location */
	int * const ptr = &x;

	*ptr = 7; // allowed: *ptr is not const
	*ptr = &y; //error: ptr is const: cannot assign new address

	printf("%d\n", y);
	return 0; // indicates successful termination
} // end main