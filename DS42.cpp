#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

// Create a new node
struct Node* createNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Insert into BST
struct Node* insert(struct Node* root, int data) {
    if (root == NULL) return createNode(data);
    if (data < root->data) root->left = insert(root->left, data);
    else root->right = insert(root->right, data);
    return root;
}

// Inorder Traversal to find kth smallest
void kthMin(struct Node* root, int k, int *count, int *result) {
    if (root == NULL || *count >= k) return;
    kthMin(root->left, k, count, result);
    (*count)++;
    if (*count == k) {
        *result = root->data;
        return;
    }
    kthMin(root->right, k, count, result);
}

int main() {
    struct Node* root = NULL;
    root = insert(root, 20);
    insert(root, 8);
    insert(root, 22);
    insert(root, 4);
    insert(root, 12);
    insert(root, 10);
    insert(root, 14);

    int k = 3, count = 0, result = -1;
    kthMin(root, k, &count, &result);

    if (result != -1)
        printf("The %dth minimum element is %d\n", k, result);
    else
        printf("Less than %d elements in BST.\n", k);

    return 0;
}

