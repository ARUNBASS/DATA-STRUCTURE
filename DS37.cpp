#include <stdio.h>
#include <stdlib.h>

// Structure for each node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Insert into BST
struct Node* insert(struct Node* root, int value) {
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

// Search a value in BST
int search(struct Node* root, int key) {
    if (root == NULL)
        return 0; // Not found
    if (root->data == key)
        return 1; // Found
    if (key < root->data)
        return search(root->left, key);
    else
        return search(root->right, key);
}

// Inorder traversal (optional)
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {
    struct Node* root = NULL;
    int choice, value, key;

    while (1) {
        printf("\n1. Insert\n2. Search\n3. Display Inorder\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                break;
            case 2:
                printf("Enter number to search: ");
                scanf("%d", &key);
                if (search(root, key))
                    printf("Number %d found in the tree.\n", key);
                else
                    printf("Number %d not found.\n", key);
                break;
            case 3:
                printf("Inorder Traversal: ");
                inorder(root);
                printf("\n");
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}

