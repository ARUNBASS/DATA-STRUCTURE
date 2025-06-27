#include <stdio.h>
#define TABLE_SIZE 10

int hashTable[TABLE_SIZE];

// Initialize all slots to -1 (indicating empty)
void initHashTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i] = -1;
    }
}

// Hash function
int hash(int key) {
    return key % TABLE_SIZE;
}

// Insert a key using linear probing
void insert(int key) {
    int index = hash(key);
    int i = 0;

    while (hashTable[(index + i) % TABLE_SIZE] != -1) {
        i++;
        if (i == TABLE_SIZE) {
            printf("Hash table is full! Cannot insert %d\n", key);
            return;
        }
    }

    hashTable[(index + i) % TABLE_SIZE] = key;
    printf("Inserted %d at index %d\n", key, (index + i) % TABLE_SIZE);
}

// Search for a key
int search(int key) {
    int index = hash(key);
    int i = 0;

    while (hashTable[(index + i) % TABLE_SIZE] != -1) {
        if (hashTable[(index + i) % TABLE_SIZE] == key) {
            return (index + i) % TABLE_SIZE;
        }
        i++;
        if (i == TABLE_SIZE) {
            break;
        }
    }
    return -1;
}

// Display the hash table
void display() {
    printf("Hash Table:\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("Index %d: %d\n", i, hashTable[i]);
    }
}

int main() {
    int choice, key, result;

    initHashTable();

    while (1) {
        printf("\nHash Table Operations:\n");
        printf("1. Insert\n2. Search\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter key to insert: ");
                scanf("%d", &key);
                insert(key);
                break;
            case 2:
                printf("Enter key to search: ");
                scanf("%d", &key);
                result = search(key);
                if (result != -1) {
                    printf("Key %d found at index %d\n", key, result);
                } else {
                    printf("Key %d not found!\n", key);
                }
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}

