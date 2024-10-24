#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for a character node
typedef struct CharacterNode {
    char name[50];
    int health;
    int attack;
    struct CharacterNode* left;
    struct CharacterNode* right;
} CharacterNode;

// Function to create a new character node
CharacterNode* createCharacterNode(const char* name, int health, int attack) {
    CharacterNode* newNode = (CharacterNode*)malloc(sizeof(CharacterNode));
    strcpy(newNode->name, name);
    newNode->health = health;
    newNode->attack = attack;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a new character into the BST
CharacterNode* insertCharacter(CharacterNode* root, const char* name, int health, int attack) {
    if (root == NULL) {
        return createCharacterNode(name, health, attack);
    }
    if (strcmp(name, root->name) < 0) {
        root->left = insertCharacter(root->left, name, health, attack);
    } else if (strcmp(name, root->name) > 0) {
        root->right = insertCharacter(root->right, name, health, attack);
    }
    return root;
}

// Function to search for a character in the BST
CharacterNode* searchCharacter(CharacterNode* root, const char* name) {
    if (root == NULL || strcmp(root->name, name) == 0) {
        return root;
    }
    if (strcmp(name, root->name) < 0) {
        return searchCharacter(root->left, name);
    }
    return searchCharacter(root->right, name);
}

// Function for in-order traversal to display characters
void inorderTraversal(CharacterNode* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("Name: %s, Health: %d, Attack: %d\n", root->name, root->health, root->attack);
        inorderTraversal(root->right);
    }
}

// Function to free the character tree
void freeCharacterTree(CharacterNode* root) {
    if (root != NULL) {
        freeCharacterTree(root->left);
        freeCharacterTree(root->right);
        free(root);
    }
}

// Example usage
int main() {
    CharacterNode* characterTree = NULL;

    // Insert characters into the BST
    characterTree = insertCharacter(characterTree, "Warrior", 150, 30);
    insertCharacter(characterTree, "Mage", 100, 20);
    insertCharacter(characterTree, "Archer", 120, 25);
    insertCharacter(characterTree, "Rogue", 90, 35);

    // Display characters
    printf("In-order traversal of character tree:\n");
    inorderTraversal(characterTree);

    // Search for a character
    const char* searchName = "Mage";
    CharacterNode* searchResult = searchCharacter(characterTree, searchName);
    if (searchResult != NULL) {
        printf("Found character: %s, Health: %d, Attack: %d\n", searchResult->name, searchResult->health, searchResult->attack);
    } else {
        printf("Character '%s' not found.\n", searchName);
    }

    // Clean up
    freeCharacterTree(characterTree);
    return 0;
}
