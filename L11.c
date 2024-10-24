#include <stdio.h>
#include <stdlib.h>

#define MAX 100 // Maximum number of nodes in the array-based tree

// Define the structure for a node in the binary tree
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node for the structure-based tree
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function for inorder traversal of the binary tree (structure-based)
void inorderTraversal(struct Node* root) {
    if (root == NULL)
        return;
    inorderTraversal(root->left);  // Traverse left subtree
    printf("%d ", root->data);     // Visit node
    inorderTraversal(root->right); // Traverse right subtree
}

// Function to perform inorder traversal in array-based binary tree
void inorderTraversalArray(int tree[], int index, int size) {
    if (index >= size || tree[index] == -1) {
        return; // Base case: index out of bounds or no node present
    }
    // Traverse the left subtree
    inorderTraversalArray(tree, 2 * index + 1, size);
    // Print the root node
    printf("%d ", tree[index]);
    // Traverse the right subtree
    inorderTraversalArray(tree, 2 * index + 2, size);
}

int main() {
    // Creating the structure-based binary tree
    struct Node* root = createNode(1); // Root node
    root->left = createNode(2);        // Left child of root
    root->right = createNode(3);       // Right child of root
    root->left->left = createNode(4);  // Left child of left child
    root->left->right = createNode(5); // Right child of left child
    
    // Perform inorder traversal (structure-based)
    printf("Inorder Traversal (Structure): ");
    inorderTraversal(root);
    printf("\n");

    // Creating the array-based binary tree
    int tree[MAX] = {1, 2, 3, 4, 5, -1, -1}; // -1 indicates no node present
    int size = 7; // Total number of nodes in the tree (including empty spots as -1)

    // Perform inorder traversal (array-based)
    printf("Inorder Traversal (Array): ");
    inorderTraversalArray(tree, 0, size);
    printf("\n");
    
    // Free allocated memory for the structure-based tree
    free(root->left->left);
    free(root->left->right);
    free(root->left);
    free(root->right);
    free(root);

    return 0;
}
