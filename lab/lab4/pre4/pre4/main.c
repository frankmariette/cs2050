/* Francois Mariette
 Prelab4: prelab4.c
 Recursion
 */

#include <stdio.h>
#include <stdlib.h>

void mergeSort(int array[], int n);
void merge(int array[], int *arr1, int n1, int *arr2, int n2);
int * copySubArray( int array[], int start, int n );
int searchArray( int *array, int target, int n );
long int factorial(long int n);


int main ( void )
{
    
    
    int array[] = { 5, 9, 10, 6, 4, 8, 7, 2, 1, 3 };
    
    int input, target, n;
    n = sizeof(array)/sizeof(int); // Provides size of array

    
    printf( "Input an integer: ");
    scanf("%d", &input);
    printf("The factorial of %d is %ld.\n", input ,factorial(input));
    
    
    printf("Pick an integer between 1 and 10 to find in the array\n");
    scanf("%d", &target);
    searchArray(array, target, n);
    
    return 0;
}


int searchArray( int *array, int target, int n )
{
	int i; // counter
    int low = 0, high = n-1;
    int middle;
    
	/* Initial pass to check if array is sorted */
	for ( i = 0; i < (n - 1); i++ ){
		if ( array[i] > array[i + 1] ) {
			mergeSort(array, n);
		}
		else {
			;
		}
	}

	while (low <= high){
		middle = (low + high) / 2;
		if ( array[middle] == target ){
		 	printf("%d was found at location %d\n",target, middle+1);
			return middle;
		}
		else if (array[middle] > target) {
			high = middle - 1;
		}
		else {
			low = middle + 1;
		}
	}
	printf("%d not found in array\n", target);
	return -2;
}

void mergeSort( int array[], int n )
{
	int n1, n2, *arr1, *arr2;
    
	if ( n <= 1 ) {
		return;
	}
    
	n1 = n / 2;
	n2 = n - n1;
	arr1 = copySubArray(array, 0, n1);
	arr2 = copySubArray(array, n1, n2);
	mergeSort(arr1, n1);
	mergeSort(arr2, n2);
	merge(array, arr1, n1, arr2, n2);
	free(arr1);
	free(arr2);
    
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

void merge(int array[], int *arr1, int n1, int *arr2, int n2)
{
	int p, p1, p2;
	p = p1 = p2 = 0;
	while (p1 < n1 && p2 < n2) {
		if ( arr1[p1] < arr2[p2] ){
			array[p++] = arr1[p1++];
		}
		else {
			array[p++] = arr2[p2++];
		}
	}
	while( p1 < n1 ) array[p++] = arr1[p1++];
	while( p2 < n2 ) array[p++] = arr2[p2++];
}

long int factorial ( long int n )
{
	if ( n == 0 ){
		return 1;
	}
	else if ( (n - 1) == 0  ) {
		return n;
	}
	else {
		return n * factorial(n-1);
	}
}