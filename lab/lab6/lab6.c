/* Lab 6
 10/11/2013
 Project Key: LAB6
 Lab section: e
 Name: Francois Mariette
 PawPrint: 
 Student Number: 
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_FILE_LENGTH 20

typedef struct node_
{
	int value;
	struct node_* next;
}Node;

typedef Node* List;

int create_list(List** array, FILE* fp);
Node* new_node(int value);
int list_sum(Node* head);
void print_list(List* array, int length);
void insertion_sort( List* array, int length);
void free_list(List* array, int length);

int main(int argc, char const *argv[])
{
	FILE* fp;
	char filename[MAX_FILE_LENGTH];
	List* array = NULL;
    
	while (fp == NULL){
		if ( argc == 2 ){
			fp = fopen(argv[1], "r");
		}
		else {
			printf("Input a file to open: ");
			scanf("%s", filename);
			fp = fopen(filename, "r");
		}
	}
    
	create_list(&array, fp);
    
	return 0;
}

int create_list(List** array, FILE* fp)
{
	int length, index, value, i; // i is a counter
	Node* newNode;
    
	fscanf(fp, "%d", &length); // Gathers length of array
    *array =(List*)malloc(length * sizeof(Node*));
    
    for (i = 0; i < length; i++){
        (*array)[i] = NULL;
    }
    
	while(fscanf(fp, "%d%d", &index, &value)!=EOF)  {
		
		newNode = new_node(value);
		if ((*array)[index] == NULL)
		{
			(*array)[index] = newNode;
		}
		else {
			newNode->next = (*array)[index];
			(*array)[index] = newNode;
		}
	}
	print_list(*array, length);
	return length;
}

Node* new_node(int value)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
    
	newNode->value = value;
	newNode->next = NULL;
    
	return newNode;
}

int list_sum(Node* head)
{
    int sum = 0;
    while (head != NULL) {
        sum += head->value;
        head = head->next;
    }
    
    return sum;
}

void print_list(List* array, int length)
{
    
	Node* head;
	int i, sum;
	for (i = 0; i < length; i++){
		printf("|%d| ", i );
        if (array[i] == NULL){
            printf("NULL");
        }
        else{
            head = array[i];
            sum = list_sum(head);
            while (head != NULL){
                printf("%d -> ", head->value);
                head = head->next;
            }
        }
		printf("NULL = %d\n", sum);
	}
}


