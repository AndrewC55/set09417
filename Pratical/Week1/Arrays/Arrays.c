#include <stdio.h>

int main()
{
    int matricNumber, gradeNumber;

    // ask user for matric number
    printf("Please enter your Matric Number\n");
    // enter matric number and assign it to the matricNumber variable
    scanf("%d", &matricNumber);
    // ask user for how many grades they would to enter
    printf("Please enter the amount of grades you wish to enter\n");
    // enter how many grades they would like to store
    scanf("%d", &gradeNumber);
    
    // declare size of grades array to be whatever user has entered
    int grades[gradeNumber];

    // for loop through the amount of times user has entered
    for (int i = 0; i < gradeNumber; ++i) {
        // ask user for the grade of the 'x' subject
        printf("Please enter the grade for subject number %d:\n", i+1);
        // user enters grade
        scanf("%d", &grades[i]);
    }

    // tells user matric number
    printf("Results for student: %d\n", matricNumber);

    // for loop through the grades and displays them
    for (int i = 0; i < gradeNumber; ++i) {
        printf("%d \n", grades[i]);
    }

    return 0;
}