/* Prelab 6
   Francois Mariette
*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100

void insertionsort(int array[], int length);

int main(void)
{
	int array[SIZE], i; // declares array and counter
	srand(time(NULL));

	printf("Initial array\n\n");

	for( i = 0; i < SIZE; i++){
		array[i] = rand() % (SIZE + 1);
	}

	for (i = 0; i < SIZE; i++){
		printf("%d ", array[i] );
	}

	printf("\n\nSorted Array\n");

	insertionsort(array, SIZE);

}


void insertionsort(int array[], int length)
{
	int tempElement;
	int i, j; // i is counter for initial array, j is counter for temp_array

	for (i = 0; i < length; i++){

		tempElement = array[i];
		j = i - 1;

		while ( tempElement < array[j] && j >= 0){
			array[j+1] = array[j];
			j = j-1; 
		}

		array[j+1] = tempElement;
	}


	for (i = 0; i < SIZE; i++) {
		printf("%d ", array[i]);
	}

	printf("\n\n");
}
