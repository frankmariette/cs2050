/* Francois Mariette
 14103682
 Homework 1 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SONG_LENGTH 10
#define ARTIST_LENGTH 16
#define CD_LENGTH 20

typedef struct song_ {
    char* song;
    char* artist;
    char* album;
    int rating;
    
    struct song_ *nextPtr;
}Song;
typedef Song *SongPtr;

/* Prototypes */


SongPtr new_song(char* song, char* artist, char* album, int rating);
SongPtr insert_by_song(SongPtr head, SongPtr newSong);
void print_list(SongPtr head);
int update_song(SongPtr head, char* name, int rating);
void free_node(SongPtr node);
SongPtr delete_odd(SongPtr head);
SongPtr delete_even(Song* head);

/*
 * This function begins by checking that exactly two command line arguments are given. If not
 * the program is terminated with an appropriate error message. It then attempts to open the input
 * file and terminates with an appropriate error message if it fails. The function then runs through
 * the input file, calls new_song() and then insert_by_song() to create a linked list. print_list() is
 * called when the linked list is fully completed. The program will then ask for a name of a song a
 * new rating and call update song. The function will prompted for a new song and rating until update_song()
 * is successful. After, the list is successfully updated print_list() will be called. The function will
 * then call delete_even(), print_list(), delete_odd() and print_list() one last time before exiting.
 */
int main ( int argc, char **argv )
{
	SongPtr startPtr = NULL;
    char song[SONG_LENGTH];
    char artist[ARTIST_LENGTH];
    char album[CD_LENGTH];
	int rating;
    
	FILE *fPtr = fopen( *(argv + 1), "r" ); // File pointer
    
	if( argc != 2 ) {
		printf( "No input file provided\n");
		return 2; // terminates with error
	} // end if
	
	if ( fPtr == NULL) {
		printf( "File can't be opened\n" );
	} // end if
	else {
		// opens file, reads it then closes it
        while( fscanf(fPtr, "%s%s%s%d", song, artist, album, &rating) != EOF)
        {
		   	//Starts loop of new_song to insert_by_song and then returns the head of the list to startPtr
		   	startPtr = insert_by_song(startPtr, new_song(song, artist, album, rating)); // new_song returns a pointer to new song
            
		}; // end while
        
        
		fclose(fPtr); // closes input file
		print_list(startPtr); // print songs
        
        
		// variables for update song
		char choice[SONG_LENGTH];
		int newRating;
        
		// Ask user for input if there is a list
		if (startPtr != NULL){
			do {
				printf("\nEnter a song and a new rating:");
				scanf("%s%d", choice, &newRating);
			} while ( update_song(startPtr, choice, newRating) != 1);
            print_list(startPtr);
            
            // Start deletion of nodes and reprint lists after each deletion
            startPtr = delete_even(startPtr); // deletes all even nodes
            printf("\n");
            print_list(startPtr);
            
            startPtr = delete_odd(startPtr);
            printf("\n");
            print_list(startPtr);
		}
	}
	return 0;
} // end main

/*
 * Allocate space for a new Song node and set its members. The default
 * value of next should be NULL
 * Return: A pointer to the new node
 */
Song* new_song(char* song, char* artist, char* album, int rating){
    SongPtr newSong = (SongPtr) malloc( sizeof( Song ) ); // Create node
    
    if (newSong != NULL) {
	 	newSong->song = (char*)malloc(SONG_LENGTH * sizeof(char));
	 	newSong->artist = (char*)malloc(ARTIST_LENGTH * sizeof(char));
	 	newSong->album = (char*)malloc(CD_LENGTH * sizeof(char));
	 	newSong->rating = rating;
 		newSong->nextPtr = NULL;
        
        
 		strcpy(newSong->song, song);
 		strcpy(newSong->artist, artist);
 		strcpy(newSong->album, album);
    }
    
    else {
        //	printf("%as not inserted. No memory available\n", song );
    }
    
	return newSong;
    
}

/*
 * Inserts Song* node into the linked list specified by the pointer head. The node
 * should be inserted in alphabetical order by the field song.
 * Return: A pointer to the head of the linked list
 */
