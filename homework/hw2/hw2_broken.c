/* Name: Francois Mariette
   PawPrint: FHMQPD
   Student Number: 14103682
   Homework: Homework 2
   Lab Section: e
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Assume max char count in file */
#define MAX 20

/* library struct - DO NOT CHANGE */
typedef struct library
{
    char *genre;
    char *band;
    char *album;
    float rating;
    struct library *next;
}Library;

/* Function Prototypes - DO NOT CHANGE */
Library *Read_File(FILE *);
void Print(Library *);
Library *Create_List(Library *, Library *);
Library *Create_Album(char *, char *, char *, float);
Library *Merge(Library *, Library *);
int Count_List(Library *);
void Split_List(Library *, Library **, Library **);
Library *Merge_Sort(Library *);
Library *Delete_Genre(Library *);
void Free_Entry(Library *);
Library *Clean(Library *);

/* MAIN
 * Error check file parameter
 * Call Read_File to fill our list
 * Print our list
 * Merge Sort the linked list (by genre)
 * Delete a genre
 * Free the list
 */
int
main(int argc, char **argv)
{
    
    if(argc != 2)
    {
        printf("Not enough arguments.\n");
        return 0;
    }
    
    FILE *fp = NULL;
    
    if((fp = fopen(argv[1], "r")) == NULL)
    {
        printf("File can not be opened.\n");
        return 0;
    }
    
    //Library Head = NULL;
    Library* Head = NULL;
    Head = Read_File(fp);
    
    //Print(&Head);
    Print(Head);
    
    Head = Merge_Sort(Head);
    //Print(&Head);
    Print(Head);
    
    Head = Delete_Genre(Head);
    //Print(&Head);
    Print(Head);
    
    Head = Clean(Head);
    //Print(&Head);
    Print(Head);
    
    return 0;
}


/* Clean()
 * Delete the linked list, recursively
 */

Library *
Clean(Library *Head)
{
    if(Head == NULL) return Head;
    
    Library *Tmp = Head->next;
    Free_Entry(Head);
    if (Tmp != NULL){ // prevents program from freeing non allocated memory
        Clean(Tmp->next);
    }
    Head = NULL;
    return Head;
}


/* Free_Entry()
 * wrapper function to free a struct Library
 */


void
Free_Entry(Library *Entry)
{
    /* New code to free all memory associated with Entry node */
    free(Entry->genre);
    Entry->genre = NULL;
    
    free(Entry->band);
    Entry->band = NULL;
    
    free(Entry->album);
    Entry->album = NULL;
    /* End of new code */
    
    
    free(Entry);
    Entry = NULL;
}


/* Delete_Genre()
 * Deletes a genre inputted by user
 * Logic:
 * prompt user for genre input
 * traverse list deleting all structs that contain the genre
 */

Library *
Delete_Genre(Library *Head)
{
    if(!Head)
    {
        printf("List Empty.\n");
        return Head;
    }
    
    //char *input = malloc(MAX * sizeof(char *));
    char *input =(char *)malloc(MAX * sizeof(char *));
    
    Library *Current = Head;
    Library *Tail = NULL;
    
    printf("Which genre would you like to delete?\n");
    
    scanf("%s", input);
    
    // while(Current)
    while(Current != NULL)
    {
        //if(strcmp(Current->genre, input))
        if (strcmp(Current->genre, input) == 0) {
            // if(Current = Head)
            if(Current == Head)
            {
                Head = Head->next;
                Free_Entry(Current);
                Current = Head;
            }
            else {
                //Tail->next = Current->next;
                Tail->next = Current->next;
                Free_Entry(Current);
                Current = Tail->next;
            }
            
        }
        else{
            Tail = Current;
            Current = Current->next;
        }
    }
    return Head; // Returns Head so that it is not lost
}


/* Read_File()
 * Open file fp
 * Create a struct from information in text file
 * Link our list with newly created struct
 */
Library *
Read_File(FILE *fp)
{
    Library *Head, *Entry;
    Head = Entry = NULL;
    
    
    //char *genre, *band, *album;
    char genre[MAX], band[MAX], album[MAX]; // allocates memory for array
    float rating;
    
    //while(1)    {
    while( 1 ){
        fscanf(fp, "%s%s%s%f", genre, band, album, &rating);
        if(feof(fp)){
            break;
        }
        Entry = Create_Album(genre, band, album, rating);
        //Head = Create_List(Entry, Head);
        Head = Create_List(Head, Entry);
    }
    
    return Head;
}

