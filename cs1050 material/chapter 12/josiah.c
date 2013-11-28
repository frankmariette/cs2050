#include <stdio.h>

int main(void)
{
        int highgrade, grade1, grade2, grade3;
        int section1, section2, section3;
        int midterm1, midterm2, final;

        highgrade = 0;


                printf("Enter the midterm1 grade:");
                scanf( "%d", &grade1 );

                while (( grade1 < 0) || (grade1 > 100)){
                        printf("Invalid grade enter the grade again:\n");
                        scanf("%d", &grade1 );
                }
                if (grade1 > highgrade) {
                        highgrade = grade1;
                }

                printf("Enter the midterm2 grade:");
                scanf( "%d", &grade2 );

                while (( grade2 < 0 ) || (grade2 > 100 )){
                        printf("Invalid grade enter the grade again:\n");
                        scanf("%d", &grade2 );
                }
                if (grade2 > highgrade) {
                        highgrade = grade2;
                }

                printf("Enter the final grade:");
                scanf( "%d", &final );

                while (( final < 0 ) || (final > 100)){
                        printf("Invalid grade enter the grade again:\n");
                        scanf("%d", &final);
                }
                if (grade3 > highgrade) {
                        highgrade = grade3;
}

                printf("Highest grade for the student is %d.\n", highgrade);

}
