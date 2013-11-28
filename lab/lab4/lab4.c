/* Lab 4
   09/20/2013
   Project Key: ibm
   Lab secontion: E
   Name: Francois Mariette
   PawPrint: FHMQPD
   Student Number: 14103682
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int value;
	struct node* next;
}Node;

/* Prototypes */
Node* create_node(int data);
Node* insert_end(Node* head, int data);
void print_list(Node* head);
int search(Node* head, int data); 
void factorial_list(Node* head);
void delete_list(Node* head);
long int factorial( int n );


int main ( int argc, char **argv )`
{
	
	if (argc < 2){
		printf("No input file provided!\n");
		return -1;
	}
	else {
		FILE *fPtr;
		int input; // values for linked list
		Node* head = NULL;  // head of list


		fPtr = fopen(argv[1], "r");
		
		while ( (fscanf(fPtr, "%d", &input) != EOF ) ){
			head = insert_end(head, input);
		}
		print_list(head);

		int target;
		printf("Enter a number to search for: \n");
		scanf("%d", &target);
		search(head, target);
		factorial_list(head);
		print_list(head);
		delete_list(head);
	}	

}


Node* insert_end(Node* head, int data)
{
	Node* newNode = (Node*) malloc( sizeof(Node) );
	newNode->value = data;
	newNode->next = NULL;


	if ( head == NULL ) { // base case
		head = newNode;
		return head;
	}
	else {
		if (head->next == NULL){
			head->next = newNode;
			insert_end(newNode->next, data);
		}
		else {

			insert_end(head->next, data);
		}
	}
	return head;
}

void print_list(Node* head)
{
	if ( head == NULL ){
		printf("NULL\n");
		return;
	} // end if
	else {
		printf("%d->", head->value );
		print_list( head->next );
	}
}

int search (Node* head, int data)
{
	if ( head->value == data ){
		printf("%d was found\n", data);
		return 1;
	}
	else {
		if (head->next == NULL){
			printf("%d not found\n", data);
			return 0;
		}
		else {
			search(head->next, data);
		}
	}
	return 0;
}

void factorial_list(Node* head)
{
	if (head == NULL){
		return;
	}
	else {
		head->value = factorial(head->value);
		factorial_list(head->next);
	}

}

long int factorial ( int n )
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

void delete_list(Node* head)
{

	if( head->next == NULL ){
		free(head);
		return;
	}
	else{
		Node* temp = head->next;
		head->next = head->next->next;
		free(temp);
		delete_list(head);
	}
}
