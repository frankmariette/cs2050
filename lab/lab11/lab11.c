/* Lab 11
   11/22/13
   Francois Mariette
   FHMQPD
   14103682
   Lab e
   Project Key: LAB11
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE 250

int isDate(char* string);
int isPhoneNumber(char* string);
int isName(char* string);
int isEmail(char* word);

int main(int argc, char **argv)
{
	FILE *input = fopen(argv[1], "r");
	int name_counter = 0, words = 0;
	char buffer[MAX_LINE], *token, delim[] = " ,\t";
	char name[MAX_LINE];

	if (input == NULL){
		return -1;
	}

	while(fgets(buffer, MAX_LINE, input)){
		if (buffer[strlen(buffer) - 1] == '\n'){
			buffer[strlen(buffer) - 1] = '\0';
		}
		token = strtok(buffer, delim);
		while( token != NULL ){
			//printf("%s\n", token);
			if (isDate(token) == 1){
				printf("Found a date: %s\n", token );
			}
			if (isPhoneNumber(token)){
				printf("Found a phone number: %s\n", token );
			}

			if (name_counter == 1 && isName(token) == 0){
				name_counter = 0;
			}
			
			if (isName(token)){
				name_counter++;
				if (name_counter == 2){
					printf("Name found: %s %s\n", name, token );
					name_counter = 0;
				}
				else {
					strcpy(name, token);
				}
			}
			if (isEmail(token)){
				printf("Found an email: %s\n", token );
			}

			
			token = strtok(NULL, delim);
			words++;

		}
		
	}
	printf("There are %d words in the file\n", words );
}

int isDate(char* string)
{
	int i;
	if (strlen(string) == 8){
		if( string[2] == '/' && string[5] == '/'){
			for (i = 0; i < 2; i++){
				if(isdigit(string[i]) == 0){
					return 0;
				}
			}
			for (i = 3; i < 5; i++){
				if (isdigit(string[i]) == 0){
					return 0;
				}
			}
			for (i = 6; i < 8; i++){
				if (isdigit(string[i]) == 0){
					return 0;
				}
			}
			return 1;
		}
		return 0;
	}
	else{
		return 0;
	}
}

int isPhoneNumber(char* string)
{
	int i;
	if ( strlen(string) == 14 ){
		if ( (string[0] == '(') && (string[4] == ')')  && (string[5] == '-') && (string[9] == '-') ){
			for (i = 1; i < 4; i++){
				if (isdigit(string[i]) == 0){
					return 0;
				}
			}
			for ( i = 6; i < 9; i++){
				if (isdigit(string[i]) == 0){
					return 0;
				}
			}
			for ( i = 10; i < 14; i++){
				if (isdigit(string[i]) == 0){
					return 0;
				}
			}
			return 1;
		}
		return 0;
	}
	else {
		return 0;
	}
}

int isName(char* string)
{
	int i;
	if (isalpha(string[0]) == 1 && isupper(string[0]) == 1){
		for (i = 1; i < strlen(string); i++){
			if( !isalpha(string[i]) || !islower(string[i]) ) {
				return 0;
			}
		}
		return 1;
	}
	return 0;
}

int isEmail(char* word)
{
	int i, at_flag = 0, period_flag = 0;
	for (i = 0; i < strlen(word); i++ ){
		if(isalpha(word[i]) == 0 && word[i] != '@' && word[i] != '.'){
			return 0;
		}
		if ( word[i] == '@'){
			at_flag++;
		}
		if ( at_flag == 1 && word[i] == '.'){
			period_flag++;
		}
	}

	if ( at_flag == 1 && period_flag == 1){
		return 1;
	}

	return 0;
}