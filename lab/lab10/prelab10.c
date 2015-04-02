/* Francois Mariette
   Prelab 10
   prelab10.c
*/


#include <stdio.h>
#include <stdlib.h>


void quick_sort(int* arr, int start, int end);
int partition(int* arr, int start, int end);

int main(int argc, char const *argv[])
{

	int length, value, i;
	FILE *fptr = fopen(argv[1], "r");

	if (fptr == NULL) {
		printf("Usage: ./a.out <input_filename>\n");	
		return -1;
	}
	else {
		fscanf(fptr, "%d", &length);
		int arr[length];

		for (i = 0; i < length; i++)
		{
			fscanf(fptr, "%d", &value);
			arr[i] = value;
		}

		for ( i = 0; i < length; i++ ) {
			printf("%d ", arr[i] );
		}
		printf("\n");

		quick_sort(arr, 0, length-1);

		for ( i = 0; i < length; i++ ){
			printf("%d ", arr[i] );
		}
		printf("\n");

	}


	return 0;
}

void quick_sort(int* arr, int start, int end)
{
	int middle;
	if (start < end ){
		middle = partition(arr, start, end);
		quick_sort(arr, start, middle-1 );
		quick_sort(arr, middle+1, end);
	}
}

int partition(int* arr, int start, int end)
{
	int pivot, i, middle, t;
	pivot = arr[start];
	i = start; middle = end+1;

	while (1) {
		
		while( arr[i] <= pivot && i <= end) {
			i++;
		}
		
		while ( arr[middle] > pivot){
			middle--;
		}
		if ( i >= middle ) {
			break;
		}
		t = arr[i];
		arr[i] = arr[middle];
		arr[middle] = t;
	}

	t = arr[start];
	arr[start] = arr[middle];
	arr[middle] = t;
	return middle;
}
