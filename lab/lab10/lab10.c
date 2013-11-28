/* Lab 10
 11/15/2013
 Project Key: LAB10
 Lab section: e
 Name: Francois Mariette
 PawPrint: fhmqpd
 Student Number: 14103682
 */


#include <stdio.h>
#include <stdlib.h>


int compareSmallerOnLeft(int num1, int num2);
int compareSmallerOnRight(int num1, int num2);
void quick_sort(int* arr, int start, int end, int(*compare)(int,int));
int partition(int* arr, int start, int end, int(*compare)(int,int));
int b_search(int *arr, int data, int(*compare)(int, int), int start, int end);
void print(int* arr, int length);

int main(int argc, char const *argv[])
{
	int length, value, i, sort_order;
	int(*compare)(int, int);
	FILE *input, *search;
	input = fopen(argv[1], "r");
	search = fopen(argv[2], "r");

	if (input == NULL || search == NULL){
		printf("Usage: ./a.out <input_file> <search_file>\n");
		return -1;
	}

	fscanf(input, "%d", &length);
	int arr[length];

	for (i = 0; i < length; i++){
		fscanf(input, "%d", &value);
		arr[i] = value;
	}

	printf("Do you want to sort with smaller values on the right(1) or left(2)? ");
	scanf("%d", &sort_order);
	while(sort_order > 2 && sort_order < 1){
		printf("Please enter 1 for smaller values on the right or 2 for smaller values on the left\n");
		scanf("%d", &sort_order);
	}

	if ( sort_order == 1 ){
		compare = compareSmallerOnRight;
	}
	else {
		compare = compareSmallerOnLeft;
	}
	print(arr, length);
	quick_sort(arr, 0, length-1, compare);
	print(arr, length);

	while (fscanf(search, "%d", &value) != EOF ){
		if (b_search(arr, value, compare, 0, length-1) == 1){
			printf("%d was found in the array.\n", value );
		}
		else {
			printf("%d was not found in the array\n", value);
		}
	}

	return 0;
}

int compareSmallerOnLeft(int num1, int num2)
{
	if (num1 == num2){
		return 0;
	}
	else if (num1 > num2){
		return -1;
	}
	else {
		return 1;
	}
}

int compareSmallerOnRight(int num1, int num2){
	if (num1 == num2){
		return 0;
	}
	else if ( num1 > num2 ){
		return 1;
	}
	else {
		return -1;
	}
}

void quick_sort(int* arr, int start, int end, int(*compare)(int,int))
{
	int middle;
	if (start < end){
		middle = partition(arr, start, end, compare);
		quick_sort(arr, start, middle-1, compare);
		quick_sort(arr, middle+1, end, compare);
	}
}

int partition(int* arr, int start, int end, int(*compare)(int,int))
{
	int pivot, i, middle, temp;
	pivot = arr[start];
	i = start;
	middle = end;

	while(1){
		while( (compare(arr[i],pivot) == 0 || compare(arr[i],pivot) == 1) && i <= end ) {
			i++;
		}

		while( compare(arr[middle], pivot) == -1 ){
			middle--;
		}
		if ( i >= middle ) {
			break;
		}
		temp = arr[i];
		arr[i] = arr[middle];
		arr[middle] = temp;
	}


	temp = arr[start];
	arr[start] = arr[middle];
	arr[middle] = temp;
	return middle;

}

int b_search(int *arr, int data, int(*compare)(int, int), int start, int end)
{
	int middle = (start + end) / 2;

	while ( start <= end ){
		if (compare(arr[middle],data) == -1) {
			end = middle - 1;
		}
		else if (compare(arr[middle], data) == 1){
			start = middle + 1;
		}
		else{
			return 1;
		}
		middle = (start + end)/2;
	}

	return 0;
}

void print(int *arr, int length)
{
	int i;

	for(i = 0; i < length; i++){
		printf("%d ", arr[i] );
	}
	printf("\n");
}