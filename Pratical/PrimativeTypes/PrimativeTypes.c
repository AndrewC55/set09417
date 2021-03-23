#include <stdio.h>

int main(int argc, char **argv)
{
    // declare variable integerVariable as type integer
    int integerVariable;
    // dcelare variable size as type size_t
    size_t size;

    // says variable size is equal to the sizeof (in memory) of integerVariable
    size = sizeof(integerVariable);

    // similar to php's sprintf function this line is printing the string message with an inputted specifier (%zu will be populated with the variable size)
    printf("Size of Integer Variable is %zu btyes \n", size);

    return 0;
}