#include <stdio.h>
#include <stdlib.h>


#define TABLE_SIZE      10


struct hashNode {
    int key;
    int value;
    struct hashNode *next;
};

struct hashNode *hash_table[TABLE_SIZE];

struct hashNode *createHashNode(int key, int value)
{
    struct hashNode *newNode = (struct hashNode *)malloc(sizeof(struct hashNode));
    newNode->key = key;
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}
int hashFunction(int key)
{
    return (key % TABLE_SIZE);
}

void insert(int key, int value)
{
    int index = hashFunction(key);
    struct hashNode *newNode = createHashNode(key, value);
    struct hashNode *tmp  = hash_table[index];
    if(!tmp) {
        hash_table[index] = newNode;
        return;
    }
    while(tmp->next) 
        tmp = tmp->next;
    
    tmp->next = newNode;
}

void display()
{
    for(int i = 0; i < TABLE_SIZE; i++) {

        struct hashNode *tmp = hash_table[i];
        while(tmp != NULL) {
            printf("key = %d : value = %d : index = %d\n", tmp->key, tmp->value, i);
            tmp = tmp->next;
        }
    }
}

int main()
{

    for(int i = 0; i < TABLE_SIZE; i++)
        hash_table[i] = NULL;

    insert(1230, 10);
    insert(1231, 20);
    insert(1232, 30);
    insert(1233, 40);
    insert(1234, 50);
    insert(1235, 60);
    insert(1236, 70);
    insert(1237, 80);
    insert(1238, 90);
    insert(1239, 100);

    display();


    return 0;
}
