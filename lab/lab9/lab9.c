/* Lab 9
 11/1/13
 Project Key: LAB9
 Lab Section: e
 Name: Francois Mariette
 PawPrint: FHMQPD
 Student #: 14103682
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct bt {
	int value;
	struct bt *right;
	struct bt *left;
} BST;

BST* insert(BST* root, int value);
void printTree(BST* root);
void displayBST(BST* root, int depth);
void padding(char toPrint, int numTimes);
int search(BST* root, int value);
BST* findMin(BST* root);
BST* delete (BST* root, int value);
BST* findNearest(BST* root, int value);

int main(int argc, char const *argv[])
{
	FILE* fp = fopen(argv[1], "r");
	char filename[15];
	int value;
	BST* root = NULL, *min = NULL;
    
	while ( fp == NULL ){
		printf("File can't be opened. Enter a new file: ");
		scanf("%s",filename);
		fp = fopen(filename, "r");
	}
    
	while ( fscanf(fp, "%d", &value) != EOF ){
		root = insert(root, value);
	}
    
	printTree(root);
    
     printf("Enter a value to search for in the tree:\n" );
     scanf("%d", &value);
     if (search(root, value) == 1){
     printf("%d was found\n", value );
     }
     
     min = findMin(root);
     printf("%d is the smallest node\n", min->value );
     
    
	printf("Enter a node to delete: ");
	scanf("%d", &value);
	root = delete (root, value);
	printTree(root);
    
	return 0;
}

BST* insert(BST* root, int value)
{
	if ( root == NULL ) {
		root = (BST *)malloc(sizeof(BST));
		root->value = value;
		root->left = NULL;
		root->right = NULL;
	}
    
	else if( value < root->value){
		root->left = insert(root->left, value);
	}
	else if( value > root->value ){
		root->right = insert(root->right, value);
	}
    
	return root;
}

void printTree(BST* root)
{
	displayBST(root, 0);
}

void displayBST(BST* root, int depth)
{
	if (root == NULL){
		padding(' ',depth);
		printf("-\n");
		return;
	}
	displayBST(root->right, depth+4);
	padding(' ', depth);
	printf("%d\n", root->value);
	displayBST(root->left, depth+4);
}

void padding(char toPrint, int numTimes)
{
	int i;
	for (i=0; i < numTimes; i++){
		printf("%c", toPrint);
	}
}
int search(BST* root, int value)
{
	if (root != NULL){
		if (root->value == value){
			return 1;
		}
		else {
			if ( value < root->value ) {
				return search(root->left,value);
			}
			else {
				return search(root->right, value);
			}
		}
	}
	return 0;
}

BST* findMin(BST* root)
{
	if ( root == NULL ) {
		return NULL;
	}
    
	else if ( root->left == NULL ) {
		return root;
	}
    
    return findMin(root->left);
}

BST* delete (BST* root, int value)
{
	BST* min;
    
	if (!root) { return NULL; }
	
	else if (root->left != NULL && value < root->value ){
		root->left = delete (root->left, value);
		return root;
	}
    
	else if (root->right != NULL && value > root->value) {
		root->right = delete (root->right, value);
		return root;
	}
    
	else {
   		
   		BST* temp;

	    if (root->left == NULL) { // no left child
	    	temp = root;
	        root = root->right;
	        free(temp);
	        return root;

	    }
	    else if (root->right == NULL) { // no right child
	    	temp = root;
	        root = root->left;
	        free(temp);
	        return root;
	    }
		else { // two children
			min = findMin(root->right);
			root->value = min->value;
			root->right = delete (root->right, min->value); // sets right node as top of temp tree
			return root;
		}
	}   
}

// Bonus function
BST* findNearest(BST* root, int value)
{
}
