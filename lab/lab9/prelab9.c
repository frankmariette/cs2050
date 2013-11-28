/* Prelab 9
   Binary Search Trees
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
BST* deleteNode(BST* root, int value);
BST* findNearest(BST* root, int value);

// Extra function
void preorder(BST* root);

int main(int argc, char const *argv[])
{
	FILE* fp = fopen(argv[1], "r");
	char filename[15];
	int value;
	BST* root = NULL;

	while ( fp == NULL ){
		printf("File can't be opened. Enter a new file: ");
		scanf("%s",filename);
		fp = fopen(filename, "r");
	}

	while ( fscanf(fp, "%d", &value) != EOF ){
		root = insert(root, value);
	}

	printf("Enter a value to search for in the tree:\n" );
	scanf("%d", &value);
	if (search(root, value) == 1){
		printf("%d was found\n", value );
	}
	else {
		printf("%d not found\n", value );
	}

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
			search(root->left,value);
			search(root->right, value);
		}
	}
	return 0;
}

void preorder(BST* root)
{
	if( root != NULL){
		printf("%d\n", root->value );
		preorder(root->left);
		preorder(root->right);
	}
}