#include <stdio.h>

int main(int argc, char **argv)
{
    // declaring variable integerVariable as type integer
    int integerVariable;
    // declaring variable longVariable as type long
    long longVariable;
    // declaring variable shortVariable as type short
    short shortVariable;
    // declaring variable charVariable as type char
    char charVariable;
    // declaring variable floatVariable as type float
    float floatVariable;
    // declaring variable doubleVariable as type double
    double doubleVariable;


    // similar to php's sprintf function this line is printing the string message with an inputted specifier (%zu will be populated with the size of integerVariable)
    printf("Size of Integer Variable is %zu btyes \n", sizeof(integerVariable));
    // similar to php's sprintf function this line is printing the string message with an inputted specifier (%zu will be populated with the size of longVariable)
    printf("Size of Long Variable is %zu btyes \n", sizeof(longVariable));
    // similar to php's sprintf function this line is printing the string message with an inputted specifier (%zu will be populated with the size of shortVariable)
    printf("Size of Byte Variable is %zu btyes \n", sizeof(shortVariable));
    // similar to php's sprintf function this line is printing the string message with an inputted specifier (%zu will be populated with the size of charVariable)
    printf("Size of Char Variable is %zu btyes \n", sizeof(charVariable));
    // similar to php's sprintf function this line is printing the string message with an inputted specifier (%zu will be populated with the size of floatVariable)
    printf("Size of Float Variable is %zu btyes \n", sizeof(floatVariable));
    // similar to php's sprintf function this line is printing the string message with an inputted specifier (%zu will be populated with the size of doubleVariable)
    printf("Size of Double Variable is %zu btyes \n", sizeof(doubleVariable));

    return 0;
}