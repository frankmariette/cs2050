/* Figure 7.28: figure7_28.c
   Demonstrating an array of pointers to functions */
#include <stdio.h>

/* Prototypes */
void function1( int a );
void function2( int b );
void function3( int c );

int main( void )
{
	/* initialize array of 3 pointers to functions that each take an int argument and return void */
	void (*f[3])( int ) = { function1, function2, function3 };

	int choice;

	printf("Enter a number between 0 and 2, 3 to end: ");
	scanf("%d", &choice);

	/* process the user's choice */
	while ( choice >= 0 && choice < 3 ) {

		/* invoke function at location choice in array f and pass choice as an argument */
		(*(f + choice))( choice );

		printf( "Enter a number between 0 and 2, 3 to end: ");
		scanf("%d", &choice );
	} // end while

	printf("Progam execution completed.\n");
	return 0; // indicates successful termination of program
} // end main 

void function1( int a )
{
	printf("You entered %d so function1 was called\n\n", a );
} // end function1

void function2( int b )
{
	printf("You entered %d so function2 was called\n\n", b );
} // end function2

void function3( int c)
{
	printf("You entered %d so function3 was called\n\n", c );
} // end function3

