//
//  main.c
//  figure7_7
//
//  Created by Francois Mariette on 8/31/13.
//  Copyright (c) 2013 Francois Mariette. All rights reserved.
//

#include <stdio.h>

void cubeByReference( int *nptr ); /*prototype */

int main(void)
{
	int number = 5;
    
	printf("The originial value of number is %d", number);
    
	// Pass the address of number to cubeByReference
	cubeByReference( &number );
    
	printf("\nThe new value of number is %d\n", number);
	return 0;
}

void cubeByReference( int *nPtr ) {
	*nptr = *nPtr * *nPtr * *nPtr;
}
