#include <stdio.h>
#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;

void enqueue(int value) {
    if (rear == SIZE - 1) {
        printf("Queue is Full\n");
    } else {
        if (front == -1) front = 0;
        queue[++rear] = value;
        printf("Inserted %d\n", value);
    }
}

void dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue is Empty\n");
    } else {
        printf("Deleted %d\n", queue[front++]);
    }
}

void display() {
    if (front == -1 || front > rear) {
        printf("Queue is Empty\n");
    } else {
        printf("Queue Elements: ");
        for (int i = front; i <= rear; i++)
            printf("%d ", queue[i]);
        printf("\n");
    }
}

int main() {
    int choice, value;
    while (1) {
        printf("\n1. ENQUEUE\n2. DEQUEUE\n3. DISPLAY\n4. EXIT\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid Choice\n");
        }
    }
    return 0;
}


