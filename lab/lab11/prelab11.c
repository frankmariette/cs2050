/* Prelab 11
   Francois Mariette
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 256

int isDate(char* string);

int main(int argc, char const *argv[])
{
	FILE *filename = fopen(argv[1], "r");
	char string[MAX];
	char* token;
	char delim[] = " ";


	if (filename == NULL) {
		return -1;
	}
	else{
		while ( fgets(string, MAX, filename) ){
			if (string[strlen(string)- 1] == '\n'){
				string[strlen(string) - 1] = '\0';
			}
			token = strtok(string, delim);
			while ( token != NULL ){
				//if ( isDate(token) == 1){
				//	printf("Token is a date\n");
				//}
				printf("%s\n", token );
				token = strtok(NULL, delim);
			}
		}
	}

	return 0;
}

int isDate( char* string )
{
	char tok[] = "";
	char *token;
	token = strtok(string, tok);
	int month, day, year;	
	
	return 0;
}