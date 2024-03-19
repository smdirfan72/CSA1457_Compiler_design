#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 10

// Structure for each symbol entry
struct Symbol {
    char name[20];
    int value;
    struct Symbol *next;
};

// Hash table for symbol table
struct Symbol *hashTable[SIZE];

// Hash function
int hash(char *name) {
    int sum = 0;
    while (*name)
        sum += *name++;
    return sum % SIZE;
}

// Insertion operation
void insert(char *name, int value) {
    int index = hash(name);
    struct Symbol *newSymbol = (struct Symbol *)malloc(sizeof(struct Symbol));
    if (!newSymbol) {
        printf("Memory allocation failed!\n");
        return;
    }
    strcpy(newSymbol->name, name);
    newSymbol->value = value;
    newSymbol->next = NULL;

    // Insert at the beginning of the linked list
    newSymbol->next = hashTable[index];
    hashTable[index] = newSymbol;
}

// Search operation
struct Symbol *search(char *name) {
    int index = hash(name);
    struct Symbol *temp = hashTable[index];
    while (temp) {
        if (strcmp(temp->name, name) == 0)
            return temp;
        temp = temp->next;
    }
    return NULL;
}

// Deletion operation
void deleteSymbol(char *name) {
    int index = hash(name);
    struct Symbol *temp = hashTable[index];
    struct Symbol *prev = NULL;

    while (temp != NULL && strcmp(temp->name, name) != 0) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Symbol not found\n");
        return;
    }

    if (prev == NULL)
        hashTable[index] = temp->next;
    else
        prev->next = temp->next;

    free(temp);
    printf("Symbol deleted successfully\n");
}

// Display symbol table
void display() {
    printf("\n------ Symbol Table ------\n");
    for (int i = 0; i < SIZE; i++) {
        struct Symbol *temp = hashTable[i];
        while (temp != NULL) {
            printf("Name: %s, Value: %d\n", temp->name, temp->value);
            temp = temp->next;
        }
    }
}

int main() {
    for (int i = 0; i < SIZE; i++)
        hashTable[i] = NULL;

    insert("x", 10);
    insert("y", 20);
    insert("z", 30);

    display();

    struct Symbol *result = search("y");
    if (result != NULL)
        printf("\nFound: Name: %s, Value: %d\n", result->name, result->value);
    else
        printf("\nNot found\n");

    deleteSymbol("y");

    display();

    return 0;
}

