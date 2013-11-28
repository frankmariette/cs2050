/* Fig. 7.20: figure7_20.c
   Using subscripting and pointer notations with arrays */

#include <stdio.h>

int main(void)
{
	int b[] = { 10, 20, 30, 40 }; // initialize array
	int *bPtr = b; // set bPtr to point to array b
	int i; // Counter
	int offset; // Counter

	// Output array b using array subscript notation
	printf("Array b printed with: \nArray subscript notation\n");

	// Loop through array b
	for ( i=0; i < 4; i++ ){
		printf("b[ %d ] = %d\n", i,  b[i]);
	} // End for

	// Output array b using array name and pointer/offset notation
	printf("\nPointer/offset notation where\n"
		   "the pointer is the array name\n" );
	
	// loop through array b
	for ( offset = 0; offset < 4; offset++ ) {
		printf("( b + %d ) = %d\n", offset, *(b + offset) );
	} // end for

	// Output array b using bPtr and array subscript notation
	printf("\nPointer subscript notation\n");

	// loop through array b
	for ( offset = 0; offset < 4; offset++ ) {
		printf("bPtr[ %d ] = %d\n", offset, bPtr[offset] );
	} // end for

	// Output array b using bPtr and pointer/offset notation
	printf("\nPointer/offset notation\n");

	// Loop through array 
	for ( offset = 0; offset < 4; offset++ ){
		printf("*( bPtr + %d ) = %d\n", offset, *(bPtr + offset) );
	} // end for

	return 0; // Indicates successful termination

} // end main