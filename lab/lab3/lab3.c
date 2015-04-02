/***************************
 *Lab 3
 *09/13/2013
 *Project Key: google
 *Lab Section E
 *Name: Francois Mariette
 *PawPrint: 
 *Student Number: 
 ***************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
void Add_Int(NodePtr list, int value);
Node* Delete_Range(NodePtr list, int low, int high);

int main( void )
{
	int i; // counter
	int data;
	NodePtr list = NULL;
    
	/* Generates a linked list with 10 random numbers between 20-60 */
	srand(time(NULL));
	for (i =0; i < 10; i++ ){
		data = (rand() % 41) + 20;
		list = Insert_Front( list, Create_Node( data ));
	}
	Print_list( list ); // prints the initial list
    
	/* Gather value from user to add to all nodes */
	printf("Enter an integer to add to all nodes\n");
	while ( !(scanf("%d", &data) ) ) {
		printf("Incorrect input, enter an integer:\n");
		scanf("%d", &data);
	}
	Add_Int(list, data );
	Print_list( list );
    
    
	/* Declare variables required for function Delete_Range */
	int low, high;
    
	/* Asks user for a range (low-high) and deletes nodes within range. Returns head node if (high, low) is provided */
	printf("Input a range (low, high) to delete:\n");
	scanf( "%d%d", &low, &high );
	list = Delete_Range(list, low, high);
	Print_list( list ); // prints list after initial deletion
    
	/* Delete the rest of the nodes */
	Delete_List(list);

    
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

void Add_Int( NodePtr list, int value)
{
	NodePtr currentPtr; // points to the node currently being changed
	currentPtr = list;
    
	// Iterates through the list changing the values
	while( currentPtr != NULL ) {
		currentPtr->value = (currentPtr->value + value);
		currentPtr = currentPtr->next;
	}
}

NodePtr Delete_Range(NodePtr list, int low, int high)
{
	NodePtr currentPtr, temp;
    if (low > high) {
        return list;
    }
    
    if (list == NULL) {
        return list;
    }
    
	else {
        
        // Deletes head node and reassigns head to the next node in the list
        while( list != NULL && (list->value >= low) && (list->value <= high)) {
            temp = list;
            list = list->next;
            free(temp);
        }
        
		currentPtr = list;
	 	
	 	// iterates throught the list to delete nodes within range
	 	while( currentPtr->next != NULL ) {
            if ( (currentPtr->next->value >= low) && (currentPtr->next->value <= high) ){
                temp = currentPtr->next;
                currentPtr->next = currentPtr->next->next;
                free( temp );
            } // end if
            else{
                currentPtr = currentPtr->next;
            } // end else
	 	} // end while
        return list;
    } // end else
	
	
    
} // end function Delete_Range