SongPtr insert_by_song(SongPtr head, SongPtr newSong){
    
	SongPtr previousSong, nextSong;
    
	if (!head){
		head = newSong;
	}
	else{
		previousSong = NULL;
		nextSong = head;
		
		// Finds location for node insertion
		while( nextSong != NULL && newSong->song[0] > nextSong->song[0] ){
			previousSong = nextSong;
			nextSong = nextSong->nextPtr;
		}
        // If newSong points to NULL this adds Node to tail of list
		if (!nextSong){
			previousSong->nextPtr = newSong;
		}
        //
		else{
			if ( previousSong == NULL ) {
				newSong->nextPtr = head;
				head = newSong;
			} // end if
			else {
				newSong->nextPtr = previousSong->nextPtr;
				previousSong->nextPtr = newSong;
			} // end else
		}// end else
	}
	return head;
} // end function insert_by_song


/*
 * Runs through the linked list specified by the pointer head and prints it
 * to the screen
 */
void print_list(SongPtr head){
    
	if (head == NULL) {
		printf("List is empty\n\n");
	} // end if
	else {
		printf( "%20s%20s%20s%20s\n", "Song", "Artist", "Album", "Rating");
        
		// loops through nodes
		while(head != NULL) {
			printf("%20s%20s%20s%20d\n", head->song, head->artist, head->album, head->rating);
			head = head->nextPtr;
		}
	}
}


/*
 * Searches throught the linked list specified by the pointer head for a Song with a
 * field song that matches the string name. If found, the nodes rating is updated to
 * match that of the parameter rating
 * Return: 1 if the linked list is updated, 0 otherwise
 */
int update_song(Song* head, char* name, int rating){
    
    SongPtr current = head;
    
    while ( current != NULL ){
    	if ( strcmp(current->song, name) == 0){
    		current->rating = rating;
    		return 1;
    	}
    	else {
    		current = current->nextPtr;
    	}
    }
    printf("Song not found\n");
    return 0;
}


/*
 * Runs through the linked list specifed by the pointer head and deletes every node
 * whose rating is even. This function should call free_node().
 * Return: The head of the linked list
 *
 * Add checks for making sure head isn't first node.  If it is, need to make a temp node, and then move the current node to next node. Free the memory after
 */
SongPtr delete_even(SongPtr head){
 	SongPtr currentSong, temp;
	
    if (head == NULL) {
        return head;
    }
    
	else {
        
        // Deletes head node and reassigns
        while( head->rating%2 == 0) {
            temp = head;
            head = head->nextPtr;
            free_node(temp);
        }
        
		currentSong = head;
	 	
	 	while( currentSong->nextPtr != NULL ) {
            
            if ((currentSong->nextPtr->rating % 2) == 0){
     			temp = currentSong->nextPtr;
     			currentSong->nextPtr = currentSong->nextPtr->nextPtr;
     			free_node(temp);
            }
            else{
                currentSong = currentSong->nextPtr;
            }
	 	}
        
	}
    
    return head;
}


/*
 * Runs through the linked list specifed by the pointer head and deletes every node
 * whose rating is odd. This function should call free_node().
 * Return: The head of the linked list
 */
SongPtr delete_odd(SongPtr head){
    SongPtr currentSong, temp;
    
    if (head == NULL) {
        return head;
    }
    
    else {
        
        // Deletes head node and reassigns
        while ( head != NULL && (head->rating % 2 != 0)) {
            temp = head;
            head = head->nextPtr;
            free_node(temp);
        }
        
        currentSong = head;
        
        while( head != NULL && currentSong->nextPtr != NULL ) {
            
            if ((currentSong->nextPtr->rating % 2) != 0){
               	temp = currentSong->nextPtr;
               	currentSong->nextPtr = currentSong->nextPtr->nextPtr;
                free(temp);
            }
            else{
                currentSong = currentSong->nextPtr;
            }
        }
        
    }
    
    return head;
}


/*
 * Frees all allocated memory associated with the node "node"
 * Return : None
 */
void free_node(Song* node){
    free(node->song);
    free(node->album);
    free(node->artist);
    free(node);
}