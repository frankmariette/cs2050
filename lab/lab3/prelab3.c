/* Prelab 3: prelab3.c
   Francois Mariette
   14103682
   CS2050 Lab section: e */
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int value;
	struct node* next;
}Node;
typedef Node *NodePtr;

// Prototypes
void Print_list(NodePtr list);
void Delete_List(NodePtr list);
NodePtr Insert_Front(NodePtr list, NodePtr new_node);
NodePtr Create_Node(int data);

int main( void )
{
	int input;
	NodePtr list = NULL;
	NodePtr newNode;
    
    FILE *fptr = fopen("numbers.txt", "r"); 
	
	if (!fptr){
        perror("fopen");
		printf("File can't be opened\n");
	}
	else { 
		while( fscanf( fptr, "%d", &input ) == 1 ){
			newNode = Create_Node(input);
			list = Insert_Front(list, newNode );
			Print_list( list );
		}
		fclose( fptr );

	Delete_List( list );

	}
	return 0; // indicates successful termination
}

NodePtr Create_Node( int data )
{
	NodePtr newNode = (NodePtr) malloc( sizeof( Node ) );
	newNode->value = data;
	newNode->next = NULL;
	return newNode;
}

/* Inserts the node new_node to the front of the linked list */
NodePtr Insert_Front( NodePtr list, NodePtr new_node )
{

	if (list == NULL) {
		list = new_node;
	}
	else {

		// Inserts node
		new_node->next = list;
		list = new_node;
	}
	return list;
}

void Print_list( NodePtr list )
{
	if( list == NULL ){
		printf("List is empty\n");
	}
	else {
		while ( list != NULL ){
			printf("%d->", list->value );
			list = list->next;
		}
		printf("NULL\n");
	}
}

void Delete_List(NodePtr list)
{
	NodePtr temp; // temporary node pointer
	// Iterates through the list deleting the fist node
	if (list == NULL){
		printf("List is empty\n");
	}
	else {
		while( list != NULL ){
			temp = list;
			list = list->next;
			free( temp );
		}
		printf("List successfully deleted!\n");
	}
}








