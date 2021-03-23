#include <stdio.h>

int main()
{
    int grades[11];
    
    // prints and scans so user can enter their respective grades
    printf("Please enter grade for SD1\n");
    scanf("%d", &grades[0]);
    printf("Please enter grade for Info Systems\n");
    scanf("%d", &grades[1]);
    printf("Please enter grade for UX\n");
    scanf("%d", &grades[2]);
    printf("Please enter grade for Maths\n");
    scanf("%d", &grades[3]);
    printf("Please enter grade for Computer Systems\n");
    scanf("%d", &grades[4]);
    printf("Please enter grade for PP1\n");
    scanf("%d", &grades[5]);
    printf("Please enter grade for OOP\n");
    scanf("%d", &grades[6]);
    printf("Please enter grade for Database Systems\n");
    scanf("%d", &grades[7]);
    printf("Please enter grade for Project Management\n");
    scanf("%d", &grades[8]);
    printf("Please enter grade for Software Enigeering Methods\n");
    scanf("%d", &grades[9]);
    printf("Please enter grade for PP2\n");
    scanf("%d", &grades[10]);

    // for loop through the grades and display
    for (int i = 0; i < 11; i++) {
        printf("%d \n", grades[i]);
    }

    return 0;
}