/* Print()
 * Print the linked list
 */
void
Print(Library *Head)
{
    //if(!Head)
    if(Head == NULL)
    {
        printf("Library is empty.\n");
        return;
    }
    
    while(Head != NULL)
    {
        printf("%20s %20s %20s %20.2f \n",
               Head->genre, Head->band, Head->album, Head->rating);
        Head = Head->next;
    }
    printf("\n\n");
    //return Head;  <-- This code isn't needed as function has a return type of void.
}


/* Create_Album
 * Create a struct and assign the given args to it as appropriate
 */

Library *
Create_Album(char *genre, char *band, char *album, float rating)
{
    //Library *Entry = malloc(sizeof(Library));
    Library *Entry = (Library *)malloc(sizeof(Library));
    
    /* New code to malloc space for fields */
    Entry->genre = (char *)malloc(MAX * sizeof(char *));
    Entry->band = (char *)malloc(MAX * sizeof(char *));
    Entry->album = (char *)malloc(MAX * sizeof(char *));
    //    /* End of new code */
    
    strcpy(Entry->genre, genre);
    strcpy(Entry->band, band);
    strcpy(Entry->album, album);
    Entry->rating = rating;
    Entry->next = NULL;
    
    return Entry;
}


/* Create_List()
 * Push Entry onto our List
 */
Library *
Create_List(Library *Head, Library *Entry)
{
    if(!Head){
        //if ( Head == NULL)
        return Entry;
    }
    else {
        //   Entry->next = Head;  Needs head to point to entry
        //   return Entry; Create_List needs return Head
        Entry->next = Head->next;
        Head->next = Entry;
        return Head;
    }
}


/* Merge_Sort()
 * Recursively split our list between Left and Right
 * Merge our Left and Right lists
 */

Library *
Merge_Sort(Library* Head)
{
    Library *Tmp = Head;
    Library *Left, *Right, *Result;
    Left = Right = Result = NULL;
    
    int count = Count_List(Head);
    
    //if(count == 1){
    if(count <= 1){
        return Tmp;
    }
    
    Split_List(Head, &Left, &Right);
    
    // Left = Merge_Sort(*Left);
    Left = Merge_Sort(Left);
    
    //Right = Merge_Sort(*Right);
    Right = Merge_Sort(Right);
    
    Result = Merge(Left, Right);
    
    return Result;
}



/* Split_List()
 * split our list in half
 */

void
Split_List(Library *Head, Library **Left, Library **Right)
{
    int size = Count_List(Head);
    int i;
    
    Library* Tmp = (Library*)malloc(sizeof(Library)); // Code added to declare and malloc memory
    Tmp = Head;
    *Left = Head;
    
    // for(i=1; i<size/2; ++i)
    for(i=2; i<(size/2); ++i)
        Tmp=Tmp->next;
    
    *Right = Tmp->next;
    Tmp->next = NULL;
}



/* Merge()
 * Merge two linked lists Left and Right together in sorted order
 */

Library *
Merge(Library *Left, Library *Right)
{
    Library *Result, *Tmp;
    Result = Tmp = NULL;
    /*
     if(strcmp(Left->genre, Right->genre) <= 0)
     {
     Result = Left;
     Left = Left->next;
     }
     else
     {
     Result = Right;
     Right = Right->next;
     }
     Tmp = Result;
     */
    
    if (Left == NULL){
        return Right;
    }
    else if (Right == NULL){
        return Left;
    }
    else {
        
        //while(Left != NULL && Right != NULL)
        //{
        //if(Left != NULL && Right!= NULL)
        //{
        if (strcmp(Left->genre, Right->genre) <= 0)
        {
            //Tmp->next = Left;
            //Left = Left->next;
            Result = Left;
            Result->next = Merge(Left->next, Right);
        }
        else
        {
            //Tmp->next = Right;
            //Right = Right->next;
            Result = Right;
            Result->next = Merge(Left, Right->next);
        }
        //Tmp = Tmp->next;
        //}
        // }
    }
    return Result;
}



/* Count_List()
 * Count the number of elements in a linked list
 */

int
Count_List(Library* Head)
{
    //Library *Tmp = Head;
    Library *Tmp = (Library*)malloc(sizeof(Library));
    Tmp = Head;
    int count = 0;
    
    while(Tmp->next != NULL)
    {
        count++;
        Tmp = Tmp->next;
    }
    return count; // Returns number of items in the list
}



