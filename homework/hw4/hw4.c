/* Francois Mariette
 Homework 4
 Lab section: e
 Student Number: 14103682
 PawPrint: FHMQPD
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


typedef struct course_ {
	char* course_code;
	char* course_title;
	int creditHours;
	char* professor;
	struct course_ *next;
}Course;

/* Prototypes */
void parser(FILE* input, char* search, Course** list);
Course* create_course(char* course_code, char* course_title[], int title_counter,  int creditHours, char* professor[]);
void search_list(Course** list, char* target);
void register_course(Course** list, Course* newCourse);
int isProfessor(char* string);
int isCode(char* string);
int isTitle(char* string);
void print_courses(Course* list);
void displayMenu(void);
int sum_credit_hours(Course* list);


#define MAX_LINE_SIZE 200

/* Main takes an input file in and opens it.  After this a menu is displayed for the user to choose from.  The choices either add 
   a course to the linked list or prints the list of current courses out for the user. */

int main(int argc, char const *argv[])
{
	FILE *input = fopen(argv[1], "r");
	char filename[MAX_LINE_SIZE];
	char search[MAX_LINE_SIZE];
	int choice = 0;
	Course* list = NULL;
    
	if (argc != 2){
		printf("Usage: ./a.out <input file>\n");
	}
	while (input == NULL) {
		printf("File cannot be opened. Choose a different file\n");
		scanf("%s", filename);
		input = fopen(filename, "r");
	}
    
	while( choice != 3 ){
		rewind(input);
		displayMenu();
		scanf("%d", &choice);
		switch (choice) {
            case 1: // Register Course
                printf("What course would you like to add?\n");
                scanf("%s", search);
                parser(input, search, &list);
                break;
            case 2: // List courses
            	if ( list == NULL ){
            		printf("You have not registered for any courses\n");
            		break;
            	}
            	else {
            		printf("You are currently registered for:\n");
                	print_courses(list);
                	printf("\n");
                	break;
                }
            case 3: // Exit
            	if (list == NULL){
            		printf("You have not registered for any courses. Have a good day!\n");
            		return 0;
            	}
            	else {
            		printf("For a total of %d hours of credit. Have a good day!\n", sum_credit_hours(list));
            		return 0;
            	}
                
            default:
                printf("Not a valid input. Select from the options provided!\n");
		}
	}
    return 0;
}

/* Parses the file taking in the linked-list, file pointer and a course to search for.
	If the course is found it is added to the linked list.  Otherwise the user is informed
	the course is not available and prompted to enter different course */

void parser(FILE* input, char* search, Course** list)
{
    
	char string[MAX_LINE_SIZE];
	char *token;
	char course_code[MAX_LINE_SIZE];
	char *professor[10];
	char *course_title[10];
	int creditHours = 0;
    char* temp;
	int code_flag = 0, prof_flag = 0, credit_flag = 0, title_counter = 0;
    
    
	while (fgets(string, MAX_LINE_SIZE, input)){
		if(string[ strlen(string) - 1] == '\n'){
			string[ strlen(string) - 1] = '\0';
		}
		token = strtok(string, " ,\t");
		while (token != NULL){
            if ( prof_flag == 2){
                token = NULL;
                break;
            }
			if ( code_flag == 1 && title_counter > 0 && credit_flag == 0){
				if (token[1] == '\0' ){
					creditHours = atoi(token);
					credit_flag++;
				}
			}
			if (code_flag == 1 && credit_flag == 0 ){
				if (isTitle(token) == 1){
					course_title[title_counter] = (char*)malloc((strlen(token)+1) * sizeof(char));
					strcpy(course_title[title_counter],token);
					title_counter++;
				}
			}
            
			if ( code_flag == 1 && credit_flag == 1 && prof_flag < 3){
				if ( prof_flag == 0 && strlen(token) > 1){
					if ( isProfessor(token) == 1 ){
						professor[prof_flag] = (char*)malloc((strlen(token)+1) * sizeof(char));
						strcpy(professor[prof_flag], token);
						prof_flag++;
					}
				}
				else if (prof_flag == 1){
					if ( isProfessor(token) == 1 ){
						professor[prof_flag] = (char*)malloc((strlen(token)+1) * sizeof(char));
						strcpy(professor[prof_flag], token);
						prof_flag++;
					}
				}
				
			}
            if (code_flag == 0 && strcmp(token,search) == 0 ){
				strcpy(course_code, token);
				code_flag++;
			}
            
			temp = (char*)strtok(NULL, "\t, ");
            if (temp != NULL){
                token = temp;
            }
            else{
                break;
            }
		}
        
	}
    
    if (code_flag == 0){
    	printf("INVALID - Course not found\n");
    	return;
    }

   register_course(list, create_course(course_code, course_title, title_counter, creditHours, professor));
   printf("You are now registered for the course\n");

	return;
    
	
}

