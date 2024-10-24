#include <stdio.h>
#include <stdlib.h>

// Define the AVL node structure
typedef struct AVLNode {
    int value;
    struct AVLNode *left;
    struct AVLNode *right;
    int height;
} AVLNode;

// Function prototypes
AVLNode* createNode(int value);
int height(AVLNode *node);
int max(int a, int b);
AVLNode* rightRotate(AVLNode *y);
AVLNode* leftRotate(AVLNode *x);
int getBalance(AVLNode *node);
AVLNode* insert(AVLNode* node, int value);
void inOrder(AVLNode *root);
void preOrder(AVLNode *root);
void postOrder(AVLNode *root);
void freeTree(AVLNode *root); // Function to free allocated memory

// Create a new AVL node
AVLNode* createNode(int value) {
    AVLNode *node = (AVLNode*)malloc(sizeof(AVLNode));
    if (node == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    node->height = 1; // New node is initially at height 1
    return node;
}

// Get the height of a node
int height(AVLNode *node) {
    if (node == NULL) return 0;
    return node->height;
}

// Get the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Perform a right rotation
AVLNode* rightRotate(AVLNode *y) {
    AVLNode *x = y->left;
    AVLNode *T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x; // Return new root
}

// Perform a left rotation
AVLNode* leftRotate(AVLNode *x) {
    AVLNode *y = x->right;
    AVLNode *T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y; // Return new root
}

// Get the balance factor of a node
int getBalance(AVLNode *node) {
    if (node == NULL) return 0;
    return height(node->left) - height(node->right);
}

// Insert a value into the AVL tree
AVLNode* insert(AVLNode* node, int value) {
    if (node == NULL) return createNode(value);

    // Insert in the appropriate subtree
    if (value < node->value)
        node->left = insert(node->left, value);
    else if (value > node->value)
        node->right = insert(node->right, value);
    else 
        return node; // Duplicate values are not allowed

    // Update height of this ancestor node
    node->height = 1 + max(height(node->left), height(node->right));

    // Get the balance factor
    int balance = getBalance(node);

    // Perform rotations to balance the tree
    // Left Left Case
    if (balance > 1 && value < node->left->value)
        return rightRotate(node);

    // Right Right Case
    if (balance < -1 && value > node->right->value)
        return leftRotate(node);

    // Left Right Case
    if (balance > 1 && value > node->left->value) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left Case
    if (balance < -1 && value < node->right->value) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node; // Return the (unchanged) node pointer
}

// In-order traversal
void inOrder(AVLNode *root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->value);
        inOrder(root->right);
    }
}

// Pre-order traversal
void preOrder(AVLNode *root) {
    if (root != NULL) {
        printf("%d ", root->value);
        preOrder(root->left);
        preOrder(root->right);
    }
}

// Post-order traversal
void postOrder(AVLNode *root) {
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->value);
    }
}

// Free the tree's allocated memory
void freeTree(AVLNode *root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

// Main function to test the AVL tree
int main() {
    AVLNode *root = NULL;

    // Insert nodes into the AVL tree
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    // Print tree traversals
    printf("In-order traversal: ");
    inOrder(root);
    printf("\n");

    printf("Pre-order traversal: ");
    preOrder(root);
    printf("\n");

    printf("Post-order traversal: ");
    postOrder(root);
    printf("\n");

    // Free allocated memory
    freeTree(root);

    return 0;
}
