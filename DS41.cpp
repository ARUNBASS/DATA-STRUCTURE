#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to reverse a linked list
struct Node* reverse(struct Node* head) {
    struct Node *prev = NULL, *curr = head, *next = NULL;
    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

// Function to check if linked list is palindrome
int isPalindrome(struct Node* head) {
    struct Node *slow = head, *fast = head;
    
    // Find middle
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Reverse second half
    struct Node* secondHalf = reverse(slow);
    struct Node* firstHalf = head;

    // Compare halves
    while (secondHalf) {
        if (firstHalf->data != secondHalf->data)
            return 0;
        firstHalf = firstHalf->next;
        secondHalf = secondHalf->next;
    }
    return 1;
}

void push(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

void display(struct Node* head) {
    while (head) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;

    // Example: Palindrome list: 1 -> 2 -> 3 -> 2 -> 1
    push(&head, 1);
    push(&head, 2);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);

    printf("Linked List: ");
    display(head);

    if (isPalindrome(head))
        printf("It is a Palindrome\n");
    else
        printf("Not a Palindrome\n");

    return 0;
}