/* Creates a node containing fields: course code, course title/description, creditHours and professor name;
 Returns a pointer to the address of the new node. 
 */

Course* create_course(char* course_code, char* course_title[], int title_counter, int creditHours, char* professor[])
{
	int i;
	char temp_title[1000] = {0};
	char temp_prof[1000] = {0};
	Course* courseNode = (Course*)malloc(sizeof(Course));
    
	courseNode->course_code  = (char*)malloc(MAX_LINE_SIZE * sizeof(char));
	courseNode->course_title = (char*)malloc(MAX_LINE_SIZE * sizeof(char));
	courseNode->creditHours  = creditHours;
	courseNode->professor    = (char*)malloc(MAX_LINE_SIZE * sizeof(char));
	courseNode->next         = NULL;
	
	strcpy(courseNode->course_code, course_code);
	strcpy(temp_title, course_title[0]);
	for ( i = 1; i < title_counter; i++){
		strcat(temp_title, " ");
		strcat(temp_title, course_title[i]);
	}
	strcpy(courseNode->course_title, temp_title);

	strcpy(temp_prof, professor[0]);
	strcat(temp_prof, " ");
	strcat(temp_prof, professor[1]);
	strcpy(courseNode->professor, temp_prof);
    
	return courseNode;
    
}


/* Adds a new course to the end of the linked list.
 Input: Head of linked list, course node to be inserted.
 */
void register_course(Course** list, Course* newCourse)
{
	Course* current = *list;
    
    
	if (*list == NULL) {
        
		*list = newCourse;
		return;
	}
    
	while (current->next != NULL){
		current = current->next;
	}
    
	current->next = newCourse;
    
	return;
}


/* Takes in a string and checks to see if it meets the parameters for a name.
 Returns 1 if true and 0 if false. */
int isProfessor(char* string)
{
	int i;
	if (isupper(string[0]) == 1){
		for (i = 1; i < strlen(string); i++){
			if( islower(string[i]) == 0 ) {
				return 0;
			}
		}
		return 1;
	}
	return 0;
}

/* Checks to see if the inputted string meets the parameters of a title word. 
	Returns 1 if true or 0 if false */

int isTitle(char* string)
{
	int i;
	for (i = 1; i < strlen(string); i++){
		if( !isalpha(string[i]) && !isupper(string[i]) ) {
			return 0;
		}
	}
	return 1;
}
/* Recursively prints all courses added to the list */

void print_courses(Course* list)
{
	if ((list) == NULL){
		return;
	}
	else{
		printf("\n");
		printf("%-10s%25s%20s%d%20s%s\n", (list)->course_code, (list)->course_title, "Credit Hours: ", (list)->creditHours, "Professor: ", (list)->professor );
		print_courses(list->next);
	}
}

/* Displays a menu for user to see. Takes no arguments and returns nothing */

void displayMenu( void )
{
	printf("1-Register for a Course\n");
	printf("2-See my total\n");
	printf("3-Exit\n");
	printf("Choice: ");
}

/* Sums all of the credit hours for courses that are registered for.  Doesn't check for a NULL list initially as this is done in main() */

int sum_credit_hours( Course* list)
{
	int sum = 0;

	while(list != NULL){
		sum = sum + list->creditHours;
		list = list->next;
	}
	return sum;
}
