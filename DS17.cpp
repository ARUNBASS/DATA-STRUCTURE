#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to print the linked list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Function to merge two lists
struct Node* mergeLists(struct Node* l1, struct Node* l2) {
    if (l1 == NULL) return l2;
    if (l2 == NULL) return l1;

    struct Node* temp = l1;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = l2;
    return l1;
}

int main() {
    struct Node *head1 = createNode(1);
    head1->next = createNode(3);
    head1->next->next = createNode(5);

    struct Node *head2 = createNode(2);
    head2->next = createNode(4);
    head2->next->next = createNode(6);

    printf("List 1: ");
    printList(head1);

    printf("List 2: ");
    printList(head2);

    struct Node *merged = mergeLists(head1, head2);
    printf("Merged List: ");
    printList(merged);

    return 0;
}

