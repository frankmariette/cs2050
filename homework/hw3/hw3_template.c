//libraries
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//binary search tree Structure----/* DO NOT CHANGE */------
typedef struct BST {
	int value;
    int treeNum;
	struct BST* left;
	struct BST* right;
}BST;

//list of pointers to the root node----/* DO NOT CHANGE */------
typedef struct rootList {
	struct BST* root;
	struct rootList* next;
}rootList;

//BFS Queue Structure-----/* DO NOT CHANGE */-------
typedef struct bfsQ{
	struct BST* treeNode;
	struct bfsQ* next;
	
}bfsQ;

//Function Prototypes-------/* DO NOT CHANGE */------
void insert_BST(BST** root, int insertValue, int treeNum);
BST* createTreeNode(int nodeValue, int treeNum);
void printTrees(rootList* listHead);
void print_BST_inorder(BST* root);
void enqueue(bfsQ** qHead, BST* new_tree_node);
BST* dequeue(bfsQ** qHead);
void BFS (rootList* listHead, int searchValue);
void insert_rootList(rootList** listHead, BST* root);
void free_list(rootList** listHead);
void free_BSTs(BST* root);

//maximum line size
#define MAX_LINE_SIZE 20

/********************************** MAIN *****************************************
 
 parameters: int argc (total number of command line arguments.
 char*argv[] (an array that holds the command line arguments)
 returns: int value of success (0) or failure (1)
 
 -> Your main function should read two files from the command line:
 1.) argv[1] should read the file input.txt. This file will have
 integer values that you will use to insert into the binary search tree.
 2.) argv[2] should read the file search.txt. This file will have
 integer values that you will use to search the binary search tree using BFS
 -> Main will call the functions: insert_BST, insert_rootList and BFS.
 
 *********************************************************************************/

int main (int argc, char*argv[]){
}

/********************************** createTreeNode *******************************
 parameters: int value to be inserted in the binary search tree
 returns: pointer to a newly created binary search tree node (BST*)
 
 -> createTreeNode simply creates a new tree node using the value passed as the
 parameter.
 *********************************************************************************/

BST* createTreeNode(int nodeValue, int treeNum){
	BST* newNode = (BST*)malloc(sizeof(BST));

	newNode->value = nodeValue;
	newNode->treeNum = treeNum;
	newNode->left = NULL;
	newNode->right = NULL;

	return newNode;
}

/********************************** insert_BST ****************************************
 parameters: the reference of the root (BST**) and the int value to be inserted.
 returns: void
 
 -> This function recursively finds the right position in the binary search tree 
    for the new value and inserts the node containing the new value in that position.
 ****************************************************************************************/

void insert_BST(BST** root, int insertValue, int treeNum){
	if (root == NULL) {
		createTreeNode(insertValue, treeNum);
	}
	else if( insertValue < (*root)->value ){
		insert_BST((*root)->left, insertValue, treeNum);
	}
	else if( insertValue > (*root)->value ){
		insert_BST((*root)->right, insertValue, treeNum);
	}
}


/********************************** insert_rootList ******************************
 parameters: the reference of the head pointer to the list (BST**) and pointer
 to the root of the new binary search tree
 returns: void
 
 -> This function inserts the new binary search tree at the BACK of the linked
    list containing pointers to the roots of the binary search trees.
 *********************************************************************************/

void insert_rootList(rootList** listHead, BST* new_root){
}

/************************************** BFS **************************************
 parameters: the pointer to the start of the linked list and the int value to be
 searched
 returns: void
 
 -> This function implements a variant of a level by level search or formally
 called as the BREADTH FIRST SEARCH.
 -> This function searches for a given value in the binary search trees and it does that
 by searching for level 1 in each binary search trees, then moving on to level 2 if
 it fails to find it that value in level 1 and so on.
 -> Basically, you have to search for a given value in all the binary search trees, one
 level at a time, in the linked list simultaneously.
 
 //////////////////////////////////////////////////////////////////////////////
 / HINT: Use the enqueue and dequeue functions to solve this problem. You will
 /       have a hard time solving this problem without using the enqueue and
 /       dequeue functions.
 /////////////////////////////////////////////////////////////////////////////
 
 *********************************************************************************/

void BFS(rootList* listHead, int searchValue){
}

/************************************ enqueue ************************************
 parameters: the reference of the head of the queue and pointer to the tree node
 to be inserted in the queue
 returns: void
 
 -> This Function inserts the new tree node in the queue that is used to do a BFS.
 
 *********************************************************************************/

void enqueue(bfsQ** qHead, BST* new_tree_node){
}

/********************************** dequeue **************************************
 parameters: the reference of the head of the queue.
 returns: pointer to the dequeued tree node
 
 -> This Function dequeue's the tree node in front of the queue and returns it.
 
 *********************************************************************************/

BST* dequeue(bfsQ** qHead){
}

/********************************** printTrees **************************************
 parameters: pointer to the head of the linked list
 returns: void
 
 -> This Function prints all the binary search trees in the linked list
 *********************************************************************************/

void printTrees(rootList* listHead){
}

/****************************** print_BST_inorder *******************************
 parameters: pointer to the root of the tree
 returns: void
 
 -> This Function prints the binary search tree using inorder traversal
 *********************************************************************************/

void print_BST_inorder(BST* root){
}

/********************************* free_list *************************************
 parameters: reference of the pointer to the head of the linked list
 returns: void
 
 -> This function frees all the allocated memory.
 -> This function also calls the free_BSTs function to free the binary search trees.
 *********************************************************************************/

void free_list(rootList** listHead){
}

/********************************* free_BSTs *************************************
 parameters: Pointer to the root of the binary search tree
 returns: void
 
 -> This function frees all the nodes in the given binary search tree recursively.
 *********************************************************************************/

void free_BSTs(BST* root){
}

