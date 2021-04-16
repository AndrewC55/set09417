#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

struct DataItem
{
    int key;
    int data[SIZE];
};


void display(void);
int hashCode(int key);
void insert(int key, int data);
struct DataItem* search(int key);

int main()
{
    return 0;
}

void display(void)
{
    for (int i = 0; i < SIZE; i++) {
        if (hashArray[i] != NULL) {
            printf(" (%d,%d)", hashArray[i]->key, hashArray[i]->data);
        } else {
            printf(" -,- ");
        }
    }
    printf("\n");
}

int hashCode(int key)
{
    return key % SIZE;
}

void insert(int key, int data)
{
    struct DataItem *item = (struct DataItem*)malloc(sizeof(struct DataItem));
    item->data = data;
    item->key = key;

    int hashIndex = hashCode(key);
    while (hashArray[hashIndex] != NULL && hashArray[hashIndex]->key != -1)
    {
        ++hashIndex;
        hashIndex %= SIZE;
    }
    hashArray[hashIndex] = item;
}

struct DataItem* search(int key)
{
    int hashIndex = hashCode(key);
    while (hashArray[hashIndex] != NULL)
    {
        if (hashArray[hashIndex]->key == key) {
            return hashArray[hashIndex];
        }
        ++hashIndex;
        hashIndex %= SIZE;
    }

    return NULL;
}