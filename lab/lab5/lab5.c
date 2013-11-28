/* 
   Lab 5
   10/04/13
   Project key: LAB5
   Lab Section: e
   Name: Francois Mariette
   PawPrint: FHMQPD
   Student Number: 14103682
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int linearSearch( int array[], int length, int key );
int binarySearch( int array[], int length, int key );
void merge(int array[], int *arr1, int n1, int *arr2, int n2);
void mergeSort(int array[], int n);
int * copySubArray( int array[], int start, int n );

int main(int argc, char **argv)
{
	FILE *fptr; // File pointer
	
	int fcounter, i; // counters
	int length;
	int key;
	clock_t start, end; // Start and end timers
	double runtime;

	printf("%15s%15s%15s%15s\n", "L search 1", "Sort", "L Search 2", "B search" );
	for( fcounter = 2; fcounter < argc; fcounter++ ) {
		fptr = fopen( argv[fcounter], "r");
		if (fptr == NULL){
			printf("Unable to open %s\n", argv[fcounter] );
		}
		else{
			

			fscanf( fptr, "%d", &length );
			int array[length];

			for ( i = 0; i < length; ++i){
				fscanf(fptr, "%d", &array[i]);
			}

			/* Linear search 1 time */
			start = clock();
			linearSearch( array, length, key );
			end = clock();
			runtime = (double)(end-start)/ CLOCKS_PER_SEC;
			printf("%15.10f", runtime );

			/* Merge sort timer */
			start = clock();
			mergeSort(array, length);
			end = clock();
			runtime = (double)(end-start)/ CLOCKS_PER_SEC;
			printf("%15.10f", runtime);

			/* Linear search 2 time */
			start = clock();
			linearSearch( array, length, key );
			end = clock();
			runtime = (double)(end-start)/ CLOCKS_PER_SEC;
			printf("%15.10f", runtime );

			/* Binary search time */
			start = clock();
			binarySearch( array, length, key );
			end = clock();
			runtime = (double)(end-start)/ CLOCKS_PER_SEC;
			printf("%15.10f\n", runtime );

		}
	
	}


	return 0;
}

/* Iterates through array to find key */
int linearSearch( int array[], int length, int key )
{
	int i; // Counter
	for (i = 0; i < length; i++ ){
		if (array[i] == key){
			return 1;
		}
	}
	return 0;
}

/* Recursively sorts the array */
void mergeSort( int array[], int length )
{
	int n1, n2, *arr1, *arr2;
    
	if ( length <= 1 ) {
		return;
	}
    
	n1 = length / 2;
	n2 = length - n1;
	arr1 = copySubArray(array, 0, n1);
	arr2 = copySubArray(array, n1, n2);
	mergeSort(arr1, n1);
	mergeSort(arr2, n2);
	merge(array, arr1, n1, arr2, n2);
	free(arr1);
	free(arr2);
    
}

void merge(int array[], int *arr1, int n1, int *arr2, int n2)
{
	int p, p1, p2;
	p = p1 = p2 = 0;
	while (p1 < n1 && p2 < n2) {  // makes sure that the loop breaks when the end of an array is reached
		if ( arr1[p1] < arr2[p2] ){ // if element from arr1 is smaller, sets that one first in the main array
			array[p++] = arr1[p1++]; 
		}
		else {
			array[p++] = arr2[p2++];
		}
	}
	while( p1 < n1 ) array[p++] = arr1[p1++];
	while( p2 < n2 ) array[p++] = arr2[p2++];
}

int * copySubArray( int array[], int start, int n )
{
	int i, *result;
	result = (int*)malloc(n * sizeof(int));
	for (i = 0; i < n; i++) {
		result[i] = array[start + i];
	}
	return (result);
}

int binarySearch( int array[], int length, int key )
{
	int i; // counter
    int low = 0, high = length-1;
    int middle;
 
	while (low <= high){
		middle = (low + high) / 2;
		if ( array[middle] == key ){
			return middle;
		}
		else if (array[middle] > key) {
			high = middle - 1;
		}
		else {
			low = middle + 1;
		}
	}
	return -2;
}