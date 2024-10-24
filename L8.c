#include <stdio.h>
#include <stdlib.h>

// Definition of the doubly linked list node
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Insert a node at the front of the list
void insertAtFront(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    if (*head != NULL) {
        (*head)->prev = newNode;
    }
    *head = newNode;
}

// Insert a node at the end of the list
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

// Delete a node from the list
void deleteNode(struct Node** head, int key) {
    struct Node* temp = *head;

    // If the node to be deleted is the head node
    if (temp != NULL && temp->data == key) {
        *head = temp->next;
        if (*head != NULL) {
            (*head)->prev = NULL;
        }
        free(temp);
        return;
    }

    // Find the node to be deleted
    while (temp != NULL && temp->data != key) {
        temp = temp->next;
    }

    // If the key is not present in the list
    if (temp == NULL) return;

    // Unlink the node from the list
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }
    free(temp);
}

// Print the list in forward direction
void printList(struct Node* node) {
    printf("Traversal in forward direction:\n");
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

// Print the list in reverse direction
void printReverseList(struct Node* node) {
    struct Node* last = node;
    if (node == NULL) return;
    while (last->next != NULL) {
        last = last->next;
    }
    printf("Traversal in reverse direction:\n");
    while (last != NULL) {
        printf("%d ", last->data);
        last = last->prev;
    }
    printf("\n");
}

// Main function to demonstrate operations on doubly linked list
int main() {
    struct Node* head = NULL;

    // Insert elements into the list
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    insertAtFront(&head, 5);

    // Print list in forward and reverse direction
    printList(head);
    printReverseList(head);

    // Delete a node and print the list again
    deleteNode(&head, 20);
    printList(head);
    printReverseList(head);

    return 0;
}
