#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for Stack Node
typedef struct StackNode {
    char customer_name[50];
    struct StackNode* next;
} StackNode;

// Structure for Stack
typedef struct Stack {
    StackNode* top;
} Stack;

// Function to create a new stack node
StackNode* createStackNode(const char* customer_name) {
    StackNode* newNode = (StackNode*)malloc(sizeof(StackNode));
    strcpy(newNode->customer_name, customer_name);
    newNode->next = NULL;
    return newNode;
}

// Function to initialize the stack
Stack* createStack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->top = NULL;
    return stack;
}

// Push function to add a customer to the stack
void push(Stack* stack, const char* customer_name) {
    StackNode* newNode = createStackNode(customer_name);
    newNode->next = stack->top; // Link new node to current top
    stack->top = newNode;       // Update top to new node
    printf("Customer added to stack: %s\n", customer_name);
}

// Pop function to serve the last customer
void pop(Stack* stack) {
    if (!stack->top) {
        printf("No customers in stack.\n");
        return;
    }
    StackNode* temp = stack->top;
    printf("Served from stack: %s\n", temp->customer_name);
    stack->top = stack->top->next; // Move top pointer to next node
    free(temp);                    // Free the served customer node
}

// Check if the stack is empty
int isStackEmpty(Stack* stack) {
    return stack->top == NULL;
}

// Peek function to see the last customer
void peek(Stack* stack) {
    if (stack->top) {
        printf("Last customer to be served: %s\n", stack->top->customer_name);
    } else {
        printf("No customers in stack.\n");
    }
}

// Free the stack
void freeStack(Stack* stack) {
    while (!isStackEmpty(stack)) {
        pop(stack);
    }
    free(stack);
}

// Example usage
int main() {
    Stack* serviceStack = createStack();
    push(serviceStack, "Customer A");
    push(serviceStack, "Customer B");
    push(serviceStack, "Customer C");

    peek(serviceStack); // Outputs: Customer C
    pop(serviceStack);  // Outputs: Served from stack: Customer C
    peek(serviceStack); // Outputs: Customer B

    // Clean up
    freeStack(serviceStack);
    return 0;
}
