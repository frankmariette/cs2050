
/* Lab 7
 10/18/13
 Project Key: LAB7
 Lab Section: e
 Name: Francois Mariette
 PawPrint: FHMQPD
 Student #: 14103682
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct spqueue {
	int priority;
	char* value;
	struct spqueue* next;
}SubPQueue;

typedef struct pqueue {
	int priority;
	SubPQueue* subQueue;
	struct pqueue* next;
}PQueue;

#define MAX_VALUE_SIZE 20
#define MAX_LINE_LENGTH 100

void enqueue(PQueue** queue, int priority1, int priority2, char* value);
char* dequeue(PQueue** queue);
void free_sub_node(SubPQueue* node);
void print_queue(PQueue* node);
SubPQueue* create_nodeSubQ(int priority, char* value);
PQueue* create_nodePQ(int priority);
int isElement(PQueue* PQNode, int priority);
SubPQueue* insertNode(SubPQueue* head);

int main(int argc, char **argv)
{
	PQueue** queue = (PQueue**)malloc(sizeof(PQueue));
    
	char filename[MAX_VALUE_SIZE], command[MAX_VALUE_SIZE], value[MAX_VALUE_SIZE];
	int priority1, priority2;
    
    
	FILE* fp = fopen(argv[1], "r");
	while (fp == NULL){
		printf("Can't open file. Input a file:\n");
		scanf("%s", filename);
	}
	while (!feof(fp)){
		fscanf(fp, "%s", command);
		if (strcmp(command, "enqueue") == 0){
			fscanf(fp, "%d%d%s", &priority1, &priority2, value);
			enqueue(queue, priority1, priority2, value);
		}
		else if (strcmp(command, "print") == 0){
			print_queue((*queue));
		}
        //else if (strcmp(command, "dequeue") == 0){
        //    printf("%s",dequeue(queue));
        //}
        else {
         break;
        }
	}
    
    
	return 0;
}

void enqueue(PQueue** queue, int priority1, int priority2, char* value)
{
    
	/* Creates nodes for sub queue */
    SubPQueue* newNodeSQueue = create_nodeSubQ(priority2, value);
    PQueue* PQNode = *queue;
    
	if(!PQNode) {
        
		PQNode = create_nodePQ(priority1);
        PQNode->priority = priority1;
        PQNode->next = NULL;
        PQNode->subQueue = newNodeSQueue;
        *queue = PQNode;
        return;
	}
    if (priority1 > PQNode->priority){
        PQueue* newPQNode = create_nodePQ(priority1);
        newPQNode->next = PQNode;
        newPQNode->subQueue = newNodeSQueue;
        *queue = newPQNode;
    }
    
    else if (isElement(*queue, priority1) == 1){
        while (PQNode->priority != priority1){
            PQNode = PQNode->next;
        }
        if (newNodeSQueue->priority > PQNode->subQueue->priority ){
            newNodeSQueue->next = PQNode->subQueue;
            PQNode->subQueue = newNodeSQueue;
        }
        else if ( newNodeSQueue->priority == PQNode->subQueue->priority){
            SubPQueue* temp = PQNode->subQueue;
            SubPQueue* prev = NULL;
            while (temp != NULL && newNodeSQueue->priority == temp->priority){
                prev = temp;
                temp = temp->next;
            }
            newNodeSQueue->next = prev->next;
            prev->next = newNodeSQueue;
        }
        else{
            SubPQueue* temp = PQNode->subQueue;
            SubPQueue* prev = NULL;
            while (newNodeSQueue->priority < temp->priority && temp != NULL){
                prev = temp;
                temp = temp->next;
            }
            newNodeSQueue->next = prev->next;
            prev->next = newNodeSQueue;
        }
    }
    
    else {
        PQueue* newPQNode = create_nodePQ(priority1);
        PQueue* prev = NULL;
        while (PQNode != NULL && newPQNode->priority < PQNode->priority ){
            prev = PQNode;
            PQNode = PQNode->next;
        }
        
        newPQNode->next = prev->next;
        prev->next = newPQNode;
        newPQNode->subQueue = newNodeSQueue;

        
    }
}

char* dequeue(PQueue** queue)
{
    PQueue* currentPQNode = *queue;
    SubPQueue *tempSub;
    
    tempSub = currentPQNode->subQueue;
    currentPQNode->subQueue= tempSub->next;

    char* string = tempSub->value;
    free_sub_node(tempSub);
    
    if(*queue == NULL){
        free(*queue);
    }
    return string;
}

void free_sub_node(SubPQueue* node)
{
    free(node);
}

PQueue* create_nodePQ(int priority)
{
    PQueue* newNodePQueue = (PQueue*)malloc(sizeof(PQueue));
    newNodePQueue->priority = priority;
    newNodePQueue->subQueue = NULL;
    newNodePQueue->next = NULL;
    
    return newNodePQueue;
}

SubPQueue* create_nodeSubQ(int priority, char* value)
{
    SubPQueue* newNodeSQueue = (SubPQueue*)malloc(sizeof(SubPQueue));
	newNodeSQueue->priority = priority;
	newNodeSQueue->value = (char*)malloc(MAX_VALUE_SIZE * sizeof(char));
	strcpy(newNodeSQueue->value, value);
    return newNodeSQueue;
}

int isElement(PQueue* PQNode, int priority)
{
    while ( PQNode != NULL){
        if (priority == PQNode->priority){
            return 1;
        }
        PQNode = PQNode->next;
    }
    return 0;
}

void print_queue(PQueue* node)
{
    if (node == NULL){
        printf("Queue empty");
    }
    else{
        SubPQueue* current = NULL;
        while (node != NULL){
            current = node->subQueue;
            while ( current != NULL ){
                printf("%s -> ", current->value );
                current = current->next;
            }
            printf("NULL");
            printf("\n|\n");
            printf("v\n");
            node = node->next;
        }
        printf("NULL\n");
    }
}