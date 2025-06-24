#include <stdio.h>
#include <stdlib.h>

struct Node {
    int key, height;
    struct Node *left, *right;
};

int height(struct Node* n) { return n ? n->height : 0; }
int max(int a, int b) { return (a > b) ? a : b; }

struct Node* newNode(int key) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->key = key; node->left = node->right = NULL; node->height = 1;
    return node;
}

struct Node* rightRotate(struct Node* y) {
    struct Node* x = y->left; struct Node* T2 = x->right;
    x->right = y; y->left = T2;
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
    return x;
}

struct Node* leftRotate(struct Node* x) {
    struct Node* y = x->right; struct Node* T2 = y->left;
    y->left = x; x->right = T2;
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;
    return y;
}

int getBalance(struct Node* n) { return n ? height(n->left) - height(n->right) : 0; }

struct Node* insert(struct Node* node, int key) {
    if (!node) return newNode(key);
    if (key < node->key) node->left = insert(node->left, key);
    else if (key > node->key) node->right = insert(node->right, key);
    else return node;

    node->height = 1 + max(height(node->left), height(node->right));
    int bal = getBalance(node);

    if (bal > 1 && key < node->left->key) return rightRotate(node);
    if (bal < -1 && key > node->right->key) return leftRotate(node);
    if (bal > 1 && key > node->left->key) { node->left = leftRotate(node->left); return rightRotate(node); }
    if (bal < -1 && key < node->right->key) { node->right = rightRotate(node->right); return leftRotate(node); }

    return node;
}

struct Node* minValueNode(struct Node* node) {
    while (node->left) node = node->left;
    return node;
}

struct Node* deleteNode(struct Node* root, int key) {
    if (!root) return root;
    if (key < root->key) root->left = deleteNode(root->left, key);
    else if (key > root->key) root->right = deleteNode(root->right, key);
    else {
        if (!root->left || !root->right) {
            struct Node* temp = root->left ? root->left : root->right;
            if (!temp) { free(root); return NULL; }
            *root = *temp; free(temp);
        } else {
            struct Node* temp = minValueNode(root->right);
            root->key = temp->key;
            root->right = deleteNode(root->right, temp->key);
        }
    }
    root->height = 1 + max(height(root->left), height(root->right));
    int bal = getBalance(root);

    if (bal > 1 && getBalance(root->left) >= 0) return rightRotate(root);
    if (bal > 1 && getBalance(root->left) < 0) { root->left = leftRotate(root->left); return rightRotate(root); }
    if (bal < -1 && getBalance(root->right) <= 0) return leftRotate(root);
    if (bal < -1 && getBalance(root->right) > 0) { root->right = rightRotate(root->right); return leftRotate(root); }

    return root;
}

int search(struct Node* root, int key) {
    if (!root) return 0;
    if (key == root->key) return 1;
    return key < root->key ? search(root->left, key) : search(root->right, key);
}

void inorder(struct Node* root) {
    if (root) { inorder(root->left); printf("%d ", root->key); inorder(root->right); }
}

int main() {
    struct Node* root = NULL;
    int choice, key;
    while (1) {
        printf("\n1.Insert 2.Delete 3.Search 4.Display 5.Exit: ");
        scanf("%d", &choice);
        if (choice == 5) break;
        switch (choice) {
            case 1: printf("Enter key: "); scanf("%d", &key); root = insert(root, key); break;
            case 2: printf("Enter key: "); scanf("%d", &key); root = deleteNode(root, key); break;
            case 3: printf("Enter key: "); scanf("%d", &key); printf("%s\n", search(root, key) ? "Found" : "Not Found"); break;
            case 4: inorder(root); printf("\n"); break;
            default: printf("Invalid choice\n");
        }
    }
    return 0;
}

