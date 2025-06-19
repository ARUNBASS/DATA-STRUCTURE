#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void insertAtEnd(int val) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;

    if (head == NULL)
        head = newNode;
    else {
        struct Node *temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
}

void deleteByValue(int val) {
    struct Node *temp = head, *prev = NULL;

    while (temp != NULL && temp->data != val) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Value not found!\n");
        return;
    }

    if (prev == NULL)
        head = temp->next;
    else
        prev->next = temp->next;

    free(temp);
    printf("Deleted %d\n", val);
}

void display() {
    struct Node *temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice, val;

    do {
        printf("\n1. Insert  2. Delete  3. Display  4. Exit\nChoice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &val);
                insertAtEnd(val);
                break;
            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &val);
                deleteByValue(val);
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 4);

    return 0;
}

