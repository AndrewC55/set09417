#include <stdio.h>

#define MAX 5

void display(int*);
void init(int*);
void insert(int*, int pos, int num);
void delete(int*, int pos);
void reverse(int*);
void search(int*, int num);

int main(void)
{
    int array[MAX];

    insert(array, 1, 11);
    insert(array, 2, 12);
    insert(array, 3, 13);
    insert(array, 4, 14);
    insert(array, 5, 15);

    printf("Array contents: \n");
    display(array);

    delete(array, 5);
    delete(array, 2);

    printf("After deletion: \n");
    display(array);

    insert(array, 2, 222);
    insert(array, 5, 555);

    printf("After Insertion: \n");
    display(array);

    reverse(array);

    printf("After Reversal: \n");
    display(array);

    search(array, 222);
    search(array, 666);

    return 0;
}

void display(int* array)
{
    for(int i = 0; i < MAX; i++) {
        printf("%d \t", i);
    }
    printf("\n");

    for(int i = 0; i < MAX; i++) {
        printf("%d \t", array[i]);
    }
    printf("\n");
}

void init(int* array)
{
    for(int i = 0; i < MAX; i++) {
        array[i] = 0;
    }
}

void insert(int* array, int pos, int num)
{
    int i;;

    for(i = MAX - 1; i >= pos; i--) {
        array[i] = array[i - 1];
    }

    array[i] = num;
}

void delete(int* array, int pos)
{
    int i;

    for(i = pos; i < MAX; i++) {
        array[i - 1] = array[i];
    }
    
    array[i] = 0;
}

void reverse(int* array)
{
    for(int i = 0; i < MAX/2; i++) {
        int temp = array[i];
        array[i] = array[MAX - 1 - i];
        array[MAX - 1 - i] = temp;
    }
}

void search(int* array, int num)
{
    int i;
    for(i = 0; i < MAX; i++) {
        if (array[i] == num) {
            printf("%d found in postion %d \n", num, i + 1);
        }
    }

    if (i == MAX) {
        printf("%d not found in array\n", num);
    }
}