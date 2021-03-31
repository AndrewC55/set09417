#include <stdio.h>

#define MAX 10

void enqueue(int *, int item, int *, int *);
void dequeue();
int empty(int *);

int main()
{
    int array[MAX];
    int front = -1, rear = -1;
    return 0;
}

void enqueue(int *array, int item, int *front, int *rear)
{
    if (*rear == MAX - 1) {
        printf("Queue is full \n");
        return;
    } else {
        printf("Enqueueing: %d \n", item);
        (*rear)++;
        array[*rear] = item;

        if (*front == -1) {
            *front = 0;
        }
    }
}

int dequeue(int *array, int *front, int *rear)
{
    printf("Dequeueing: %d\n", array[*front]);

    array[*front] = 0;

    if (*front == *rear) {
        (*front)--;
    } else {
        (*front++;
    }

    return array[*front];
}

int empty(int *front)
{
    if (*front == -1) {
        printf("Queue is empty\n");
        return 1;
    }

    return 0;
}