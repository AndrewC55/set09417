#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

struct DataItem
{
    int key;
    int data;
};

struct DataItem* hashArray[SIZE];
struct DataItem* tempItem;
struct DataItem* item;

void display(void);
int hashCode(int key);
void insert(int key, int data);
struct DataItem* search(int key);
struct DataItem* delete(struct DataItem* item);

int main()
{
    tempItem = (struct DataItem*)malloc(sizeof(struct DataItem));
    tempItem->data = -1;
    tempItem->key = -1;

    display();
    insert(1, 20);
    insert(2, 70);
    insert(42, 80);
    insert(4, 25);
    insert(12, 44);
    insert(14, 32);
    insert(17, 11);
    insert(37, 97);
    insert(10, 0);
    display();

    item = search(37);
    if (item != NULL) {
        printf("Element found: %d\n", item->data);
    } else {
        printf("Element not found\n");
    }

    item = delete(item);
    if (item != NULL) {
        printf("Element found: %d\n", item->data);
    } else {
        printf("Element not found\n");
    }

    item = search(37);
    if (item != NULL) {
        printf("Element found: %d\n", item->data);
    } else {
        printf("Element not found\n");
    }
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

struct DataItem* delete(struct DataItem* item)
{
    int key = item->key;
    int hashIndex = hashCode(key);

    while (hashArray[hashIndex] != NULL)
    {
        if (hashArray[hashIndex]->key == key) {
            struct DataItem *temp = hashArray[hashIndex];
            hashArray[hashIndex] = NULL;
            return temp;
        }
        ++hashIndex;
        hashIndex %= SIZE;
    }
    return NULL;
}