/* Francois Mariette
   Prelab 7
   
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node_
{
	int value;
	struct node_ *next;
}Queue;

/* Prototypes */
Queue* enqueue(Queue* head, int value);
int dequeue(Queue** head);
void print_queue(Queue* head);

#define MAX 20


int main(int argc, char const *argv[])
{
	Queue** priority_queue = NULL;
	Queue* head = NULL;
	FILE *fp = fopen(argv[1], "r");
	char filename[MAX];
	int value;

	while (fp == NULL){
		printf("Input file can't be opened. Enter a file to open\n");
		scanf("%s", filename);
		fp = fopen(filename, "r");
	}

	while (fscanf(fp, "%d", &value) != EOF){
		head = enqueue(head, value);
	} 

	print_queue(head);


	return 0;
}

Queue* enqueue(Queue* head, int value)
{
	Queue* new_node =(Queue*)malloc(sizeof(Queue));
	new_node->value = value;
	new_node->next = NULL;

	if (head == NULL){
		head = new_node;
	}
	else {
		if(head->next == NULL){
			head->next = new_node;
		}
		else {
			enqueue(head->next, value);
		}
	}

	return head;
}

int dequeue(Queue** head)
{
	Queue* temp = NULL, current = NULL;
	if ( (*head)->next->next == NULL){
		temp = (*head)->next;
		free(temp);
		(*head)->next = NULL;
	}
	else {

		while (current->next->next != NULL){
			current = current->next;
		}
	}
}

void print_queue(Queue* head)
{
	if (head == NULL){
		printf("Queue is empty");
	}
	else {
		while (head != NULL){
			printf( "%d->", head->value );
			head = head->next;
		}
		printf("NULL\n");
	}

}



